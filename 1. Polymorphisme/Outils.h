/**
 * @file Outils.h
 * @brief consigne des méthodes de classe (cf.static)
   s_anneeActuelle()
 * @author Lopistéguy
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

    // Méthode de classe qui retourne l’année actuelle
    static short int s_anneeActuelle () {
        time_t timer;       // stocke l’heure actuelle
        struct tm *newTime; // pointe sur une structure
        // demande l'heure que l’on récupère à l’adresse de timer
        time (&timer);
        newTime = localtime(&timer); // décompose timer dans 1 structure
        return (newTime->tm_year + 1900); // retourne l’année actuelle
    }
protected: // -non-
private:   // -non-
};
#endif
