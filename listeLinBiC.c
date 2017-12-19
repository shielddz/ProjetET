// la meme structure que listLinBi
//taille de la liste
int tailleListeLinBiC(listeLinBi *tete){
    int i=0;
    listeLinBi *p = tete;
    if(listeLinBiVide(tete)){
        return i;
    }else if(tete->prc == NULL){
        return 1;
    }
    i++;
    while(p->prc != tete){
        p = p->prc;
        i++;
    }
    return i;

}

//1 si la taille de la liste == 10, 0 sinon
int listeLinBiCPleine(listeLinBi *tete){
    if(tailleListeLinBiC(tete) == 10){
        return 1;
    }
    return 0;
}

//supprimer la première version du texte
listeLinBi* supprimerDebutListeLinBiC(listeLinBi *tete){
    listeLinBi *p = NULL;
    if(listeLinBiVide(tete)){
        return NULL;
    }else if(tete->prc == NULL){
        free(tete);
        return NULL;
    }
    p = tete->svt;
    p->svt->prc = p->prc;
    p->prc->svt = p->svt;
    free(p);
    return tete;
}

//supprimer la dernière version du texte
listeLinBi* supprimerFinListeLinBiC(listeLinBi *tete){
    listeLinBi *p = NULL;
    if(listeLinBiVide(tete)){
        return NULL;
    }else if(tete->prc == NULL){
        free(tete);
        return NULL;
    }
    p = tete;
    tete->svt->prc = tete->prc;
    tete->prc->svt = tete->svt;
    tete = tete->prc;
    free(p);
    return tete;
}

//ajouter un element a la fin, et l'affecter a la tete ( LIFO )
listeLinBi* ajouterFinListeLinBiC(listeLinBi *tete, texte *elem){
    listeLinBi *p = NULL;
    if(listeLinBiCPleine(tete)){
        supprimerDebutListeLinBiC(tete);
    }
    //premier ajout
    if(listeLinBiVide(tete)){
        tete = creerListeLinBi();
        ajouterChaine(&(tete->monTexte), elem->chaine);
        return tete;
    }
    p = tete->svt;
    if(p == NULL){
        p = creerListeLinBi();
        p->svt = tete;
        p->prc = tete;
        tete->svt = p;
        tete->prc = p;
        ajouterChaine(&(p->monTexte), elem->chaine);
        tete = p;
        return tete;
    }
    p = creerListeLinBi();
    p->svt = tete->svt;
    p->prc = tete;
    tete->svt->prc = p;
    tete->svt = p;
    ajouterChaine(&(p->monTexte), elem->chaine);
    tete = p;
    return tete;

}

//ajouter au debut
listeLinBi* ajouterDebutListeLinBiC(listeLinBi *tete, texte *elem){
    listeLinBi *p = NULL;
    if(listeLinBiCPleine(tete)){
        supprimerDebutListeLinBiC(tete);
    }
    //premier ajout
    if(listeLinBiVide(tete)){
        tete = creerListeLinBi();
        ajouterChaine(&(tete->monTexte), elem->chaine);
        return tete;
    }
    p = tete->svt;
    if(p == NULL){
        p = creerListeLinBi();
        p->svt = tete;
        p->prc = tete;
        tete->svt = p;
        tete->prc = p;
        ajouterChaine(&(p->monTexte), elem->chaine);
        return tete;
    }
    p = creerListeLinBi();
    p->svt = tete->svt;
    p->prc = tete;
    tete->svt->prc = p;
    tete->svt = p;
    ajouterChaine(&(p->monTexte), elem->chaine);
    return tete;
}

//retourner un element a la position pos donn�e
texte* retournerTexteListeLinBiC(listeLinBi *tete, int pos){
    int i=1, tailleL = tailleListeLinBiC(tete);
    listeLinBi *p = tete;

    if(pos == tailleL){
        return tete;
    }else if(tailleL == 1){
        return NULL;
    }
    while(p->prc != tete && i<=(tailleL - pos)){
        p = p->prc;
        i++;
    }
    if(i == (tailleL - pos + 1)){
        return p;
    }
    return NULL;
}

//afficher tout les elements de la liste
void afficherListeLinBiC(listeLinBi *tete){
    int i;
    if(listeLinBiVide(tete)){
        printf("La liste est vide.\n");
    }else{
        for(i=1; retournerTexteListeLinBiC(tete, i) != tete; i++){
            printf("Version n%d : '%s'.\n", i, retournerTexteListeLinBiC(tete, i)->chaine);
        }
        printf("Version n%d : '%s'.\n", tailleListeLinBiC(tete), retournerTexteListeLinBiC(tete, i)->chaine);
    }

}


listeLinBi* ctrlzListeLinBiC(listeLinBi *tete){
    listeLinBi *del = NULL;
    if(listeLinBiVide(tete)){
        printf("Il n'existe aucune ancienne version.\n");
        return NULL;
    }else if(tete->prc == NULL){
        free(tete);
        return NULL;
    }
    del = tete;
    tete->svt->prc = tete->prc;
    tete->prc->svt = tete->svt;
    tete = tete->prc;
    free(del);
    return tete;
}
