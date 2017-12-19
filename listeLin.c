//1- liste lin�aire simplement chain�e ( FIFO )
typedef struct listeLin{
    texte monTexte;
    struct listeLin *svt;
}listeLin;

//creer un element de la liste lin�aire
listeLin* creerListeLin(){
    listeLin *output;
    output = (listeLin *) malloc(sizeof(listeLin));
    output->monTexte = creer();
    output->svt = NULL;
    return output;
}

//retourne la taille de la liste
int tailleListeLin(listeLin *tete){
    int i=0;
    listeLin *p = tete;
    if(p == NULL){
        return i;
    }
    i++;
    while(p->svt != NULL){
        p = p->svt;
        i++;
    }
    return i;

}

// retourne 1 si la liste est vide, 0 sinon
int listeLinVide(listeLin *tete){
    if(tete == NULL){
        return 1;
    }
    return 0;
}
//retourne 1 si la taille de la liste est 10, 0 sinon
int listeLinPleine(listeLin *tete){
    if(tailleListeLin(tete) == 10){
        return 1;
    }
    return 0;
}

//supprimer le dernier element de la liste
listeLin* supprimerFinListeLin(listeLin *tete){
    listeLin *p = tete;
    if(listeLinVide(tete)){
        return NULL;
    }else if(tete->svt == NULL){
        free(tete);
        return NULL;
    }
    tete = tete->svt;
    free(p);
    return tete;
}

//supprimer le premier element de la liste
listeLin* supprimerDebutListeLin(listeLin *tete){
    listeLin *p = tete, *second;
    if(listeLinVide(tete)){
        return NULL;
    }else if(tete->svt == NULL){
        free(tete);
        return NULL;
    }
    while(p->svt->svt !=NULL){
        p = p->svt;
    }
    second = p->svt;
    p->svt = NULL;
    free(second);
    return tete;

}

//ajouter Texte a la fin de la liste
listeLin* ajouterFinListeLin(listeLin *tete, texte *elem){
    listeLin *p = NULL;
    if(listeLinPleine(tete)){
        tete = supprimerDebutListeLin(tete);
    }

    //premier ajout
    if(listeLinVide(tete)){
        tete = creerListeLin();
        ajouterChaine(&(tete->monTexte), elem->chaine);
        return tete;
    }

    p = creerListeLin();
    p->svt = tete;
    ajouterChaine(&(p->monTexte), elem->chaine);
    tete = p;

    return tete;
}

//ajouter Texte a la fin de la liste
listeLin* ajouterDebutListeLin(listeLin *tete, texte *elem){
    listeLin *p = tete;

    //premier ajout
    if(listeLinVide(tete)){
        tete = creerListeLin();
        ajouterChaine(&(tete->monTexte), elem->chaine);
        return tete;
    }
    while(p->svt != NULL){
        p = p->svt;
    }
    p->svt = creerListeLin();
    p = p->svt;
    ajouterChaine(&(p->monTexte), elem->chaine);
    return tete;

}

//retourne le texte a la position pos donn�e
texte* retournerPosListeLin(listeLin *tete, int pos){
    int i=1, tailleL = tailleListeLin(tete);
    listeLin *p = tete;

    if(pos == tailleL){
        return tete;
    }
    while(p->svt != NULL && i<=(tailleL - pos)){
        p = p->svt;
        i++;
    }
    if(i == (tailleL - pos + 1)){
        return p;
    }
    return NULL;
}

//affichage des elements de la liste
void afficherListeLin(listeLin *tete){
    int i;
    if(listeLinVide(tete)){
        printf("La liste est vide.\n");
    }else{
        for(i=1; retournerPosListeLin(tete, i) != NULL; i++){
            printf("Version n%d : '%s'.\n", i, retournerPosListeLin(tete, i)->chaine);
        }
    }
}


listeLin* ctrlzListeLin(listeLin *tete){
    listeLin *del = NULL;
    if(listeLinVide(tete)){
        printf("Il n'existe aucune ancienne version.\n");
    }else{
        del = tete;
        tete = tete->svt;
        free(del);
    }
    return tete;
}
