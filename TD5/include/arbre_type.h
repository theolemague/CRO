#ifndef arbre_type_h_
#define arbre_type_h_

struct model_noeud {
    int val;
    struct model_noeud *filsGauche ;
    struct model_noeud *filsDroit ;
};

typedef struct model_noeud NOEUD;

typedef NOEUD *ARBRE;

#endif