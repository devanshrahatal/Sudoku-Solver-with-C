// Sudoku solver by Mahee & Devansh

#include <stdio.h>
#define GSize 9

// Function to Display the Sudoku
void dispSudoku(int sudoku[GSize][GSize]) 
{
    int row, col;
    
    printf("------+-------+------\n");
    for (row = 0; row < GSize; row++){
        for (col = 0; col < GSize; col++){
            printf("%d ", sudoku[row][col]);
            if (col == 2 || col == 5) 
            {
                printf("| ");
            }
        }
        printf("\n");
        if (row == 2 || row == 5) 
        {
            printf("------+-------+------\n");
        }
    }
    printf("------+-------+------\n");
}

// Function to Check if a Number is Valid. checks the row, column, and the 3x3 subgrid for any duplicates.
int isValid(int sudoku[GSize][GSize], int row, int col, int num) 
{
    int i, j;
    
    // row checking
    for (i = 0; i < GSize; i++){
        if (sudoku[row][i] == num)
        {
            return 0;
        }
    }

    // column checking
    for (i = 0; i < GSize; i++){
        if (sudoku[i][col] == num)
        {
            return 0;
        }
    }

    // checking 3x3 sudoku
    int row_3 = row - row % 3;
    int col_3 = col - col % 3;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (sudoku[row_3 + i][col_3 + j] == num)
            {
                return 0;
            }
        }
    }
    return 1;
}

// Function to Solve the Sudoku
int solveSudoku(int sudoku[GSize][GSize]) 
{
    int row, col, num, foundEmptyCell = 0;

    // finding empty cell
    for (row = 0; row < GSize && !foundEmptyCell; row++){
        for (col = 0; col < GSize && !foundEmptyCell; col++){
            if (sudoku[row][col] == 0) 
            {
                foundEmptyCell = 1;
                row--;
                col--;
            }
        }
    }

    // if no empty cell is found, the puzzle is solved
    if (!foundEmptyCell) 
    {
        return 1;
    }

    // putting number if empty cell exists
    for (num = 1; num <= 9; num++){
        if (isValid(sudoku, row, col, num))
        {
            sudoku[row][col] = num; // put number

            if (solveSudoku(sudoku)) 
            {
                return 1;
            }
            sudoku[row][col] = 0;
        }
    }
    return 0;
}

// Main Function
int main() 
{
    int sudoku[GSize][GSize] = {
        {0, 4, 0, 0, 0, 0, 8, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 6, 0, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 9, 0, 0},
        {2, 0, 0, 9, 0, 0, 0, 0, 1}
    };

    printf("\n===== SUDOKU SOLVER BY MAHEE & DEVANSH =====\n");

    printf("\nOriginal Sudoku :\n\n");
    dispSudoku(sudoku);

    printf("\n============================================\n");

    if (solveSudoku(sudoku))
    {
        printf("\nSolved Sudoku :\n\n");
        dispSudoku(sudoku);
    }
    else
    {
        printf("\nThere's no solution for it.\n");
    }

    printf("\n============================================\n\n");

    return 0;
}