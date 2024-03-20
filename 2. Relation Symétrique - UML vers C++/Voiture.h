/**
 * @file Voiture.h
 * @brief sp�cifie une Voiture en relation r�ciproque avec Individu
 Relation r�ciproque
 * @author Lopist�guy
 * @version 0.1
 * @date jj/mm/aaa
 */

#ifndef VOITURE_H
#define VOITURE_H

using namespace std;

#include <iostream>
#include "Individu.h"

class Individu; // Annonce une d�finition ult�rieure de Individu
                // permet de faire r�f�rence aux membres de Individu dans ce code

// SPECIFICATION de la classe Individu
class Voiture {
    /// ATTRIBUTS
    public:
        string imat, marque;
        Individu* monPilote; // Impl�mente un bon lien

    /// METHODES
    public:
        // Constructeur
        Voiture (string="", string="");
        // Destructeur
        ~Voiture();

        // M�thodes usuelles : toString
        string toString ();
        string toStringAndLink();

        // Methodes sp�cifiques : majMonPilote, supprimerLien, setMonPilote
        void majMonPilote (Individu*);
        void setMonPilote(Individu*);
        void supprimerLien();
};

#endif // VOITURE_H
