/*************************************************************************
                           Collection  -  description
                             -------------------
    début                : ${2024-10-03}
    copyright            : (C) ${2024} par ${Eli and Corentin}
*************************************************************************/

//---------- Réalisation de la classe <Collection> (fichier Collection.cpp) -------

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
#include <fstream>
#include <iostream>
#include <string>

//------------------------------------------------------------- Constantes
const char *FICHIER_SAUVEGARDE = "ressources/sauvegarde.txt";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Collection::Ajouter(Trajet *t)
// Algorithme :
//      Si la collection est pleine -> agrandissement
//      Et on insère le trajet dans la collection
{
    if (nbTrajets == nbTrajetsMax)
    {
        Trajet **tmpTrajets = new Trajet *[nbTrajetsMax * 2];
        for (int i = 0; i < nbTrajetsMax; i++)
        {
            tmpTrajets[i] = trajets[i];
        }
        nbTrajetsMax *= 2;
        delete trajets;
        trajets = tmpTrajets;
    }
    trajets[nbTrajets++] = t;
}

const Collection *Collection::RechercherTrajet(const char *dep, const char *arr) const
{
    Collection *resultats = new Collection();
    for (int i = 0; i < nbTrajets; i++)
    {
        if (strcmp(trajets[i]->GetVilleDep(), dep) == 0 && strcmp(trajets[i]->GetVilleArr(), arr) == 0)
        {
            // Copie en profondeur pour ne pas détruire les trajets du catalogue depuis une recherche
            Trajet *t;
            if (trajets[i]->getType() == Trajet::SIMPLE)
            {
                t = new TrajetSimple((TrajetSimple *)trajets[i]);
            }
            else
            {
                t = new TrajetCompose((TrajetCompose *)trajets[i]);
            }
            resultats->Ajouter(t);
        }
    }

    return resultats;
}

void Collection::Afficher(int affichage) const
{
    for (int i = 0; i < nbTrajets; i++)
    {
        if (affichage == 0)
            cout << endl
                 << "Trajet n°" << i + 1 << " : " << endl;
        else
            cout << endl;

        trajets[i]->Afficher();
    }
}

bool Collection::EstVide() const
{
    return (nbTrajets == 0 ? true : false);
}

const char *Collection::GetPremiereVille()
{
    if (nbTrajets == 0)
        return NULL;
    return trajets[0]->GetVilleDep();
}

const char *Collection::GetDerniereVille()
{
    if (nbTrajets == 0)
        return NULL;
    return trajets[nbTrajets - 1]->GetVilleArr();
}

int Collection::GetNbTrajets() const
{
    return nbTrajets;
}

Trajet* Collection::GetTrajet(int index) const
{
    if (index >= 0 && index < nbTrajets)
    {
        return trajets[index];
    }
    return nullptr; // Si l'index est invalide
}

void Collection::EcrireMetaDonnees(ofstream &fichier, int type) const
{
    int nbSimples = 0;
    int nbComposes = 0;

    for (int i = 0; i < nbTrajets; i++)
    {
        if ((type == 1 || type == 0) && trajets[i]->getType() == Trajet::SIMPLE)
        {
            nbSimples++;
        }

        if ((type == 2 || type == 0) && trajets[i]->getType() == Trajet::COMPOSE)
        {
            nbComposes++;
        }
    }

    fichier << nbSimples << endl;
    fichier << nbComposes << endl;
}

void Collection::SauvegarderTout() const
{
    ofstream fichier(FICHIER_SAUVEGARDE, ios::out);

    if (!fichier)
    {
        cerr << "Erreur lors de l'ouverture du fichier pour la sauvegarde." << endl;
        return;
    }

    // Écrire les métadonnées pour tous les types
    EcrireMetaDonnees(fichier, 0);

    // Sauvegarder tous les trajets
    for (int i = 0; i < nbTrajets; i++)
    {
        trajets[i]->Sauvegarder(fichier);
    }

    fichier.close();
    cout << "Sauvegarde complète effectuée avec succès." << endl;
}

