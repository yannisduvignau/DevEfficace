/**
 * @file Voiture.cpp
 * @brief Impl�mentation des methodes de Voiture
Voiture::Voiture, Voiture::~Voiture:, Voiture::toString,
Voiture::toStringAndLink, Voiture::majMaVoiture, Voiture::setMaVoiture, Voiture::supprimerLien,
 * @author Lopist�guy
 * @version 0.1
 * @date jj/mm/aaa
 */
 #include "Voiture.h"

 Voiture::Voiture (string m, string i) : imat (i), marque (m) {
    monPilote = nullptr;
}

string Voiture::toString() {
       return (marque + " " + imat);
}

string Voiture::toStringAndLink() {
    string resultat;
	resultat = toString();
    if (monPilote != nullptr) {
		resultat+= " a le pilote : " + monPilote->toString();
	}
	return resultat;
}

void Voiture::majMonPilote(Individu* pilote){
		monPilote = pilote;
}

void Voiture::supprimerLien () { // Idem pour Individu
	if (monPilote != nullptr) {
		monPilote -> majMaVoiture (nullptr);
		monPilote = nullptr;
	}
}

void Voiture::setMonPilote(Individu* pilote) { // Idem pour Individu
    // Supprimer mon �ventuel lien actuel
    supprimerLien () ;

    if (pilote != nullptr) {  // Construire le nouveau lien
        // Supprimer l��ventuel lien actuel de mon correspondant
        pilote -> supprimerLien ();

        // Etablir le lien crois� avec mon correspondant
        pilote -> majMaVoiture(this); // Il pointe sur moi
        majMonPilote(pilote); 		  // Je pointe sur lui
    }
}

Voiture::~Voiture() {
    supprimerLien();
}
