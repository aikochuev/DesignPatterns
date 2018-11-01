#include "stdafx.h"
#include "CommandManagerClassic.h"

CommandManager* CommandManager::getInstance()
{
    static CommandManager* m_commandManager;
    if(m_commandManager == nullptr)
        m_commandManager = new CommandManager();
    return m_commandManager;
}

void CommandManager::executeCommand(Command* cmd)
{
    if(const char* err = cmd->errCode())
        std::cout << err << std::endl;
    else
    {
        commandStackUndo.push(cmd);
        cmd->doExecute();
    }
}

void CommandManager::undo()
{
    if(commandStackUndo.size() > 0)
    {
        commandStackUndo.top()->undo();
        commandStackRedo.push(commandStackUndo.top());
        commandStackUndo.pop();
    }
    else
        std::cout << "Undo Command Stack is Empty" << std::endl;
}

void CommandManager::redo()
{
    if(commandStackRedo.size() > 0)
    {
        commandStackRedo.top()->redo();
        commandStackUndo.push(commandStackRedo.top());
        commandStackRedo.pop();
    }
    else
        std::cout << "Redo Command Stack is Empty" << std::endl;
}

SetValueCommand::SetValueCommand(std::vector<int>& vector, int value, int index) :Command(vector)
{
    if(m_vector.size() > index)
    {
        m_value = value;
        m_saveIndex = index;
        m_saveValue = m_vector[index];
    }
    else
        m_err = "Error : Invalid index";
}

void SetValueCommand::doExecute()
{
    if(m_vector.size() > m_saveIndex)
        m_vector[m_saveIndex] = m_value;
    else
        m_err = "Error : Invalid index";
}

void SetValueCommand::execute()
{
    CommandManager::getInstance()->executeCommand(this);
}

void SetValueCommand::undo()
{
    if(m_vector.size() > m_saveIndex)
        m_vector[m_saveIndex] = m_saveValue;
}

void SetValueCommand::redo()
{
    doExecute();
}

PopBackCommand::PopBackCommand(std::vector<int>& vector) : Command(vector)
{
    if(!m_vector.empty())
        m_saveValue = m_vector.back();
    else
        m_err = "Error : Vector is Empty";
}

void PopBackCommand::doExecute()
{
    if(!m_vector.empty())
        m_vector.pop_back();
    else
        m_err = "Error : Vector is Empty";
}

void PopBackCommand::execute()
{
    CommandManager::getInstance()->executeCommand(this);
}

void PopBackCommand::undo()
{
    m_vector.push_back(m_saveValue);
}

void PopBackCommand::redo()
{
    doExecute();
}

PushBackCommand::PushBackCommand(std::vector<int>& vector, int value) : Command(vector)
{
    m_value = value;
}

void PushBackCommand::doExecute()
{
    m_vector.push_back(m_value);
}

void PushBackCommand::execute()
{
    CommandManager::getInstance()->executeCommand(this);
}

void PushBackCommand::undo()
{
    if(!m_vector.empty())
        m_vector.pop_back();
}

void PushBackCommand::redo()
{
    doExecute();
}
