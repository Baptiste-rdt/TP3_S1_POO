/*************************************************************************
                           TrajetSimple  -  Un trajet simple entre deux villes
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ------
#if ! defined ( TRAJETSIMPLE )
#define TRAJETSIMPLE

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <TrajetSimple>
// La classe TrajetSimple sert à créer un trajet sans escale, allant d'un point A à un point B avec un moyen de transport
//
//------------------------------------------------------------------------ 

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( );
    // Mode d'emploi : 
    //      Affiche un trajet simple à l'écran

    const char* GetVilleDep ( );
    // Mode d'emploi : 
    //      Renvoie la ville de départ du trajet

    const char* GetVilleArr ( );
    // Mode d'emploi : 
    //      Renvoie la ville d'arrivée du trajet

    const char* GetTransport ( );
    // Mode d'emploi : 
    //      Renvoie le mode de transport du trajet

    TYPE getType() {return SIMPLE;};
    // Mode d'emploi : 
    //      Retourne le type de trajet (simple)

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const char* dep, const char* arr, const char* transport);
    // Mode d'emploi : 
    //      Construit un trajet simple

    TrajetSimple( TrajetSimple *t);
    // Mode d'emploi : 
    //      Construit un trajet simple à partir d'un autre -> copie en profondeur

    virtual ~TrajetSimple ( );
    // Mode d'emploi : 
    //      Détruit un trajet simple

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char* villeDep;
    char* villeArr;
    char* moyenTransport;

};

//--------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE
