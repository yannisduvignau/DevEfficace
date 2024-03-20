/**
 * @file main.cpp
 * @brief Impl�mente une relation sym�trique 1-1 entre Voiture et Individu
 // 1. MISE EN PLACE
 // 2. BON LIEN
 // 3. AFFICHER TOUT
 // 4. LIEN RECIPROQUE
 // 5. DETRUIRE L'OBJET LI�
 * @author Lopist�guy
 * @version 0.1
 * @date jj/mm/aaa
 */

#include <cstdlib>
#include <iostream>

#include "Voiture.h"
#include "Individu.h"

using namespace std;

// FONCTION PRINCIPALE
int main(int argc, char *argv[]) {

    // 1. MISE EN PLACE
    cout << "\n\n1 - Mise en place\n\n";

    // D�claration des objets
    Voiture	 voit1 ("RenaultClio", "123AB64"),
             voit2 ("Peugeot106", "678CD96"),
             voit3 ("CitroenPicasso", "456EF75");
    Individu ind1 ("Dupond","Pierre"),
             ind2 ("Martin", "Louis"),
             ind3 ("Durand", "Marcel");

    // Affichage de leurs valeurs
    cout << ind1.toString() << endl
         << ind2.toString() << endl
         << ind3.toString() << endl;
    cout << voit1.toString() << endl
         << voit2.toString() << endl
         << voit3.toString() << endl;

    // 2. BON LIEN
    cout << "\n\n2 - Bon lien\n\n";
    ind3.maVoiture = &voit3; voit3.monPilote = &ind3;
    cout << "La voiture de " << ind3.toString()
         << " est " << ind3.maVoiture->toString()
         << endl << endl;

     // Changement de la plaque de voit3
     voit3.imat = "77777NO22";
     cout << "La nouvelle plaque de " << voit3.marque
          << " est devenue " << voit3.imat
          << endl << endl;

     cout << "La voiture de " << ind3.toString()
          << " est " << ind3.maVoiture->toString()
          << endl << endl;

    // 3. AFFICHER TOUT
    cout << "\n\n3 - Afficher tout quand on dispose d'un correspondant\n\n";
    cout << ind3.toStringAndLink()  << endl
         << voit3.toStringAndLink() << endl
         << ind2.toStringAndLink()  << endl
         << voit2.toStringAndLink() << endl;

    // 4. LIEN RECIPROQUE
    cout << "\n\n4 - Gestion de la sym�trie du lien avec un seul appel !\n";
    ind3.setMaVoiture (&voit3);  // Lie ind3 � voit3 avec un seul 'set'
    cout << voit3.toStringAndLink() << endl
         << ind3.toStringAndLink()  << endl << endl;
    // Lie voit3 et ind2 avec un seul 'set' qui g�re la r�ciproque
    voit3.setMonPilote (&ind2); // et d�lie ce qui est � d�lier
    cout << ind3.toStringAndLink()  << endl   // N'est plus li�
         << voit3.toStringAndLink() << endl   // Li� � ind2
         << ind2.toStringAndLink()  << endl;  // Li� � voit3

    // 5. DETRUIRE OBJET LI�
    cout << "\n\n5 - Detruire un objet lie\n\n";
    cout << ind2.toStringAndLink() << endl; // Objet ind2 li� � voit3
    delete (&voit3);                        // Destruction de voit3
    cout << ind2.toStringAndLink() << endl; // Objet ind2 n'est plus li� � voit3
}
