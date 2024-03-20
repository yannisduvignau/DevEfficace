/**
 * @file Administrateur.cpp
 * @brief implémente Administrateur.h
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */
#include "Administrateur.h"

string Administrateur::toString (string message) {
    string resultat = message;
    resultat += identite + " (" + fonction +")";
    return resultat;
}
