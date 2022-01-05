#ifndef _INC_BankUI
#define _INC_BankUI

void rect(int width, int height, int x, int y)
{
    int i,j;

    gotoxy(x,y);
    //Top
    printf("\xDA");
    for(i=0; i<width; i++)
        printf("\xC4");
    printf("\xBF\n");

    gotoxy(x,wherey());
    //Left and Right
    for(i=0; i<height; i++)
    {
        printf("\xB3");
        for(j=0; j<width; j++)
            printf(" ");
        printf("\xB3\n");

        gotoxy(x,wherey());
    }

    //Bottom
    printf("\xC0");
    for(i=0; i<width; i++)
        printf("\xC4");
    printf("\xD9");
}
#pragma region ASCII_ART
void BankTitle(int x, int y)
{
    gotoxy(x,y);
    puts("  ______      ____          _   _ _  __");
    gotoxy(x,++y);
    puts(" |  ____|    |  _ \\   /\\   | \\ | | |/ /");
    gotoxy(x,++y);
    puts(" | |__ ______| |_) | /  \\  |  \\| | ' / ");
    gotoxy(x,++y);
    puts(" |  __|______|  _ < / /\\ \\ | . ` |  <  ");
    gotoxy(x,++y);
    puts(" | |____     | |_) / ____ \\| |\\  | . \\ ");
    gotoxy(x,++y);
    puts(" |______|    |____/_/    \\_\\_| \\_|_|\\_\\");

}
void BankArt(int x, int y)
{
    gotoxy(x,y);
    puts("         _._._                       _._._");
    gotoxy(x,++y);
    puts("        _|   |_                     _|   |_");
    gotoxy(x,++y);
    puts("        | ... |_._._._._._._._._._._| ... |");
    gotoxy(x,++y);
    puts("        | ||| |  o    E-BANK     o  | ||| |");
    gotoxy(x,++y);
    puts("        | \"\"\" |  \"\"\"    \"\"\"    \"\"\"  | \"\"\" |");
    gotoxy(x,++y);
    puts("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())");
    gotoxy(x,++y);
    puts("  (())) |     |---------------------|     | (()))");
    gotoxy(x,++y);
    puts(" (())())| \"\"\" |  \"\"\"    \"\"\"    \"\"\"  | \"\"\" |(())())");
    gotoxy(x,++y);
    puts(" (()))()|[-|-]|  :::   .-\"-.   :::  |[-|-]|(()))()");
    gotoxy(x,++y);
    puts(" ()))(()|     | |~|~|  |_|_|  |~|~| |     |()))(()");
    gotoxy(x,++y);
    puts("    ||  |_____|_|_|_|__|_|_|__|_|_|_|_____|  ||");
}
void AjoutClientTitle(int x, int y)
{
    gotoxy(x,y);
    puts("           _             _                                 _ _            _   ");
    gotoxy(x,++y);
    puts("     /\\   (_)           | |                               | (_)          | |  ");
    gotoxy(x,++y);
    puts("    /  \\   _  ___  _   _| |_ ___ _ __   _   _ _ __     ___| |_  ___ _ __ | |_ ");
    gotoxy(x,++y);
    puts("   / /\\ \\ | |/ _ \\| | | | __/ _ \\ '__| | | | | '_ \\   / __| | |/ _ \\ '_ \\| __|");
    gotoxy(x,++y);
    puts("  / ____ \\| | (_) | |_| | ||  __/ |    | |_| | | | | | (__| | |  __/ | | | |_ ");
    gotoxy(x,++y);
    puts(" /_/    \\_\\ |\\___/ \\__,_|\\__\\___|_|     \\__,_|_| |_|  \\___|_|_|\\___|_| |_|\\__|");
    gotoxy(x,++y);
    puts("         _/ |                                                                 ");
    gotoxy(x,++y);
    puts("        |__/                                                                  ");
}
void CreerCompteTitle(int x, int y)
{
    gotoxy(x,y);
    puts("   _____       __                            _____                      _         ");
    gotoxy(x,++y);
    puts("  / ____|     /_/                           / ____|                    | |       ");
    gotoxy(x,++y);
    puts(" | |     _ __ ___  ___ _ __   _   _ _ __   | |     ___  _ __ ___  _ __ | |_ ___ ");
    gotoxy(x,++y);
    puts(" | |    | '__/ _ \\/ _ \\ '__| | | | | '_ \\  | |    / _ \\| '_ ` _ \\| '_ \\| __/ _ \\");
    gotoxy(x,++y);
    puts(" | |____| | |  __/  __/ |    | |_| | | | | | |___| (_) | | | | | | |_) | ||  __/ ");
    gotoxy(x,++y);
    puts("  \\_____|_|  \\___|\\___|_|     \\__,_|_| |_|  \\_____\\___/|_| |_| |_| .__/ \\__\\___| ");
    gotoxy(x,++y);
    puts("                                                                 | |                      ");
    gotoxy(x,++y);
    puts("                                                                 |_|                      ");
}
void DepotTitle(int x, int y)
{
    gotoxy(x,y);
    puts("  _____    __        //\\  _  ");
    gotoxy(x,++y);
    puts(" |  __ \\  /_/       |/ \\|| | ");
    gotoxy(x,++y);
    puts(" | |  | | ___ _ __   ___ | |_ ");
    gotoxy(x,++y);
    puts(" | |  | |/ _ \\ '_ \\ / _ \\| __|");
    gotoxy(x,++y);
    puts(" | |__| |  __/ |_) | (_) | |_ ");
    gotoxy(x,++y);
    puts(" |_____/ \\___| .__/ \\___/ \\__|");
    gotoxy(x,++y);
    puts("             | |              ");
    gotoxy(x,++y);
    puts("             |_|              ");
}
void RetraitTitle(int x, int y)
{
    gotoxy(x,y);
    puts("  _____      _             _ _   ");
    gotoxy(x,++y);
    puts(" |  __ \\    | |           (_) |  ");
    gotoxy(x,++y);
    puts(" | |__) |___| |_ _ __ __ _ _| |_ ");
    gotoxy(x,++y);
    puts(" |  _  // _ \\ __| '__/ _` | | __|");
    gotoxy(x,++y);
    puts(" | | \\ \\  __/ |_| | | (_| | | |_ ");
    gotoxy(x,++y);
    puts(" |_|  \\_\\___|\\__|_|  \\__,_|_|\\__|");
}
void VirementTitle(int x, int y)
{
    gotoxy(x,y);
    puts(" __      ___                               _   ");
    gotoxy(x,++y);
    puts(" \\ \\    / (_)                             | |  ");
    gotoxy(x,++y);
    puts("  \\ \\  / / _ _ __ ___ _ __ ___   ___ _ __ | |_ ");
    gotoxy(x,++y);
    puts("   \\ \\/ / | | '__/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|");
    gotoxy(x,++y);
    puts("    \\  /  | | | |  __/ | | | | |  __/ | | | |_ ");
    gotoxy(x,++y);
    puts("     \\/   |_|_|  \\___|_| |_| |_|\\___|_| |_|\\__|");
}
void SupprimerClientTitle(int x, int y)
{
    gotoxy(x,y);
    puts("  ___                    _                                _ _         _   ");
    gotoxy(x,++y);
    puts(" / __|_  _ _ __ _ __ _ _(_)_ __  ___ _ _   _  _ _ _    __| (_)___ _ _| |_ ");
    gotoxy(x,++y);
    puts(" \\__ \\ || | '_ \\ '_ \\ '_| | '  \\/ -_) '_| | || | ' \\  / _| | / -_) ' \\  _|");
    gotoxy(x,++y);
    puts(" |___/\\_,_| .__/ .__/_| |_|_|_|_\\___|_|    \\_,_|_||_| \\__|_|_\\___|_||_\\__|");
    gotoxy(x,++y);
    puts("          |_|  |_|                                                        ");
}
void CloturerCompteTitle(int x, int y)
{
    gotoxy(x,y);
    puts("   ___ _ //\\ _                                                    _       ");
    gotoxy(x,++y);
    puts("  / __| |/_\\| |_ _  _ _ _ ___ _ _   _  _ _ _    __ ___ _ __  _ __| |_ ___ ");
    gotoxy(x,++y);
    puts(" | (__| / _ \\  _| || | '_/ -_) '_| | || | ' \\  / _/ _ \\ '  \\| '_ \\  _/ -_)");
    gotoxy(x,++y);
    puts("  \\___|_\\___/\\__|\\_,_|_| \\___|_|    \\_,_|_||_| \\__\\___/_|_|_| .__/\\__\\___|");
    gotoxy(x,++y);
    puts("                                                            |_|           ");
}
void DetailsClientTitle(int x, int y)
{
    gotoxy(x,y);
    puts("  ___       __                    _   _               _ _               _ _         _   ");
    gotoxy(x,++y);
    puts(" |_ _|_ _  / _|___ _ _ _ __  __ _| |_(_)___ _ _    __| ( )  _ _ _    __| (_)___ _ _| |_ ");
    gotoxy(x,++y);
    puts("  | || ' \\|  _/ _ \\ '_| '  \\/ _` |  _| / _ \\ ' \\  / _` |/ || | ' \\  / _| | / -_) ' \\  _|");
    gotoxy(x,++y);
    puts(" |___|_||_|_| \\___/_| |_|_|_\\__,_|\\__|_\\___/_||_| \\__,_| \\_,_|_||_| \\__|_|_\\___|_||_\\__|");
}
void DetailsCompteTitle(int x, int y)
{
    gotoxy(x,y);
    puts("  ___       __                    _   _               _ _                              _       ");
    gotoxy(x,++y);
    puts(" |_ _|_ _  / _|___ _ _ _ __  __ _| |_(_)___ _ _    __| ( )  _ _ _    __ ___ _ __  _ __| |_ ___ ");
    gotoxy(x,++y);
    puts("  | || ' \\|  _/ _ \\ '_| '  \\/ _` |  _| / _ \\ ' \\  / _` |/ || | ' \\  / _/ _ \\ '  \\| '_ \\  _/ -_)");
    gotoxy(x,++y);
    puts(" |___|_||_|_| \\___/_| |_|_|_\\__,_|\\__|_\\___/_||_| \\__,_| \\_,_|_||_| \\__\\___/_|_|_| .__/\\__\\___|");
    gotoxy(x,++y);
    puts("                                                                                 |_|           ");
}
void ListerClientTitle(int x, int y)
{
    gotoxy(x,y);
    puts("  ___       __                    _   _               _             _ _         _      ");
    gotoxy(x,++y);
    puts(" |_ _|_ _  / _|___ _ _ _ __  __ _| |_(_)___ _ _    __| |___ ___  __| (_)___ _ _| |_ ___");
    gotoxy(x,++y);
    puts("  | || ' \\|  _/ _ \\ '_| '  \\/ _` |  _| / _ \\ ' \\  / _` / -_|_-< / _| | / -_) ' \\  _(_-<");
    gotoxy(x,++y);
    puts(" |___|_||_|_| \\___/_| |_|_|_\\__,_|\\__|_\\___/_||_| \\__,_\\___/__/ \\__|_|_\\___|_||_\\__/__/");
}
void ListerCompteTitle(int x, int y)
{
    gotoxy(x,y);
    puts("  ___       __                    _   _               _                            _          ");
    gotoxy(x,++y);
    puts(" |_ _|_ _  / _|___ _ _ _ __  __ _| |_(_)___ _ _    __| |___ ___  __ ___ _ __  _ __| |_ ___ ___");
    gotoxy(x,++y);
    puts("  | || ' \\|  _/ _ \\ '_| '  \\/ _` |  _| / _ \\ ' \\  / _` / -_|_-< / _/ _ \\ '  \\| '_ \\  _/ -_|_-<");
    gotoxy(x,++y);
    puts(" |___|_||_|_| \\___/_| |_|_|_\\__,_|\\__|_\\___/_||_| \\__,_\\___/__/ \\__\\___/_|_|_| .__/\\__\\___/__/");
    gotoxy(x,++y);
    puts("                                                                             |_|              ");
}
#pragma endregion

