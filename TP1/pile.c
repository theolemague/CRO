#include <stdio.h>

#include "pile.h"
#include "pile_type.h"
 
/*!***********************************************
* \brief  Programme de test des fonction du module pile.c
**************************************************/    

int error1(char *message) {
	int size = sizeof(message);
	for (int i=0; i<size;i++){
		fprintf(stdout,"%c", message[i]);
	}
	fprintf(stdout,"\n");
	return 0;
}	

PILE InitPile(){
	return (PILE) NULL;
}

PILE Empiler (PILE pile, int elem){
	PILE newPile = (PILE) malloc(sizeof(ELEMPILE));
	newPile->suivant = pile;
	newPile->elem = elem;
	return newPile;
}

int Depiler(PILE* pile){
	int elem;
	if (*pile == NULL) {
		char error = {"Erreur pile vide"};
		error1(error);
		elem =-1;
	}else{
		int elem = (*pile)->elem;
		*pile = (*pile)->suivant;
	} 
	free(*pile);
	return elem;
}

void afficherPile (PILE pile){
	if (pile != NULL){
		fprintf(stdout,"%d\n", pile->elem);
		afficherPile((PILE) pile->suivant);
	}
	else{
		fprintf(stdout,"\n\n_\n");
	}
}