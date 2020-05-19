#include <stdio.h>
#include <stdlib.h>

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

int nullTabEntierQ(int *tab, int N)
{
  int res=1;
  for (int i=0;i<N;i++)
    {
      if (tab[i]!=0)
	res=0;
    }
  return res;
}

#define N 10
int main()
{
  int *tab,res;
  tab=CreerTabEntier(N);
  res=nullTabEntierQ(tab,N);
  printf("le resultat est : %d\n",res);
  return 0;
}
