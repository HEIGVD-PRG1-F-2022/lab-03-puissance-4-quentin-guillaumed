/*
-----------------------------------------------------------------------------------
Nom du fichier  : player.cpp
Auteur(s)       : Guillaume Dunant, Quentin Aellen
Date creation   : 23.10.2022

Description     : Puissance 4

Remarque(s)     : <a completer>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>

#include "../include/player.h"

using namespace std;

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
    int input = 0;
    do {
        cout << "Entrez un chiffre entre 1 et " << maxInputValue << getPlayerColorCoin(player) << endl
             << "> ";
        cin >> input;
    } while (input > maxInputValue || input < 1);
    return input;
}