/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier ${file_name}) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "Collection.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char* TrajetCompose::GetVilleDep()
{
    return c->GetPremiereVille();
}

const char* TrajetCompose::GetVilleArr()
{
    return c->GetDerniereVille();
}

void TrajetCompose::Afficher()
{
    c->Afficher(1);
}

void TrajetCompose::Ajouter(Trajet *t)
{
    c->Ajouter(t);
}

void TrajetCompose::Sauvegarder(ofstream &fichier) const
{
    fichier << "{" << endl;
    c->SauvegarderTout(); // Utilisation récursive de Sauvegarder
    fichier << "}" << endl;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( )
    : Trajet()
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
    c = new Collection();
} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose (TrajetCompose *t)
    : Trajet()
{
    #ifdef MAP
        cout << "Appel au constructeur par recopie de <TrajetCompose>" << endl;
    #endif
    c = new Collection(t->c);
} 

TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif
    delete c;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
