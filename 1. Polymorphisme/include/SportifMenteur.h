/**
 * @file SportifMenteur.h
 * @brief classe qui sp�cialise Sportif
 * ajoute     : l'attribut tuteur et ses accesseurs
 * sp�cialise : toString() et getAge()
 * @author Lopist�guy
 * @version 0.1
 * @date jj/mm/aaa
 */
#ifndef SPORTIFMENTEUR_H
#define SPORTIFMENTEUR_H

#include <Sportif.h>

class SportifMenteur : public Sportif {

/// ATTRIBUTS ///
private:
    string tuteur;

/// METHODES
public:
    // CONSTRUCTEUR
    SportifMenteur
    (string nom="", string prenom="",
     short int annee=0, string tuteur="");

    // ENCAPSULATION get&set : tuteur
    string getTuteur() { return tuteur; }
    void setTuteur(string val) { tuteur = val; }

    // METHODES USUELLES : toString
    string toString();

    // METHODES SPECIFIQUES : getAge
    short int getAge();
};

#endif // SPORTIFMENTEUR_H
