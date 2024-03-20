/**
 * @file SportifMenteur.cpp
 * @brief SportifMenteur::SportifMenteur, SportifMenteur::toString, SportifMenteur::getAge
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */
#include "SportifMenteur.h"

SportifMenteur::SportifMenteur
(string nom, string prenom, short int annee, string tuteur)
 : Sportif (nom, prenom, annee)   // Délègue la construction/init
                                  // des attributs à la super-classe
{
    this->setTuteur (tuteur);     // Traite l'attribut supplémentaire local
}
string SportifMenteur::toString() { // spécialise toString()
    string message;
    // invoque le toString() de la super-classe Sportif
    message = this -> Sportif::toString();
    message += "  -  tuteur : " + getTuteur();  // complète le code
    return message;
}

short int SportifMenteur::getAge() { // spécialise getAge()
    short int age;
    // invoque le getAge() de la super-classe Sportif
    age = this->Sportif::getAge(); // obtient l'age réel
    return (age<18 ? 18 : age);
}
