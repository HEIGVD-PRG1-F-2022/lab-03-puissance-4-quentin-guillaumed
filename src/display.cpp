/*
-----------------------------------------------------------------------------------
Nom du fichier  : display.cpp
Auteur(s)       : Guillaume Dunant, Quentin Aellen
Date creation   : 23.10.2022

Description     : Puissance 4

Remarque(s)     : <a completer>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
#include "../include/display.h"
#include "../include/player.h"

using namespace std;

/**
 * Use const variable Rules to display rules
 */
void displayGameRules() {
    if (RULES.size() == 0) {
        cout << "Aucune regle est défini, have fun !" << endl;
        return;
    }

    for (int x = 0; x < RULES.size(); x++) {
        cout << "Regle " << x + 1 << ": " << RULES[x] << endl;
    }
}

void displayGameBoardHeader(std::vector<std::vector<char>> &gameBoard) {
    cout << endl;
    for (int header = 0; header <= gameBoard.size(); header++) {
        cout << setw(3) << setfill(' ') << header + 1 << " ";
    }
    cout << endl;
}

void displayGameBoard(std::vector<std::vector<char>> &gameBoard) {
    const int gameBoardRowSize = gameBoard.size();
    const int gameBoardColSize = gameBoard[0].size();
    const int gameBoardSeparatorWidth = (gameBoardRowSize + 1) * 4 + 1;

    displayGameBoardHeader(gameBoard);

    cout << setw(gameBoardSeparatorWidth) << setfill('-') << "" << endl;

    for (int row = 0; row < gameBoardRowSize; row++) {
        for (int col = 0; col < gameBoardColSize; col++) {
            cout << "|" << setw(3) << setfill(' ') << getPlayerColorCoin((Player) gameBoard[row][col]);

            if (col == (gameBoardColSize - 1)) {
                cout << "|";
            }
        }
        cout << endl
             << setw(gameBoardSeparatorWidth) << setfill('-') << "" << endl;
    }
}