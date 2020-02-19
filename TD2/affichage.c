#include <stdio.h>
#include "affichage.h"

int main(){
	char sentence[80]={0};
	fprintf(stdout, "Entrez une phrase\n");
	gets(sentence);
	for (int i=0; i<sizeof(sentence); i++){// escape pressed 
		fprintf(stdout, "%c", sentence[i]);
	}
	fprintf(stdout, "\n");
}

int factorielle(int n)
{
int i, fact=1;
for (i = 1; i<=n; i++) fact *= i;
  return fact;
}