void Collection::SauvegarderParType(int type) const
{
    ofstream fichier(FICHIER_SAUVEGARDE, ios::out);

    if (!fichier)
    {
        cerr << "Erreur lors de l'ouverture du fichier pour la sauvegarde." << endl;
        return;
    }

    // Écrire les métadonnées pour le type sélectionné
    EcrireMetaDonnees(fichier, type);

    // Sauvegarder les trajets du type sélectionné
    for (int i = 0; i < nbTrajets; i++)
    {
        if ((type == 1 && trajets[i]->getType() == Trajet::SIMPLE) ||
            (type == 2 && trajets[i]->getType() == Trajet::COMPOSE))
        {
            trajets[i]->Sauvegarder(fichier);
        }
    }

    fichier.close();
    cout << "Sauvegarde des trajets de type " 
         << (type == 1 ? "simple" : "composé") 
         << " effectuée avec succès." << endl;
}

void Collection::SauvegarderPlage(int debut, int fin) const
{
    if (debut <= 0 || fin > nbTrajets || debut > fin)
    {
        cerr << "Indices de plage invalides." << endl;
        return;
    }

    ofstream fichier(FICHIER_SAUVEGARDE, ios::out);

    if (!fichier)
    {
        cerr << "Erreur lors de l'ouverture du fichier pour la sauvegarde." << endl;
        return;
    }

    int nbSimples = 0;
    int nbComposes = 0;

    // Compter les types dans la plage sélectionnée
    for (int i = debut - 1; i < fin; i++)
    {
        if (trajets[i]->getType() == Trajet::SIMPLE)
        {
            nbSimples++;
        }
        else if (trajets[i]->getType() == Trajet::COMPOSE)
        {
            nbComposes++;
        }
    }

    // Écrire les métadonnées
    fichier << nbSimples << endl;
    fichier << nbComposes << endl;

    // Sauvegarder les trajets dans la plage
    for (int i = debut - 1; i < fin; i++)
    {
        trajets[i]->Sauvegarder(fichier);
    }

    fichier.close();
    cout << "Sauvegarde de la plage [" << debut << ", " << fin << "] effectuée avec succès." << endl;
}

void Collection::SauvegarderParVilles(const char *depart, const char *arrivee) const
{
    ofstream fichier(FICHIER_SAUVEGARDE, ios::out);

    if (!fichier)
    {
        cerr << "Erreur lors de l'ouverture du fichier pour la sauvegarde." << endl;
        return;
    }
    
    bool trajetTrouve = false;

    // Étape 1 : Compter les trajets correspondants
    int nbSimples = 0;
    int nbComposes = 0;

    for (int i = 0; i < nbTrajets; i++)
    {
        if ((depart == nullptr || strcmp(trajets[i]->GetVilleDep(), depart) == 0) &&
            (arrivee == nullptr || strcmp(trajets[i]->GetVilleArr(), arrivee) == 0))
        {
            if (trajets[i]->getType() == Trajet::SIMPLE)
            {
                nbSimples++;
            }
            else if (trajets[i]->getType() == Trajet::COMPOSE)
            {
                nbComposes++;
            }
        }
    }

    // Étape 2 : Écrire les métadonnées dans le fichier
    fichier << nbSimples << endl;
    fichier << nbComposes << endl;

    // Étape 3 : Sauvegarder les trajets correspondants
    for (int i = 0; i < nbTrajets; i++)
    {
        if ((depart == nullptr || strcmp(trajets[i]->GetVilleDep(), depart) == 0) &&
            (arrivee == nullptr || strcmp(trajets[i]->GetVilleArr(), arrivee) == 0))
        {
            trajets[i]->Sauvegarder(fichier);
            trajetTrouve = true;
        }
    }

    fichier.close();
    
    if (trajetTrouve)
    {
        cout << "Sauvegarde des trajets correspondant aux villes spécifiées effectuée avec succès." << endl;
    }
    else
    {
        cerr << "Erreur : Aucun trajet ne correspond aux villes spécifiées." << endl;
    }
}

void Collection::ImporterTouteSauvegarde()
{
    ifstream file;

    const int TAILLE_MAX = 50;
    char ligne[TAILLE_MAX];

    file.open(FICHIER_SAUVEGARDE);

    while (file.getline(ligne, TAILLE_MAX))
    {
        if (ligne[0] == '#')
        {
            Trajet *trajet = this->LireTrajetSimple(file);
            this->Ajouter(trajet);
        }
        else if (ligne[0] == '{')
        {
            Trajet *trajet = this->LireTrajetCompose(file);
            this->Ajouter(trajet);
        }
    }

    file.close();
}

