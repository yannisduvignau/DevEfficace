/**
 * @file Sportif.cpp
 * @brief Sportif::Sportif, Sportif::toString, Sportif::getAge
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */
#include "Sportif.h"

Sportif::Sportif(string n, string p, short int a) {
    this->setNom(n);
    this->setPrenom(p);
    this->setAnneeNaissance(a);
};

string Sportif::toString () {
    string resultat;
    resultat = "nom : " + getNom() + "  -  prenom : " + getPrenom();
    return resultat;
};

short int Sportif::getAge() {
    short int resultat;
    resultat = Outils::s_anneeActuelle() - this->getAnneeNaissance();
    return resultat;
};
