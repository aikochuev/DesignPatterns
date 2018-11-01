#include "stdafx.h"
#include "Matrix.h"

void IMatrix::printMatrix(IMatrix* v)
{
    for(int i = 0; i < v->getN(); i++)
    {
        bool line = false;
        for(int j = 0; j < v->getN(); j++)
        {
            if(int* value = v->getValue(i, j))
            {
                std::cout << *value << " ";
                line = true;
            }
        }
        if(line)
            std::cout << std::endl;
    }
}

const int Matrix::getN()
{ 
    return m_values.size(); 
}

int* Matrix::getValue(const int i, const int j)
{ 
    if(i < m_values.size() && j < m_values.size())
        return &m_values[i][j];
    std::cout << "Index Error : max index = " << m_values.size() << std::endl;
    return nullptr;
}

void Matrix::setValue(const int val, const int i, const int j)
{
    if(i < m_values.size() && j < m_values.size())
        m_values[i][j] = val;
    else
        std::cout << "Index Error : max index = " << m_values.size() << std::endl;
}

IMatrix* Matrix::reset()
{ 
    return this;
}