/*********************************************************/
/* fichier utils.c                                       */
/* utilitaire de conversion de format                    */
/*********************************************************/

#include<stdio.h>

#include "macro.h"

/*!
************************************************
* \brief  traduit un entier compris entre 0 et 15 en le
*   caractère héxadécimal correspondant.
* \param entier un entier
* \result un charactère
* \warning Affiche un message d'erreur et renvoie le caractère '-'
*    en cas d'entrée érronée
**************************************************/    
char inttohexa(int entier)
{char res;
 switch(entier)
   {
   case 0 : res='0';break;
   case 1 : res='1';break;
   case 2 : res='2';break;
   case 3 : res='3';break;
   case 4 : res='4';break;
   case 5 : res='5';break;
   case 6 : res='6';break;
   case 7 : res='7';break;
   case 8 : res='8';break;
   case 9 : res='9';break;
   case 10 : res='A';break;
   case 11 : res='B';break;
   case 12 : res='C';break;
   case 13 : res='D';break;
   case 14 : res='E';break;
   case 15 : res='F';break;
   default: 
     {
       fprintf(stderr,"Iinttohexa:wrong value %d\n",entier);
       res='-';
     }
   }
 return(res);
}

/*!
************************************************
* \brief traduit un caractère héxadécimal (entre '0' et 'F')  
*   en l'entier compris entre 0 et 15 correspondant.
* \param un charactère
* \result entier un entier
* \warning Affiche un message d'erreur et renvoie -1
*    en cas d'entrée érronée
**************************************************/    
int hexatoint(char caract)
{int res;
 switch(caract)
   {
   case '0' : res=0;break;
   case '1' : res=1;break;
   case '2' : res=2;break;
   case '3' : res=3;break;
   case '4' : res=4;break;
   case '5' : res=5;break;
   case '6' : res=6;break;
   case '7' : res=7;break;
   case '8' : res=8;break;
   case '9' : res=9;break;
   case 'A' : res=10;break;
   case 'a' : res=10;break;
   case 'B' : res=11;break;
   case 'b' : res=11;break;
   case 'C' : res=12;break;
   case 'c' : res=12;break;
   case 'D' : res=13;break;
   case 'd' : res=13;break;
   case 'E' : res=14;break;
   case 'e' : res=14;break;
   case 'F' : res=15;break;
   case 'f' : res=15;break;
   default: res=-1;
   }
 return(res);
}
