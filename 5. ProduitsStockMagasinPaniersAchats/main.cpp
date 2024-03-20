#include <iostream>
#include <map>
#include <list>

using namespace std;

typedef string 	Libelle;
typedef string 	Code;
typedef float 	Prix;
typedef int 	Quantite;
typedef string 	Adresse;

/** CLASSE Produit **/
class Produit {
    // ATTRIBUTS
    public:
        Libelle   libelle;
        Code      code;
        Prix      prix;
    // CONSTRUCTEUR
    public:
        Produit (Libelle l="", Code c="", Prix p=0):
                 libelle(l), code(c), prix (p) {};
    // METHODES USUELLES : toString
    public:
        string toString(string message="") {
            return message + "(" + code + ") " + libelle + " a " + to_string(prix) + " euros";
        }
/*        bool operator< (const Produit& p) const {
            return (code < p.code);
        }
*/
};

/*class CompareClefProduit { // dit dans operator() comment comparer la clef du map
public:
	bool operator()(const Produit* p1, const Produit* p2) const {
		return (p1->code < p2->code);
    }
};

*/

/** CLASSE Magasin **/
class Magasin {
    // DEFINITION
    public:
		typedef map<Produit*, Quantite> Stockage;
    // ATTRIBUTS
    public:
		Stockage stock;
		Adresse  adresse;
    // CONSTRUCTEUR
    public:
		Magasin (Adresse a="", Stockage s=Stockage()) :
			     adresse(a), stock(s) {};
    // METHODES USUELLES : toString
    public:
    string toString (string message="") {
        string resultat;              // Retourn  par toString()
        Stockage::iterator it;        // Pour parcourir le stock
        /** Construction du message **/
        resultat = message;
        resultat += "Magasin : " + adresse + "\n";
        // Parcours complet du stock
        for (it = stock.begin(); it != stock.end(); it++) {
            resultat += to_string(it->second) + " x "; // La quantit  (cad la valeur)
            resultat += it->first->toString()+"\n";    // Le produit (cad la clef)
        }
        return resultat;
    }

 };

/** CLASSE Panier **/
class Panier {
    // DEFINITION
    public:
        typedef list <pair <Produit*, Quantite> > DesProduits;
    // ATTRIBUTS
    public:
        string      acheteur;
        DesProduits achats;
        Magasin*    magasin;

    // CONSTRUCTEUR
    public:
        Panier (string a, Magasin* m = new Magasin(), DesProduits dp = DesProduits()) :
                acheteur(a), magasin(m), achats(dp) {};

    // METHODES USUELLES : toString
    public:
        string toString(string message ="") {
        string resultat;            // R sultat retourn  par toString
        string produitsDuPanier=""; // Produits achet s
        int coutTotal = 0;          // Cout du panier - accumulateur
        DesProduits::iterator it;   // Pour parcourir les achats

        // Parcours complet des achats pour  tablir la liste des produitsAchet s
        for (it = achats.begin(); it != achats.end(); it++) {
            produitsDuPanier += to_string(it->second) + " x "; // La quantit 
            produitsDuPanier += it->first->toString() + "\n";  // Le produit
            coutTotal += it->second * it->first->prix;
        }

        /** Construction du message **/
        resultat = message;
        resultat += "Panier de : " + acheteur;
        resultat += " dans le magasin : " + magasin->adresse + "\n";
        resultat += produitsDuPanier;
        resultat += "COUT *** " + to_string (coutTotal) + " ***\n";
        return resultat;
   }

    // METHODES SPECIFIQUES : acheter
    public:
    bool acheter(Produit* produitEnvisage, Quantite quantiteEnvisagee) {
        if (magasin->stock.find(produitEnvisage) != magasin->stock.end()          // SI produitEnvisage dans le stock
            &&                                                                    //    et
            magasin->stock.find(produitEnvisage)->second >= quantiteEnvisagee) {  //    en stock suffisant ALORS
            magasin->stock.find(produitEnvisage)->second -= quantiteEnvisagee;               // Diminuer le stock
            achats.push_back(DesProduits::value_type (produitEnvisage, quantiteEnvisagee));  // Ins rer dans le panier
            return true;                                                                     // Retourner vrai
        }                                                                         // SINON
        else return false;                                                                   // Retourner faux
    };
};

/** PROGRAMME PRINCIPAL **/
int main() {
    // Cr ation des produits
    Produit p1 ("TABLE", "T001", 110);
    Produit p2 ("FAUTEUIL", "F001", 90);
    Produit p3 ("CHAISE", "C001", 70);
    // Visualisation des produits
    cout << "=====PRODUITS=====\n";
    cout << p1.toString() << "\n"
         << p2.toString() << "\n"
         << p3.toString();

    // Cr ation du magasin et approvisionnement
    Magasin monMagasin("Anglet");
    monMagasin.stock[&p1] = 1;
    monMagasin.stock[&p2] = 2;
    monMagasin.stock[&p3] = 3;
    // Visualisation du magasin
    cout << "\n\n=====MAGASIN=====\n";
    cout << monMagasin.toString();

    // Cr ation du panier et tentatives d'achats
    cout << "\n=====PANIER=====\n";
    Panier monPanier ("Echeverry", &monMagasin);
    cout << (monPanier.acheter(&p1, 2) ? "Achat OK\n" : "Achat impossible\n");
    cout << (monPanier.acheter(&p2, 1) ? "Achat OK\n" : "Achat impossible\n");
    cout << (monPanier.acheter(&p3, 1) ? "Achat OK\n" : "Achat impossible\n");

    // Visualisation du panier...
    cout << monPanier.toString();
    // ... et visualisation du magasin d bit 
    cout << "\n=====MAGASIN=====\n";
    cout << monMagasin.toString();

    return 0;
}
