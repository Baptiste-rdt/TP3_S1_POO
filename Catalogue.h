/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ------
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

        void ImporterTouteSauvegarde(const char* nomFichier);
        // Mode d'emploi :
        //      Import de trajets à partir d'un fichier de sauvegarde (tous les trajets)

        void ImporterTypeSauvegarde(const int type, const char* nomFichier);
        // Mode d'emploi :
        //      Import de trajets à partir d'un fichier de sauvegarde (trajets filtrer par type)

        void ImporterVilleSauvegarde(const char* depart, const char* arrivee, const char* nomFichier);
        // Mode d'emploi :
        //      Import de trajets à partir d'un fichier de sauvegarde (trajets filtrer par ville)

        void ImporterSelectionSauvegarde(const int debut, const int fin, const char* nomFichier);
        // Mode d'emploi :
        //      Import de trajets à partir d'un fichier de sauvegarde (selection par rapport aux index)
        
        void SauvegarderTout(const char* nomFichier) const;
        // Mode d'emploi :
        //      Sauvegarde tous les trajets du catalogue dans un fichier

        void SauvegarderParType(int type, const char* nomFichier) const;
        // Mode d'emploi :
        //      Sauvegarde les trajets du catalogue dans un fichier (seulement les trajets du type)

        void SauvegarderParVilles(const char *depart, const char *arrivee, const char* nomFichier) const;
        // Mode d'emploi :
        //      Sauvegarde les trajets du catalogue dans un fichier (seulement les trajets avec les villes demandées)

        void SauvegarderPlage(int debut, int fin, const char* nomFichier) const;
        // Mode d'emploi :
        //      Sauvegarde les trajets du catalogue dans un fichier (seulement les index souhaités)

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