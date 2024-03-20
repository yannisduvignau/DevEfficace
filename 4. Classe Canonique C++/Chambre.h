/**
 * @file Chambre.h
 * @brief spécifie une Chambre
Attributs : numero, etage, prix
Methodes  : Chambre, toString
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */

#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>

using namespace std;

/** CLASSE CHAMBRE ***/
class Chambre {
    /// ATTRIBUTS
    public:
        string				numero;
        string				etage;
        unsigned short int	prix;

    /// CONSTUCTEUR
    public:
        Chambre (string n="", string e="", unsigned short int p=0) :
            numero(n), etage(e), prix(p) {};

    /// METHODES USUELLE : toString
    public:
        string toString(string message="");
};

#endif // CHAMBRE_H
