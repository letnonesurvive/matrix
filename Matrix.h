#pragma once
#include <memory>
#include <map>
#include <vector>
#include <stdexcept>

template <class T, T>
class Matrix;

template <class T>
class ReadProxy
{
public:
    ReadProxy() 
    {}
private:
    size_t myRow, myColumn;
};

template <class T>
class WriteProxy
{
public:
    WriteProxy()
    {}
private:
    size_t myRow, myColumn;
};

template <class T, T theDefaultValue>
class Matrix
{
public: 
    Matrix()
    {

    }

    Matrix (const Matrix& m)
    {
        myValues = m.myValues;
    }

    Matrix& operator= (const Matrix& m)
    {
        myValues = m.myValues;
    }

    T get_default_value() const
    {
        return theDefaultValue;
    }

    size_t size() const
    {
        return myValues.size();
    }

    //T operator() (size_t theRow, size_t theCol) const
    //{
    //    //return ReadProxy<T>();
    //    auto aPair = std::make_pair(theRow, theCol);
    //    try {
    //        auto aValue = myValues.at(aPair);
    //        return aValue;
    //    }
    //    catch (...) {
    //    }
    //    return theDefaultValue;

    //}

    //T operator() (size_t theRow, size_t theCol)
    //{
    //    auto aPair = std::make_pair(theRow, theCol);
    //    return myValues[aPair];
    //}

    T& operator() (size_t theRow, size_t theCol)
    {
        auto aPair = std::make_pair(theRow, theCol);
        return myValues[aPair];
    }


private:
    std::map <std::pair <size_t, size_t>, T> myValues;
};