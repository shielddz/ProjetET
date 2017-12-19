typedef struct file{
    texte tab[10];
    int taille, debut;
}file;

file initFile(){
    file output;
    int i;
    output.taille = 0;
    output.debut = -1;
    for(i=0; i<10; i++){
        output.tab[i] = creer();
    }
    return output;
}

int fileVide(file *maFile){
    if(!maFile->taille){
        return 1;
    }
    return 0;
}

texte *teteFile(file *maFile){
    if(fileVide(maFile)){
        return NULL;
    }
    return &(maFile->tab[maFile->debut]);
}

int filePleine(file *maFile){
    if(maFile->taille == 10){
        return 1;
    }
    return 0;
}
texte *defiler(file *maFile){
    texte *output;
    texte *del;
    if(fileVide(maFile)){
        return NULL;
    }
    if(maFile->taille == 1 && maFile->debut == 9){
        del = &(maFile->tab[maFile->debut]);
        output = teteFile(maFile);
        maFile->tab[maFile->debut] = creer();
        maFile->taille--;
        maFile->debut = -1;
        free(del);
    }else{
        del = &(maFile->tab[maFile->debut]);
        output = teteFile(maFile);
        maFile->tab[maFile->debut] = creer();
        maFile->taille--;
        maFile->debut = (maFile->debut + 1)%10;
        free(del);
    }
    return output;
}

void enfiler(file *maFile, texte *elem){
    if(filePleine(maFile)){
        texte *del;
        del = defiler(maFile);
        free(del);
    }
    if(fileVide(maFile)){
        maFile->debut = 0;
    }
    ajouterChaine(&(maFile->tab[(maFile->debut + maFile->taille)%10]), elem->chaine);
    maFile->taille++;
}

void afficherFile(file maFile){
    int i, len = maFile.taille, deb = maFile.debut;
    if(!fileVide(&maFile)){
        for(i=deb; i<=(len+deb-1); i++){
            printf("Version %d: '%s'.\n", (i-deb+1)%11, maFile.tab[i%10].chaine);
        }
    }else{
        puts("La file est vide.\n");
    }
}

void ctrlzFile(file *maFile){
    texte *del = NULL;
    if(maFile->taille == 1){
        del = &(maFile->tab[maFile->debut]);
        maFile->tab[maFile->debut] = creer();
        maFile->taille--;
        maFile->debut = -1;
        free(del);
    }else if(!fileVide(maFile)){
        del = &(maFile->tab[maFile->debut+maFile->taille-1]);
        maFile->tab[maFile->debut+maFile->taille-1] = creer();
        maFile->taille--;
        free(del);
    }else{
        printf("Il n'existe aucune ancienne version.\n");
    }
}
