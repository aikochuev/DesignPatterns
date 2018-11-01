#include "stdafx.h"
#include "IMatrix.h"
#include <iostream>

void FullMatrix::draw()
{
    printf("%s\n",__FUNCTION__);
    drawBorder(m_m, m_n);
    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
        {
            drawValue(i, j, m_values[i* m_n + j]);
            drawCells(i, j);
        }
}

void SparseMatrix::draw()
{
    printf("%s\n", __FUNCTION__);
    drawBorder(m_m, m_n);
    for (int i = 0; i < m_values.size(); i++)
        drawValue(m_values[i].s_rowIndex, m_values[i].s_colIndex, m_values[i].s_value);
}

void IMatrix::setDrawer(IDrawer* d)
{
    m_drawer = d;
}

void IMatrix::drawCells(int i, int j)
{
    m_drawer->drawCells(i, j);
}

void IMatrix::drawValue(int i, int j, int value)
{
    m_drawer->drawValue(i, j, value);
}

void IMatrix::drawBorder(int m, int n)
{
    m_drawer->drawBorder(m, n);
}
