#include<gtk/gtk.h>
#include<stdbool.h>
#include "functions.h"

struct WidPos get_pos_on_board( GtkWidget *widget, struct BoardInfo *board )
{
    struct WidPos position = { -1, -1 };
    for( int i=0; i<9; i++ )
        for( int j=0; j<9; j++ )
        {
            GtkWidget *child = gtk_grid_get_child_at( GTK_GRID(board->grid1), j, i );
            if( child == widget )
            {
                position.y = i;
                position.x = j;
                return position;
            }
        }
    return position;
}

struct WidPos get_number( GtkWidget *widget, struct BoardInfo *board )
{
    struct WidPos position = { -1, -1 };
    for( int i=0; i<9; i++ )
    {
        GtkWidget *child = gtk_grid_get_child_at( GTK_GRID(board->grid2), i, 0 );
        if( child == widget )
        {
            position.x = i;
            position.y = 0;
            return position;
        }
    }
    return position;
}

bool check_if_sudoku( struct BoardInfo *board )
{
    for( int i=0; i<9; i++ )
    {
        for( int j=0; j<9; j++ )
        {
            if( board->arr2[i][j] != 0 && !is_safe2( board->arr2, i, j, board->arr2[i][j] ) )
            {
                return false;
            }
        }
    }
    return true;
}

bool check_if_correct( struct BoardInfo *board )
{
    for( int i=0; i<9; i++ )
    {
        for( int j=0; j<9; j++ )
            if( board->arr[i][j] != board->arr2[i][j] )
            {
                return false;
            }
    }
    return true;
}

void set_color( GtkWidget *widget, gpointer data )
{
    struct ColorInfo *color = data;

    for( int i=0; i<3; i++ )
        if( color->colors[i] == widget )
            color->color = i;

}
