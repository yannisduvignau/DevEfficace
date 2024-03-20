#include <list>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


//Pair
/*template <class T1, class T2>
class pair{
    typedef T1 first_type;
    typedef T2 second_type;

    pair(const first_type&, const second_type&);

    first_type first;
    second_type second;
};*/


//##############################################//
//                      TD1                     //
//##############################################//

//TD1 - Liste simple
void listeSimple(){
    //Nouveau type ListeS de type list
    typedef list<string> ListeS;

    //Déclarer la liste
    ListeS uneListeS;

    //Ajouter des éléments dans la liste
    uneListeS.push_back(ListeS::value_type("Pantxika"));
    uneListeS.push_back(ListeS::value_type("Patrick"));
    uneListeS.push_back(ListeS::value_type("Yann"));
    uneListeS.push_back(ListeS::value_type("Philippe"));

    //Déclaration d'un itérateur
    ListeS::iterator itListeS;
    itListeS = uneListeS.begin();

    //Parcourir la liste et afficher tous les éléments
    while (itListeS != uneListeS.end())
    {
        cout << *itListeS << endl;
        itListeS ++;
    }
}

//TD1 - Liste simple
void listePair(){
    typedef list<pair<string,string>> ListeP;
    ListeP uneListeP;
    
    //Ajouter des éléments dans la liste
    uneListeP.push_back(ListeP::value_type("Pantxika","06.20.01.69.06"));
    uneListeP.push_back(ListeP::value_type("Patrick","06.20.01.69.06"));
    uneListeP.push_back(ListeP::value_type("Yann","06.20.01.69.06"));
    uneListeP.push_back(ListeP::value_type("Philippe","06.20.01.69.06"));

    ListeP::iterator itListeP;
    itListeP = uneListeP.begin();
    
    cout << endl;
    while (itListeP != uneListeP.end())
    {
        cout << "             -  " << itListeP->first << ", " << itListeP->second << endl;
        itListeP++;
    }
}

//TD1 - Le map
void leMap(){
    typedef map<string,string> Annuaire;
    Annuaire unAnnuaire;

    pair<Annuaire::iterator,bool> resultatInsert;
    
    //Test insertion
    cout << endl<<" ////////////////////////////////////////////////////";
    cout << endl<<" ////              TEST D'INSERTION              ////";
    cout << endl<<" ////////////////////////////////////////////////////" << endl;

    for (int i = 0; i < 3; i++)
    {
        resultatInsert = unAnnuaire.insert(pair<string,string>("Pantxika","06 20 01 69 06"));

        if(resultatInsert.second == true){
            cout << "Insertion BIEN realisee" <<endl;
        }else{
            cout << "Insertion MAL realisee" <<endl;
        }
    }

    //Peuplement de unAnnuaire
    cout << endl<<" ////////////////////////////////////////////////////";
    cout << endl<<" ////          PEUPLEMENT DE unAnnuaire          ////";
    cout << endl<<" ////////////////////////////////////////////////////" << endl;

    unAnnuaire.insert(pair<string,string>("Yann","06 20 01 69 07"));
    unAnnuaire.insert(pair<string,string>("Philippe","06 20 01 69 08"));
    unAnnuaire.insert(pair<string,string>("Patrick","06 20 01 69 09"));

    //Création de l'opérateur
    Annuaire::iterator iterateur;
    iterateur = unAnnuaire.begin();

    //Parcourir l'annuaire et afficher tous les éléments
    cout << endl<<" ////////////////////////////////////////////////////";
    cout << endl<<" ////      AFFICHAGE DE TOUS LES ELEMENTS        ////";
    cout << endl<<" ////////////////////////////////////////////////////" << endl;

    while (iterateur != unAnnuaire.end())
    {
        cout << iterateur->second <<endl;
        iterateur ++;
    }

    //Recherche par clef
    cout << endl<<" ////////////////////////////////////////////////////";
    cout << endl<<" ////             RECHERCHE PAR CLEF             ////";
    cout << endl<<" ////////////////////////////////////////////////////" << endl;

    string clef_a_chercher;
    cout << "Entrer une clef a chercher: ";
    cin >> clef_a_chercher;

    if (unAnnuaire.find(clef_a_chercher) != unAnnuaire.end())
    {
        cout << "Le num de "<< clef_a_chercher <<" est : "<< unAnnuaire.at(clef_a_chercher) << endl;
    }else{
        cout << "La clef n'existe pas";
    } 
}
//##############################################//
//                      TD2                     //
//##############################################//

