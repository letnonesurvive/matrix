#pragma once
#include <memory>
#include <map>
#include <vector>
#include <stdexcept>

template <class T>
class Matrix;

template <class T>
class ReadProxy {

public:
    ReadProxy (const Matrix<T>& theMatrix, size_t theIndex) : myMatrix(theMatrix), myIndex(theIndex) {}

    const T& operator[](size_t theIndex) const
    {
        auto aRow = myMatrix.get_value(myIndex);
        return aVar.get_value(theIndex);
    }

private:
    const Matrix<T>& myMatrix;
    size_t myIndex; // row's index
};

template <typename T>
class WriteProxy {

public:
    WriteProxy(const Matrix<T>& theMatrix, size_t theIndex) : myMatrix(theMatrix), myIndex(theIndex) {}

    T& operator[](size_t theIndex)
    {
        auto aRow = myMatrix.get_value (myIndex);
        //Matrix<T>::MatrixRow aRow;

    }

private:
    const Matrix<T>& myMatrix;
    size_t myIndex; // row's index
};

template <class T>
class Matrix
{
public:
    Matrix(const T& theDefaultValue) 
    {
        myDefaultValue = theDefaultValue;
    }
    size_t size() const
    {
        return myRows.size();
    }

    T get_default_value () const
    {
        return myDefalutValue;
    }

    class MatrixRow
    {
    public:
        MatrixRow()
        {

        }

        const T& get_value (size_t theIndex) const
        {
            static T aRes = -1; // must be default value
            try {
                return myValues.at(theIndex);
            }
            catch (const std::out_of_range) {
            }
            return aRes;
        }


    private:
        std::map<size_t, T> myValues;
    };


    ReadProxy<T> operator[](size_t theIndex) const
    {
        return ReadProxy<T>(*this, theIndex);
    }

    const MatrixRow& get_value(size_t theIndex) const
    {
        static MatrixRow aRes;
        try {
            return myRows.at(theIndex);
        }
        catch (const std::out_of_range) {
        }
        return aRes;
    }

    void set_value(size_t theIndex, const T& theValue)
    {
        myRows[index]
    }

    WriteProxy<T> operator[](size_t theIndex)
    {
        return WriteProxy<T>(*this, theIndex);
    }

private:
    T myDefaultValue;
    std::map<size_t, MatrixRow> myRows;
};