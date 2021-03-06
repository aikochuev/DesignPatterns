#include "stdafx.h"
#include <vector>
#include <iostream>
#include "Decorator.h"
#include <string>
#include <sstream>

int main()
{
    int size = 0;
    std::cout << "Creating Matrix ..." << std::endl;
    std::cout << "Enter size of matrix : ";
    std::scanf("%d", &size);
    std::vector<std::vector<int>> matrixVector;
    matrixVector.resize(size);
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            matrixVector[i].push_back(10*i+j+11);
    IMatrix* matrix = new Matrix(matrixVector);
    IMatrix::printMatrix(matrix);
    char* command = new char[128];
    std::cout << "Supported commands :  zero, trans, minor 'n' 'index', reset, print, set 'value' 'row' 'column', get 'row' 'column', exit" << std::endl;
    while(std::strcmp(command, "exit") != 0)
    {
        std::cout << "Command : ";
        std::scanf("%s", command);
        if(std::strcmp(command, "zero") == 0)
        {
            matrix = new ZeroSeter(matrix);
            IMatrix::printMatrix(matrix);
            continue;
        }
        if(std::strcmp(command, "trans") == 0)
        {
            matrix = new Transponse(matrix);
            IMatrix::printMatrix(matrix);
            continue;
        }
        if(std::strcmp(command, "reset") == 0)
        {
            matrix = matrix->reset();
            IMatrix::printMatrix(matrix);
            continue;
        }
        if(std::strcmp(command, "minor") == 0)
        {
            int n = 0;
            std::scanf("%d", &n);
            std::vector<int> index;
            for(int i = 0; i < n; i++)
            {
                int id = 0;
                std::scanf("%d", &id);
                index.push_back(id - 1);
            }
            matrix = new Minor(matrix, index);
            IMatrix::printMatrix(matrix);
            continue;
        }
        if(std::strcmp(command, "set") == 0)
        {
            int value = 0;
            std::scanf("%d", &value);
            int row = 0;
            std::scanf("%d", &row);
            int column = 0;
            std::scanf("%d", &column);
            matrix->setValue(value, row - 1, column - 1);
            IMatrix::printMatrix(matrix);
            continue;
        }
        if(std::strcmp(command, "get") == 0)
        {
            int row = 0;
            std::scanf("%d", &row);
            int column = 0;
            std::scanf("%d", &column);
            if(int* value = matrix->getValue(row - 1, column - 1))
                std::cout << "Value = " << *value << std::endl;
            continue;
        }
        if(std::strcmp(command, "print") == 0)
        {
            IMatrix::printMatrix(matrix);
            continue;
        }
        if(std::strcmp(command, "exit") == 0)
        {
            continue;
        }
        printf("Unexpected command : %s\n", command);
        std::cout << "Supported commands :  zero, trans, minor 'n' 'index', reset, print, set 'value' 'row' 'column', get 'row' 'column', exit" << std::endl;
    }
    system("pause");
    return 0;
}

