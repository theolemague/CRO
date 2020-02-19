/*********************************************************/
/* fichier utils.c                                       */
/* utilitaire de conversion de format                    */
/*********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "macro.h"
#include "utils.h"

#ifdef DEBUG
static int debug=TRUE;
#else
static int debug=FALSE;
#endif



/*!
************************************************
* \brief range une trame érroné dans le fichier f0
* \param trame la trame érronée 
* \result un charactère
* \warning Affiche un message d'erreur et renvoie le caractère '-'
*    en cas d'entrée érronée
**************************************************/    
int reportChecksumError(char *trame,int checksum)
{
  if (debug)
  {
    fprintf(stderr,"Warning: checksum incorrect pour %s, ",trame);
    fprintf(stderr,"ckecksum=%d should be %lu \n",checksum,strlen(trame)%16);
  }
 return(0);
}

/*!
************************************************
* \brief parcours la trame et range au fur et a mesure les 
*   paquets de 7 caractère suivit du checksum dans le fichier 
*   donné en argument 
* \param fichierCourant descripteur du fichier dans lequel doivent 
*     etre rangé les caractères de la trame
* \param trame la trame a traiter
* \warning Ne ferme pas le fichier apres y avoir rangé la trame
**************************************************/    
int ecrirePaquets(FILE *fichierCourant,char *trame)
{
  int i;
  int counterTrame; // index dans la trame
  int counterLigne; // nombre de caractère écrites dans une ligne du fichier
 
  counterTrame=0; 
  counterLigne=0; 
  while (trame[counterTrame]!='\0')
  {
    // on copie le caractère dans le fichier
    fputc(trame[counterTrame],fichierCourant);
    counterTrame++;
    counterLigne++;
    if (counterLigne==7)
    {
      // si on est en fin de paquet, on met le checksum
      // et on passe à la ligne dans le paquet
      fputc(inttohexa(7),fichierCourant);
      fputc('\n',fichierCourant);
      counterLigne=0;
    }
  }
  //il reste la dernière ligne a finir.
  if (counterLigne!=0)
  {
    for(i=counterLigne;i<7;i++)
    fputc('?',fichierCourant);
    fputc(inttohexa(counterLigne),fichierCourant);
    fputc('\n',fichierCourant);
  }
  
  return(0);
}


/*!
************************************************
* \brief lit une trame (sauf le premier caractere, fichier de destination 
*       qui a déjà été lu) dans le fichier de descripteur fichTrame et 
*       la recopie dans un tableau de taille TAILLEMAXTRAME, 
* \param fichTrame le descripteur de fichier de trame
* \param trame le tableau de caractère a remplir par la trame
* \result La fonction renvoie -1 si la trame est invalide, 0 si la trame
*        est valide
* \warning Le checksum et Le retour chariot en fin de ligne ne sont
**************************************************/    
int lireTrame(FILE *fichTrame, char trame[TAILLEMAXTRAME], FILE *fichPaquet)
{
  char caract1,prevcaract;
  int counter,checksum;

  //il faut lire un caractère en avance, avant de copier
  //la chaine car on ne veut pas ecrire le \n ni le checksum
  // par exemple pour la trame aze3\n on stocke aze dans la trame
  caract1=fgetc(fichTrame);
  counter=0; //counter du nombre de caractères dans la trame
  
  while ((caract1!=EOF) && (caract1!='\n') && (counter<TAILLEMAXTRAME))
    {
      trame[counter]=caract1; 
      caract1=fgetc(fichTrame);
      counter++;
    }

  //terminaison de la chaine de caractère trame,
  // on revient deux en arriere et on écrase le dernier (checksum)
  prevcaract=trame[counter-1];
  checksum=hexatoint(prevcaract);
  trame[counter-1]='\0';

  if (debug) fprintf(stdout,"Trame lue: %s\n",trame);
  else fprintf(stdout,".");

  if (counter==TAILLEMAXTRAME) {
    fprintf(stdout,"Erreur: trame trop longue %s\n",trame);
    exit(-1);
  }
  
  //traitement de la trame, 
  // le checksum est dans prevcaract
  //La trame contient exactement counter caractère

  if (checksum!=((counter-1)%16)) 
    {
      trame[counter]='\0';
      reportChecksumError(trame,checksum);
    }
  else
    {
      ecrirePaquets(fichPaquet,trame);
    }
  
  if (caract1==EOF)
    return 1;
  else
    return 0;
  
}
  

