#include "stdafx.h"
#include "CommandManager.h"

void CommandManager::executeCommand(Command* cmd)
{
    if(const char* err = cmd->errCode())
        std::cout << err << std::endl;
    else
    {
        commandStackUndo.push_back(cmd);
        cmd->execute();
    }
}

void CommandManager::undo()
{
    if(commandStackUndo.size() > 1)
    {
        commandStackUndo.pop_back();
        for(const auto& cmd: commandStackUndo)
            cmd->execute();
    }
    else
        std::cout << "Undo Command Stack is Empty" << std::endl;
}

SetValueCommand::SetValueCommand(std::vector<int>& vector, int value, int index):Command(vector)
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

void SetValueCommand::execute()
{
    if(m_vector.size() > m_saveIndex)
        m_vector[m_saveIndex] = m_value;
    else
        m_err = "Error : Invalid index";
}

PopBackCommand::PopBackCommand(std::vector<int>& vector) : Command(vector)
{
    if(!m_vector.empty())
        m_saveValue = m_vector.back();
    else
        m_err = "Error : Vector is Empty";
}

void PopBackCommand::execute()
{
    if(!m_vector.empty())
        m_vector.pop_back();
    else
        m_err = "Error : Vector is Empty";
}

PushBackCommand::PushBackCommand(std::vector<int>& vector, int value) : Command(vector)
{
    m_value = value;
}

void PushBackCommand::execute()
{
    m_vector.push_back(m_value);
}

void ResetCommand::execute()
{
    m_vector.clear();
}
CommandManager::CommandManager(std::vector<int>& vector)
{
    commandStackUndo.push_back(new ResetCommand(vector));
}

