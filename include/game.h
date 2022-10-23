/*
-----------------------------------------------------------------------------------
Nom du fichier  : game.h
Auteur(s)       : Guillaume Dunant, Quentin Aellen
Date creation   : 23.10.2022

Description     : Puissance 4

Remarque(s)     : <a completer>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#ifndef CONNECT4_GAME_H
#define CONNECT4_GAME_H

#include <vector>

void startGame();

/**
 * Check if there is space to play at a specified column
 * @param gameBoard reference of the game 2D vector array
 * @param selectedCol column you want to check if there still available place
 * @return
 */
int availableColSpace(std::vector<std::vector<char>> &gameBoard, int selectedCol);

/**
 * Verify if there is a victory case on the game-board
 * @param gameBoard reference of the game 2D vector array
 * @return
 */
bool checkVictory(std::vector<std::vector<char>> &gameBoard, int, int);

#endif //CONNECT4_GAME_H
