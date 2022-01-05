#ifndef _INC_GestionDeComptesBancaires
#define _INC_GestionDeComptesBancaires

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//Structures
typedef struct
{
    int jour;
    int mois;
    int annee;

} Date;

typedef struct
{
    char CIN[10];
    char Nom[20];
    char Prenom[20];
    char Ville[20];
    Date DateDeNaissance;
    
} CLIENT;

typedef struct
{
    int NumeroDuCompte;
    Date DateDeCreation;
    char Localisation[20];
    CLIENT Proprietaire;
    float SoldeActuel;
    float AncienSolde;
    char DerniereOperation[10];
    
} COMPTEBANCAIRE;

//Functions Prototype
int Client_Exist(char*);
int Compte_Exist(int);
int Client_Avoir_Compte(char*);
void AjoutClient(int, int);
void CreationCompte(int, int);
void AfficherClient(int, int, int);
void DetailsClient(char*, int, int);
void ListerClients(int, int);
void AfficherCompte(int, int, int);
void DetailsCompte(int, int, int);
void ListerComptes(int, int);
int Retrait(int, int, int);
int Depot(int, int, int);
int Virement(int, int, int, int);
int SupprimerClient(char*);
int CloturerCompte(int);

//Global variables
CLIENT *Client;
int ClientsNombre;
COMPTEBANCAIRE *Compte;
int ComptesNombre;

