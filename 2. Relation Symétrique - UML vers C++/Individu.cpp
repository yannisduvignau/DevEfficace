/**
 * @file Individu.cpp
 * @brief Impl�mentation des methodes de Individu
Individu::Individu, Individu::~Individu:, Individu::toString,
Individu::toStringAndLink, Individu::majMaVoiture, Individu::setMaVoiture, Individu::supprimerLien,
 * @author Lopist�guy
 * @version 0.1
 * @date jj/mm/aaa
 */

#include "Individu.h"

Individu::Individu (string n, string p) : nom(n), prenom(p) {
    maVoiture = nullptr;
};

string Individu::toString() {
       return (nom + " " + prenom);
}

string Individu::toStringAndLink() {
	string resultat;
	resultat = toString();
    if (maVoiture != nullptr) {
		resultat += "  Pilote la voiture : " + maVoiture->toString();
	}
    return resultat;
}

void Individu::majMaVoiture(Voiture* voiture){
		maVoiture = voiture;
}

void Individu::supprimerLien () {
	if (maVoiture != nullptr) {
		maVoiture -> majMonPilote (nullptr) ;
		maVoiture = nullptr;
	}
}

void Individu::setMaVoiture (Voiture* voiture) {
	// Supprimer mon �ventuel lien actuel
	supprimerLien () ;

	if (voiture != nullptr) { // Construire le nouveau lien
        // Supprimer l��ventuel lien actuel de mon correspondant
        voiture -> supprimerLien ();

        // Etablir le lien crois� avec mon correspondant
        voiture -> majMonPilote(this); // Il pointe sur moi
        majMaVoiture(voiture); 		   // Je pointe sur lui
	}
}

Individu::~Individu() {
    supprimerLien();
}

