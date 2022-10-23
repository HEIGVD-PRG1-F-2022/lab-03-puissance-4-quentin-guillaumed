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

const int WIN_CONDITION = 4;
const int BOARD_WIDTH = 7;
const int BOARD_HEIGHT = 6;

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
 * @param x coordinate x of the case to check
 * @param y coordinate y of the case to check
 * @return true if there is a victory, otherwise false
 */
bool checkVictory(std::vector<std::vector<char>> &gameBoard, int x, int y);

/**
 * Check if the win condition is fulfilled horizontally
 * @param x
 * @param y
 * @return
 */
bool checkHorizontal(std::vector<std::vector<char>> &gameBoard, int x, int y);

/**
 * Check if the win condition is fulfilled vertically
 * @param x
 * @param y
 * @return
 */
bool checkVertical(std::vector<std::vector<char>> &gameBoard, int x, int y);

/**
 * Check if a diagonal fulfills a win condition
 * @param x
 * @param y
 * @return
 */
bool checkDiagonals(std::vector<std::vector<char>> &gameBoard, int x, int y);

#endif //CONNECT4_GAME_H
