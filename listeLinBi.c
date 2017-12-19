//2- liste lin�aire doublement chain�e ( bi-directionnelles )
typedef struct listeLinBi{
    texte monTexte;
    struct listeLinBi *svt, *prc;
}listeLinBi;

//creer un element de la liste doublement chain�e
listeLinBi* creerListeLinBi(){
    listeLinBi *output;
    output = (listeLinBi *) malloc(sizeof(listeLinBi));
    output->monTexte = creer();
    output->svt = NULL;
    output->prc = NULL;
    return output;
}

//retourner la taille de la liste
int tailleListeLinBi(listeLinBi *tete){
    int i=0;
    listeLinBi *p = tete;
    if(tete == NULL){
        return i;
    }
    i++;
    while(p->prc != NULL){
        p = p->prc;
        i++;
    }
    return i;

}

//1 si la liste est vide, 0 sinon
int listeLinBiVide(listeLinBi *tete){
    if(tete == NULL){
        return 1;
    }
    return 0;
}

//1 si la liste est pleine ( taille == 10 ), 0 sinon
int listeLinBiPleine(listeLinBi *tete){
    if(tailleListeLinBi(tete) == 10){
        return 1;
    }
    return 0;
}

//supprimer le dernier element de la liste
listeLinBi* supprimerFinListeLinBi(listeLinBi *tete){
    listeLinBi *p = tete, *second;
    if(listeLinBiVide(tete)){
        return NULL;
    }else if(p->prc == NULL){
        free(tete);
        return NULL;
    }
    tete = tete->prc;
    tete->svt = NULL;
    free(p);

    return tete;
}

//supprimer le premier element de la liste
listeLinBi* supprimerDebutListeLinBi(listeLinBi *tete){
    listeLinBi *p = tete, *second;
    if(listeLinBiVide(tete)){
        return NULL;
    }else if(tete->prc == NULL){
        free(tete);
        return NULL;
    }
    while(p->prc->prc !=NULL){
        p = p->prc;
    }
    second = p->prc;
    p->prc = NULL;
    free(second);
    return tete;
}

//ajouter un element a la fin de la liste
listeLinBi* ajouterFinListeLinBi(listeLinBi *tete, texte *elem){
    listeLinBi *p = NULL;
    if(listeLinBiPleine(tete)){
        tete = supprimerDebutListeLinBi(tete);
    }
    //premier ajout
    if(listeLinBiVide(tete)){
        tete = creerListeLinBi();
        ajouterChaine(&(tete->monTexte), elem->chaine);
        return tete;
    }
    p = creerListeLinBi();
    p->prc = tete;
    tete = p;
    ajouterChaine(&(p->monTexte), elem->chaine);
    return tete;

}

//ajouter un element au debut de la liste
listeLinBi* ajouterDebutListeLinBi(listeLinBi *tete, texte *elem){
    listeLinBi *p = tete;

    //premier ajout
    if(listeLinBiVide(tete)){
        tete = creerListeLinBi();
        ajouterChaine(&(tete->monTexte), elem->chaine);
        return tete;
    }
    while(p->prc != NULL){
        p = p->prc;
    }
    p->prc = creerListeLinBi();
    p->prc->svt = p;
    p = p->prc;
    ajouterChaine(&(p->monTexte), elem->chaine);
    return tete;

}

//retourne le texte a la position pos donn�e
texte* retournerPosListeLinBi(listeLinBi *tete, int pos){
    int i=1, tailleL = tailleListeLinBi(tete);
    listeLinBi *p = tete;

    if(pos == tailleL){
        return tete;
    }
    while(p->prc != NULL && i<=(tailleL - pos)){
        p = p->prc;
        i++;
    }
    if(i == (tailleL - pos + 1)){
        return p;
    }
    return NULL;
}

//afficher tout les elements de la liste
void afficherListeLinBi(listeLinBi *tete){
    int i;
    if(listeLinBiVide(tete)){
        printf("La liste est vide.\n");
    }else{
        for(i=1; retournerPosListeLinBi(tete, i) != NULL; i++){
            printf("Version n%d : '%s'.\n", i, retournerPosListeLinBi(tete, i)->chaine);
        }
    }
}


listeLinBi* ctrlzListeLinBi(listeLinBi *tete){
    listeLinBi *del = NULL;
    if(listeLinBiVide(tete)){
        printf("Il n'existe aucune ancienne version.\n");
        return tete;
    }else if(tete->prc == NULL){
        free(tete);
        return NULL;
    }
    del = tete;
    tete = tete->prc;
    tete->svt = NULL;
    free(del);
    return tete;
}
