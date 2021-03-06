/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../AIPlayer.h"
#include "../Checker.h"
#include "../BoardManager.h"
#include "../ConsolePrinter.h"

TEST(AI_PLAYER_TEST, GET_POINT) {
    BoardManager boardManager(4);
    Matrix<Checker> board(4, 4);
    Graphic* printer = new ConsolePrinter();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = Nothing;
        }
    }
    board[0][0] = White;
    board[0][1] = White;
    board[1][0] = Black;
    board[2][0] = AvailableW;
    boardManager.Init(board);
    AIPlayer playerW(White, boardManager, printer);
    AIPlayer playerB(Black, boardManager, printer);
    Point point1 = playerW.GetPointFromPlayer();
    Point point2 = playerB.GetPointFromPlayer();
    Point tmp1(2, 0);
    Point tmp2(-1, -1);
    EXPECT_TRUE(tmp1 == point1 && tmp2 == point2);
    delete printer;
}

