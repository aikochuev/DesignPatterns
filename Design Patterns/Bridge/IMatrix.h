#pragma once
#include "IDrawer.h"
#include <vector>

class IMatrix
{
    IDrawer* m_drawer;
public:
    void setDrawer(IDrawer* d);
    virtual void draw() = 0;
protected:
    virtual void drawCells(int i, int j);
    virtual void drawValue(int i, int j, int value);
    virtual void drawBorder(int m, int n);
};

class FullMatrix : public IMatrix
{
    std::vector<int> m_values;
    const int m_m, m_n;
public:
    FullMatrix(std::vector<int> values, const int m, const int n) : m_values(values), m_m(m), m_n(n) {}
    virtual void draw();
};
class SparseMatrix : public IMatrix
{
    
public:
    struct SparseElem
    {
        SparseElem(int value, int rowIndex, int colIndex) :s_value(value), s_rowIndex(rowIndex), s_colIndex(colIndex) {}
        int s_value;
        int s_rowIndex;
        int s_colIndex;
    };
    SparseMatrix(std::vector<SparseElem> values, const int m, const int n) :m_values(values), m_m(m), m_n(n) {}
    virtual void draw();
private:
    const int m_m, m_n;
    std::vector<SparseElem> m_values;
};
