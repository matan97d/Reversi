/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/
#ifndef REVERSI_COMMAND_H
#define REVERSI_COMMAND_H

#include <iostream>
using namespace std;

// command interface.
class Command {

public:
    virtual ~Command();
    virtual int execute(int clientSocket, string& command) = 0;
};


#endif //REVERSI_COMMAND_H
