/*************************************************************************
                           Main  -  description
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include systéme
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Main.h"
#include "Catalogue.h"
#include "Collection.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes
const int TAILLE = 50;
//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
TrajetCompose* creerTrajetCompose() 
{
    int nbTrajets;
    char dep [TAILLE];
    char arr [TAILLE];
    char transport [TAILLE];
    TrajetCompose *t = new TrajetCompose();
    cout << "Veuillez entrer le nombre de trajets (simple) constituant votre trajet composé : ";
    cin >> nbTrajets;
    cout << endl;
    for (int i = 0; i < nbTrajets; i++) 
    {
        cout << "\tVeuillez entrer la ville de départ du trajet n°" << i + 1 << ": ";
        cin >> dep;
        cout << endl << "\tVeuillez entrer la ville d'arrivée du trajet n°" << i + 1 << ": ";
        cin >> arr;
        cout << endl << "\tVeuillez entrer le moyen de transport du trajet n°" << i + 1 << ": ";
        cin >> transport;
        cout << endl;

        TrajetSimple *ts = new TrajetSimple(dep, arr, transport);
        t->Ajouter(ts);
    }
    return t;
}

static void menu ( )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
    Catalogue *c = new Catalogue();
    char dep [TAILLE];
    char arr [TAILLE];
    char transport [TAILLE];
    while(1)
    {
        cout << "Menu: " << endl;
        cout << "\t1: Ajouter un trajet simple" << endl;
        cout << "\t2: Ajouter un trajet compose" << endl;
        cout << "\t3: Afficher le catalogue" << endl;
        cout << "\t4: Rechercher un trajet" << endl;
        cout << "\t0: Quitter" << endl;
        int choix;
        cin >> choix;
        switch(choix)
        {
            case 0:
                cout << "Au revoir" << endl;
                delete c;
                return; 
            case 1: 
            {
                cout << "Veuillez entrer la ville de départ : ";
                cin >> dep;
                cout << endl << "Veuillez entrer la ville d'arrivée : ";
                cin >> arr;
                cout << endl << "Veuillez entrer le moyen de transport : ";
                cin >> transport;
                
                TrajetSimple *ts = new TrajetSimple(dep, arr, transport);
                c->Ajouter(ts);
                break;
            }
            case 2: 
            {
                TrajetCompose* tc = creerTrajetCompose();
                c->Ajouter(tc);
                break;
            }
            case 3:
            {
                c->Afficher();
                break;
            }
            case 4:
            {
                cout << "Veuillez entrer la ville de départ : ";
                cin >> dep;
                cout << endl << "Veuillez entrer la ville d'arrivée : ";
                cin >> arr;
                const Collection *coll = c->RechercherTrajet(dep, arr);
                
                cout << (coll->EstVide() ? "Aucun trajet ne correspond à votre demande" : "Voici les différents trajets correspondants à votre recherche : ") << endl << endl;
                coll->Afficher();
                delete coll;
                break;
            }
            default:
            {
                cout << "Choix incorrect" << endl;
                break; // revenir au menu
            }
        }
    }
} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main ( )
{
  menu();
  return 0;
} //----- fin de main
