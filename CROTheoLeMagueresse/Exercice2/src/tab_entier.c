#include <stdio.h>
#include <stdlib.h>
#include "tab_entier.h"

int *CreerTabEntier(int N)
{
  int *tab;

  tab=(int *)malloc(N*sizeof(int));
  if (tab==0)
    {
      printf("error in malloc\n");
      exit(-1);
    }
  for (int i=0;i<N;i++)
    tab[i]=0;
  return tab;
}

void afficherTabEntier(int *tab, int N){
    fprintf(stdout, "Le tableau est :\n");
    for(int i=0; i<N ; i++){
        fprintf(stdout, "%d ; ", tab[i]);
    }
    fprintf(stdout, "\n");
}

void remplirTabEntier(int *tab, int N){
    for (int i=0 ; i<N ; i++){
        fprintf(stdout, "Entrez une valeur pour la case %d\n",i);
        scanf("%d", &tab[i]);
    }
}