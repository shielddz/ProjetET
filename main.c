#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"
#include "listeLin.h"
#include "listeLinBi.h"
#include "listeLinBiC.h"
#include "pile.h"
#include "file.h"

int main()
{
    int choiceLoad, choiceStruct, choiceMenu, choiceSubMenu;
    int save = 1, quit = 0;
    int pos, occ, confirmation, ctrlz = 0, fileset = 0;

    //fichier
    FILE *fichier = NULL;

    //declaration du texte
    texte myText;
    char *s, filepath[50];
    memset(filepath, '\0', 50);

    //choisir la structure
    choiceStruct = chooseStruct();

    //declarer la stucture correspondante a choice
    pile maPile;
    file maFile;
    listeLin *maListe = NULL;
    listeLinBi *maListeBi = NULL;
    listeLinBi *maListeBiC = NULL;

    //remplissage du premier texte
    loading:
    cls();
    choiceLoad = chooseMethod();
    myText = creer();
    if(choiceLoad !=1 ){
        s = (char *) malloc(40 * sizeof(char));
        memset(s, '\0', 40);
        printf("Entrez un texte(max 40): ");
        fflush(stdin);
        gets(s);
        ajouterChaine(&myText, s);
        save = 0;
        cls();
    }else{
        printf("Entrez la destination du fichier: ");
        fflush(stdin);
        gets(filepath);
        fichier = fopen(filepath, "r");
        s = (char *) malloc(100 * sizeof(char));
        memset(s, '\0', 100);
        if(fichier != NULL){
            fgets(s, 100, fichier);
            ajouterChaine(&myText, s);
            fclose(fichier);
            fileset = 1;
        }else{
            cls();
            fclose(fichier);
            printf("Erreur.\n");
            goto loading;
        }
        cls();
    }


    //copier dans la structure.
    switch(choiceStruct){
    case 1:
        maPile = initPile();
        empiler(&maPile, &myText);
        break;
    case 2:
        maFile = initFile();
        enfiler(&maFile, &myText);
        break;
    case 3:
        maListe = ajouterFinListeLin(maListe, &myText);
        break;
    case 4:
        maListeBi = ajouterFinListeLinBi(maListeBi, &myText);
        break;
    case 5:
        maListeBiC = ajouterFinListeLinBiC(maListeBiC, &myText);
        afficherListeLinBiC(maListeBiC);
        break;
    }

    //liberer myText apres chaque ecriture d'un nouveau texte
    free(s);
    liberer(&myText);
    myText.chaine = (char *) malloc(16 * sizeof(char));
    myText.capa = 16;
    myText.longeur = 0;






    do{
        menu :
        choiceMenu = chooseMenu();
        cls();
        switch(choiceMenu){
        //affichage du texte
        case 1:
            switch(choiceStruct){
            case 1:
                printf("'%s'.\n(Sa taille : %d)\n", SommetPile(&maPile).chaine, SommetPile(&maPile).longeur);
                break;
            case 2:
                printf("'%s'.\n(Sa taille : %d)\n", maFile.tab[maFile.taille+maFile.debut-1%10].chaine, maFile.tab[maFile.taille+maFile.debut-1%10].longeur);
                break;
            case 3:
                printf("'%s'.\n(Sa taille : %d)\n", maListe->monTexte.chaine, maListe->monTexte.longeur);
                break;
            case 4:
                printf("'%s'.\n(Sa taille : %d)\n", maListeBi->monTexte.chaine, maListeBi->monTexte.longeur);
                break;
            case 5:
                printf("'%s'.\n(Sa taille : %d)\n", maListeBiC->monTexte.chaine, maListeBiC->monTexte.longeur);
                break;
            }
            break;
        //Inserer une chaine
        case 2:
            pos = 1;
            cls();
            choiceSubMenu = chooseSubMenu2();
            if(choiceSubMenu<1 || choiceSubMenu>2){
                cls();
                printf("Erreur!\n");
                goto menu;
            }
            switch(choiceStruct){
            case 1:
                printf("'%s'.\n(Sa taille : %d)\n", SommetPile(&maPile).chaine, SommetPile(&maPile).longeur);
                break;
            case 2:
                printf("'%s'.\n(Sa taille : %d)\n", maFile.tab[maFile.taille+maFile.debut-1%10].chaine, maFile.tab[maFile.taille+maFile.debut-1%10].longeur);
                break;
            case 3:
                printf("'%s'.\n(Sa taille : %d)\n", maListe->monTexte.chaine, maListe->monTexte.longeur);
                break;
            case 4:
                printf("'%s'.\n(Sa taille : %d)\n", maListeBi->monTexte.chaine, maListeBi->monTexte.longeur);
                break;
            case 5:
                printf("'%s'.\n(Sa taille : %d)\n", maListeBiC->monTexte.chaine, maListeBiC->monTexte.longeur);
                break;
            }
            printf("Tapez la chaine a inserer dans le texte(max 40): ");
            myText = creer();
            s = (char *) malloc(40 * sizeof(char));
            memset(s, '\0', 40);
            fflush(stdin);
            gets(s);
            switch(choiceStruct){
            case 1:
                ajouterChaine(&myText, SommetPile(&maPile).chaine);
                break;
            case 2:
                ajouterChaine(&myText, maFile.tab[maFile.taille+maFile.debut-1%10].chaine);
                break;
            case 3:
                ajouterChaine(&myText, maListe->monTexte.chaine);
                break;
            case 4:
                ajouterChaine(&myText, maListeBi->monTexte.chaine);
                break;
            case 5:
                ajouterChaine(&myText, maListeBiC->monTexte.chaine);
                break;
            }

            switch(choiceSubMenu){
            case 1:
                printf("\nEntrez la position dans laquelle vous voulez inserer la chaine: ");
                scanf("%d", &pos);
            case 2:
                insererChaine(&myText, s, pos);
                switch(choiceStruct){
                case 1:
                    empiler(&maPile, &myText);
                    break;
                case 2:
                    enfiler(&maFile, &myText);
                    break;
                case 3:
                    maListe = ajouterFinListeLin(maListe, &myText);
                    break;
                case 4:
                    maListeBi = ajouterFinListeLinBi(maListeBi, &myText);
                    break;
                case 5:
                    maListeBiC = ajouterFinListeLinBiC(maListeBiC, &myText);
                    break;
                }
                free(s);
                liberer(&myText);
                myText.chaine = (char *) malloc(16 * sizeof(char));
                myText.capa = 16;
                myText.longeur = 0;
                break;
            }
            cls();
            if(ctrlz < 10){
                ctrlz++;
            }
            save = 0;
            printf("Tache executee.\n");
            break;
        //chercher une sous chaine
        case 3:
            cls();
            choiceSubMenu = chooseSubMenu3();
            if(choiceSubMenu<1 || choiceSubMenu>2){
                cls();
                printf("Erreur!\n");
                goto menu;
            }
            printf("Tapez la chaine a chercher dans le texte(max 40): ");
            myText = creer();
            s = (char *) malloc(40 * sizeof(char));
            memset(s, '\0', 40);
            fflush(stdin);
            gets(s);
            switch(choiceSubMenu){
            case 1:
                switch(choiceStruct){
                case 1:
                    occ = position(SommetPile(&maPile), s);
                    break;
                case 2:
                    occ = position(maFile.tab[maFile.taille+maFile.debut-1%10], s);
                    break;
                case 3:
                    occ = position(maListe->monTexte, s);
                    break;
                case 4:
                    occ = position(maListeBi->monTexte, s);
                    break;
                case 5:
                    occ = position(maListeBiC->monTexte, s);
                    break;
                }
                break;
            case 2:
                switch(choiceStruct){
                case 1:
                    occ = dernierePosition(SommetPile(&maPile), s);
                    break;
                case 2:
                    occ = dernierePosition(maFile.tab[maFile.taille+maFile.debut-1%10], s);
                    break;
                case 3:
                    occ = dernierePosition(maListe->monTexte, s);
                    break;
                case 4:
                    occ = dernierePosition(maListeBi->monTexte, s);
                    break;
                case 5:
                    occ = dernierePosition(maListeBiC->monTexte, s);
                    break;
                }
                break;
            }
            if(occ == -1){
                printf("Aucune occurence de '%s' n'a ete trouve dans le texte.\n", s);
            }else{
                printf("'%s' est trouvee a la position: %d.\n", s, occ);
            }
            free(s);
            liberer(&myText);
            myText.chaine = (char *) malloc(16 * sizeof(char));
            myText.capa = 16;
            myText.longeur = 0;
            system("pause");
            cls();
            printf("Tache executee.\n");
            break;
        //supprimer le texte
        case 4:
            choiceSubMenu = chooseSubMenu4();
            if(choiceSubMenu != 1){
                cls();
                goto menu;
            }else{
                myText = creer();
                switch(choiceStruct){
                case 1:
                    empiler(&maPile, &myText);
                    break;
                case 2:
                    enfiler(&maFile, &myText);
                    break;
                case 3:
                    maListe = ajouterFinListeLin(maListe, &myText);
                    break;
                case 4:
                    maListeBi = ajouterFinListeLinBi(maListeBi, &myText);
                    break;
                case 5:
                    maListeBiC = ajouterFinListeLinBiC(maListeBiC, &myText);
                    break;
                }
                //free(s);
                liberer(&myText);
                myText.chaine = (char *) malloc(16 * sizeof(char));
                myText.capa = 16;
                myText.longeur = 0;
            }
            cls();
            if(ctrlz < 10){
                ctrlz++;
            }
            save = 0;
            printf("Tache executee.\n");
            break;
        //ctrlz
        case 5:
            if(ctrlz){
                switch(choiceStruct){
                case 1:
                    ctrlzPile(&maPile);
                    break;
                case 2:
                    ctrlzFile(&maFile);
                    break;
                case 3:
                    maListe = ctrlzListeLin(maListe);
                    break;
                case 4:
                    maListeBi = ctrlzListeLinBi(maListeBi);
                    break;
                case 5:
                    maListeBiC = ctrlzListeLinBiC(maListeBiC);
                    break;
                }
                ctrlz--;
            }else{
                cls();
                printf("Erreur!\n");
                goto menu;
            }
            cls();
            save = 0;
            printf("Tache executee.\n");
            break;
        //sauvegarder le texte
        case 6:
            fileload:
            if(fileset){
                fichier = fopen(filepath, "w+");
                switch(choiceStruct){
                case 1:
                    fputs(SommetPile(&maPile).chaine, fichier);
                    break;
                case 2:
                    fputs(maFile.tab[maFile.taille+maFile.debut-1%10].chaine, fichier);
                    break;
                case 3:
                    fputs(maListe->monTexte.chaine, fichier);
                    break;
                case 4:
                    fputs(maListeBi->monTexte.chaine, fichier);
                    break;
                case 5:
                    fputs(maListeBiC->monTexte.chaine, fichier);
                    break;
                }
                fclose(fichier);
            }else{
                printf("Entrez la destination du fichier: ");
                fflush(stdin);
                gets(filepath);
                fichier = fopen(filepath, "w+");
                cls();
                if(fichier != NULL){
                    switch(choiceStruct){
                    case 1:
                        fputs(SommetPile(&maPile).chaine, fichier);
                        break;
                    case 2:
                        fputs(maFile.tab[maFile.taille+maFile.debut-1%10].chaine, fichier);
                        break;
                    case 3:
                        fputs(maListe->monTexte.chaine, fichier);
                        break;
                    case 4:
                        fputs(maListeBi->monTexte.chaine, fichier);
                        break;
                    case 5:
                        fputs(maListeBiC->monTexte.chaine, fichier);
                        break;
                    }
                    fclose(fichier);
                    fileset = 1;
                }else{
                    cls();
                    fclose(fichier);
                    printf("Erreur.\n");
                    goto fileload;
                }
            }
            save = 1;
            break;
        case 7:
            quit = 1;
            if(save != 1){
                choiceSubMenu = chooseSubMenu7();
                if(choiceSubMenu != 1){
                    goto fileload;
                }
            }
            break;
        }
    }while(!quit);

    cls();
    printf("Au revoir.\n");

    return 0;
}