void Collection::ImporterTypeSauvegarde(const int type)
{
    ifstream file;

    const int TAILLE_MAX = 50;
    char ligne[TAILLE_MAX];
    int nbSimple = 0;
    int nbCompose = 0;
    int nbType = 0;
    int estCompose = 0;

    file.open(FICHIER_SAUVEGARDE);

    // Récupération du nombre de trajet de chaque type
    for (int i = 1; i < 3; i++)
    {
        file.getline(ligne, TAILLE_MAX);
        switch (i)
        {
        case 1:
            nbSimple = atoi(ligne);
            break;
        case 2:
            nbCompose = atoi(ligne);
            break;
        }
    }

    // Attribution au compteur du nombre de trajet du type souhaité
    switch (type)
    {
    case 1:
        nbType = nbSimple;
        break;
    case 2:
        nbType = nbCompose;
        break;
    }

    while (file.getline(ligne, TAILLE_MAX) && nbType > 0)
    {
        if (ligne[0] == '#')
        {
            if (type == 1 && estCompose == 0)
            {
                Trajet *trajet = this->LireTrajetSimple(file);
                this->Ajouter(trajet);
            }
            else
            {
                for (int i = 0; i < 3; i++)
                {
                    file.getline(ligne, TAILLE_MAX);
                }
            }
        }
        else if (ligne[0] == '{')
        {
            if (type == 2)
            {
                Trajet *trajet = this->LireTrajetCompose(file);
                this->Ajouter(trajet);
            }
            else
            {
                estCompose++;
            }
        }
        else if (ligne[0] == '}')
        {
            estCompose--;
        }
    }

    file.close();
}

void trim(char *chaine)
{
    // Supprimer les espaces ou caractères invisibles en début de chaîne
    char *start = chaine;
    while (*start && (*start == ' ' || *start == '\r' || *start == '\n' || *start == '\t'))
    {
        start++;
    }

    // Déplacer le contenu utile au début
    memmove(chaine, start, strlen(start) + 1);

    // Supprimer les espaces ou caractères invisibles en fin de chaîne
    char *end = chaine + strlen(chaine) - 1;
    while (end >= chaine && (*end == ' ' || *end == '\r' || *end == '\n' || *end == '\t'))
    {
        *end = '\0';
        end--;
    }
}

void Collection::ImporterVilleSauvegarde(const char *depart, const char *arrivee)
{
    ifstream file;

    const int TAILLE_MAX = 50;
    char ligne[TAILLE_MAX];
    int estCompose = 0;
    streampos position;

    file.open(FICHIER_SAUVEGARDE);

    while (file.getline(ligne, TAILLE_MAX))
    {
        position = file.tellg();
        bool estValide = true;
        if (ligne[0] == '#')
        {
            file.getline(ligne, TAILLE_MAX);
            trim(ligne);
            if (strcmp(depart, "") != 0)
            {
                if (strcmp(ligne, depart) != 0)
                {
                    estValide = false;
                }
            }
            file.getline(ligne, TAILLE_MAX);
            trim(ligne);
            if (strcmp(arrivee, "") != 0)
            {
                if (strcmp(ligne, arrivee) != 0)
                {
                    estValide = false;
                }
            }
            if (estValide)
            {
                file.seekg(position);
                Trajet *trajet = this->LireTrajetSimple(file);
                this->Ajouter(trajet);
            }
            else
            {
                file.getline(ligne, TAILLE_MAX);
            }
        }
        else if (ligne[0] == '{')
        {
            estCompose++;
            file.getline(ligne, TAILLE_MAX);
            trim(ligne);
            if (strcmp(depart, ""))
            {
                if (strcmp(ligne, depart) != 0)
                {
                    estValide = false;
                }
            }
            file.getline(ligne, TAILLE_MAX);
            trim(ligne);
            if (strcmp(arrivee, ""))
            {
                if (strcmp(ligne, arrivee) != 0)
                {
                    estValide = false;
                }
            }
            if (estValide)
            {
                file.seekg(position);
                Trajet *trajet = this->LireTrajetCompose(file);
                this->Ajouter(trajet);
            }
            else
            {
                while (estCompose > 0)
                {
                    file.getline(ligne, TAILLE_MAX);
                    if (ligne[0] == '{')
                    {
                        estCompose++;
                    }
                    else if (ligne[0] == '}')
                    {
                        estCompose--;
                    }
                }
            }
        }
    }

    file.close();
}

