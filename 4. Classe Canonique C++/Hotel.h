/**
 * @file Hotel.h
 * @brief spécifie un Hotel
ATTRIBUTS : nom, adresse, mesChambres, lesAdministrateurs
METHODES  : Hotel, Hotel (Hotel), ~Hotel, operator=, toString,
administréPar, ajouterChambre, modifierPrixChambre
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */
#ifndef HOTEL_H
#define HOTEL_H
#include "Administrateur.h"
#include "Chambre.h"
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

/** CLASSE Hotel ***/
class Hotel {
    public:  /** ICI TOUT EST PUBLIC **/
    /// ATTRIBUTS
        string				nom;
        string				adresse;
        // Attributs qui implementent les relations
        set<Chambre*>        mesChambres;        // Spécifiques à chaque hôtel
        set<Administrateur*> lesAdministrateurs; // Existent en dehors des hôtels

    /// CONSTRUCTEURS
        // Constructeur de base
        Hotel(string n="", string a="") :
            nom(n), adresse(a) {};

        // Constucteur de recopie
        // . initialise ses attributs avec les mêmes valeurs que celles de l'hotelModele
        // . crée SES chambres sur la base de celles de l'hotelModele
        Hotel (const Hotel& hotelModele);

    /// DESTRUCTEUR
        virtual ~Hotel();

    /// METHODES USUELLES : toString, operator=
        string toString (string message="");

        // operator=
        // . initialise ses attributs avec les mêmes valeurs que celles de l'hotelSource
        // . crée SES chambres sur la base de celles de l'hotelSource.
        Hotel& operator= (const Hotel& hotelSource);

    /// METHODES SPECIFIQUES : administrePar, ajouterChambre, modifierPrixChambre
        // Attribue un administrateur de plus si il n'est pas déjà administrateur de l'hôtel
        bool administrePar (Administrateur* admin);

        // Crée et ajoute une chambre de plus si elle n'est pas déjà dans l'hôtel
        bool ajouterChambre (string numero="", string etage="", unsigned short int prix=0);

        // Affecte un nouveau prix à la chambre de numéro donné
        bool modifierPrixChambre(string numero, unsigned short int prix);
};

#endif // HOTEL_H
