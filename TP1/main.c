#include <stdio.h>
#include <time.h>

#include "pile.h"
#include "hanoi.h"
#include "pile_type.h"

#define Nombre 9
 
/*!***********************************************
* \brief  Programme de test des fonction du module pile.c
**************************************************/    

int main(int argc,char **argv)	
{
  PILE pDepart, pPassage, pArrive;
  int val,i;
  
  pDepart=InitPile();
  pPassage=InitPile();
  pArrive=InitPile();
  
  for (i=Nombre;i>0;i--)
    {
      val=i;
      pDepart=Empiler(pDepart,val);
      
    }

  afficherPile(pDepart);

  hanoi(pDepart, pPassage, pArrive, Nombre);
    
  afficherPile(pArrive);

  return 0;
 
}



