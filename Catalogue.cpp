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
#include <fstream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Collection.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Sauvegarder()
// Algorithme :
//      On crée un fichier texte et on écrit dedans les trajets du catalogue
{
    const char* nomFichier = "SauvegardeCatalogue.txt";

    // Vérifier si le fichier existe déjà
    ifstream fileCheck(nomFichier);
    if (fileCheck.good()) {
        fileCheck.close();
        // Supprimer le fichier existant
        if (remove(nomFichier) != 0) {
            cerr << "Erreur : Impossible de supprimer le fichier existant " << nomFichier << endl;
            return;
        }
        cout << "Fichier existant " << nomFichier << " supprimé." << endl;
    }

    // Créer un nouveau fichier
    ofstream fichier(nomFichier);

    // Vérifier si le fichier a été créé avec succès
    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible de créer le fichier " << nomFichier << endl;
        return;
    }

    // Écrire une ligne d'en-tête dans le fichier
    fichier << "Fichier de sauvegarde de trajets" << endl;

    // Fermer le fichier
    fichier.close();

    cout << "Fichier " << nomFichier << " créé avec succès." << endl;
}

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
