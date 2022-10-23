/*
-----------------------------------------------------------------------------------
Nom du fichier  : game.cpp
Auteur(s)       : Guillaume Dunant, Quentin Aellen
Date creation   : 23.10.2022

Description     : Puissance 4

Remarque(s)     : <a completer>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <vector>
#include <iostream>
#include "../include/player.h"
#include "../include/display.h"
#include "../include/game.h"

using namespace std;

void startGame() {

    displayGameRules();

    // Wait for the user to start
    cout << "Appuyer sur <Enter> pour commencer une partie ";
    cin.ignore();

    bool currentPlayer = false;

    // Clear the console and display the board
    system("cls");

    vector<vector<char>> board(6, vector<char>(7, ' '));
    int col;
    int availableCase = -1;

    do {
        Player player = currentPlayer ? Player::RED : Player::YELLOW;
        displayGameBoard(board);

        do {
            col = getPlayerInput(board[0].size(), player);
            availableCase = availableColSpace(board, col);
        } while (availableCase == -1);

        board[availableCase][col - 1] = (int) player;

        currentPlayer = !currentPlayer;
    } while (!checkVictory(board, availableCase, col - 1));

    displayGameBoard(board);
}

int availableColSpace(vector<vector<char>> &gameBoard, int col) {
    for (int x = gameBoard.size() - 1; x >= 0; x--) {
        if (gameBoard[x][col - 1] == ' ')
            return x;
    }
    return -1;
}

bool checkVictory(vector<vector<char>> &board, int x, int y) {
    // Check the column
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        // Si l'index est en-dehors du tableau
        if (x + i + 1 >= board.size()) {
            break;
        }

        if (board[x + i][y] == board[x + i + 1][y]) {
            counter++;
        } else {
            break;
        }

        if (counter >= 4) {
            return true;
        }
    }

    // Check the row
    counter = 1;
    // Exit flag to stop a side when there isn't a series of coin
    bool f1 = true, f2 = true;

    for (int i = 0; i < 4; i++) {
        // Si l'index est en-dehors du tableau
        if (x + i + 1 >= board[0].size() && x - i - 1 < 0) {
            break;
        }

        // Check right
        if (board[x][y + i] == board[x][y + i + 1] && f1) {
            counter++;
        } else {
            f1 = false;
        }

        // Check left
        if (board[x][y - i] == board[x][y - i - 1] && f2) {
            counter++;
        } else {
            f2 = false;
        }

        if (!f1 && !f2)
            break;

        if (counter >= 4) {
            return true;
        }
    }

    //Check the diag / and \
    counter = 1;
    f1 = true, f2 = true;
    bool f3 = true, f4 = true;

    for (int i = 0; i < 4; i++) {
        // Si l'index est en-dehors du tableau
        if (y - i - 1 < 0) {
            f2 = false;
            f3 = false;
        }

        if (y + i + 1 > board[i].size() - 1) {
            f1 = false;
            f4 = false;
        }

        if (x + i + 1 > board.size() - 1) {
            f2 = false;
            f4 = false;
        }

        if (x - i - 1 < 0) {
            f1 = false;
            f3 = false;
        }

        // Check diag / up
        if (f1 && board[x + i][y + i] == board[x + i - 1][y + i + 1]) {
            counter++;
        } else {
            f1 = false;
        }

        // Check diag / down
        if (f2 && board[x - i][y - i] == board[x - i + 1][y - i - 1]) {
            counter++;
        } else {
            f2 = false;
        }

        // Check diag \ up
        if (f3 && board[x + i][y - i] == board[x + i - 1][y - i - 1]) {
            counter++;
        } else {
            f3 = false;
        }

        // Check diag \ down
        if (f4 && board[x - i][y + i] == board[x - i + 1][y + i + 1]) {
            counter++;
        } else {
            f4 = false;
        }

        if ((!f1 && !f2) || (!f3 && !f4))
            break;

        if (counter >= 4) {
            return true;
        }
    }

    return false;
}