#include <stdio.h>
#include "sqrt.h"

int sqrt(int a, int space)
{
  int i,temp,res;

  for (i=0;i<space;i++) fprintf(stdout," ");
  fprintf(stdout," Appel de carre(%d)\n",a);

  if (a==1)
    res=1;
  else
    {
      temp=sqrt(a-1,space+3);
      res=temp+2*a-1;
    }

  for (i=0;i<space;i++) fprintf(stdout," ");
  fprintf(stdout," Retour de carre(%d)=%d\n",a,res);
  
  return(res);