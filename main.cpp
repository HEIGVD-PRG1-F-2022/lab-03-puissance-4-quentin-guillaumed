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

void displayGameRules();

void startGame();

void displayBoard();

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

    //Clear the console and display the board
    system("cls");
    displayBoard();
}

/**
 *
 * @param board
 */
void displayBoard(vector<vector<char>> &board) {
    string charToDisplay = "";

    for(int row = 0; row < board.size(); row++){
        for(int col = 0; col < board[row].size(); col++){

        }
    }
}
