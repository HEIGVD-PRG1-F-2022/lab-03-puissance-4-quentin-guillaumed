/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Guillaume Dunant, Quentin Aellen
Date creation   : 18.10.2022

Description     : Puissance 4

Remarque(s)     : <a completer>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

enum class Player {
    YELLOW,
    RED,
};

string getPlayerColorCoin(Player player);

void displayGameRules();

void startGame();

void displayBoard(vector<vector<char>> &);

int getPlayerInput(int, Player);

int getAvailableColSpace(vector<vector<char>> &, int);

bool checkVictory(vector<vector<char>> &, int, int);

int main() {

    displayGameRules();
    startGame();

    return EXIT_SUCCESS;
}

/**
 * Display the rules of the game (https://fr.wikipedia.org/wiki/Puissance_4)
 */
void displayGameRules() {
    string rules[] = {
            "Le but du jeu est d'aligner une suite de 4 pions de meme couleur sur une grille comptant 6 rangees et 7 colonnes.",
            "Chaque joueur dispose de 21 pions d'une couleur (par convention, en general jaune ou rouge).",
            "Tour a tour, les deux joueurs placent un pion dans la colonne de leur choix, le pion coulisse alors jusqu'a la position la plus basse possible dans la dite colonne a la suite de quoi c'est a l'adversaire de jouer.",
            "Le vainqueur est le joueur qui realise le premier un alignement (horizontal, vertical ou diagonal) consecutif d'au moins quatre pions de sa couleur.",
            "Si, alors que toutes les cases de la grille de jeu sont remplies, aucun des deux joueurs n'a realise un tel alignement, la partie est declaree nulle. "
    };

    int cnt = 1;
    for (string rule: rules) {
        cout << "Regle " << cnt << ": " << rule << endl;
        cnt++;
    }
}

void startGame() {

    //Wait for the user to start
    cout << "Appuyer sur <Enter> pour commencer une partie ";
    cin.ignore();

    bool currentPlayer = false;

    //Clear the console and display the board
    system("cls");

    vector<vector<char>> board(6, vector<char>(7, ' '));
    int col;
    int availableCase = -1;

    do {
        Player player = currentPlayer ? Player::RED : Player::YELLOW;
        displayBoard(board);

        do {
            col = getPlayerInput(board[0].size(), player);
            availableCase = getAvailableColSpace(board, col);
        } while (availableCase == -1);

        board[availableCase][col - 1] = (int) player;

        currentPlayer = !currentPlayer;
    } while (!checkVictory(board, availableCase, col - 1));
}

/**
 *
 * @param board
 */
void displayBoard(vector<vector<char>> &board) {

    const int boardWidth = (board.size() + 1) * 4 + 1;

    cout << setw(boardWidth) << setfill('-') << "" << endl;
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[row].size(); col++) {
            cout << "|" << setw(3) << setfill(' ') << getPlayerColorCoin((Player) board[row][col]);

            if (col == (board[row].size() - 1)) {
                cout << "|";
            }
        }
        cout << endl << setw(boardWidth) << setfill('-') << "" << endl;
    }
}

string getPlayerColorCoin(Player player) {
    string playerCoin;
    switch (player) {
        case Player::YELLOW:
            playerCoin = "\x1b[93m * \x1b[0m";
            break;
        case Player::RED:
            playerCoin = "\x1b[91m * \x1b[0m";
            break;
        default:
            playerCoin = " ";
            break;
    }
    return playerCoin;
}

int getPlayerInput(int maxInputValue, Player player) {
    int input;
    do {
        cout << "Entrez un chiffre entre 1 et " << maxInputValue << getPlayerColorCoin(player) << endl << "> ";
        cin >> input;
    } while (input > maxInputValue || input < 1);
    return input;
}

int getAvailableColSpace(vector<vector<char>> &board, int col) {
    for (int x = board.size() - 1; x >= 0; x--) {
        if (board[x][col - 1] == ' ') return x;
    }
    return -1;
}

bool checkVictory(vector<vector<char>> &board, int x, int y) {
    //Check the column
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        //Si l'index est en-dehors du tableau
        if (x + i + 1 >= board.size()) {
            break;
        }

        if (board[x + i][y] == board[x + i + 1][y]) {
            counter++;
        }

        if (counter >= 4) {
            return true;
        }

    }

    //Check the row
    counter = 1;
    // Exit flag to stop a side when there isn't a series of coin
    bool f1 = true, f2 = true;

    for (int i = 0; i < 4; i++) {
        //Si l'index est en-dehors du tableau
        if (x + i + 1 >= board[0].size() && x - i - 1 < 0) {
            break;
        }

        // Check right
        if (board[x][y + i] == board[x][y + i + 1] && f1) {
            counter++;
        } else {
            f1 = false;
        }

        //Check left
        if (board[x][y - i] == board[x][y - i - 1] && f2) {
            counter++;
        } else {
            f2 = false;
        }

        if (!f1 && !f2) break;

        if (counter >= 4) {
            return true;
        }
    }

    //Check the diag / and \
    counter = 1;
    f1 = true, f2 = true;
    bool f3 = true, f4 = true;

    for (int i = 0; i < 4; i++) {
        //Si l'index est en-dehors du tableau
        if (y - i < 0) {
            f2 = false;
            f3 = false;
        }
        // Check diag / up
        if (board[x + i][y + i] == board[x + i + 1][y + i + 1] && f1) {
            counter++;
        } else {
            f1 = false;
        }

        //Check diag / down
        if (board[x - i][y - i] == board[x - i - 1][y - i - 1] && f2) {
            counter++;
        } else {
            f2 = false;
        }

        // Check diag \ up
        if (board[x + i][y - i] == board[x + i + 1][y - i - 1] && f3) {
            counter++;
        } else {
            f3 = false;
        }

        //Check diag \ down
        if (board[x - i][y + i] == board[x - i - 1][y + i + 1] && f4) {
            counter++;
        } else {
            f4 = false;
        }

        if ((!f1 && !f2) || (!f3 && !f4)) break;

        if (counter >= 4) {
            return true;
        }
    }

    return false;
}