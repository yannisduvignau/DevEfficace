/**
 * @file main.cpp
 * @brief Polymorphisme
   Mise en oeuvre du polymorphisme depuis une fonction
   - utilisation du mot clef "virtual" pour la méthode dans la superclasse
   - OK passage par référence
   - OK passage par adresse
   - NOK passage par valeur
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */
#include <iostream>
#include "Outils.h"
#include "Sportif.h"
#include "SportifMenteur.h"

using namespace std;

/// METHODES GLOBALES ///
void afficheAgeSportifParValeur (Sportif sportif) {
    cout << "Ne en " << sportif.getAnneeNaissance ()
         << " dit avoir " << sportif.getAge() << " ans\n";
};

void afficheAgeSportifParReference (Sportif& sportif) {
    cout << "Ne en " << sportif.getAnneeNaissance ()
         << " dit avoir " << sportif.getAge() << " ans\n";
};

void afficheAgeSportifParAdresse (Sportif* sportif) {
    cout << "Ne en " << sportif->getAnneeNaissance ()
         << " dit avoir " << sportif->getAge() << " ans\n";
};

/// PROCEDURE PRINCIPALE ///
int main() {
    Sportif        sportif1 ("DURANT", "Jean",   1980);
    SportifMenteur sportif2 ("MARTIN", "Pierre", 2007, "ZIDANE");
    SportifMenteur sportif3 ("DUPONT", "Louis",  2010, "DESCHAMPS");

    cout << Outils::s_anneeActuelle() << endl;
    cout << sportif1.toString() << " " << sportif1.getAnneeNaissance() << "-" <<  sportif1.getAge() << "ans" << endl;
    cout << sportif2.toString() << " " << sportif2.getAnneeNaissance() << "-" <<  sportif2.getAge() << "ans" << endl;
    cout << sportif3.toString() << " " << sportif3.getAnneeNaissance() << "-" <<  sportif3.getAge() << "ans" << endl;

    // Usage d'une fonction par valeur. Le polymorphisme ne marche pas
    cout << "Par valeur\n";
    afficheAgeSportifParValeur (sportif1);
    afficheAgeSportifParValeur (sportif2);
    afficheAgeSportifParValeur (sportif3);

    // Usage d'une fonction par référence. Le polymorphisme marche
    cout << "Par reference\n";
    afficheAgeSportifParReference (sportif1);
    afficheAgeSportifParReference (sportif2);
    afficheAgeSportifParReference (sportif3);

    // Usage d'une fonction par adresse. Le polymorphisme marche
    cout << "Par adresse\n";
    afficheAgeSportifParAdresse (&sportif1);
    afficheAgeSportifParAdresse (&sportif2);
    afficheAgeSportifParAdresse (&sportif3);
    return 0;
}
