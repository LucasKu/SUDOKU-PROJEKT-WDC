#include<gtk/gtk.h>
#include<stdlib.h>
#include<stdbool.h>
#include "functions.h"

void board_init()
{

    GtkWidget *window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
    GtkWidget *grid = gtk_grid_new();
    GtkWidget *layout = gtk_layout_new(NULL, NULL);

    GtkWidget *grid1 = gtk_grid_new();
    GtkWidget *grid2 = gtk_grid_new();
    GtkWidget *grid3 = gtk_grid_new();

    gtk_window_set_position( GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS );
    gtk_window_set_title( GTK_WINDOW(window), "SUDOKU" );
    gtk_window_set_default_size( GTK_WINDOW(window), 598, 750 );
    //gtk_container_add( GTK_CONTAINER(window), grid );
    gtk_container_add( GTK_CONTAINER(window), layout );

    gtk_grid_set_row_spacing( GTK_GRID(grid), 30 );

    gtk_grid_attach( GTK_GRID(grid), grid1, 0, 0, 1, 1 );
    gtk_grid_attach( GTK_GRID(grid), grid2, 0, 1, 1, 1 );
    gtk_grid_attach( GTK_GRID(grid), grid3, 0, 2, 1, 1 );

    GdkPixbuf *background = gdk_pixbuf_new_from_file( "img/background.png", NULL );
    gtk_layout_put( GTK_LAYOUT(layout), gtk_image_new_from_pixbuf(background), 0, 0 );

    gtk_layout_put( GTK_LAYOUT(layout), grid, 0, 0 );

    GdkPixbuf *Empty = gdk_pixbuf_new_from_file( "img/empty.png", NULL );

    GdkPixbuf *One = gdk_pixbuf_new_from_file( "img/one.png", NULL );
    GdkPixbuf *Two = gdk_pixbuf_new_from_file( "img/two.png", NULL );
    GdkPixbuf *Three = gdk_pixbuf_new_from_file( "img/three.png", NULL );
    GdkPixbuf *Four = gdk_pixbuf_new_from_file( "img/four.png", NULL );
    GdkPixbuf *Five = gdk_pixbuf_new_from_file( "img/five.png", NULL );
    GdkPixbuf *Six = gdk_pixbuf_new_from_file( "img/six.png", NULL );
    GdkPixbuf *Seven = gdk_pixbuf_new_from_file( "img/seven.png", NULL );
    GdkPixbuf *Eight = gdk_pixbuf_new_from_file( "img/eight.png", NULL );
    GdkPixbuf *Nine = gdk_pixbuf_new_from_file( "img/nine.png", NULL );

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

        GdkPixbuf *Number;
        if( i == 0 )    Number = One;
        else if( i == 1 )    Number = Two;
        else if( i == 2 )    Number = Three;
        else if( i == 3 )    Number = Four;
        else if( i == 4 )    Number = Five;
        else if( i == 5 )    Number = Six;
        else if( i == 6 )    Number = Seven;
        else if( i == 7 )    Number = Eight;
        else if( i == 8 )    Number = Nine;

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

    //

    g_signal_connect( G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL );

    gtk_widget_show_all( window );

    return;

}
