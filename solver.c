#include<gtk/gtk.h>
#include<stdbool.h>
#include<stdlib.h>
#include "functions.h"

bool solve_sudoku( int **arr )
{

    int *row=(int*)malloc(sizeof(int)) , *col=(int*)malloc(sizeof(int));

    if( !find_unassigned_location( arr, row, col ) )
        return true;

    for( int num=1; num<=9; num++ )
    {
        if( is_safe( arr, *row, *col, num ) )
        {
            arr[*row][*col]=num;

            if( solve_sudoku(arr) )
                return true;

            arr[*row][*col]=0;
        }
    }

    free(row);
    free(col);
    return false;

}

bool find_unassigned_location( int **arr, int *row, int *col )
{

    for( (*row)=0; (*row)<9; (*row)++ )
        for( (*col)=0; (*col)<9; (*col)++ )
            if( arr[*row][*col] == 0 )
            {
                return true;
            }
    return false;

}

bool used_in_row( int **arr, int row, int num )
{

    for( int col=0; col<9; col++ )
        if( arr[row][col] == num )
            {
                return true;
            }

    return false;

}

bool used_in_col( int **arr, int col, int num )
{

    for( int row=0; row<9; row++ )
        if( arr[row][col] == num )
            {
                return true;
            }

    return false;

}

bool used_in_box( int **arr, int boxStartRow, int boxStartCol, int num )
{

    for( int row=0; row<3; row++ )
        for( int col=0; col<3; col++ )
            if( arr[row + boxStartRow][col + boxStartCol] == num )
            {
                return true;
            }

    return false;

}

bool is_safe( int **arr, int row, int col, int num )
{

    return !used_in_row( arr, row, num )
            && !used_in_col( arr, col, num )
            && !used_in_box( arr, row - row%3, col - col%3, num )
            && arr[row][col] == 0;

}

bool is_safe2( int **arr, int row, int col, int num )
{

    return !used_in_row2( arr, row, col, num )
            && !used_in_col2( arr, row, col, num )
            && !used_in_box2( arr, row, col, row - row%3, col - col%3, num );

}

bool used_in_row2( int **arr, int row, int pos, int num )
{

    for( int col=0; col<9; col++ )
        if( col != pos && arr[row][col] == num )
            {
                return true;
            }

    return false;

}

bool used_in_col2( int **arr, int pos, int col, int num )
{

    for( int row=0; row<9; row++ )
        if( row != pos && arr[row][col] == num )
            {
                return true;
            }

    return false;

}

bool used_in_box2( int **arr, int rpos, int cpos, int boxStartRow, int boxStartCol, int num )
{

    for( int row=0; row<3; row++ )
        for( int col=0; col<3; col++ )
            if( row+boxStartRow != rpos && col+boxStartCol != cpos && arr[row + boxStartRow][col + boxStartCol] == num )
            {
                return true;
            }

    return false;

}