typedef string Reference;
typedef string Libelle;
typedef double Prix;
typedef double Poids;
Reference referenceCherchee;

//                                                                             TD2 - exemple de find
void exempleDeFind(){
    typedef map<Reference,pair<Libelle,Prix>> MapDeProduits;
    MapDeProduits unMapDeProduits;

    //Alimentation de unMapDeProduits
    unMapDeProduits["REF1"]= pair<Libelle,Prix>("chorizo",1.57);
    unMapDeProduits["REF2"]= pair<Libelle,Prix>("saucisse",8.57);
    unMapDeProduits["REF3"]= pair<Libelle,Prix>("olive",0.57);

    //recherche dans le map
    Reference referenceRecherche;
    
    MapDeProduits::iterator existe;
    existe = unMapDeProduits.begin();


    while (existe != unMapDeProduits.end())
    {
        cout << existe->first <<endl;
        existe ++;
    }
    cout << "Entrer une clef a chercher: ";
    cin >> referenceRecherche;

    if (unMapDeProduits.find(referenceRecherche) != unMapDeProduits.end())
    {
        cout << "Le clef "<< referenceRecherche <<" correspond a : "<< unMapDeProduits.at(referenceRecherche).first<<", "<< unMapDeProduits.at(referenceRecherche).second<< endl;
    }else{
        cout << "Echec de recherche";
    }
}


//                                                                              TD2 - exemple de Find_if

//Class produit
class Produit{
    //ATTRIBUTS
    public:
        Reference reference;
        Libelle libelle;
        Prix prix;
    //METHODES
    public:
        Produit(Reference reference="", Libelle libelle="", Prix prix=0);
        virtual string toString();
};

//CONSTRUCTEUR
Produit::Produit(Reference r, Libelle l, Prix p){
    this->reference = r;
    this->libelle = l;
    this->prix = p;
}
//METHODE TO_STRING()
string Produit::toString(){
    string message;
    message = "\nREF_PRODUIT : "+this->reference+"\n       Libelle : "+this->libelle+"\n       Prix    : "+to_string(this->prix)+"\n";
    return message;
}

bool memeReference(Produit P){
    if (P.reference == referenceCherchee)
    {
        return true;
    }else{return false;}
    
}
void exempleFindIf(){
    //Nouveau type ListeS de type list
    typedef list<Produit> ListeDeProduits;

    //Déclarer la liste
    ListeDeProduits uneListeDeProduits;

    //Déclarer 3 produits
    Produit P1 ("REF1","chorizo",1.57);
    Produit P2 ("REF2","olive",10.00);
    Produit P3 ("REF3","concombre",3.29);

    //TEST de création des produits -
    //cout << P1.toString();        OK
    //cout << P2.toString();        OK
    //cout << P3.toString();        OK

    //Alimentation de la liste avec 3 produits
    uneListeDeProduits.push_back(ListeDeProduits::value_type(P1));
    uneListeDeProduits.push_back(ListeDeProduits::value_type(P2));
    uneListeDeProduits.push_back(ListeDeProduits::value_type(P3));

    //Recherche avec find_if
    cout << "Entrer une reference a chercher: ";
    cin >> referenceCherchee;

    ListeDeProduits::iterator it = find_if (uneListeDeProduits.begin(), uneListeDeProduits.end(), memeReference);
    if(it != uneListeDeProduits.end()){
        cout << "\nLe premier produit avec la reference "<<referenceCherchee<<" est :\n" << it->toString() << '\n';
    }else{cout<<"Aucune ref correspondante";}
    
}

