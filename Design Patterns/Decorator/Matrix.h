#pragma once
#include <vector>
#include <iostream>

class IMatrix
{
public:
    virtual const int getN() = 0;
    virtual int* getValue(const int i, const int j) = 0;
    virtual void setValue(const int val, const int i, const int j) = 0;
    virtual IMatrix* reset() = 0;
    static void printMatrix(IMatrix* v);
};

class Matrix : public IMatrix
{
    std::vector<std::vector<int>> m_values;
public:
    Matrix(std::vector<std::vector<int>>& a) : m_values(a) {}
    const int getN();
    int* getValue(const int i, const int j);
    void setValue(const int val, const int i, const int j);
    virtual IMatrix* reset();
};