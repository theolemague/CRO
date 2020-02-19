/*********************************************************/
/* fichier main.c                                       */
/*  TP1 AGP                                                 */
/*********************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "macro.h"
#include "utils.h"
#include "trame.h"

/*
#ifdef DEBUG
static int debug=TRUE;
#else
static int debug=FALSE;
#endif
*/

void help ()
{
  fprintf(stdout,"usage: lireTrame [options] nomFich\n");
  fprintf(stdout," nomFich est le nom d'un fichier contenant les trames\n");
  fprintf(stdout," (pas d'option pour l'instant)\n");
}

int error1 (int err)
{
  fprintf(stderr,"Error numero %d exiting....\n",err);
  exit(1);
}	



/*!
************************************************
* \brief  vérifie les argument argv et argc, 
* Le nom du fichie de trame est donné en argument du programme
* Effectue, en boucle jusqu'à la fin du ficher: 
*    lire la trame (fonction lireTrame)
     ranger les paquet (fonction ecrirePaquets)
**************************************************/    
//fonction main
//
int  main( int argc, char *argv[])
{
  FILE *fichTrame, *fichPaquet;
  char nomFichIn[20],nomFichOut[20],nomFichOut2[20]; 
  char trame[TAILLEMAXTRAME];
  int endOfFile,err;
  
 //verification du nombre d'argument
  if (argc!=2)  
    {
      help();
      error1(10);
    }
  else 
    {
      strcpy(nomFichIn,argv[1]);
      // recupération du nom de fichier de trame
      strcpy(nomFichOut,argv[1]);
      strcat(nomFichOut,".paquet");
      // recupération du nom de fichier de trame
    }

  //ouverture du fichier de trames
  fichTrame=fopen(nomFichIn,"r");
  if (!fichTrame) error1(20);

  //recopie éventuelle du fichier de sortie  
  if ((fichPaquet=fopen(nomFichOut,"r"))!=0)
    {
      //Le fichier existe car on a pu l'ouvrir en ecriture
      fclose(fichPaquet);
      fprintf(stderr,"Warning: Fichier %s existe: renomage en %s.old\n",
	      nomFichOut,nomFichOut);
      //creation d'une nouvelle chaine pour le nouveau nom
      strcpy(nomFichOut2,nomFichOut);
      strcat(nomFichOut2,".old");
      //renomage du fichier incriminé, fonction systeme
      err=rename(nomFichOut,nomFichOut2);
      if (err) error1(21);
    }

  //ouverture du fichier de trames
  fichPaquet=fopen(nomFichOut,"w");
  if (!fichPaquet) error1(20);

  /*********************************************************/
  /* debut du traitement                                  */
  /*********************************************************/
  
  endOfFile=0;
  
  while (!endOfFile)
    {

     /*************************************************/
     /* Lecture d'une trame                           */
     /* si on arrive à EOF, resultat 1                */
     /*************************************************/
      endOfFile=lireTrame(fichTrame,trame,fichPaquet);
   }


 //fermeture des fichier ouverts
  fclose (fichTrame);
  fclose (fichPaquet);
  
  fprintf(stdout,"\nFichier %s traité avec succès\n",nomFichIn);
 
  return(0);
}
