#pragma once
#include <memory>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <tuple>

template <class T, T theDefaultValue>
class Matrix;

template <class T>
class matrix_iterator;

template <class T, T theDefaultValue>
class Matrix
{
public:
    using CellType = std::pair <size_t, size_t>;

public: 
    Matrix() : myMaxRowIndex(0), myMaxColIndex(0)
    {

    };

    class matrix_iterator
    {
    public:
        matrix_iterator() {}

        matrix_iterator (typename std::map<CellType, T>::iterator theIt)
        {
            myIt = theIt;
        };

        matrix_iterator& operator++()
        {
            ++myIt;
            return *this;
        }

        bool operator== (const matrix_iterator& theOther) const 
        {
            return myIt == theOther.myIt;
        }

        bool operator!= (const matrix_iterator& theOther) const 
        {
            return myIt != theOther.myIt;
        }

        std::tuple<size_t, size_t, T> operator*() const 
        {
            return std::make_tuple (myIt->first.first, myIt->first.second, myIt->second);
        }

    private:
        typename std::map<CellType, T>::iterator myIt;
    };

    matrix_iterator begin()
    {
        return matrix_iterator (myValues.begin());
    }

    matrix_iterator end()
    {
        return matrix_iterator (myValues.end());
    }

    T get_default_value() const
    {
        return theDefaultValue;
    }

    size_t size()
    {
        EraseExtraValues();
        return myValues.size();
    }

    const T operator() (size_t theRow, size_t theCol) const
    {
        auto aPair = std::make_pair (theRow, theCol);
        try {
            return myValues.at (aPair);
        }
        catch (std::out_of_range&) {

        }
        return theDefaultValue;
    }

    T& operator() (size_t theRow, size_t theCol)
    {
        calculate_max_indexes (theRow, theCol);
        auto aPair = std::make_pair (theRow, theCol);
        myValues[aPair] = theDefaultValue;
        return myValues[aPair];
    }

    void Print (CellType& from, CellType& to) const
    {
        if (to.first < from.first || to.second < from.second) {
            throw std::logic_error ("The second cell less then first");
        }

        for (size_t i = from.first; i <= to.first; ++i) {
            for (size_t j = from.second; j <= to.second; ++j) {
                std::cout << this->operator()(i, j) << ' ';
            }
            std::cout << std::endl;
        }
    }

    friend std::ostream& operator<< (std::ostream& os, const Matrix& theMatrix)
    {
        for (size_t i = 0; i <= theMatrix.myMaxRowIndex; ++i) {
            for (size_t j = 0; j <= theMatrix.myMaxColIndex; ++j) {
                os << theMatrix (i, j) << ' ';
            }
            os << std::endl;
        }
        return os;
    }

private:

    void calculate_max_indexes (size_t theRow, size_t theCol)
    {
        if (theRow > myMaxRowIndex) {
            myMaxRowIndex = theRow;
        }
        if (theCol > myMaxColIndex) {
            myMaxColIndex = theCol;
        }
    }

    void EraseExtraValues()
    {
        std::vector <CellType> anErasedValues;

        for (const auto &aPair : myValues) {
            if (aPair.second == theDefaultValue) {
                const auto& aCell = aPair.first;
                anErasedValues.push_back(aCell);
            }
        }

        for (const auto& aVariable : anErasedValues) {
            myValues.erase(aVariable);
        }

    }

private:
    std::map <CellType, T> myValues;
    size_t myMaxRowIndex;
    size_t myMaxColIndex;
};

