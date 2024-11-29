/*************************************************************************
                           Trajet  -  Classe de base pour les trajets
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ------
#if ! defined ( TRAJET )
#define TRAJET

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Trajet>
// La classe Trajet est une classe abstraite qui sert à regrouper des trajets simples et composés
//
//------------------------------------------------------------------------ 

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    enum TYPE {SIMPLE, COMPOSE};

    virtual const char* GetVilleDep ( ) = 0;
    // Mode d'emploi : 
    //      Renvoie la ville de départ d'un trajet

    virtual const char* GetVilleArr ( ) = 0;
    // Mode d'emploi : 
    //      Renvoie la ville d'arrivée d'un trajet

    virtual void Afficher ( ) = 0;
    // Mode d'emploi : 
    //      Affiche un trajet à l'écran

    virtual TYPE getType() = 0;
    // Mode d'emploi : 
    //      Retourne le type d'un trajet (simple ou compose)

    virtual void Sauvegarder(ofstream &fichier) const = 0;
    // Mode d'emploi :
    //      Sauvegarde un trajet dans un fichier

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( );
    // Mode d'emploi : 
    //      Construit un trajet 

    Trajet ( Trajet *t );
    // Mode d'emploi : 
    //      Construit un trajet à partir d'un autre -> copie en profondeur

    virtual ~Trajet ( );
    // Mode d'emploi : 
    //      Détruit un trajet
 
//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET
