#include <stdio.h>
#include "pgcd.h"

int pgcd(int a, int b) {
	int res;
	if (a<b){
		int c = a;
		a = b;
		b = a;
	}
	printf("Appel de pgcd(%d,%d)\n", a,b);
	if (a%b == 0){
		res = b;
	}
	else{
		res = pgcd(b, a%b);
	}
	printf("Retour de pcdg(%d,%d) = %d\n", a,b,res);
	return(res);
}