//                                                                              TD2 - exemple de For each et partition

class Piece :public Produit{
    public:
        Poids poids;
    public:
        Piece(Reference reference="", Libelle libelle="", Prix prix=0, Poids poids=0);
        string toString();
};

Piece::Piece
(Reference r, Libelle l, Prix p, Poids po)
 : Produit (r, l, p)   // Délégue la construction/init
                                  // des attributs à la super-classe
{
    this->poids = po;     // Traite l'attribut supplémentaire local
}
string Piece::toString() { // spécialise toString()
    string message;
    // invoque le toString() de la super-classe Piece
    message = this -> Produit::toString();
    message.erase(0, 13);
    message ="REF_PIECE"+message+ "       Poids   : "+to_string(this->poids)+"\n\n"; 
    return message;
}

//Fonction invoquée depuis la fonction for_each
void afficher(Piece* unePiece){
    cout << unePiece->toString();
}

void surPoids(Piece* unePiece){
    if (unePiece->poids > 80)
    {
        unePiece->poids = unePiece->poids+(unePiece->poids*0.10);
    }
}

bool tropCestTrop(Piece* unePiece){
    if (unePiece->prix > 100)
    {
        return true;
    }else{return false;}
}


int exempleForEachEtPartition(){
    //Nouveau type ListeS de type list
    typedef list<Piece*> ListeDePieces;

    //Déclarer la liste
    ListeDePieces uneListeDePieces;

    //Déclarer 3 produits
    Piece P4 ("REF4","tracteur",100.57,50.0);
    Piece P5 ("REF5","voiture",10.00,64.0);
    Piece P6 ("REF6","bus",300.29,89.0);

    //TEST de création des produits -
    //cout << P4.toString();        OK
    //cout << P5.toString();        OK
    //cout << P6.toString();        OK

    //Alimentation de la liste avec 3 produits
    uneListeDePieces.push_back(ListeDePieces::value_type(&P4));
    uneListeDePieces.push_back(ListeDePieces::value_type(&P5));
    uneListeDePieces.push_back(ListeDePieces::value_type(&P6));
    
    //Utilisation de for_each
    for_each(uneListeDePieces.begin(), uneListeDePieces.end(), afficher);

    //TEST SURPOID          -- OK (pas oublier &unePiece)
    //for_each(uneListeDePieces.begin(), uneListeDePieces.end(), afficher);
    //cout << "_____________________________________________________________________\n";
    //for_each(uneListeDePieces.begin(), uneListeDePieces.end(), surPoids);
    //for_each(uneListeDePieces.begin(), uneListeDePieces.end(), afficher);

    //TEST PARTITION        -- OK 
    // Réorganise la liste avec les plus de 100euros en début les autres en fin
    ListeDePieces::iterator finDesCheres; // Résultat de partition
    finDesCheres = partition(uneListeDePieces.begin(), uneListeDePieces.end(), tropCestTrop);
    //for_each(uneListeDePieces.begin(), finDesCheres, afficher);    Affiche les + de 100euros
    //for_each(finDesCheres, uneListeDePieces.end(), afficher);     Affiche les - de 100euros

    return 0;
}



//Programme principal
int main()
{
    //////////////////////////      TD1
    //listeSimple();
    //listePair();
    //leMap();

    //////////////////////////      TD2
    exempleDeFind();
    //exempleFindIf();
    //exempleForEachEtPartition();
    return 0;
}


// Pourquoi est-ce que la liste est composée de Piece* ?

/*En fait Piece* est le type d’élément stocké dans le conteneur manipulé dans cet exercice. C’est 
donc le type d’élément manipulé dans les procédures afficher, surPoids et tropCestTrop. Ceci 
permet aux procédures de modifier les valeurs pointées. Concrétement surPoids modifie poids 
et tropCestTrop modifie le prix. */