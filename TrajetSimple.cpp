/*************************************************************************
                           TrajetSimple  -  Un trajet simple entre deux villes
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher ( )
{
    cout << "\tVille de départ : " << villeDep << endl;
    cout << "\tVille d'arrivé : " << villeArr << endl;
    cout << "\tMoyen de transport : " << moyenTransport << endl;
} //----- Fin de Afficher

const char* TrajetSimple::GetVilleDep ( )
{
    return villeDep;
} //----- Fin de GetVilleDep

const char* TrajetSimple::GetVilleArr ( )
{
    return villeArr;
} //----- Fin de GetvilleArr

const char* TrajetSimple::GetTransport ( )
{
    return moyenTransport;
} //----- Fin de GetTransport

void TrajetSimple::Sauvegarder(ofstream &fichier) const
{
    fichier << "#" << endl;
    fichier << villeDep << endl;
    fichier << villeArr << endl;
    fichier << moyenTransport << endl;
} //----- Fin de Sauvegarder

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple ( const char* dep, const char* arr, const char* transport)
    : Trajet()
// Algorithme : Allocation dynamique des villes et du moyen de transport
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

    villeDep = new char[strlen(dep) + 1];
    strcpy(villeDep, dep);

    villeArr = new char[strlen(arr) + 1];
    strcpy(villeArr, arr);

    moyenTransport = new char[strlen(transport) + 1];
    strcpy(moyenTransport, transport);
} //----- Fin de TrajetSimple


TrajetSimple::TrajetSimple( TrajetSimple *t)
    : Trajet()
{
    #ifdef MAP
        cout << "Appel au constructeur par recopie de <TrajetSimple>" << endl;
    #endif
    villeDep = new char[strlen(t->villeDep) + 1];
    strcpy(villeDep, t->villeDep);

    villeArr = new char[strlen(t->villeArr) + 1];
    strcpy(villeArr, t->villeArr);

    moyenTransport = new char[strlen(t->moyenTransport) + 1];
    strcpy(moyenTransport, t->moyenTransport);
}


TrajetSimple::~TrajetSimple ( )
// Algorithme : Libération de la mémoire dynamique
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

    delete [] villeDep;
    delete [] villeArr;
    delete [] moyenTransport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
