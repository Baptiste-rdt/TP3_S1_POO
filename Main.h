/*************************************************************************
                           Main  -  description
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Interface du module <Main> (fichier Main.h) ---------
#if ! defined ( MAIN )
#define MAIN

#include "Catalogue.h"

//------------------------------------------------------------------------ 
// Réle du module <Main>
//
//
//------------------------------------------------------------------------ 

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
static void menu();
// Mode d'emploi : 
//    Affiche le menu et gère les différents choix de l'utilisateur

int main();
// Mode d'emploi : 
//    Point d'entrée du programme

static void MenuImport(Catalogue* c);
// Mode d'emploi :
//    Affiche le menu lié à l'import

static void MenuImportType(Catalogue* c, const char* nomFichier);
// Mode d'emploi :
//    Affiche le menu lié à l'import par type

static void MenuImportVille(Catalogue* c, const char* nomFichier);
// Mode d'emploi :
//    Affiche le menu lié à l'import par ville

static void MenuImportSelection(Catalogue* c, const char* nomFichier);
// Mode d'emploi :
//    Affiche le menu lié à l'import d'une sélection

static void MenuSauvegarde(Catalogue *c);
// Mode d'emploi :
//    Affiche le menu lié à la sauvegarde

static void MenuSauvegardeType(Catalogue *c);
// Mode d'emploi :
//    Affiche le menu lié à la sauvegarde par type

static void MenuSauvegardeVille(Catalogue *c);
// Mode d'emploi :
//    Affiche le menu lié à la sauvegarde par ville

static void MenuSauvegardeSelection(Catalogue *c);
// Mode d'emploi :
//    Affiche le menu lié à la sauvegarde d'une sélection

static string* UtiliserFichier();
// Mode d'emploi :
//    Permet de demander à l'utilisateur de sélectionner un fichier, et l'ouvrir s'il existe, ou le créé

#endif // MAIN
