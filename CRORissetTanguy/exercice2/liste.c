#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

void afficherList(LIST liste1)
{
  if (liste1!=NULL)
    {
      printf(" -> %d",liste1->val);
      afficherList(liste1->suivant);
    }
}

LIST InsertionListTriee(LIST liste1, int val)
{
  if (liste1==NULL)
    {
      LIST newelem;
      newelem=(LIST)malloc(sizeof(CELL));
      if (newelem==0)
	{
	  printf("pb in malloc\n");
	  exit(-1);
	}
      newelem->val=val;
      newelem->suivant=NULL;
      return newelem;
    }
  else
    {
      if (liste1->val < val)
	{
	  LIST temp;
	  temp=InsertionListTriee(liste1->suivant, val);
	  liste1->suivant=temp;
	  return liste1;
	}
      else
	{
	  LIST newelem;
	  newelem=(LIST)malloc(sizeof(CELL));
	  if (newelem==0)
	    {
	      printf("pb in malloc\n");
	      exit(-1);
	    }
	  newelem->val=val;
	  newelem->suivant=liste1;
	  return newelem;
	}
    }
}


int main()
{
  LIST liste1=NULL;

  liste1=InsertionListTriee(liste1, 10);
  liste1=InsertionListTriee(liste1, -10);
  liste1=InsertionListTriee(liste1, 11);
  liste1=InsertionListTriee(liste1, 0);
  liste1=InsertionListTriee(liste1, -10);
  liste1=InsertionListTriee(liste1, 40);

  afficherList(liste1);

  
    
  return 0;
}
