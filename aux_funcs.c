#include<gtk/gtk.h>
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
