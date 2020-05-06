#include <stdlib.h>
#include <stdio.h>
#include <string.h>

         
     
int lireSudoku(FILE *fich,int sudoku[9][9])
{int i,j,res;
 int val; 
 for (i=0; i<9; i++) 
   for (j=0; j<9; j++) 
     {
       res=fscanf(fich, "%d",&val);
       if (res==EOF)
         {
           fprintf(stderr,"Fin de ficher atteinte: manque des coefficients\n");
           exit(-1);
         }
       sudoku[i][j]=val;
     }
 return(0);
}

int ecrireSudoku(FILE *fich,int sudoku[9][9])
{int i,j;
 for (i=0; i<9; i++) 
   {
     for (j=0; j<9; j++) 
       {
         fprintf(fich, "%d ",sudoku[i][j]);
       }
     fprintf(fich, "\n");
   }
  fprintf(fich, "\n");
  return(0);
}

int sudokuValide(int sudoku[9][9]){
  int lineSum, rowSum, regionSum, i,j,k,l ; 
  for (i=0; i<9; i++) 
  {
    lineSum = 0;
    rowSum = 0;
    for (j=0; j<9; j++){
      if (sudoku[i][j]== (int) NULL || sudoku[j][i]== (int) NULL) return(1);
      lineSum+=sudoku[i][j];
      rowSum+=sudoku[j][i];
    
      regionSum=0;
      for (k=0; k<3; k++){ 
        for (l=0; l<3; l++){
          regionSum += sudoku[k+(3*(i/3))][l+(3*(j/3))];
        }
      }
      if (regionSum!=45)return(1);
    }

  if (lineSum!=45 || rowSum!=45) return(1);
  }
  return(0);
}


int isPossible(int i, int j, int val, int M[9][9][9]){
  if (M[i][j][val]==0)return(1);
  else return(0);
}


void makeRestrictions(int sudoku[9][9], int M[9][9][9]){
  for (int i=0; i<9;i++){
    for (int j=0; j<9;j++){
      if (sudoku[i][j]!= (int)NULL && M[i][j][sudoku[i][j]-1] != 1){
        for (int k=0;k<9;k++){
          M[i][k][sudoku[i][j]-1] = 1;
          M[k][j][sudoku[i][j]-1] = 1;
          for (int m=0; m<3;m++){
            M[(i/3)+(k/3)][(j/3)+m][sudoku[i][j]-1] = 1;
          }
        } 
      }
    } 
  }
}

void solve(int sudoku[9][9], int M[9][9][9]){
  int nbRestriction, memory;
  for (int i=0;i<9;i++){
    for (int j=0;j<9;j++){
      nbRestriction = 0;
      for (int k=0;k<9;k++){
        if (isPossible(i,j,k,M)==1) {
          nbRestriction++;
          memory = k+1;
        }
      }
      fprintf(stdout,"for %d,%d there is %d -> %d\n", i, j, sudoku[i][j], memory);
      if (nbRestriction ==1){
        sudoku[i][j]=memory;
        makeRestrictions(sudoku,M);
        ecrireSudoku(stdout,sudoku);
        solve(sudoku,M);
      }
    }
  } 
}

void fillSimpleSudoku(int sudoku[9][9]){
  int M[9][9][9]={0};
  makeRestrictions(sudoku, M);
  solve(sudoku, M);
}






