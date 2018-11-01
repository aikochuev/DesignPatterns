#pragma once
#include <stack>
#include <vector>
#include <iostream>

class CommandManager;
class Command
{
protected:
    std::vector<int>& m_vector;
    const char* m_err = nullptr;
    virtual void execute() = 0;
    const char* errCode() { return m_err; }
    Command(std::vector<int>& vector) :m_vector(vector) {}
    friend CommandManager;
};

class CommandManager
{
    std::deque<Command*> commandStackUndo;
public:
    CommandManager(std::vector<int>& vector);
    void executeCommand(Command* cmd);
    void undo();
};

class SetValueCommand : public Command
{
    int m_saveValue;
    int m_saveIndex;
    int m_value;
    void execute();
public:
    SetValueCommand(std::vector<int>& vector, int value, int index);
};

class PopBackCommand : public Command
{
    int m_saveValue;
    void execute();
public:
    PopBackCommand(std::vector<int>& vector);
};

class ResetCommand : public Command
{
    void execute();
public:
    ResetCommand(std::vector<int>& vector) : Command(vector) {}
};
class PushBackCommand : public Command
{
    int m_value;
    void execute();
public:
    PushBackCommand(std::vector<int>& vector, int value);
};
