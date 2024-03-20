/**
 * @file Hotel.cpp
 * @brief implémente Hotel.h
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */

#include "Hotel.h"

Hotel::Hotel(const Hotel& hotelModel) {
    // Initialise ses attributs avec les m mes valeurs que celles de hotelModel
    nom = hotelModel.nom;
    adresse = hotelModel.adresse;

    // Copie les adresses des administrateurs sur la base de celles de hotelModel
    lesAdministrateurs.insert(hotelModel.lesAdministrateurs.begin(), hotelModel.lesAdministrateurs.end());

    // Cr e SES chambres sur la base de celles de hotelModel
    set<Chambre*>::iterator chambre = hotelModel.mesChambres.begin();
    for ( ; chambre != hotelModel.mesChambres.end() ; chambre++) {
        mesChambres.insert (new Chambre (**chambre));
    }
}

Hotel& Hotel::operator= (const Hotel& hotelSource) {
    // Initialise ses attributs avec les mêmes valeurs que celles de l'hotelSource
    nom = hotelSource.nom;
    adresse = hotelSource.adresse;

    // Copie les adresses des administrateurs sur la base de celles de l'hotelSource
    lesAdministrateurs.insert(hotelSource.lesAdministrateurs.begin(), hotelSource.lesAdministrateurs.end());

    // Crée SES chambres sur la base de celles de l'hotelSource
    set<Chambre*>::iterator chambre;
    for (chambre = hotelSource.mesChambres.begin(); // Initialisation
         chambre != hotelSource.mesChambres.end();  // Condition de fin
         chambre++) {                               // Progression
        /// Traitement
        mesChambres.insert (new Chambre (**chambre)); // Insère une chambre sur le modèle de la chambre courante
    }
    return *this;
}

Hotel::~Hotel() {
    // Parcours complet de SES chambres pour les détruire
    set<Chambre*>::iterator chambre;
    for (chambre = this->mesChambres.begin(); // Initialisation
         chambre != this->mesChambres.end();  // Condition de fin
         chambre++) {                         // Progression
        /// Traitement
        delete *chambre;                      // Destruction de la chambre
    }

}

string Hotel::toString (string message) {
    string resultat = message;

    /// Intègre nom et adresse
    resultat += nom + " : " + adresse + "\n";

    /// Intègre lesAdministrateurs
    set<Administrateur*>::iterator admin;
    for (admin = lesAdministrateurs.begin(); admin != lesAdministrateurs.end(); admin++) {
        resultat += (*admin)->toString ("ADMIN : ") + "\n";
    }
    /// Intègre les chambres
    set<Chambre*>::iterator chambre;
    for (chambre = mesChambres.begin(); chambre != mesChambres.end() ; chambre++) {
        resultat += (*chambre)->toString ("CHAMBRE : ") + "\n";
    }
    return resultat;
}

bool Hotel::administrePar (Administrateur* admin) {
    // Le second paramètre d'insert est un bool qui dit si l'insertion est OK
    return (lesAdministrateurs.insert(admin).second);

    /** Ce qui équivaut à ce qui suit : **/
/*  bool resultat; // Résultat de l'ajout de l'admin

    // Si l'admin n'est pas déjà parmi lesAdministrateurs
    if (*(lesAdministrateurs.find(admin)) != admin) {
        // Ajout de l'admin
        lesAdministrateurs.insert(admin);
        resultat = true;   // Ajout OK
    }
    else resultat = false; // Ajout NON OK
    return (resultat);
*/
}

bool Hotel::ajouterChambre (string numero, string etage, unsigned short int prix) {
    // Si les paramètres ne sont pas renseignés alors ne rien faire
    if (numero == "" || etage == "" || prix == 0) return false;

    // Sinon création de la chambre puis tentative d'insertion
    Chambre* nouvelleChambre = new Chambre (numero, etage, prix);
    // Le second paramètre d'insert est un bool qui dit si l'insertion est OK
    return (mesChambres.insert(nouvelleChambre).second);
}

bool Hotel::modifierPrixChambre(string numero, unsigned short int prix) {
    bool modification = false;    // Résultat de la modificataion du prix

    set<Chambre*>::iterator chambre;
    for (chambre = mesChambres.begin(); chambre != mesChambres.end() ; chambre++) {
        if ((*chambre)->numero == numero) {
            (*chambre)->prix = prix;
            modification = true;
            break;
        }
    }
    return modification;
}
