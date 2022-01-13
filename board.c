#include<gtk/gtk.h>
#include<stdlib.h>
#include "functions.h"

void board_init()
{

    GtkWidget *window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
    GtkWidget *grid = gtk_grid_new();

    GtkWidget *grid1 = gtk_grid_new();
    GtkWidget *grid2 = gtk_grid_new();

    gtk_window_set_title( GTK_WINDOW(window), "SUDOKU" );
    gtk_container_add( GTK_CONTAINER(window), grid );

    gtk_grid_set_row_spacing( GTK_GRID(grid), 30 );

    gtk_grid_attach( GTK_GRID(grid), grid1, 0, 0, 1, 1 );
    gtk_grid_attach( GTK_GRID(grid), grid2, 0, 1, 1, 1 );

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

    int **arr = (int**)malloc(9 * sizeof(int*));
    for( int i=0; i<9; i++ )
        arr[i] = (int*)malloc(9 * sizeof(int));
    for( int i=0; i<9; i++ )
        for( int j=0; j<9; j++ )
            arr[i][j]=0;

    board->arr = arr;

    for( int i=0; i<9; i++ )
        for( int j=0; j<9; j++ )
        {

            GtkWidget *image = gtk_image_new_from_pixbuf( Empty );
            GtkWidget *button = gtk_button_new();

            g_signal_connect( G_OBJECT(button), "clicked", G_CALLBACK(click_on_board), board );

            gtk_button_set_image( GTK_BUTTON(button), image );
            gtk_grid_attach(GTK_GRID(grid1), button, j, i, 1, 1);

        }

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

    g_signal_connect( G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL );

    gtk_widget_show_all( window );

    return;

}