void Collection::ImporterSelectionSauvegarde(const int debut, const int fin)
{
    ifstream file;

    const int TAILLE_MAX = 50;
    char ligne[TAILLE_MAX];
    int indexCourant = 0;
    int nbSimple = 0;
    int nbCompose = 0;

    file.open(FICHIER_SAUVEGARDE);

    for (int i = 1; i < 3; i++)
    {
        file.getline(ligne, TAILLE_MAX);
        switch (i)
        {
        case 1:
            nbSimple = atoi(ligne);
            break;
        case 2:
            nbCompose = atoi(ligne);
            break;
        }
    }

    if (debut <= (nbSimple + nbCompose))
    {
        while (file.getline(ligne, TAILLE_MAX) && indexCourant <= fin)
        {
            if (ligne[0] == '#')
            {
                indexCourant++;
                if (indexCourant >= debut && indexCourant <= fin)
                {
                    Trajet *trajet = this->LireTrajetSimple(file);
                    this->Ajouter(trajet);
                }
            }
            else if (ligne[0] == '{')
            {
                indexCourant++;
                if (indexCourant >= debut && indexCourant <= fin)
                {
                    Trajet *trajet = this->LireTrajetCompose(file);
                    this->Ajouter(trajet);
                }
            }
        }
    }

    file.close();
}

//-------------------------------------------- Constructeurs - destructeur

Collection::Collection()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Collection>" << endl;
#endif
    nbTrajets = 0;
    nbTrajetsMax = 5;
    trajets = new Trajet *[5];
} //----- Fin de Collection

Collection::Collection(Collection *c)
{
#ifdef MAP
    cout << "Appel au constructeur par recopie de <Collection>" << endl;
#endif
    nbTrajets = c->nbTrajets;
    nbTrajetsMax = c->nbTrajetsMax;
    trajets = new Trajet *[nbTrajetsMax];
    for (int i = 0; i < nbTrajets; i++)
    {

        if (c->trajets[i]->getType() == Trajet::SIMPLE)
        {
            trajets[i] = new TrajetSimple((TrajetSimple *)c->trajets[i]);
        }
        else
        {
            trajets[i] = new TrajetCompose((TrajetCompose *)c->trajets[i]);
        }
    }
}

Collection::~Collection()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Collection>" << endl;
#endif
    for (int i = 0; i < nbTrajets; i++)
    {
        delete trajets[i];
    }
    delete[] trajets;
} //----- Fin de ~Collection

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

Trajet *Collection::LireTrajetCompose(ifstream &file)
{
    const int TAILLE_MAX = 50;
    char ligne[TAILLE_MAX];

    TrajetCompose *trajets = new TrajetCompose();

    while (file.getline(ligne, TAILLE_MAX))
    {
        if (ligne[0] == '}')
        {
            break;
        }

        if (ligne[0] == '#')
        {
            Trajet *trajet = LireTrajetSimple(file);
            trajets->Ajouter(trajet);
        }
        else if (ligne[0] == '{')
        {
            Trajet *sousTrajet = LireTrajetCompose(file);
            trajets->Ajouter(sousTrajet);
        }
    }

    return trajets;
}

Trajet *Collection::LireTrajetSimple(ifstream &file)
{
    const int TAILLE_MAX = 50;
    char ligne[TAILLE_MAX];

    char depart[TAILLE_MAX];
    char arrivee[TAILLE_MAX];
    char transport[TAILLE_MAX];

    for (int i = 0; i < 3; i++)
    {
        file.getline(ligne, TAILLE_MAX);
        switch (i)
        {
        case 0:
            strcpy(depart, ligne);
            break;
        case 1:
            strcpy(arrivee, ligne);
            break;
        case 2:
            strcpy(transport, ligne);
            break;
        }
    }

    return new TrajetSimple(depart, arrivee, transport);
}