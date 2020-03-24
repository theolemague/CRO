#include "arbre_type.h"
#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>

ARBRE creerArbre(int val, ARBRE filsGauche, ARBRE filsDroit){
    NOEUD* newTree;
    newTree = (NOEUD*) malloc(sizeof(NOEUD));
    newTree->val = val;
    newTree->filsGauche = filsGauche;
    newTree->filsDroit = filsDroit;
    return newTree;
}

void afficheArbre(ARBRE tree){
    if(tree==NULL) {return;}
    if(tree->filsGauche!=NULL){afficheArbre(tree->filsGauche);}
    fprintf(stdout, "%d\n", tree->val);
    if(tree->filsDroit!=NULL){afficheArbre(tree->filsDroit);}
}

int max(int a, int b){
    if (a<b) return b;
    else return a;
}

int hauteurArbre(ARBRE tree){
    if (tree==NULL) return -1;
    else return (max(hauteurArbre(tree->filsGauche)+1, hauteurArbre(tree->filsDroit)+1));
}

void detruireArbre(ARBRE tree){
    free(tree);
}

