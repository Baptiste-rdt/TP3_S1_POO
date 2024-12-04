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
#include <cstring>
#include <fstream>
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
TrajetCompose *creerTrajetCompose()
{
    int nbTrajets;
    char dep[TAILLE];
    char arr[TAILLE];
    char transport[TAILLE];
    TrajetCompose *t = new TrajetCompose();
    cout << "Veuillez entrer le nombre de trajets (simple) constituant votre trajet composé : ";
    cin >> nbTrajets;
    cin.ignore(); // Clear the input buffer
    cout << endl;
    for (int i = 0; i < nbTrajets; i++)
    {
        cout << "\tVeuillez entrer la ville de départ du trajet n°" << i + 1 << ": ";
        cin.getline(dep, TAILLE);
        cout << "\tVeuillez entrer la ville d'arrivée du trajet n°" << i + 1 << ": ";
        cin.getline(arr, TAILLE);
        cout << "\tVeuillez entrer le moyen de transport du trajet n°" << i + 1 << ": ";
        cin.getline(transport, TAILLE);
        cout << endl;

        TrajetSimple *ts = new TrajetSimple(dep, arr, transport);
        t->Ajouter(ts);
    }
    return t;
}

static void menu()
{
    Catalogue *c = new Catalogue();
    char dep[TAILLE];
    char arr[TAILLE];
    char transport[TAILLE];
    while (1)
    {
        cout << "Menu: " << endl;
        cout << "\t1: Ajouter un trajet simple" << endl;
        cout << "\t2: Ajouter un trajet compose" << endl;
        cout << "\t3: Afficher le catalogue" << endl;
        cout << "\t4: Rechercher un trajet" << endl;
        cout << "\t5: Importer une sauvegarde" << endl;
        cout << "\t6: Sauvegarder le catalogue" << endl;
        cout << "\t0: Quitter" << endl;
        int choix;
        cin >> choix;
        cin.ignore(); // pour éviter les problèmes de lecture de chaînes
        switch (choix)
        {
        case 0:
            cout << "Au revoir" << endl;
            delete c;
            return;
        case 1:
        {
            cout << "Veuillez entrer la ville de départ : ";
            cin.getline(dep, TAILLE);
            cout << "Veuillez entrer la ville d'arrivée : ";
            cin.getline(arr, TAILLE);
            cout << "Veuillez entrer le moyen de transport : ";
            cin.getline(transport, TAILLE);

            TrajetSimple *ts = new TrajetSimple(dep, arr, transport);
            c->Ajouter(ts);
            break;
        }
        case 2:
        {
            TrajetCompose *tc = creerTrajetCompose();
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
            cin.getline(dep, TAILLE);
            cout << "Veuillez entrer la ville d'arrivée : ";
            cin.getline(arr, TAILLE);

            const Collection *coll = c->RechercherTrajet(dep, arr);

            cout << (coll->EstVide() ? "Aucun trajet ne correspond à votre demande" : "Voici les différents trajets correspondants à votre recherche : ") << endl
                 << endl;
            coll->Afficher();
            delete coll;
            break;
        }
        case 5:
        {
            MenuImport(c);
            break;
        }
        case 6:
        {
            MenuSauvegarde(c);
            break;
        }
        default:
        {
            cout << "Choix incorrect" << endl;
            break; // revenir au menu
        }
        }
    }
}

static void MenuImport(Catalogue *c)
{
    string* nomFichier = UtiliserFichier();
    cout << "\t1: Importer un fichier complet" << endl;
    cout << "\t2: Importer seulement un type de trajet" << endl;
    cout << "\t3: Importer selon la ville de départ/arrivée" << endl;
    cout << "\t4: Importer une sélection" << endl;
    cout << "\t0: Retour" << endl;
    int choix;
    cin >> choix;
    switch (choix)
    {
    case 0:
        break;
    case 1:
        c->ImporterTouteSauvegarde(nomFichier->c_str());
        break;
    case 2:
        MenuImportType(c, nomFichier->c_str());
        break;
    case 3:
        MenuImportVille(c, nomFichier->c_str());
        break;
    case 4:
        MenuImportSelection(c, nomFichier->c_str());
        break;
    default:
        cout << "Choix incorrect" << endl;
        MenuImport(c);
        break;
    }

    delete nomFichier;
}

static void MenuImportType(Catalogue *c, const char *nomFichier)
{
    cout << "Quel type souhaitez-vous importer ?" << endl;
    cout << "\t1: Trajet Simple" << endl;
    cout << "\t2: Trajet Composé" << endl;
    cout << "\t0: Retour" << endl;
    int choix;
    cin >> choix;
    switch (choix)
    {
    case 0:
        break;
    case 1:
        c->ImporterTypeSauvegarde(1, nomFichier);
        break;
    case 2:
        c->ImporterTypeSauvegarde(2, nomFichier);
        break;
    default:
        cout << "Choix incorrect" << endl;
        MenuImportType(c, nomFichier);
        break;
    }
}

