/*
-----------------------------------------------------------------------------------
Nom du fichier  : display.h
Auteur(s)       : Guillaume Dunant, Quentin Aellen
Date creation   : 23.10.2022

Description     : Puissance 4

Remarque(s)     : <a completer>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef CONNECT4_DISPLAY_H
#define CONNECT4_DISPLAY_H

#include <vector>
#include <string>

const std::vector<std::string> RULES = {
        "Le but du jeu est d'aligner une suite de 4 pions de meme couleur sur une grille comptant 6 rangees et 7 colonnes.",
        "Chaque joueur dispose de 21 pions d'une couleur (par convention, en general jaune ou rouge).",
        "Tour a tour, les deux joueurs placent un pion dans la colonne de leur choix, le pion coulisse alors jusqu'a la position la plus basse possible dans la dite colonne a la suite de quoi c'est a l'adversaire de jouer.",
        "Le vainqueur est le joueur qui realise le premier un alignement (horizontal, vertical ou diagonal) consecutif d'au moins quatre pions de sa couleur.",
        "Si, alors que toutes les cases de la grille de jeu sont remplies, aucun des deux joueurs n'a realise un tel alignement, la partie est declaree nulle. "
};

/**
 * Display rules of Connect-4 in french, based on this wikipedia article -> https://fr.wikipedia.org/wiki/Puissance_4
 */
void displayGameRules();

/**
 * Display number of cols available to play based on the game-board size
 * @param gameBoard reference of the game 2D vector array
 */
void displayGameBoardHeader(std::vector<std::vector<char>> &gameBoard);

/**
 * Display the game 2D Array
 * @param gameBoard reference of the game 2D vector array
 */
void displayGameBoard(std::vector<std::vector<char>> &gameBoard);

#endif //CONNECT4_DISPLAY_H
