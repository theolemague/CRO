#include "arbre_type.h"
#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    ARBRE tree1, tree2, tree3 ;
    tree1 = creerArbre(1, NULL, NULL);
    tree2 = creerArbre(2, NULL, NULL);
    tree3 = creerArbre(3, tree1, tree2);

    //afficheArbre(tree3);
    fprintf(stdout, "%d\n", hauteurArbre(tree3));
   
    detruireArbre(tree1);
    detruireArbre(tree2);
    detruireArbre(tree3);
    return(0);
}