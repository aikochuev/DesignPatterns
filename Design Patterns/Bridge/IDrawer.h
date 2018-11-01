#pragma once
class IDrawer
{
public:
    virtual void drawCells(int i, int j) = 0;
    virtual void drawValue(int i, int j, int value) = 0;
    virtual void drawBorder(int m, int n) = 0;
};

class CHTMLDrawer :public IDrawer
{
public:
    virtual void drawCells(int i, int j);
    virtual void drawValue(int i, int j, int value);
    virtual void drawBorder(int m, int n);
};

class CConsoleDrawer :public IDrawer
{
public:
    virtual void drawCells(int i, int j);
    virtual void drawValue(int i, int j, int value);
    virtual void drawBorder(int m, int n);
};

class CGraphicDrawer : public IDrawer
{
public:
    virtual void drawCells(int i, int j);
    virtual void drawValue(int i, int j, int value);
    virtual void drawBorder(int m, int n);
};