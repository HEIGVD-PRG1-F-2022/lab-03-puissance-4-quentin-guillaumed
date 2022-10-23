/*
-----------------------------------------------------------------------------------
Nom du fichier  : player.h
Auteur(s)       : Guillaume Dunant, Quentin Aellen
Date creation   : 23.10.2022

Description     : Puissance 4

Remarque(s)     : <a completer>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef CONNECT4_PLAYER_H
#define CONNECT4_PLAYER_H

#include <string>

/**
 * Represent the color of coin with which the player will be able to play
 */
enum class Player {
    YELLOW,
    RED,
};

/**
 * Give a string representation of the specified player
 * @param player player enum based on color you want
 * @return a string with a colored coin
 */
std::string getPlayerColorCoin(Player player);

/**
 * Ask the user to enter a number between 0 and a specified max value
 * @param maxInputValue max integer value the player will be able to input (0-maxInputValue)
 * @param player player enum based on color you want
 */
int getPlayerInput(int maxInputValue, Player player);

#endif //CONNECT4_PLAYER_H
