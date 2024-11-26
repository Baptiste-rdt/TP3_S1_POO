/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier ${file_name}) ------
#if ! defined ( TRAJETCOMPOSE )
#define TRAJETCOMPOSE

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Collection.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <TrajetCompose>
// La classe TrajetCompose sert à créer un trajet à partir de plusieurs autres. 
// C'est un trajet avec des escales, passant par différentes villes avec différents modes de transports. 
//
//------------------------------------------------------------------------ 

class TrajetCompose : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        void Afficher();
        // Mode d'emploi : 
        //      Affiche un trajet compose à l'écran

        const char* GetVilleDep();
        // Mode d'emploi : 
        //      Renvoie la ville de départ du trajet

        const char* GetVilleArr();
        // Mode d'emploi : 
        //      Renvoie la ville d'arrivée du trajet

        void Ajouter(Trajet *t);
        // Mode d'emploi : 
        //      Ajoute une étape au trajet compose

        TYPE getType() {return COMPOSE;};
        // Mode d'emploi : 
        //      Renvoie le type de trajet (compose)


    //-------------------------------------------- Constructeurs - destructeur
        TrajetCompose ( );
        // Mode d'emploi :
        //      Construit un trajet compose vide


        TrajetCompose (TrajetCompose *t);
        // Mode d'emploi :
        //      Construit un trajet compose à partir d'un trajet compose -> copie en profondeur

        virtual ~TrajetCompose ( );
        // Mode d'emploi :
        //      Détruit un trajet compose
        

    //------------------------------------------------------------------ PRIVE 

    protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
        Collection *c;
};

//--------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE
