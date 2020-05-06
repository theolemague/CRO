#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "type_bigInt.h"
#include "util_bigInt.h"
#include "io_bigInt.h"

#define DEBUG1



/*!
************************************************
* \brief Additionne deux Grands Entiers
* \param  bN1 Grand Entier
* \param  bN2 Grand Entier
* \param  res le Grand Entier résultat
* \return  0 si l'addition est OK, 1 en cas d'overflow
* \warning res doit être déjà alloué,
* ************************************************/
int addBigInt(bigInt bN1,bigInt bN2,bigInt res)
{
  int tailleMax, t1 = getNbChiffreBigInt(bN1) , t2 = getNbChiffreBigInt(bN2), add;
  if (t1<t2) tailleMax = t2;
  else tailleMax = t1;

  for (int i=0; i<tailleMax; i++) {
    add = bN1[i]+bN2[i]+res[i];
    res[i]=add%10;
    res[i+1]+=add/10;
  }

  return 0;
}





/*!
************************************************
* \brief Multiplie deux Grand Entiers avec l'algorithme suivant:
* stocker les 10 valeurs j*bN2 pour 1<=j<=9
* Pour chaque chiffre j=bN1[i] de bN1, partant de i=0,
* multiplier  j*bN2 par 10^i et l'ajouter au resultat
* \param  bN1 Grand Entier
* \param  bN2 Grand Entier
* \param  res le grand entier bN1*bN2
* \result Un entier: 1 en cas d'overflos, O sinon
* \warning res doit être déjà alloué,
* ************************************************/
int mulBigInt(bigInt bN1,bigInt bN2,bigInt res)
{
  int t1 = getNbChiffreBigInt(bN1) , t2 = getNbChiffreBigInt(bN2), mult;
  bigInt multBigInt = initBigInt(), inter = initBigInt();

  for (int i=0; i<t1; i++) {
    for (int j=0; j<t2; j++) {
      mult = bN1[i]*bN2[j];
      intToBigInt(mult, multBigInt);
      decalBigInt(j+i, multBigInt);
      copyBigInt(res, inter);
      zeroBigInt(res);
      addBigInt(multBigInt, inter, res); 
    }
  }
  return 0;
 }


 

