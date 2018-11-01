#pragma once
#include "Matrix.h"

class BaseDecorator : public IMatrix
{
protected:
    IMatrix* m_matrix;
public:
    virtual const int getN() = 0;
    virtual int* getValue(int i, int j) = 0;
    virtual void setValue(int val, int i, int j) = 0;
    virtual IMatrix* reset() = 0;
};

class Transponse : public BaseDecorator
{
public:
    Transponse(IMatrix* matrix);
    virtual const int getN();
    virtual int* getValue(const int i, const int j);
    virtual void setValue(const int val, const int i, const int j);
    virtual IMatrix* reset();
};

class Minor : public BaseDecorator
{
    std::vector<int> m_elemIndexVector;
public:
    Minor(IMatrix* matrix, const std::vector<int> elemIndexVector);
    virtual const int getN();
    virtual int* getValue(int i, int j);
    virtual void setValue(const int val, const int i, const int j);
    virtual IMatrix* reset();
};

class ZeroSeter : public BaseDecorator
{
public:
    ZeroSeter(IMatrix* matrix);
    virtual const int getN();
    virtual int* getValue(const int i, const int j);
    virtual void setValue(const int val, const int i, const int j);
    virtual IMatrix* reset();
};