int Menu(int x, int y)
{
    int choix, erreur;

    do
    {
        gotoxy(x,y);
        puts(" 1. Ajouter un client");
        gotoxy(x,wherey());
        puts(" 2. Ajouter un compte bancaire");
        gotoxy(x,wherey());
        puts(" 3. Depot");
        gotoxy(x,wherey());
        puts(" 4. Retrait");
        gotoxy(x,wherey());
        puts(" 5. Virement");
        gotoxy(x,wherey());
        puts(" 6. Supprimer un client");
        gotoxy(x,wherey());
        puts(" 7. Cloturer un compte");
        gotoxy(x,wherey());
        puts(" 8. Information d'un client");
        gotoxy(x,wherey());
        puts(" 9. Information d'un compte");
        gotoxy(x,wherey());
        puts("10. Information des clients");
        gotoxy(x,wherey());
        puts("11. Information des comptes");
        gotoxy(x,wherey());
        puts(" 0. Quiter\n");

        gotoxy(x,wherey());
        printf(">> ");
        fflush(stdin);
        erreur = scanf("%d",&choix);

        if(choix<0 || choix>11 || erreur == 0)
        {
            //delete entered choice
            gotoxy(wherex(),wherey()-1);
            puts("     ");

            gotoxy(x,y+14);
            puts("Choix Incorrect");
            Sleep(1000);
            
            gotoxy(x,wherey()-1);
            puts("               ");

            gotoxy(x,wherey()-2);
            printf(">>                                            ");
        }
        else
            return choix;
    }while(1);
}

