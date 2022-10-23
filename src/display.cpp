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
#include "../include/display.h"

using namespace std;

/**
 * Use const variable Rules to display rules
 */
void displayGameRules() {
    if(RULES.size() == 0){
        cout << "Aucune regle est défini, have fun !" << endl;
        return;
    }

    for(int x = 0; x< RULES.size(); x++){
        cout << "Regle " << x + 1 << ": " << RULES[x] << endl;
    }
}