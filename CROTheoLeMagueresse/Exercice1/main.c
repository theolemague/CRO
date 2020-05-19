#include <stdio.h>
#include <stdlib.h>

int maxTab(int tableau[5]);

int main(int argc, char** argv) {
    int tab[5]={2,44,5,7,12};
    fprintf(stdout, "Maximum de tab est : %d\n", maxTab(tab));
    return(0);
}

int maxTab(int tableau[5]){
    int max = -1;
    for (int i=0 ; i<5 ; i++){
        if (tableau[i]>max) max = tableau[i];
    }
    return(max);
}