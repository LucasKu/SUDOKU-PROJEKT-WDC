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
    clock_t start_t, end_t;
};

struct ColorInfo {
    GtkWidget **colors;
    int color;
};

struct WidPos {
    int x,y;
};

void menu_init();
void board_init( GtkWidget *widget, gpointer data );

void click_on_board( GtkWidget *widget, gpointer data );
void click_on_number( GtkWidget *widget, gpointer data );
void press_start( GtkWidget *widget, gpointer data );
void press_check( GtkWidget *widget, gpointer data );
void destroy_board( GtkWidget *window, gpointer data );
void destroy_menu( GtkWidget *window, gpointer data );

struct WidPos get_pos_on_board( GtkWidget *widget, struct BoardInfo *board );
struct WidPos get_number( GtkWidget *widget, struct BoardInfo *board );
bool check_if_sudoku( struct BoardInfo *board );
bool check_if_correct( struct BoardInfo *board );
void set_color( GtkWidget *widget, gpointer data );

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

void load_sudoku1( GtkWidget *widget, gpointer data );
void load_sudoku2( GtkWidget *widget, gpointer data );
void load_sudoku3( GtkWidget *widget, gpointer data );

#endif // FUNCTIONS_H_INCLUDED
