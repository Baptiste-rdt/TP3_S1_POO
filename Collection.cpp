/*************************************************************************
                           Collection  -  description
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Réalisation de la classe <Collection> (fichier ${file_name}) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Collection.h"
#include "Trajet.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include <cstring>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Collection::Ajouter (Trajet *t)
// Algorithme :
//      Si la collection est pleine -> agrandissement
//      Et on insère le trajet dans la collection
{
    if (nbTrajets == nbTrajetsMax) {
        Trajet **tmpTrajets = new Trajet* [nbTrajetsMax * 2];
        for (int i = 0; i < nbTrajetsMax; i++) {
            tmpTrajets[i] = trajets[i];
        }
        nbTrajetsMax *= 2;
        delete trajets;
        trajets = tmpTrajets;
    }
    trajets[nbTrajets++] = t;
} 

const Collection* Collection::RechercherTrajet(const char* dep, const char* arr) const
{
    Collection *resultats = new Collection();
    for (int i = 0; i < nbTrajets; i++) {
        if (strcmp(trajets[i]->GetVilleDep(), dep) == 0 && strcmp(trajets[i]->GetVilleArr(), arr) == 0) {
            // Copie en profondeur pour ne pas détruire les trajets du catalogue depuis une recherche
            Trajet* t;
            if (trajets[i]->getType() == Trajet::SIMPLE) {
                t = new TrajetSimple( (TrajetSimple*) trajets[i]);
            } else {
                t = new TrajetCompose( (TrajetCompose*) trajets[i]);
            }
            resultats->Ajouter(t);
        }
    }
    
    return resultats;
}

void Collection::Afficher(int affichage) const
{
    for (int i = 0; i < nbTrajets; i++) {
        if (affichage == 0) cout << endl << "Trajet n°" << i+1 << " : " << endl;
        else cout << endl;

        trajets[i]->Afficher();
    }
}

bool Collection::EstVide() const 
{
    return (nbTrajets == 0 ? true : false);
}

const char* Collection::GetPremiereVille() 
{
    if (nbTrajets == 0) return NULL;
    return trajets[0]->GetVilleDep();
}

const char* Collection::GetDerniereVille() 
{
    if (nbTrajets == 0) return NULL;
    return trajets[nbTrajets - 1]->GetVilleArr();
}

//-------------------------------------------- Constructeurs - destructeur

Collection::Collection ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Collection>" << endl;
    #endif
    nbTrajets = 0;
    nbTrajetsMax = 5;
    trajets = new Trajet* [5];
} //----- Fin de Collection

Collection::Collection (Collection *c)
{
    #ifdef MAP
        cout << "Appel au constructeur par recopie de <Collection>" << endl;
    #endif
    nbTrajets = c->nbTrajets;
    nbTrajetsMax = c->nbTrajetsMax;
    trajets = new Trajet* [nbTrajetsMax];
    for (int i = 0; i < nbTrajets; i++) 
    {
        
        if (c->trajets[i]->getType() == Trajet::SIMPLE) {
            trajets[i] = new TrajetSimple((TrajetSimple *) c->trajets[i]);
        } else {
            trajets[i] = new TrajetCompose((TrajetCompose*) c->trajets[i]);
        }
    }
}

Collection::~Collection ( )
// Algorithme :
// 
{
    #ifdef MAP
        cout << "Appel au destructeur de <Collection>" << endl;
    #endif
    for (int i = 0; i < nbTrajets; i++) {
        delete trajets[i];
    }
    delete [] trajets;
} //----- Fin de ~Collection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
