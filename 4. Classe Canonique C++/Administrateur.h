/**
 * @file Administrateur.h
 * @brief spécifie un Administrateur
Attributs : identite, fonction
Méthodes  : Administrateur, toString
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */
#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H
#include <string>

using namespace std;

/** CLASSE Administrateur ***/
class Administrateur {
    /// ATTRIBUTS
    public:
        string		identite;
        string		fonction;

    /// CONSTUCTEUR
    public:
        Administrateur (string i="", string f="") :
            identite(i), fonction(f) {};

    /// METHODES USUELLE : toString
    public:
        string toString(string message="");
};

#endif // ADMINISTRATEUR_H
