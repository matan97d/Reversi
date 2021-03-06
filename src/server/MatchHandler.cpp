/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "MatchHandler.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <cstring>
using  namespace std;

MatchHandler::MatchHandler(int max) : gameStarted(false), maxDataSizeToTransfer(max), clientSocket1(0), clientSocket2(0) {
}

MatchHandler::~MatchHandler() {
    Close();
}

void MatchHandler::setClientSocket1(int clientSocket1) {
    MatchHandler::clientSocket1 = clientSocket1;
}

void MatchHandler::setClientSocket2(int clientSocket2) {
    MatchHandler::clientSocket2 = clientSocket2;
}

bool MatchHandler::isGameStarted() const {
    return gameStarted;
}

void MatchHandler::Start() {
    gameStarted = true;
    InitiatePlayers();
    CommunicationStream();
}

void MatchHandler::InitiatePlayers() {
    int size = 2;
    std::string black = "1";
    std::string white = "2";
    int check = send(clientSocket1, &size, sizeof(size), 0);
    if (check < 0) {
        throw "Error on Initiate player1";
    }
    check = send(clientSocket1, black.c_str(), black.size(), 0);
    if (check < 0) {
        throw "Error on Initiate player1";
    }
    check = send(clientSocket2, &size, sizeof(size), 0);
    if (check < 0) {
        throw "Error on Initiate player2";
    }
    check = send(clientSocket2, white.c_str(), white.size(), 0);
    if (check < 0) {
        throw "Error on Initiate player2";
    }

}

void MatchHandler::CommunicationStream() {
    int sender = clientSocket1;
    int receiver = clientSocket2;
    int tmp;
    while (TransferData(sender, receiver)) {
        tmp = sender;
        sender = receiver;
        receiver = tmp;
    }
}

bool MatchHandler::TransferData(int sender, int receiver) {
    char buffer[maxDataSizeToTransfer];
    memset(buffer, 0, maxDataSizeToTransfer);
    int check = read(sender, buffer, maxDataSizeToTransfer);
    if (check <= 0) {
        return false;
    }
    check = send(receiver, buffer, maxDataSizeToTransfer, 0);
    if (check <= 0) {
        return false;
    }
    return true;
}

void MatchHandler::Close() {
    close(clientSocket1);
    close(clientSocket2);
}