static void MenuImportVille(Catalogue *c, const char *nomFichier)
{
    char depart[TAILLE];
    char arrivee[TAILLE];
    cin.ignore();
    cout << "Quelle ville de départ ? (vide pour toutes)" << endl;
    cin.getline(depart, TAILLE);
    cout << "Quelle ville d'arrivée ? (vide pour toutes)" << endl;
    cin.getline(arrivee, TAILLE);
    if (depart[0] == '\0')
    {
        strcpy(depart, "");
    }
    if (arrivee[0] == '\0')
    {
        strcpy(arrivee, "");
    }
    c->ImporterVilleSauvegarde(depart, arrivee, nomFichier);
}

static void MenuImportSelection(Catalogue *c, const char *nomFichier)
{
    int debut;
    int fin;
    bool estCorrecte;
    cin.ignore();
    cout << "Quel indice de départ de sélection ? (-1 pour annuler l'opération)" << endl;
    cin >> debut;
    if (debut == -1)
    {
        cout << "Opération annulée" << endl;
        return;
    }
    cout << "Quel indice de fin de selection ? (-1 pour annuler l'opération)" << endl;
    cin >> fin;
    if (fin == -1)
    {
        cout << "Opération annulée" << endl;
    }
    else if (fin < debut || debut <= 0)
    {
        cout << "Valeur erronée détéctée !" << endl;
    }
    else
    {
        c->ImporterSelectionSauvegarde(debut, fin, nomFichier);
    }
}

static string* UtiliserFichier()
{
    string *chemin = new string(); // Allouer dynamiquement une chaîne pour garantir sa persistance
    cout << "Quel fichier souhaitez-vous utiliser ? (chemin d'accès)" << endl;
    cin >> *chemin;

    if (chemin->empty())
    {
        cout << "Chemin vide ! Opération annulée." << endl;
        delete chemin; // Libération mémoire en cas d'annulation
        return nullptr;
    }

    ifstream file(chemin->c_str());

    if (!file.is_open())
    {
        cout << "Fichier introuvable. Création du fichier..." << endl;
        ofstream fichierSortie(chemin->c_str()); // Crée le fichier
        if (!fichierSortie.is_open())
        {
            cout << "Impossible de créer le fichier. Opération annulée." << endl;
            delete chemin; // Libération mémoire en cas d'annulation
            return nullptr;
        }
        fichierSortie.close();
    }

    file.open(chemin->c_str());
    if (!file.is_open())
    {
        cout << "Erreur lors de l'ouverture du fichier. Opération annulée." << endl;
        delete chemin; // Libération mémoire en cas d'annulation
        return nullptr;
    }

    file.close();
    return chemin; // Retourne le pointeur vers la chaîne
}

static void MenuSauvegarde(Catalogue *c)
{
    cout << "\t1: Sauvegarder tout le catalogue" << endl;
    cout << "\t2: Sauvegarder seulement un type de trajet" << endl;
    cout << "\t3: Sauvegarder selon la ville de départ/arrivée" << endl;
    cout << "\t4: Sauvegarder une sélection" << endl;
    cout << "\t0: Retour" << endl;

    int choix;
    cin >> choix;

    switch (choix)
    {
    case 0:
        break;
    case 1:
        c->SauvegarderTout();
        break;
    case 2:
        MenuSauvegardeType(c);
        break;
    case 3:
        MenuSauvegardeVille(c);
        break;
    case 4:
        MenuSauvegardeSelection(c);
        break;
    default:
        cout << "Choix incorrect" << endl;
        MenuSauvegarde(c);
        break;
    }
}

static void MenuSauvegardeType(Catalogue *c)
{
    cout << "Quel type souhaitez-vous sauvegarder ?" << endl;
    cout << "\t1: Trajet Simple" << endl;
    cout << "\t2: Trajet Composé" << endl;
    cout << "\t0: Retour" << endl;

    int choix;
    cin >> choix;

    switch (choix)
    {
    case 0:
        break;
    case 1:
        c->SauvegarderParType(1);
        break;
    case 2:
        c->SauvegarderParType(2);
        break;
    default:
        cout << "Choix incorrect" << endl;
        MenuSauvegardeType(c);
        break;
    }
}

static void MenuSauvegardeVille(Catalogue *c)
{
    char depart[TAILLE];
    char arrivee[TAILLE];

    cin.ignore();
    cout << "Quelle ville de départ ?" << endl;
    cin.getline(depart, TAILLE);
    cout << "Quelle ville d'arrivée ?" << endl;
    cin.getline(arrivee, TAILLE);

    if (depart[0] == '\0')
    {
        strcpy(depart, "");
    }
    if (arrivee[0] == '\0')
    {
        strcpy(arrivee, "");
    }

    c->SauvegarderParVilles(depart, arrivee);
}

static void MenuSauvegardeSelection(Catalogue *c)
{
    int debut, fin;

    cout << "Quel est l'indice de début de la sélection ? (-1 pour annuler)" << endl;
    cin >> debut;
    if (debut == -1)
    {
        cout << "Opération annulée." << endl;
        return;
    }

    cout << "Quel est l'indice de fin de la sélection ? (-1 pour annuler)" << endl;
    cin >> fin;
    if (fin == -1)
    {
        cout << "Opération annulée." << endl;
        return;
    }

    if (debut <= 0 || fin < debut)
    {
        cout << "Indices invalides. Veuillez réessayer." << endl;
        MenuSauvegardeSelection(c);
    }
    else
    {
        c->SauvegarderPlage(debut, fin);
    }
}


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
{
    menu();
    return 0;
} //----- fin de main