int Home()
{
    rect(113, 7, 6, 1);

    BankTitle(44, 2);

    rect(113, 18, 6, 12);

    rect(50, 16, 8, 13);

    BankArt(63, 14);

    return Menu(13, 14);   
}

void AjoutClientScene()
{
    rect(113, 9, 6, 1);

    AjoutClientTitle(25, 2);

    rect(113, 18, 6, 12);
}

void CreerCompteScene()
{
    rect(113, 9, 6, 1);

    CreerCompteTitle(23, 2);

    rect(113, 18, 6, 12);
}

void DepotScene()
{
    rect(113, 8, 6, 1);

    DepotTitle(50, 2);

    rect(113, 18, 6, 12);
}

void RetraitScene()
{
    rect(113, 9, 6, 1);

    RetraitTitle(50, 2);

    rect(113, 18, 6, 12);
}

void VirementScene()
{
    rect(113, 9, 6, 1);

    VirementTitle(40, 2);

    rect(113, 18, 6, 12);
}

void SupprimerClientScene()
{
    rect(113, 5, 6, 1);

    SupprimerClientTitle(30, 2);

    rect(113, 18, 6, 12);
}

void CloturerCompteScene()
{
    rect(113, 5, 6, 1);

    CloturerCompteTitle(25, 2);

    rect(113, 18, 6, 12);
}

void DetailsClientScene()
{
    rect(113, 5, 6, 1);

    DetailsClientTitle(15, 2);

    rect(113, 18, 6, 12);
}

void DetailsCompteScene()
{
    rect(113, 5, 6, 1);

    DetailsCompteTitle(15, 2);

    rect(113, 18, 6, 12);
}

void ListerClientScene()
{
    rect(113, 5, 6, 1);

    ListerClientTitle(15, 2);
}

void ListerCompteScene()
{
    rect(113, 5, 6, 1);

    ListerCompteTitle(15, 2);
}
#endif