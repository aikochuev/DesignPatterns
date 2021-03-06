#include "stdafx.h"
#include "IDrawer.h"
#include "IMatrix.h"
#include <sstream>
#include <iostream>

void choiceDrawer(IMatrix* mat)
{
    char* drawCommand = new char[128];
    std::cout << "Supported commands : html, console, graphic, exit" << std::endl;
    while(std::strcmp(drawCommand, "exit") != 0)
    {
        std::cout << "Draw command : ";
        std::scanf("%s", drawCommand);
        if(std::strcmp(drawCommand, "html") == 0)
        {
            mat->setDrawer(new CHTMLDrawer());
            mat->draw();
            continue;
        }
        if(std::strcmp(drawCommand, "console") == 0)
        {
            mat->setDrawer(new CConsoleDrawer());
            mat->draw();
            continue;
        }
        if(std::strcmp(drawCommand, "graphic") == 0)
        {
            mat->setDrawer(new CGraphicDrawer());
            mat->draw();
            continue;
        }
        if(std::strcmp(drawCommand, "exit") == 0)
        {
            continue;
        }
        printf("Unexpected command : %s\n", drawCommand);
        std::cout << "Supported commands : html, console, graphic, exit" << std::endl;
    }
}

int main()
{
    std::vector<int> values;
    const int m = 2;
    const int n = 2;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            values.push_back(rand());
    std::vector<SparseMatrix::SparseElem> sparseValues;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            SparseMatrix::SparseElem tmp(values[i*n + j], i, j);
            sparseValues.push_back(tmp);
        }
    char* command = new char[128];
    std::cout << "Supported commands : full, sparse, exit" << std::endl;
    while(std::strcmp(command, "exit") != 0)
    {
        std::cout << "Command : ";
        std::scanf("%s", command);
        if(std::strcmp(command, "full") == 0)
        {
            choiceDrawer(new FullMatrix(values, m, n));
            continue;
        }
        if(std::strcmp(command, "sparse") == 0)
        {
            choiceDrawer(new SparseMatrix(sparseValues, m, n));
            continue;
        }
        if(std::strcmp(command, "exit") == 0)
        {
            continue;
        }
        printf("Unexpected command : %s\n", command);
        std::cout << "Supported commands : full, sparse, exit" << std::endl;
    }
    system("pause");
    return 0;
}

