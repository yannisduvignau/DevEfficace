/**
 * @file Voiture.h
 * @brief spécifie une Voiture en relation réciproque avec Individu
 Relation réciproque
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */

#ifndef VOITURE_H
#define VOITURE_H

using namespace std;

#include <iostream>
#include "Individu.h"

class Individu; // Annonce une définition ultérieure de Individu
                // permet de faire référence aux membres de Individu dans ce code

// SPECIFICATION de la classe Individu
class Voiture {
    /// ATTRIBUTS
    public:
        string imat, marque;
        Individu* monPilote; // Implémente un bon lien

    /// METHODES
    public:
        // Constructeur
        Voiture (string="", string="");
        // Destructeur
        ~Voiture();

        // Méthodes usuelles : toString
        string toString ();
        string toStringAndLink();

        // Methodes spécifiques : majMonPilote, supprimerLien, setMonPilote
        void majMonPilote (Individu*);
        void setMonPilote(Individu*);
        void supprimerLien();
};

#endif // VOITURE_H
