#ifndef _INC_Fichier
#define _INC_Fichier

#include<stdio.h>
#include<stdlib.h>
#include "GestionDeComptesBancaires.h"

char* PathClient = "BaseDonnee/clients.txt";
char* PathCompte = "BaseDonnee/comptes.txt";

int GetLinesNumber(char* nomFichier)
{
    int linesCount=0;
    char ch;

    FILE* fichier = fopen(nomFichier,"r");

    if(fichier == NULL) 
    {
        return -1;
    }

    while((ch = fgetc(fichier)) != EOF)
    {
        if(ch=='\n')
            linesCount++;
    }

    fclose(fichier);

    return linesCount;
}
#pragma region  Clients Data
int LoadClient()
{
    int i=0, taille;
    FILE* fichierClient = fopen(PathClient,"r");

    if(fichierClient == NULL)
    {
        return -1;
    }

    taille = GetLinesNumber(PathClient);
    for(i=0; i<taille; i++)
    {
        ClientsNombre++;
        Client = (CLIENT*) realloc(Client, ClientsNombre * sizeof(CLIENT));        
        fscanf(fichierClient, "%s %s %s %s %d %d %d", (Client+i)->CIN, (Client+i)->Nom, (Client+i)->Prenom, (Client+i)->Ville, &((Client+i)->DateDeNaissance.jour), &((Client+i)->DateDeNaissance.mois), &((Client+i)->DateDeNaissance.annee));
    }

    fclose(fichierClient);

    return 1;
}

int SaveClient()
{
    int i;
    FILE* fichierClient = fopen(PathClient,"w");

    if(fichierClient == NULL)
    {
        return -1;
    }

    for(i=0; i<ClientsNombre; i++)
    {
        fprintf(fichierClient, "%s %s %s %s %d %d %d\n", (Client+i)->CIN, (Client+i)->Nom, (Client+i)->Prenom, (Client+i)->Ville, (Client+i)->DateDeNaissance.jour, (Client+i)->DateDeNaissance.mois, (Client+i)->DateDeNaissance.annee);
    }

    fclose(fichierClient);

    return 1;
}
#pragma endregion

#pragma region Comptes Data
int LoadCompte()
{
    int i=0, taille;
    int client_index;
    FILE* fichierCompte = fopen(PathCompte,"r");

    if(fichierCompte == NULL)
    {
        return -1;
    }

    taille = GetLinesNumber(PathCompte);
    for(i=0; i<taille; i++)
    {
        ComptesNombre++;
        Compte = (COMPTEBANCAIRE*) realloc(Compte, ComptesNombre * sizeof(COMPTEBANCAIRE));
        fscanf(fichierCompte, "%d %d %d %d %s %s %f %f %s", &((Compte+i)->NumeroDuCompte), &((Compte+i)->DateDeCreation.jour), &((Compte+i)->DateDeCreation.mois), &((Compte+i)->DateDeCreation.annee), (Compte+i)->Localisation, (Compte+i)->Proprietaire.CIN, &((Compte+i)->SoldeActuel), &((Compte+i)->AncienSolde), (Compte+i)->DerniereOperation);
    
        client_index = Client_Exist((Compte+i)->Proprietaire.CIN);
        (Compte+i)->Proprietaire = *(Client + client_index);
    }

    fclose(fichierCompte);

    return 1;
}

int SaveCompte()
{
    int i;
    FILE* fichierCompte = fopen(PathCompte,"w");

    if(fichierCompte == NULL)
    {
        return -1;
    }

    for(i=0; i<ComptesNombre; i++)
    {
        fprintf(fichierCompte, "%d %d %d %d %s %s %f %f %s\n", (Compte+i)->NumeroDuCompte, (Compte+i)->DateDeCreation.jour, (Compte+i)->DateDeCreation.mois, (Compte+i)->DateDeCreation.annee, (Compte+i)->Localisation, (Compte+i)->Proprietaire.CIN, (Compte+i)->SoldeActuel, (Compte+i)->AncienSolde, (Compte+i)->DerniereOperation);
    }

    fclose(fichierCompte);

    return 1;
}
#pragma endregion

#endif