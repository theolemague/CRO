#include <stdio.h>
#include "main.h"

int main(){
	int A[N]={1,2,3,5,6}, B[N]={9,3,7,2,5};

	fprintf(stdout, "%d\n", produit_scalaire(A, B));
}

int produit_scalaire(int A[N], int B[N]){
	int result = 0;
	for (int i=0; i<N;i++){		
		result += A[i]*B[i];
	}
	return result;
}