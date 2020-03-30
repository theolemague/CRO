#ifndef utilSudoku_h_
#define utilSudoku_h_
int lireSudoku(FILE *fich,int sudoku[9][9]);
int ecrireSudoku(FILE *fich,int sudoku[9][9]);
int sudokuValide(int sudoku[9][9]);

void fillSimpleSudoku(int sudoku[9][9]);
void makeRestrictions(int sudoku[9][9], int M[9][9][9]);
int isPossible(int i, int j, int val, int M[9][9][9]);
void solve(int sudoku[9][9], int M[9][9][9]);
#endif