//Functions Definition
int Client_Exist(char *_CIN)
{
    int i;
    for(i=0; i<ClientsNombre; i++)
    {
        if(strcmp(_CIN, (Client+i)->CIN) == 0)
            return i; //return index of the Client
    }
    return -1;
}
int Compte_Exist(int _numeroDuCompte)
{
    int i;
    for(i=0; i<ComptesNombre; i++)
    {
        if(_numeroDuCompte == (Compte+i)->NumeroDuCompte)
            return i; //return index of the account
    }
    return -1;
}
int Client_Avoir_Compte(char *_CIN)
{
    int i;
    for(i=0; i<ComptesNombre; i++)
    {
        if(strcmp((Compte+i)->Proprietaire.CIN, _CIN) == 0)
            return i; //return index of the account linked with that Client
    }
    return -1;
}
void AjoutClient(int posX, int posY)
{
    char tempCIN[10];
    
    ClientsNombre++;
    Client = (CLIENT*) realloc(Client, ClientsNombre * sizeof(CLIENT));

    gotoxy(posX, posY);

    if(Client == NULL)
    {
        puts("Reallocation Erreur!");
        return;
    }

    do
    {
        gotoxy(posX, wherey());

        printf(" CIN   : ");
        fflush(stdin);
        gets(tempCIN);

        //if the user enter "enter key" as input
        if(strcmp(tempCIN, "\0") == 0)
        {
            gotoxy(wherex(), wherey()-1);
            continue;
        }
        
        if(Client_Exist(tempCIN) != -1)
        {
            gotoxy(posX, wherey());
            puts("Le CIN existe deja");

            Sleep(1000);
            gotoxy(posX, wherey()-1);
            printf("                                   ");
            gotoxy(posX, wherey()-1);
            printf("                                   ");
        }
        else
        {
            strcpy((Client+ClientsNombre-1)->CIN, tempCIN);
            break;
        }
    }while(1);
    
    do
    {
        gotoxy(posX, wherey());
        printf(" Nom   : ");
        fflush(stdin);
        gets((Client+ClientsNombre-1)->Nom);

        //if the user enter "enter key" as input
        if(strcmp((Client+ClientsNombre-1)->Nom, "\0") == 0)
        {
            gotoxy(wherex(), wherey()-1);
        }
        else
            break;
    }while(1);

    do
    {
        gotoxy(posX, wherey());
        printf(" Prenom: ");
        fflush(stdin);
        gets((Client+ClientsNombre-1)->Prenom);

        //if the user enter "enter key" as input
        if(strcmp((Client+ClientsNombre-1)->Prenom, "\0") == 0)
        {
            gotoxy(wherex(), wherey()-1);
        }
        else
            break;
    }while(1);

    do
    {
        gotoxy(posX, wherey());
        printf(" Ville : ");
        fflush(stdin);
        gets((Client+ClientsNombre-1)->Ville);

        //if the user enter "enter key" as input
        if(strcmp((Client+ClientsNombre-1)->Ville, "\0") == 0)
        {
            gotoxy(wherex(), wherey()-1);
        }
        else
            break;
    }while(1);
    
    gotoxy(posX, wherey());
    printf(" Date de naissance (dd/mm/aaaa): ");
    fflush(stdin);
    scanf("%d/%d/%d",&(Client+ClientsNombre-1)->DateDeNaissance.jour, &(Client+ClientsNombre-1)->DateDeNaissance.mois, &(Client+ClientsNombre-1)->DateDeNaissance.annee);
}
void CreationCompte(int posX, int posY)
{
    int tempNumero;
    char tempCIN[10];
    int client_index;

    ComptesNombre++;
    Compte = (COMPTEBANCAIRE*) realloc(Compte, ComptesNombre * sizeof(COMPTEBANCAIRE));

    do
    {
        gotoxy(posX, posY);

        printf(" Numero du compte : ");
        scanf("%d",&tempNumero);

        if(Compte_Exist(tempNumero) != -1)
        {
            gotoxy(posX, wherey());
            puts("Le numero du compte existe deja");
        }
        else
            break;
    }while(1);

    (Compte + ComptesNombre - 1)->NumeroDuCompte = tempNumero;

    gotoxy(posX, wherey());
    printf(" Date de creation (dd/mm/aaaa): ");
    fflush(stdin);
    scanf("%d/%d/%d",&(Compte + ComptesNombre - 1)->DateDeCreation.jour, &(Compte + ComptesNombre - 1)->DateDeCreation.mois, &(Compte + ComptesNombre - 1)->DateDeCreation.annee);
    
    do
    {
        gotoxy(posX, wherey());
        printf(" Localisation : ");
        fflush(stdin);
        gets((Compte + ComptesNombre - 1)->Localisation);

        //if the user enter "enter key" as input
        if(strcmp((Compte + ComptesNombre - 1)->Localisation, "\0") == 0)
        {
            gotoxy(wherex(), wherey()-1);
        }
        else
            break;
    }while(1);

    do
    {
        do
        {
            gotoxy(posX, wherey());
            printf(" Proprietaire : ");
            fflush(stdin);
            gets(tempCIN);

            //if the user enter "enter key" as input
            if(strcmp(tempCIN, "\0") == 0)
            {
                gotoxy(wherex(), wherey()-1);
            }
            else
                break;
        }while(1);
        
        client_index = Client_Exist(tempCIN);
        if(client_index != -1)
        {
            if(Client_Avoir_Compte(tempCIN) == -1)
                break;
            else
            {
                gotoxy(posX, wherey());
                puts("le client a deja un compte bancaire");
            }
        }
        else
        {
            gotoxy(posX, wherey());
            puts("Client n'existe pas");
        }

        Sleep(1000);
        gotoxy(posX, wherey()-1);
        printf("                                   ");
        gotoxy(posX, wherey()-1);
        printf("                                   ");

    }while(1);

    (Compte + ComptesNombre - 1)->Proprietaire = *(Client + client_index);

    //Initialisation
    //Solde Actuel
    (Compte + ComptesNombre - 1)->SoldeActuel = 0;
    //Ancien Solde
    (Compte + ComptesNombre - 1)->AncienSolde = 0;
    //Derniere Operation
    strcpy((Compte + ComptesNombre - 1)->DerniereOperation, "~");
}
void AfficherClient(int _index, int posX, int posY)
{
    gotoxy(posX, wherey());
    printf(" CIN   : %s\n", (Client + _index)->CIN);
    gotoxy(posX, wherey());
    printf(" Nom   : %s\n", (Client + _index)->Nom);
    gotoxy(posX, wherey());
    printf(" Prenom: %s\n", (Client + _index)->Prenom);
    gotoxy(posX, wherey());
    printf(" Ville : %s\n", (Client + _index)->Ville);
    gotoxy(posX, wherey());
    printf(" Date de naissance: %d/%d/%d\n", (Client + _index)->DateDeNaissance.jour, (Client + _index)->DateDeNaissance.mois, (Client + _index)->DateDeNaissance.annee);

}
void DetailsClient(char *_CIN, int posX, int posY)
{
    int clientIndex = Client_Exist(_CIN);

    gotoxy(posX, posY);
    if(clientIndex == -1)
    {
        puts("Erreur! Client n'existe pas");
        return;
    }

    AfficherClient(clientIndex, posX, posY);
}
void ListerClients(int posX, int posY)
{
    int i;

    gotoxy(posX, posY);

    if(ClientsNombre == 0)
    {
        return;
    }

    for(i=0; i<ClientsNombre; i++)
    {
        printf("Client %d :\n",i + 1);
        AfficherClient(i, posX, posY);
        puts("");

        gotoxy(posX, wherey());
    }
}
void AfficherCompte(int _index, int posX, int posY)
{
    gotoxy(posX, wherey());
    printf("Numero du compte  : %d\n", (Compte + _index)->NumeroDuCompte);
    gotoxy(posX, wherey());
    printf("Date de Creation  : %d/%d/%d\n", (Compte + _index)->DateDeCreation.jour, (Compte + _index)->DateDeCreation.mois, (Compte + _index)->DateDeCreation.annee);
    gotoxy(posX, wherey());
    printf("Localisation      : %s\n", (Compte + _index)->Localisation);
    gotoxy(posX, wherey());
    printf("Proprietaire      : \n"); AfficherClient(Client_Exist((Compte + _index)->Proprietaire.CIN), posX, posY);
    gotoxy(posX, wherey());
    printf("Solde Actuel      : %.2f\n", (Compte + _index)->SoldeActuel);
    gotoxy(posX, wherey());
    printf("Ancien Solde      : %.2f\n", (Compte + _index)->AncienSolde);
    gotoxy(posX, wherey());
    printf("Derniere Operation: %s\n", (Compte + _index)->DerniereOperation);
}
void DetailsCompte(int _numeroDuCompte, int posX, int posY)
{
    int compteIndex = Compte_Exist(_numeroDuCompte);

    gotoxy(posX, posY);
    if(compteIndex == -1)
    {
        puts("Erreur! Compte n'existe pas");
        return;
    }

    AfficherCompte(compteIndex, posX, posY);
}
void ListerComptes(int posX, int posY)
{
    int i;

    gotoxy(posX, posY);

    if(ComptesNombre == 0)
    {
        return;
    }

    for(i=0; i<ComptesNombre; i++)
    {
        printf("Compte %d :\n", i + 1);
        AfficherCompte(i, posX, posY);
        puts("");

        gotoxy(posX, wherey());
    }
}
int Retrait(int _numeroDuCompte, int posX, int posY)
{
    int index_Compte;
    float _montant, _solde;

    gotoxy(posX, posY+2);

    index_Compte = Compte_Exist(_numeroDuCompte);
    if(index_Compte == -1)
    {
        printf("Compte %d n'existe pas\n", _numeroDuCompte);
        return -1;
    }
    
    printf("Donner montant : ");
    scanf("%f",&_montant);

    _solde = (Compte + index_Compte)->SoldeActuel;
    if(_solde >= _montant)
    {
        (Compte + index_Compte)->AncienSolde = (Compte + index_Compte)->SoldeActuel;
        (Compte + index_Compte)->SoldeActuel -= _montant;
        strcpy((Compte + index_Compte)->DerniereOperation, "Retrait");
    }
    else
    {
        gotoxy(posX, wherey());
        puts("Votre solde est insuffisant");

        return -1;
    }

    return 1;
}
int Depot(int _numeroDuCompte, int posX, int posY)
{
    int index_Compte;
    float _montant;

    gotoxy(posX, posY+2);

    index_Compte = Compte_Exist(_numeroDuCompte);
    if(index_Compte == -1)
    {
        printf("Compte %d n'existe pas\n", _numeroDuCompte);
        return -1;
    }

    printf("Donner montant : ");
    scanf("%f",&_montant);

    (Compte + index_Compte)->AncienSolde = (Compte + index_Compte)->SoldeActuel;
    (Compte + index_Compte)->SoldeActuel += _montant;
    strcpy((Compte + index_Compte)->DerniereOperation, "Depot");

    return 1;
}
int Virement(int _numeroDuCompte1, int _numeroDuCompte2, int posX, int posY)
{
    int index_Compte1;
    int index_Compte2;
    float _montant, _solde;

    gotoxy(posX, posY+3);

    index_Compte1 = Compte_Exist(_numeroDuCompte1);
    if(index_Compte1 == -1)
    {
        printf("Compte %d n'existe pas\n", _numeroDuCompte1);
        return -1;
    }

    index_Compte2 = Compte_Exist(_numeroDuCompte2);
    if(index_Compte2 == -1)
    {
        printf("Compte %d n'existe pas\n", _numeroDuCompte2);
        return -1;
    }

    printf("Donner montant : ");
    scanf("%f",&_montant);

    _solde = (Compte + index_Compte1)->SoldeActuel;

    if(_solde >= _montant)
    {
        //Compte initial
        (Compte + index_Compte1)->AncienSolde = (Compte + index_Compte1)->SoldeActuel;
        (Compte + index_Compte1)->SoldeActuel -= _montant;
        strcpy((Compte + index_Compte1)->DerniereOperation, "Virement");
        //Compte a
        (Compte + index_Compte2)->AncienSolde = (Compte + index_Compte2)->SoldeActuel;
        (Compte + index_Compte2)->SoldeActuel += _montant;
        strcpy((Compte + index_Compte2)->DerniereOperation, "Virement");
    }
    else
    {
        gotoxy(posX, wherey());
        puts("Votre solde est insuffisant");

        return -1;
    }

    return 1;
}
int SupprimerClient(char *_CIN)
{
    int i, index_Compte, index_Client = Client_Exist(_CIN);

    if(index_Client == -1)
    {
        return -1;
    }

    index_Compte = Client_Avoir_Compte(_CIN);

    if(index_Compte != -1)
    {
        //Cloturer Compte
        if(CloturerCompte(index_Compte) == -1)
            return -1;
    }
    
    for(i = index_Client; i < ClientsNombre - 1; i++)
    {
        *(Client + i) = *(Client + i + 1);
    }

    ClientsNombre--;
    Client = (CLIENT*) realloc(Client, ClientsNombre * sizeof(CLIENT));

    return 1;
}
int CloturerCompte(int index_Compte)
{
    int i;

    if(index_Compte == -1)
    {
        return -1;
    }

    for(i = index_Compte; i < ComptesNombre - 1; i++)
    {
        *(Compte + i) = *(Compte + i + 1);
    }

    ComptesNombre--;
    Compte = (COMPTEBANCAIRE*) realloc(Compte, ComptesNombre * sizeof(COMPTEBANCAIRE));

    return 1;
}
#endif