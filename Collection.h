/*************************************************************************
                           Collection  -  description
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Interface de la classe <Collection> (fichier Collection.h) ------
#if !defined(COLLECTION)
#define COLLECTION

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Collection>
// Cette classe à pour but de gérer une liste de trajets. C'est elle qui gère les données du programme.
// Elle stocke les différents trajets et offre différents services utilisable sur cette liste.
// Les services proposés servent à la classe catalogue et TrajetCompose
//
//------------------------------------------------------------------------

class Collection
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void Ajouter(Trajet *t);
    // Mode d'emploi :
    //      Ajoute un trajet dans la collection

    const Collection *RechercherTrajet(const char *dep, const char *arr) const;
    // Mode d'emploi :
    //      Renvoie tous les trajets présents dans la collection
    //      correspondants aux critères de départ et d'arrivée

    void Afficher(int affichage = 0) const;
    // Mode d'emploi :
    //      Affiche la collection à l'écran
    //      Si affichage = 1 : affichage d'un Trajet Compose

    bool EstVide() const;
    // Mode d'emploi :
    //      Test si la collection est vide ou non

    const char *GetPremiereVille();
    // Mode d'emploi :
    //      Retourne la première ville de départ de la collection
    // Contrat :
    //      Méthode utile seulement pour la classe TrajetCompose (pour avoir la ville de départ)

    const char *GetDerniereVille();
    // Mode d'emploi :
    //      Retourne la dernière ville d'arrivée de la collection
    // Contrat :
    //      Méthode utile seulement pour la classe TrajetCompose (pour avoir la ville d'arrivée)

    int GetNbTrajets() const;
    // Mode d'emploi :
    //      Retourne le nombre de trajets dans la collection

    Trajet* GetTrajet(int index) const;
    // Mode d'emploi :
    //      Retourne le trajet à l'index donné

    void EcrireMetaDonnees(ofstream &fichier, int type) const; 
    // Mode d'emploi :
    //      Ecrit les métadonnées dans un fichier de sauvegarde
  
    void SauvegarderTout() const;
    // Mode d'emploi :
    //      Sauvegarde tous les trajets de la collection dans un fichier

    void SauvegarderParType(int type) const;
    // Mode d'emploi :
    //      Sauvegarde les trajets de la collection dans un fichier (seulement les trajets du type)

    void SauvegarderPlage(int debut, int fin) const;
    // Mode d'emploi :
    //      Sauvegarde les trajets de la collection dans un fichier (seulement les index souhaités)

    void SauvegarderParVilles(const char *depart, const char *arrivee) const;
    // Mode d'emploi :
    //      Sauvegarde les trajets de la collection dans un fichier (seulement les
    //      trajets avec les villes demandées)

    void ImporterTouteSauvegarde();
    // Mode d'emploi :
    //      Importe une sauvegarde de trajets à partir d'un fichier (tous les trajets)
    
    void ImporterTypeSauvegarde(const int type);
    // Mode d'emploi :
    //      Importe une sauvegarde de trajets à partir d'un fichier et du type souhaité (seulement les trajets du type)

    void ImporterVilleSauvegarde(const char *depart, const char *arrivee);
    // Mode d'emploi :
    //      Importe une sauvegarde de trajets à partir d'un fichier (seulement les trajets avec les villes demandées)

    void ImporterSelectionSauvegarde(const int debut, const int fin);
    // Mode d'emploi :
    //      Importe une sauvegarde de trajets à partir d'un fichier (seulement les index souhaités)

    //-------------------------------------------- Constructeurs - destructeur
    Collection();
    // Mode d'emploi :
    //      Construit une collection de trajets

    Collection(Collection *c);
    // Mode d'emploi :
    //      Construit une collection de trajets à partir d'une autre en les recopiants tous en profondeur

    virtual ~Collection();
    // Mode d'emploi :
    //      Détruit une collection de trajets

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    Trajet *LireTrajetSimple(ifstream &file);
    // Mode d'emploi :
    //      Permet de lire une partie de fichier dont le buffer est passé en paramètre, afin de créer un trajetSimple
    // Contrat :
    //      Méthode utile pour créer un trajetSimple à partir d'un fichier sauvegarde

    Trajet *LireTrajetCompose(ifstream &file);
    // Mode d'emploi :
    //      Permet de lire une partie de fichier dont le buffer est passé en paramètre, afin de créer un trajetCompsoe
    // Contrat :
    //      Méthode utile pour créer un trajetCompose à partir d'un fichier sauvegarde

    ifstream OuvrirFichier(char* cheminFichier);
    // Mode d'emploi :
    //      Permet de lire une partie de fichier dont le buffer est passé en paramètre, afin de créer un trajetCompsoe
    // Contrat :
    //      Méthode utile pour créer un trajetCompose à partir d'un fichier sauvegarde

    //----------------------------------------------------- Attributs protégés
    Trajet **trajets;          // tableau de pointeurs de trajets
    unsigned int nbTrajets;    // Nombre de trajets actuellement dans le tableau
    unsigned int nbTrajetsMax; // Nombre max de trajets pouvant être dans le tableau
};

//--------------------------- Autres définitions dépendantes de <Collection>

#endif // COLLECTION
