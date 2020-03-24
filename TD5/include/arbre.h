#ifndef arbre_h_
#define arbre_h_

ARBRE creerArbre(int val, ARBRE filsGauche, ARBRE filsDroit);

void afficheArbre(ARBRE tree);

int hauteurArbre(ARBRE tree);

int max(int a, int b);

void detruireArbre(ARBRE tree);

#endif