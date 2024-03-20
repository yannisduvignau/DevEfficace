/**
 * @file Outils.h
 * @brief consigne des m�thodes de classe (cf.static)
   s_anneeActuelle()
 * @author Lopist�guy
 * @version 0.1
 * @date jj/mm/aaa
 */
#ifndef OUTILS_H
#define OUTILS_H
#include <time.h>

class Outils {
/// ATTRIBUTS -non-

/// METHODES
public:
    /* CONSTRUCTEUR      -non- */
    /* DESTRUCTEUR       -non- */
    /* ENCAPSULATION     -non- */
    /* METHODES USUELLES -non- */
    /* METHODE SPECIFIQUE : anneeActuelle */

    // M�thode de classe qui retourne l�ann�e actuelle
    static short int s_anneeActuelle () {
        time_t timer;       // stocke l�heure actuelle
        struct tm *newTime; // pointe sur une structure
        // demande l'heure que l�on r�cup�re � l�adresse de timer
        time (&timer);
        newTime = localtime(&timer); // d�compose timer dans 1 structure
        return (newTime->tm_year + 1900); // retourne l�ann�e actuelle
    }
protected: // -non-
private:   // -non-
};
#endif
