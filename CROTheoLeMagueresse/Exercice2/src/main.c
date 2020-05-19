#include "tab_entier.h"
#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(int argc, char** argv) {
    int *tab;
    tab = CreerTabEntier(N);
    afficherTabEntier(tab, N);
    remplirTabEntier(tab, N);
    afficherTabEntier(tab, N);
    return(0);
}