#include<gtk/gtk.h>
#include<stdlib.h>
#include<stdbool.h>
#include "functions.h"

void board_init( GtkWidget *widget, gpointer data )
{

    (void)widget;

    GtkWidget *window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
    GtkWidget *grid = gtk_grid_new();
    GtkWidget *layout = gtk_layout_new(NULL, NULL);

    GtkWidget *grid1 = gtk_grid_new();
    GtkWidget *grid2 = gtk_grid_new();
    GtkWidget *grid3 = gtk_grid_new();

    gtk_window_set_position( GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS );
    gtk_window_set_title( GTK_WINDOW(window), "SUDOKU" );
    gtk_window_set_default_size( GTK_WINDOW(window), 598, 750 );
    gtk_container_add( GTK_CONTAINER(window), layout );

    gtk_grid_set_row_spacing( GTK_GRID(grid), 30 );

    gtk_grid_attach( GTK_GRID(grid), grid1, 0, 0, 1, 1 );
    gtk_grid_attach( GTK_GRID(grid), grid2, 0, 1, 1, 1 );
    gtk_grid_attach( GTK_GRID(grid), grid3, 0, 2, 1, 1 );

    struct ColorInfo *color = data;

    const char* bg_names[] = { "img/default_bg.png", "img/blue_bg.png", "img/green_bg.png" };

    GdkPixbuf *background = gdk_pixbuf_new_from_file( bg_names[color->color], NULL );
    gtk_layout_put( GTK_LAYOUT(layout), gtk_image_new_from_pixbuf(background), 0, 0 );

    gtk_layout_put( GTK_LAYOUT(layout), grid, 0, 0 );

    GdkPixbuf *Empty = gdk_pixbuf_new_from_file( "img/empty.png", NULL );

    const char* img_names[] = { "img/one.png", "img/two.png", "img/three.png", "img/four.png", "img/five.png", "img/six.png", "img/seven.png", "img/eight.png", "img/nine.png", };

    struct BoardInfo *board = (struct BoardInfo*)malloc(sizeof(struct BoardInfo));
    board->widget = NULL;
    board->grid1 = grid1;
    board->grid2 = grid2;

    board->start = false;

    int **arr = (int**)malloc(9 * sizeof(int*));
    for( int i=0; i<9; i++ )
        arr[i] = (int*)malloc(9 * sizeof(int));
    for( int i=0; i<9; i++ )
        for( int j=0; j<9; j++ )
            arr[i][j]=0;

    board->arr = arr;

    int **arr2 = (int**)malloc(9 * sizeof(int*));

    for( int i=0; i<9; i++ )
        arr2[i] = (int*)malloc(9 * sizeof(int));

    board->arr2 = arr2;

    //FIRST GRID

    gtk_grid_set_row_spacing( GTK_GRID(grid1), 5 );
    gtk_grid_set_column_spacing( GTK_GRID(grid1), 5 );

    for( int i=0; i<9; i++ )
        for( int j=0; j<9; j++ )
        {

            GtkWidget *image = gtk_image_new_from_pixbuf( Empty );
            GtkWidget *button = gtk_button_new();

            g_signal_connect( G_OBJECT(button), "clicked", G_CALLBACK(click_on_board), board );

            gtk_button_set_image( GTK_BUTTON(button), image );
            gtk_grid_attach(GTK_GRID(grid1), button, j, i, 1, 1);

        }

    //SECOND GRID

    for( int i=0; i<9; i++ )
    {

        GdkPixbuf *Number = gdk_pixbuf_new_from_file( img_names[i], NULL );

        GtkWidget *image = gtk_image_new_from_pixbuf( Number );
        GtkWidget *button = gtk_button_new();

        g_signal_connect( G_OBJECT(button), "clicked", G_CALLBACK(click_on_number), board );

        gtk_button_set_image( GTK_BUTTON(button), image );
        gtk_grid_attach(GTK_GRID(grid2), button, i, 0, 1, 1);

    }

    //THIRD GRID

    GtkWidget *start_button = gtk_button_new_with_label("START");

    g_signal_connect( G_OBJECT(start_button), "clicked", G_CALLBACK(press_start), board );
    gtk_grid_attach( GTK_GRID(grid3), start_button, 0, 0, 1, 1 );

    GtkWidget *check_button = gtk_button_new_with_label("CHECK");

    g_signal_connect( G_OBJECT(check_button), "clicked", G_CALLBACK(press_check), board );
    gtk_grid_attach( GTK_GRID(grid3), check_button, 1, 0, 1, 1 );

    GtkWidget *sudoku1 = gtk_button_new_with_label("EASY SUDOKU");

    g_signal_connect( G_OBJECT(sudoku1), "clicked", G_CALLBACK(load_sudoku1), board );
    gtk_grid_attach( GTK_GRID(grid3), sudoku1, 2, 0, 1, 1 );

    GtkWidget *sudoku2 = gtk_button_new_with_label("MEDIUM SUDOKU");

    g_signal_connect( G_OBJECT(sudoku2), "clicked", G_CALLBACK(load_sudoku2), board );
    gtk_grid_attach( GTK_GRID(grid3), sudoku2, 3, 0, 1, 1 );

    GtkWidget *sudoku3 = gtk_button_new_with_label("HARD SUDOKU");

    g_signal_connect( G_OBJECT(sudoku3), "clicked", G_CALLBACK(load_sudoku3), board );
    gtk_grid_attach( GTK_GRID(grid3), sudoku3, 4, 0, 1, 1 );

    //

    g_signal_connect( G_OBJECT(window), "destroy", G_CALLBACK(destroy_board), board );

    gtk_widget_show_all( window );

    return;

}
