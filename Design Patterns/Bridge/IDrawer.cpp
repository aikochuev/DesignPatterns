#include "stdafx.h"
#include "IDrawer.h"
#include <iostream>

void CHTMLDrawer::drawCells(int i, int j)
{
    printf("%s i = %d j = %d \n", __FUNCTION__, i, j);
}

void CHTMLDrawer::drawValue(int i, int j, int value)
{
    printf("%s i = %d j = %d value = %d \n", __FUNCTION__, i, j, value);
}

void CHTMLDrawer::drawBorder(int m, int n)
{
    printf("%s m = %d n = %d \n", __FUNCTION__, m, n);
}

void CConsoleDrawer::drawCells(int i, int j)
{
    printf("%s i = %d j = %d \n", __FUNCTION__, i, j);
}

void CConsoleDrawer::drawValue(int i, int j, int value)
{
    printf("%s i = %d j = %d value = %d \n",__FUNCTION__, i, j, value);
}

void CConsoleDrawer::drawBorder(int m, int n)
{
    printf("%s m = %d n = %d \n", __FUNCTION__, m, n);
}

void CGraphicDrawer::drawCells(int i, int j)
{
    printf("%s i = %d j = %d \n", __FUNCTION__, i, j);
}

void CGraphicDrawer::drawValue(int i, int j, int value)
{
    printf("%s i = %d j = %d value = %d \n", __FUNCTION__, i, j, value);
}

void CGraphicDrawer::drawBorder(int m, int n)
{
    printf("%s m = %d n = %d \n", __FUNCTION__, m, n);
}
