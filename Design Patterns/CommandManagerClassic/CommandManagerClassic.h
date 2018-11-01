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
    virtual void doExecute() = 0;
    const char* errCode() { return m_err; }
public:
    virtual void undo() = 0;
    virtual void redo() = 0;
    virtual void execute() = 0; 
    Command(std::vector<int>& vector) :m_vector(vector) {}
    friend CommandManager;
};

class CommandManager
{
    std::stack<Command*> commandStackUndo;
    std::stack<Command*> commandStackRedo;
public:
    void executeCommand(Command* cmd);
    void undo();
    void redo();
    static CommandManager* getInstance();
private:
    CommandManager() {}
    ~CommandManager() {}
    CommandManager(CommandManager const&);
    CommandManager& operator= (CommandManager const&);
};

class SetValueCommand : public Command
{
    int m_saveValue;
    int m_saveIndex;
    int m_value;
    void doExecute();
    void undo();
    void redo();
public:
    void execute();
    SetValueCommand(std::vector<int>& vector, int value, int index);
};

class PopBackCommand : public Command
{
    int m_saveValue;
    void doExecute();
    void undo();
    void redo();
public:
    void execute();
    PopBackCommand(std::vector<int>& vector);
};

class PushBackCommand : public Command
{
    int m_value;
    void doExecute();
    void undo();
    void redo();
public:
    void execute();
    PushBackCommand(std::vector<int>& vector, int value);
};
