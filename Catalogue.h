/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier ${file_name}) ------
#if ! defined ( CATALOGUE )
#define CATALOGUE

//--------------------------------------------------- Interfaces utilisées
#include "Collection.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Catalogue>
// La classe catalogue sert d'interface entre l'utilisateur final et une collection de trajets
// Il permet la gestion de cette collection
//------------------------------------------------------------------------ 

class Catalogue
{
//----------------------------------------------------------------- PUBLIC
 
    public:
    //----------------------------------------------------- Méthodes publiques
        void Afficher();
        // Mode d'emploi :
        //      Affiche un catalogue à l'écran (liste de tous les trajets saisis)

        void Ajouter(Trajet* t);
        // Mode d'emploi : 
        //      Ajoute un trajet dans le catalogue
        
        const Collection* RechercherTrajet(const char* dep, const char* arr);
        // Mode d'emploi : 
        //      Recherche un trajet et renvoie une collection de trajets


        


    //-------------------------------------------- Constructeurs - destructeur

        Catalogue ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Catalogue ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

    //------------------------------------------------------------------ PRIVE 

    protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
        Collection *c;

    };

    //--------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE