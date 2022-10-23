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

    bool currentPlayerFlag = false;

    // Clear the console and display the board
    system("cls");

    vector<vector<char>> board(BOARD_HEIGHT, vector<char>(BOARD_WIDTH, ' '));
    int col;
    int availableCase = -1;

    Player player;

    do {
        player = currentPlayerFlag ? Player::RED : Player::YELLOW;
        displayGameBoard(board);

        do {
            col = getPlayerInput(BOARD_WIDTH, player);
            availableCase = availableColSpace(board, col);
        } while (availableCase == -1);

        board[availableCase][col - 1] = (int) player;

        currentPlayerFlag = !currentPlayerFlag;
    } while (!checkVictory(board, availableCase, col - 1));

    //Display the final board and the winner
    displayGameBoard(board);
    displayWinner(player);
}

int availableColSpace(vector<vector<char>> &gameBoard, int col) {
    for (int x = BOARD_HEIGHT - 1; x >= 0; x--) {
        if (gameBoard[x][col - 1] == ' ')
            return x;
    }
    return -1;
}

bool checkVictory(vector<vector<char>> &board, int x, int y) {
    return (checkVertical(board,x,y) || checkHorizontal(board, x,y) || checkDiagonals(board,x,y));
}

bool checkHorizontal(vector<vector<char>> &board, int x, int y){

    int counter = 1;

    // Exit flag to stop a side when there isn't a series of coin
    bool flagLeft = true, flagRight = true;

    for (int i = 0; i < WIN_CONDITION; i++) {
        // if the index is outside the array
        if (x + i + 1 >= BOARD_WIDTH && x - i - 1 < 0) {
            break;
        }

        // Check the coin on the right
        if (board[x][y + i] == board[x][y + i + 1] && flagRight) {
            counter++;
        } else {
            flagRight = false;
        }

        // Check the coin on the left
        if (board[x][y - i] == board[x][y - i - 1] && flagLeft) {
            counter++;
        } else {
            flagLeft = false;
        }

        //Stop the check if both flags are false
        if (!flagRight && !flagLeft)
            break;

        //Check the win condition
        if (counter >= WIN_CONDITION) {
            return true;
        }
    }

    return false;
}

bool checkVertical(vector<vector<char>> &board, int x, int y){
    int counter = 1;
    for (int i = 0; i < WIN_CONDITION; i++) {
        // Si l'index est en-dehors du tableau
        if (x + i + 1 >= BOARD_HEIGHT) {
            break;
        }

        // Check the coin bellow
        if (board[x + i][y] == board[x + i + 1][y]) {
            counter++;
        } else {
            break;
        }

        //Check the win condition
        if (counter >= WIN_CONDITION) {
            return true;
        }
    }

    return false;
}

bool checkDiagonals(vector<vector<char>> &board, int x, int y){

    //The down diag is \ and the up diag is /
    int counterUpDiag = 1, counterDownDiag = 1;

    // Exit flag to stop a side when there isn't a series of coin
    bool flagUpLeft = true, flagDownLeft = true, flagUpRight = true, flagDownRight = true;

    for (int i = 0; i < WIN_CONDITION; i++) {
        // If the index is outside the array on the left
        if (y - i - 1 < 0) {
            flagUpLeft = false;
            flagDownLeft = false;
        }

        // If the index is outside the array on the right
        if (y + i + 1 > BOARD_WIDTH - 1) {
            flagUpRight = false;
            flagDownRight = false;
        }

        // If the index is outside the array on the bottom
        if (x + i + 1 > BOARD_HEIGHT - 1) {
            flagDownLeft = false;
            flagDownRight = false;
        }

        // If the index is outside the array on the top
        if (x - i - 1 < 0) {
            flagUpLeft = false;
            flagUpRight = false;
        }

        // Check diag / up
        if (flagUpRight && board[x + i][y + i] == board[x + i - 1][y + i + 1]) {
            counterUpDiag++;
        } else {
            flagUpRight = false;
        }

        // Check diag / down
        if (flagDownLeft && board[x - i][y - i] == board[x - i + 1][y - i - 1]) {
            counterUpDiag++;
        } else {
            flagDownLeft = false;
        }

        // Check diag \ up
        if (flagUpLeft && board[x + i][y - i] == board[x + i - 1][y - i - 1]) {
            counterDownDiag++;
        } else {
            flagUpLeft = false;
        }

        // Check diag \ down
        if (flagDownRight && board[x - i][y + i] == board[x - i + 1][y + i + 1]) {
            counterDownDiag++;
        } else {
            flagDownRight = false;
        }

        //If all the flags are false
        if (!flagDownRight && !flagUpLeft && !flagDownLeft && !flagUpRight)
            break;

        //If one of the diag fulfill the win condition
        if (counterUpDiag >= WIN_CONDITION || counterDownDiag >= WIN_CONDITION) {
            return true;
        }
    }

    return false;
}