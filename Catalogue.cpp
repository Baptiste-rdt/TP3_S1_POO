/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier ${file_name}) -------

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
