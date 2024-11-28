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

static void MenuImportType(Catalogue* c);
// Mode d'emploi :
//    Affiche le menu lié à l'import par type

static void MenuImportVille(Catalogue* c);
// Mode d'emploi :
//    Affiche le menu lié à l'import par ville

static void MenuImportSelection(Catalogue* c);
// Mode d'emploi :
//    Affiche le menu lié à l'import d'une sélection

static void MenuSauvegarde(Catalogue *c);
static void MenuSauvegardeType(Catalogue *c);
static void MenuSauvegardeVille(Catalogue *c);
static void MenuSauvegardeSelection(Catalogue *c);

#endif // MAIN
