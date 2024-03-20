/**
 * @file Individu.h
 * @brief spécifie un Individu en relation réciproque avec Voiture
 Relation réciproque
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */
#ifndef INDIVIDU_H
#define INDIVIDU_H

using namespace std;

#include <iostream>
#include "Voiture.h" // Utilisée ci-dessous

class Voiture; // Annonce une définition ultérieure de Voiture
               // permet de faire référence aux membres de Voiture dans ce code

class Individu {
    /// ATTRIBUTS
    public:
        string nom, prenom;
        Voiture* maVoiture; // Implémente un bon lien

    /// METHODES
    public:
        // Constructeur
        Individu (string="", string="");
        // destructeur
        ~Individu();

        // Méthodes usuelles : toString
        string toString();
        string toStringAndLink();

        // Méthodes spécifiques
        void majMaVoiture (Voiture*);
        void setMaVoiture(Voiture*);
        void supprimerLien();
};

#endif // INDIVIDU_H
