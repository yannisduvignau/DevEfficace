/**
 * @file Chambre.cpp
 * @brief implémente Chambre.h
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */

#include "Chambre.h"

string Chambre::toString (string message) {
    string resultat = message;
    resultat += numero + " / " + etage + " / " + to_string(prix) + " euros";
    return resultat;
}
