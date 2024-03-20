/**
 * @file main.cpp
 * @brief Projet avec une classe canonique Hotel
 La classe canonique Hotel intègre donc :
  1. un constructeur
  2. un constructeur de recopie
  3. l'opérateur d'affectation : operator=
  4. un destructeur
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */

#include <iostream>
#include "Hotel.h"
#include "Chambre.h"
#include "Administrateur.h"

using namespace std;

int main() {

    /// Déclaration d'un Hotel hotel
    Hotel hotel ("LesDormeurs", "Terrain Instable, 75.000 PARIS");
    cout << hotel.toString("CREATION DE L'HOTEL\n") << endl;

    /// Déclaration de deux administrateurs...
    Administrateur admin1 ("Etcheverry", "President");
    Administrateur admin2 ("Dagorret", "Presidente");
    /// ... qui administrent l'hotel
    hotel.administrePar (&admin1);
    hotel.administrePar (&admin2);
    cout << hotel.toString("\nhotel AVEC ADMINISTRATEURS\n") << endl;;

    /// Déclaration de trois chambres...
    //Chambre chambre1 ("Campagne", "Rez-de-chaussee", 50);
    //Chambre chambre2 ("Royale",   "Etage 1",        100);
    //Chambre chambre3 ("Solaire",  "Etage 2",        150);
    /// ... qui composent l'hotel
    hotel.ajouterChambre ("Campagne", "Rez-de-chaussee", 50);
    hotel.ajouterChambre ("Royale",   "Etage 1",        100);
    hotel.ajouterChambre ("Solaire",  "Etage 2",        150);
    cout << hotel.toString("\nhotel AVEC ADMINISTRATEURS ET CHAMBES\n") << endl;;

    /// Construction d'un Hotel hotelBis sur la base de l'hotel
    Hotel hotelBis(hotel);   /** Invoque le constructeur de recopie **/
    cout << hotelBis.toString("\n\nhotel Bis SUITE A RECOPIE\n") << endl;

    /// Création d'un Hotel hotelTer...
    Hotel hotelTer;           // Declaration
    hotelTer = hotel;         /** Invoque l'affectation, operator=  **/
    /// ... qui est une copie de hotel
    cout << hotelTer.toString("\n\nhotel Ter SUITE A AFFECTATION\n") << endl;

    /// Modification d'attributs de chambre dans hotelBis et hotelTer
    hotelBis.modifierPrixChambre("Campagne", 70);
    cout << hotelBis.toString("\n\nhotel Bis CHANGE PRIX chambre campagne\n") << endl;
    hotelTer.modifierPrixChambre("Solaire", 170);
    cout << hotelTer.toString("\n\nhotel Ter CHANGE PRIX chambre solaire\n") << endl;

    /// Modification d'un attribut d'un administrateur
    admin1.fonction = "ambassadeur de Donald-T";
    cout << admin1.toString("\n\admin1 CHANGE de fonction\n") << endl;
    cout << "L e s   3   h o t e l s   s o n t   a f f e c t e s   p a r   c e   c h a n g e m e n t" << endl;
    cout << hotel.toString("\n\nhotel\n") << endl;
    cout << hotelBis.toString("\n\nhotel Bis\n") << endl;
    cout << hotelTer.toString("\n\nhotel Ter\n") << endl;

    /// Destruction de l'hotel de référence
    cout << hotel.toString("\n\ndestruction de hotel\n") << endl;
    delete &hotel;            /** Invoque le destructeur **/

    return 0;
}
