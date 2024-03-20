/**
 * @file Sportif.h
 * @brief classe spécialisée dans SportifMenteur
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */
#ifndef SPORTIF_H
#define SPORTIF_H

#include <string>
#include "../Outils.h"

using namespace std;

class Sportif {
/// ATTRIBUTS ///
    public:      //  -non-
    protected:   //  -non-
    private:
        string nom;
        string prenom;
        short int anneeNaissance;

/// METHODES ///
    public:
        // CONSTRUCTEUR
        Sportif(string nom="", string prenom="", short int annee=0);

        // ENCAPSULATION get&set : nom, prenom, anneeNaissance
        string getNom() { return nom; }
        void setNom(string val) { nom = val; }

        string getPrenom() { return prenom; }
        void setPrenom(string val) { prenom = val; }

        short int getAnneeNaissance() { return anneeNaissance; }
        void setAnneeNaissance(short int val) { anneeNaissance = val; }

        // METHODES USUELLES : toString
        virtual string toString();   // virtual : donc on peut spécialiser

        // METHODES SPECIFIQUES : getAge
        virtual short int getAge(); // virtual : donc on peut spécialiser

    protected:   //  -non-
    private:     //  -non-
};

#endif // SPORTIF_H
