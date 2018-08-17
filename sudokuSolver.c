#include <stdio.h>

int checkPossibility(int sudoku[][9], int row, int col, int num){
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    int i;

    for(i=0; i<9; ++i){
        if (sudoku[row][i] == num) return 0;
        if (sudoku[i][col] == num) return 0;
        if (sudoku[rowStart + (i%3)][colStart + (i/3)] == num) return 0;
    }
    return 1;
}

int solveSudoku(int sudoku[][9], int row, int col){
    int digit;
    if(row<9 && col<9){
        if(sudoku[row][col]){
            if((col+1)<9) return solveSudoku(sudoku, row, col+1);
            else if((row+1)<9) return solveSudoku(sudoku, row+1, 0);
            else return 1;
        }
        else{
            for(digit=1; digit<=9; ++digit){
                if(checkPossibility(sudoku, row, col, digit)){
                    sudoku[row][col] = digit;
                    if(solveSudoku(sudoku,row,col)) return 1;
                    else sudoku[row][col]=0;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int main(){
    int i, j;
    int sudoku[9][9]={{0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0}
										};
    if(solveSudoku(sudoku, 0, 0)){
        for(i=1; i<10; ++i){
            for(j=1; j<10; ++j){
            	printf("%d ", sudoku[i-1][j-1]);
        	}
        	printf("\n");
        }
    }
    else printf("NO SOLUTION\n");

    return 0;
}
