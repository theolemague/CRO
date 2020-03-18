#include <stdio.h>

#include "hanoi.h"


 
/*!***********************************************
* \brief  Programme de test des fonction du module pile.c
**************************************************/    

int deplacer(PILE *source, PILE *dest){
	int elem = Depiler(source);
	if (elem != -1){
		*dest = Empiler(*dest, elem);
		return 0;
	}
	else {return 1;}
}

void hanoi(PILE *depart,PILE *passage, PILE *arrive,int n){
	if (n!=0){
		hanoi(depart, arrive, passage, n-1);
		if (deplacer(depart, arrive)!=0){exit(0);}
		hanoi(passage, arrive, depart, n-1);
	}
}



