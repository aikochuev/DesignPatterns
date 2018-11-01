#include "stdafx.h"
#include "Decorator.h"

Transponse::Transponse(IMatrix* matrix)
{ 
    m_matrix = matrix;
}
const int Transponse::getN()
{ 
    return m_matrix->getN(); 
}

int* Transponse::getValue(const int i, const int j) 
{ 
    return m_matrix->getValue(j, i);
}

void Transponse::setValue(const int val, const int i, const int j) 
{ 
    m_matrix->setValue(val, j, i);
}

IMatrix* Transponse::reset() 
{
    return m_matrix->reset(); 
}

Minor::Minor(IMatrix* matrix, const std::vector<int> elemIndexVector) : m_elemIndexVector(elemIndexVector)
{
    m_matrix = matrix;
}

const int Minor::getN()
{ 
    return m_elemIndexVector.size(); 
}

int* Minor::getValue(int i, int j)
{
    if(i < m_elemIndexVector.size() && j < m_elemIndexVector.size())
        return m_matrix->getValue(m_elemIndexVector[i], m_elemIndexVector[j]);
    std::cout << "Index Error : max index = "<< m_elemIndexVector.size() << std::endl;
    return nullptr;
}

void Minor::setValue(const int val, const int i, const int j)
{
    if(i < m_elemIndexVector.size() && j < m_elemIndexVector.size())
        m_matrix->setValue(val, m_elemIndexVector[i], m_elemIndexVector[j]);
    else
        std::cout << "Index Error : max index = " << m_elemIndexVector.size() << std::endl;
}

IMatrix* Minor::reset()
{ 
    return m_matrix->reset(); 
}

ZeroSeter::ZeroSeter(IMatrix* matrix)
{
    m_matrix = matrix;
}

const int ZeroSeter::getN()
{ 
    return m_matrix->getN(); 
}

int* ZeroSeter::getValue(const int i, const int j)
{
    int zero = 0;
    if(int* value = m_matrix->getValue(i, j))
        return (i >= j ? value : &zero);
    else
        return nullptr;
}

void ZeroSeter::setValue(const int val, const int i, const int j)
{ 
    if(int* value = m_matrix->getValue(i, j))
        if(i >= j)
            m_matrix->setValue(val, i, j);
}

IMatrix* ZeroSeter::reset()
{
    return m_matrix->reset();
}