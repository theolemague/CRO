#include <stdio.h>
#include "matrice.h"
#include "matProd.h"

int matProd(int A[N][N], int B[N][N], int C[N][N])
{

	for (int i=0; i<N;i++){
    for (int j=0; j<N; j++){
      for (int k=0;k<N;k++){
      C[i][j]+= A[i][k]*B[k][j];
      }
    }
  }
  return(0);
}

int matEqualQ(int A[N][N], int B[N][N]){
 for (int i=0; i<N;i++){
    for (int j=0; j<N; j++){
      if (A[i][j]!=B[i][j]){
        return(1);
      }
      }
    }
  return(0);
} 