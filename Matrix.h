#pragma once
#include <memory>
#include <map>
#include <vector>
#include <stdexcept>
#include <ostream>

class Cell
{
public:
    Cell() {};
    
    Cell(size_t _x, size_t _y): x(_x), y(_y) {};

    size_t X() const
    {
        return x;
    }

    size_t Y() const
    {
        return y;
    }

private:
    size_t x;
    size_t y;
};

template <class T, T theDefaultValue>
class Matrix
{
    using CellType = std::pair <size_t, size_t>;

public: 
    Matrix() : myMaxRowIndex(0), myMaxColIndex(0)
    {

    }

    auto begin() const
    {
        return myValues.begin();
    }

    auto end() const
    {
        return myValues.end();
    }

    T get_default_value() const
    {
        return theDefaultValue;
    }

    size_t size()
    {
        std::vector <CellType> anErasedValues;

        for (const auto &aPair : myValues) {
            if (aPair.second == theDefaultValue) {
                const auto& aCell = aPair.first;
                anErasedValues.push_back (aCell);
            }
        }

        for (const auto& aVariable : anErasedValues) {
            myValues.erase (aVariable);
        }

        return myValues.size();
    }

    const T operator() (size_t theRow, size_t theCol) const
    {
        auto aPair = std::make_pair (theRow, theCol);
        try {
            return myValues.at (aPair);
        }
        catch (std::out_of_range) {

        }
        return theDefaultValue;
    }

    T& operator() (size_t theRow, size_t theCol)
    {
        calculate_max_indeces (theRow, theCol);
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
            os << endl;
        }
        return os;
    }

private:

    void calculate_max_indeces (size_t theRow, size_t theCol)
    {
        if (theRow > myMaxRowIndex) {
            myMaxRowIndex = theRow;
        }
        if (theCol > myMaxColIndex) {
            myMaxColIndex = theCol;
        }
    }

private:
    std::map <CellType, T> myValues;
    size_t myMaxRowIndex;
    size_t myMaxColIndex;
};
