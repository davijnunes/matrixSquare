#include <stdio.h>
#include <stdlib.h>
#define ROWS 4
#define COLUMNS 4

void printMatrix(int rows, int columns, int matrix[rows][columns]);
int sumOfLines(int rows, int columns, int matrix[rows][columns]);
int sumOfColumns(int rows, int columns, int matrix[rows][columns]);
int sumOfDiagonalMain(int rows,int columns,int matrix[rows][columns]);
int sumOfDiagonalSecondary(int rows, int columns, int matrix[rows][columns]);
int isSquare(int sumLine, int sumColum, int sumDiagonalMain, int sumDiagonalSecondary);

int main(){

    printf("\n");

    int matrix[ROWS][COLUMNS] = {{16,3,2,13},
                                 {5,10,11,8},
                                 {9,6,7,12},
                                 {4,15,14,1}};

    int sumLine = 0;
    int sumColumn = 0;
    int sumDiagonalM = 0;
    int sumDiagonalS = 0;

    // printing to matrix
    printMatrix(ROWS,COLUMNS,matrix);

    // sum of line of matrix
    sumLine = sumOfLines(ROWS,COLUMNS,matrix);
    printf("\nSum of line: %d\n",sumLine);

    // sum of colum of matrix
    sumColumn = sumOfColumns(ROWS,COLUMNS,matrix);
    printf("\nSum of column: %d\n",sumColumn);

    // sum of diagonal main
    sumDiagonalM = sumOfDiagonalMain(ROWS,COLUMNS,matrix);
    printf("\nSum of diagonal main: %d\n",sumDiagonalM);

    // sum of diagonal secondary
    sumDiagonalS = sumOfDiagonalSecondary(ROWS,COLUMNS,matrix);
    printf("\nSum of diagonal secondary: %d\n",sumDiagonalS);

    if(isSquare(sumLine,sumColumn,sumDiagonalM, sumDiagonalS)){
        printf("\nIs matrix square\n");
    }
    else{
        printf("\nNo matrix square\n");
    }
    
    


   return 0;
}

void printMatrix(int rows, int columns, int matrix[rows][columns]){

    int i = 0 , j = 0;

    while(i < rows){

        // reset of columns to line
        j = 0;

        while(j < columns){


            printf("[%2d] ",matrix[i][j]);

            j = j + 1;
        }
        printf("\n");

        i = i + 1;
    }
}

int sumOfLines(int rows, int columns, int matrix[rows][columns]){

    int i = 0, j = i, sumLine = 0;

    while(i < rows - 3){
        // reset to column
        j = 0;

        while(j < columns){
            
            sumLine = sumLine +  matrix[i][j];

            j = j + 1;
        }

        i = i + 1;

    }

    return sumLine;
}

int sumOfColumns(int rows, int columns, int matrix[rows][columns]){

    int i = 0, j = 0, sumColum = 0;

    while(j < columns - 3){

        i = 0;

        while(i < rows){
            
            sumColum = sumColum + matrix[i][j];
             i = i + 1;
        }

        j = j + 1;
      
    }

    return sumColum;
}
int sumOfDiagonalMain(int rows,int columns,int matrix[rows][columns]){

    int i = 0, j = 0, sumDiagonalMain = 0;

    while(i < rows){

        sumDiagonalMain = sumDiagonalMain + matrix[i][i];

        i = i + 1;
    }

    return sumDiagonalMain;
}

int sumOfDiagonalSecondary(int rows,int columns,int matrix[rows][columns]){

    int i = 0, j = 0, sumDiagonalSecondary = 0;

    while(i < rows){

        sumDiagonalSecondary = sumDiagonalSecondary + matrix[i][rows - i - 1];

        i = i + 1;
    }

    return sumDiagonalSecondary;
}

int isSquare(int sumLine, int sumColum, int sumDiagonalMain, int sumDiagonalSecondary){

    if(sumLine == sumColum && sumColum == sumDiagonalMain && sumDiagonalMain == sumDiagonalMain){
        return 1;
    }
    else{
        return 0;
    }
}