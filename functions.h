#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct BoardInfo {
    GtkWidget *widget;
    GtkWidget *grid1;
    GtkWidget *grid2;
    GtkWidget *grid3;
    int **arr;
    int **arr2;
    bool start;
};

struct WidPos {
    int x,y;
};

void click_on_board( GtkWidget *widget, gpointer data );
void click_on_number( GtkWidget *widget, gpointer data );
void board_init();
void press_start( GtkWidget *widget, gpointer data );
void press_check( GtkWidget *widget, gpointer data );

struct WidPos get_pos_on_board( GtkWidget *widget, struct BoardInfo *board );
struct WidPos get_number( GtkWidget *widget, struct BoardInfo *board );

bool solve_sudoku( int **arr );
bool find_unassigned_location( int **arr, int *row, int *col );
bool is_safe( int **arr, int row, int col, int num );
bool used_in_row( int **arr, int row, int num );
bool used_in_col( int **arr, int col, int num );
bool used_in_box( int **arr, int boxStartRow, int boxStartCol, int num );
bool is_safe2( int **arr, int row, int col, int num );
bool used_in_row2( int **arr, int row, int pos, int num );
bool used_in_col2( int **arr, int row, int pos, int num );
bool used_in_box2( int **arr, int rpos, int cpos, int boxStartRow, int boxStartCol, int num );

#endif // FUNCTIONS_H_INCLUDED
