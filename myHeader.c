
//output and inputs are seen from the user's point of view
//define the struct
typedef struct texte{
    char *chaine;
    int longeur;
    int capa;
}texte;

texte creer(){
    texte output;
    output.longeur = 0;
    output.capa = 16;
    output.chaine = (char *) malloc(output.capa * sizeof(char));
    memset(output.chaine, '\0', output.capa);
    return output;
}

void liberer(texte *t){
    free(t->chaine);
    t->longeur = 0;
    t->capa = 0;
}

int taille(texte t){
    return t.longeur;
}

int capacite(texte t){
    return t.capa;
}

char caractere(texte t, int pos){
    if(pos > t.longeur || pos <= 0 ){
        return NULL;
    }else{
        return t.chaine[pos-1];
    }
}

void modifierCapacite(texte *t, int minimum){
    char *st;
    if(t->capa <= minimum){
        t->capa = minimum+1;
        st = (char *) malloc(t->capa * sizeof(char));
        memset(st, '\0', t->capa);
        strcpy(st, t->chaine);
        free(t->chaine);
        t->chaine = st;
    }
}

void modifierCapacite2(texte *t, int minimum){
    char *st;
    if(t->capa <= minimum){
        t->capa = minimum * 2;
        st = (char *) malloc(t->capa * sizeof(char));
        memset(st, '\0', t->capa);
        strcpy(st, t->chaine);
        free(t->chaine);
        t->chaine = st;
    }
}

void ajouterCaractere(texte *t, char caractere){
    if(t->longeur+1 == t->capa){
        modifierCapacite(t, t->capa);
    }
    t->chaine[t->longeur] = caractere;
    t->longeur++;
}

void ajouterChaine(texte *t, char *str){
    if( (strlen(str)+t->longeur) >= t->capa ){
        modifierCapacite(t, strlen(str)+t->longeur);
    }
    strcpy((t->chaine)+t->longeur, str);
    t->longeur += strlen(str);
}

int position(texte t, char *str){
    int i, longe = strlen(str);
    char *s;

    s = (char *) malloc(longe * sizeof(char));

    for(i=0;i<t.longeur-longe+1;i++){
        strncpy(s, t.chaine+i, longe);
        s[longe] = '\0';

        if(strcmp(s, str) == 0){
            return i+1;
        }
    }
    return -1;
}

int dernierePosition(texte t, char *str){
    int i, output, ver = 0,longe = strlen(str);
    char *s;

    s = (char *) malloc(longe * sizeof(char));

    for(i=0;i<t.longeur-longe+1;i++){
        strncpy(s, t.chaine+i, longe);
        s[longe] = '\0';

        if(strcmp(s, str) == 0){
            ver = 1;
            output = i;
        }
    }
    if(ver == 1){
        return output+1;
    }
    return -1;
}
//debut = user
void insererChaine(texte *t, char *str, int debut){
    char *s;
    int i, added=0;
    debut--;
    if((t->longeur + strlen(str) + 1 ) > t->capa){
        modifierCapacite(t, (t->longeur + strlen(str)));
    }
    s = (char *) malloc(t->capa);
    memset(s, '\0', strlen(str)+t->longeur);
    if(t->longeur < debut+1){
        strncpy(s, t->chaine, t->longeur);
        for(i=t->longeur;i<=debut;i++){
            added++;
            s[i] = ' ';
        }
    }else{
        strncpy(s, t->chaine, debut);
    }
    strcpy(s+debut, str);
    if(t->longeur > debut+1){
        strncpy(s+debut+strlen(str), (t->chaine)+debut, (t->longeur)-debut);
    }

    s[strlen(str)+t->longeur+added] = '\0';
    liberer(t);
    t->chaine = s;
    t->longeur = strlen(t->chaine);
    t->capa = t->longeur+1;
}

//clears the console
void cls(){
    system("cls");
}

//le menu pour choisir la structure
int chooseStruct(){
    int output=1;
    do{
        cls();
        if(output<1 || output>5){
            printf("Erreur, reessayez!\n");
        }
        printf("Choisissez une de ces structures:\n\n");
        printf("1- Pile.\n");
        printf("2- File.\n");
        printf("3- Liste lineaire chainee.\n");
        printf("4- Liste lineaire bidirectionnelle.\n");
        printf("5- Liste lineaire circulaire bidirectionnelle.\n");
        printf("\nSaisissez le numero correspondant: ");
        scanf("%d", &output);

    }while(output<1 || output>5);
    return output;
}

int chooseMethod(){
    int output;

    do{

        if(output<1 || output>5){
            cls();
            printf("Erreur, reessayez!\n");
        }
        printf("Vous Voulez charger le texte a partir d'un fichier ou l'ecrire directement?\n");
        printf("1- A partir d'un fichier.\n");
        printf("2- Ecrire directement.\n");
        printf("Saisissez votre choix: ");
        scanf("%d", &output);
    }while(output<1 || output>5);
    return output;
}

//Menu pour choisir l'action
int chooseMenu(){
    int output=1;
    do{
        if(output<1 || output>7){
            printf("Erreur, reessayez!\n");
        }
        printf("Menu:\n\n");
        printf("1- Afficher le texte.\n");
        printf("2- Inserer une chaine dans le texte.\n");
        printf("3- Chercher une sous-chaine.\n");
        printf("4- Supprimer le texte.\n");
        printf("5- CTRLZ (retourner vers la version du texte precedente).\n");
        printf("6- Enregistrer le texte dans un fichier.\n\n");
        printf("7- Quitter.\n");
        printf("\nSaisissez l'action a executer: ");
        scanf("%d", &output);

    }while(output<1 || output>7);
    return output;
}

// sous-menu de l'option 2 du menu principal
int chooseSubMenu2(){
    int output;

    printf("ou voulez vous inserer votre chaine?\n");
    printf("2.1- Au milieu ( choisir la position ).\n");
    printf("2.2- Au debut.\n");
    printf("\nSaisissez votre choix: ");
    scanf("%d", &output);

    return output;
}

int chooseSubMenu3(){
    int output;

    printf("Choisissez :\n");
    printf("3.1- Premiere occurence de la chaine dans le texte.\n");
    printf("3.2- Derniere occurence de la chaine dans le texte.\n");
    printf("\nSaisissez votre choix: ");
    scanf("%d", &output);

    return output;
}

int chooseSubMenu4(){
    int output;

    printf("Vous confirmez cette action?\n");
    printf("4.1- Oui.\n");
    printf("4.2- Annuler\n");
    printf("saisissez votre choix: ");
    scanf("%d", &output);

    return output;
}

int chooseSubMenu7(){
    int output=1;
    do{
        if(output<1 || output>2){
            cls();
            printf("Erreur, reessayez!\n");
        }
        printf("Vous voulez quitter sans sauvegarder votre texte ?\n");
        printf("7.1- Oui.\n");
        printf("7.2- Sauvegarder.\n");
        printf("sasissez votre choix :");
        scanf("%d", &output);

    }while(output<1 || output>2);
    return output;
}
