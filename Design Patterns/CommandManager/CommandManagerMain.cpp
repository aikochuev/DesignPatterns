#include "stdafx.h"
#include "CommandManager.h"
#include <string>
#include <sstream>

void print(std::vector<int>& vector)
{
    if(vector.empty())
        std::cout << "Array is Empty" << std::endl;
    else
    {
        std::cout << "Array : ";
        for(const int& el : vector)
            std::cout << el << " ";
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<int> vector;
    CommandManager cmVector(vector);
    char* command = new char[128];
    std::cout << "Supported commands : undo, push 'value', pop, set 'index' 'value', print, exit" << std::endl;
    while(std::strcmp(command, "exit") != 0)
    {
        std::cout << "Command : ";
        std::scanf("%s", command);
        if(std::strcmp(command, "push") == 0)
        {
            int value = 0;
            std::scanf("%d", &value);
            cmVector.executeCommand(new PushBackCommand(vector, value));
            print(vector);
            continue;
        }
        if(std::strcmp(command, "pop") == 0)
        {
            cmVector.executeCommand(new PopBackCommand(vector));
            print(vector);
            continue;
        }
        if(std::strcmp(command, "set") == 0)
        {
            int index = 0;
            std::scanf("%d", &index);
            int value = 0;
            std::scanf("%d", &value);
            cmVector.executeCommand(new SetValueCommand(vector,value, index));
            print(vector);
            continue;
        }
        if(std::strcmp(command, "undo") == 0)
        {
            cmVector.undo();
            print(vector);
            continue;
        }
        if(std::strcmp(command, "print") == 0)
        {
            print(vector);
            continue;
        }
        if(std::strcmp(command, "exit") == 0)
        {
            continue;
        }
        printf("Unexpected command : %s\n", command);
        std::cout << "Supported commands : undo, redo, push 'value', pop, set 'index' 'value', print, exit" << std::endl;
    }
    system("pause");
    return 0;
}

