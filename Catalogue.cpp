/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Collection.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher () 
{
    c->Afficher();
}


void Catalogue::Ajouter(Trajet* t) 
{
    c->Ajouter(t);
} 

const Collection* Catalogue::RechercherTrajet(const char* dep, const char* arr) 
{
    const Collection *resultats = c->RechercherTrajet(dep, arr);
    return resultats;
}

void Catalogue::ImporterTouteSauvegarde(const char* nomFichier)
{
    c->ImporterTouteSauvegarde(nomFichier);
}

void Catalogue::ImporterTypeSauvegarde(const int type, const char* nomFichier)
{
    c->ImporterTypeSauvegarde(type, nomFichier);
}

void Catalogue::ImporterVilleSauvegarde(const char* depart, const char* arrivee, const char* nomFichier)
{
    c->ImporterVilleSauvegarde(depart, arrivee, nomFichier);
}

void Catalogue::ImporterSelectionSauvegarde(const int debut, const int fin, const char* nomFichier)
{
    c->ImporterSelectionSauvegarde(debut, fin, nomFichier);
}

void Catalogue::SauvegarderTout() const
{
    c->SauvegarderTout();
}

void Catalogue::SauvegarderParType(int type) const
{
    c->SauvegarderParType(type);
}

void Catalogue::SauvegarderParVilles(const char *depart, const char *arrivee) const
{
    c->SauvegarderParVilles(depart, arrivee);
}

void Catalogue::SauvegarderPlage(int debut, int fin) const
{
    c->SauvegarderPlage(debut, fin);
}

//-------------------------------------------- Constructeurs - destructeur
 
Catalogue::Catalogue ()
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Catalogue>" << endl;
    #endif
    c = new Collection();
} //----- Fin de Catalogue


Catalogue::~Catalogue ()
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <Catalogue>" << endl;
    #endif
    delete c;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
