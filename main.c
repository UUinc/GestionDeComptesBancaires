/*
▁ ▂ ▃ ▄ ▅ ▆ ▇ ▌　Projet développé par  ▌ ▇ ▆ ▅ ▄ ▃ ▂ ▁

                     LAZREK YAHYA
                    ZEGDAOUI NOUFEL
                 AHMED-LAAZIZ ZAKARIAE

*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Console.h"
#include "GestionDeComptesBancaires.h"
#include "BankUI.h"
#include "Fichier.h"

int main()
{
    int choix;
    char cin[10];
    int numeroCompte, numeroCompteReceveur;

    //Maximize Window
    MaximizeOutputWindow();
    //Main Background Color
    system("color 70");

    //Font size
    FontSize(23);

    //Load Informations
    LoadClient();
    LoadCompte();

    //boucle principale
    while(1)
    {
        //Effacer la console
        system("cls");

        choix = Home();

        //Effacer la console
        system("cls");

        //Menu
        switch(choix)
        {   
            case 1:
                AjoutClientScene();
                AjoutClient(50, 15);

                gotoxy(50, wherey()+2);
                puts("Effectu\x82 avec succ\x8As");
                
                SaveClient();
                break;
            case 2:
                CreerCompteScene();
                CreationCompte(50, 15);

                gotoxy(50, wherey()+2);
                puts("Effectu\x82 avec succ\x8As");

                SaveCompte();
                break;
            case 3:
                DepotScene();

                gotoxy(52, 15);
                printf("Donner le numero de compte: ");
                scanf("%d",&numeroCompte);

                if(Depot(numeroCompte, 56, 15) == -1)
                {
                    gotoxy(58, wherey()+2);
                    puts("op\x82ration rat\x82""e");
                }
                else
                {
                    gotoxy(50, wherey()+2);
                    puts("op\x82ration r\x82""alis\x82""e avec succ\x8As");
                }

                SaveCompte();
                break;
            case 4:
                RetraitScene();

                gotoxy(52, 15);
                printf("Donner le numero de compte: ");
                scanf("%d",&numeroCompte);

                if(Retrait(numeroCompte, 56, 15) == -1)
                {
                    gotoxy(58, wherey()+2);
                    puts("op\x82ration rat\x82""e");
                }
                else
                {
                    gotoxy(50, wherey()+2);
                    puts("op\x82ration r\x82""alis\x82""e avec succ\x8As");
                }

                SaveCompte();
                break;
            case 5:
                VirementScene();

                gotoxy(44, 15);
                printf("Donner le numero de compte expediteur: ");
                scanf("%d",&numeroCompte);

                gotoxy(46, wherey());
                printf("Donner le numero de compte receveur: ");
                scanf("%d",&numeroCompteReceveur);

                if(Virement(numeroCompte, numeroCompteReceveur, 56, 15) == -1)
                {
                    gotoxy(58, wherey()+2);
                    puts("op\x82ration rat\x82""e");
                }
                else
                {
                    gotoxy(50, wherey()+2);
                    puts("op\x82ration r\x82""alis\x82""e avec succ\x8As");
                }

                SaveCompte();
                break;
            case 6:
                SupprimerClientScene();

                gotoxy(56, 15);
                printf("Donner le CIN de client: ");
                fflush(stdin);
                gets(cin);

                if(SupprimerClient(cin) == -1)
                {
                    gotoxy(58, wherey()+2);
                    puts("client n'existe pas");
                }
                else
                {
                    gotoxy(50, wherey()+2);
                    puts("client a \x82t\x82 supprim\x82 avec succ\x8As");
                }

                SaveClient();
                break;
            case 7:
                CloturerCompteScene();

                gotoxy(54, 15);
                printf("Donner le numero de compte: ");
                scanf("%d",&numeroCompte);

                if(CloturerCompte(Compte_Exist(numeroCompte)) == -1)
                {
                    gotoxy(58, wherey()+2);
                    puts("compte n'existe pas");
                }
                else
                {
                    gotoxy(50, wherey()+2);
                    puts("compte a \x82t\x82 cl\x93tur\x82 avec succ\x8As");
                }

                SaveCompte();
                break;
            case 8:
                DetailsClientScene();

                gotoxy(50, 15);
                printf("Donner le CIN de client: ");
                fflush(stdin);
                gets(cin);

                DetailsClient(cin, 50, wherey()+1);
                break;
            case 9:
                DetailsCompteScene();

                gotoxy(50, 15);
                printf("Donner le numero de compte: ");
                scanf("%d",&numeroCompte);

                DetailsCompte(numeroCompte, 50, wherey()+1);
                break;
            case 10:
                ListerClientScene();
                rect(113, (ClientsNombre * 8), 6, 12);

                gotoxy(50, 15);
                ListerClients(50, 15);
                break;
            case 11:
                ListerCompteScene();
                rect(113, (ComptesNombre * 18), 6, 12);

                gotoxy(50, 15);
                ListerComptes(50, 15);
                break;
            default:
                //Quitter le programme avec success
                exit(0);
        }
        gotoxy(36, 13);
        puts("\xB3 Cliquer sur clavier pour revenir a menu principale \xB3");
        gotoxy(36, 14);
        puts("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
        getch();
    }

    return 0;
}