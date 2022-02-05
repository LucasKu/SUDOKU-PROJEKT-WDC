#include<gtk/gtk.h>
#include<stdlib.h>
#include<stdbool.h>
#include "functions.h"

void load_sudoku1( GtkWidget *widget, gpointer data )
{
    (void)widget;

    const char* img_names[] = { "img/one.png", "img/two.png", "img/three.png", "img/four.png", "img/five.png", "img/six.png", "img/seven.png", "img/eight.png", "img/nine.png", };
    GdkPixbuf *Empty = gdk_pixbuf_new_from_file( "img/empty.png", NULL );

    FILE *sudoku = fopen("sudokus/sudoku1.txt","r");

    if( sudoku == NULL ) return;

    struct BoardInfo *board = data;

    for( int i=0; i<9; i++ )
        for( int j=0; j<9; j++ )
        {
            int value;
            fscanf(sudoku, "%d", &value );
            board->arr[i][j] = value;

            if( value > 0 && value < 10 )
            {
                GdkPixbuf *Number = gdk_pixbuf_new_from_file( img_names[value-1], NULL );

                GtkWidget *button = gtk_grid_get_child_at( GTK_GRID(board->grid1), j, i );

                GtkWidget *image = gtk_image_new_from_pixbuf( Number );
                gtk_button_set_image( GTK_BUTTON(button), image );
            }
            else if( value == 0 )
            {
                GtkWidget *button = gtk_grid_get_child_at( GTK_GRID(board->grid1), j, i );

                GtkWidget *image = gtk_image_new_from_pixbuf( Empty );
                gtk_button_set_image( GTK_BUTTON(button), image );
            }

        }

    fclose(sudoku);

    return;

}

void load_sudoku2( GtkWidget *widget, gpointer data )
{
    (void)widget;

    const char* img_names[] = { "img/one.png", "img/two.png", "img/three.png", "img/four.png", "img/five.png", "img/six.png", "img/seven.png", "img/eight.png", "img/nine.png", };
    GdkPixbuf *Empty = gdk_pixbuf_new_from_file( "img/empty.png", NULL );

    FILE *sudoku = fopen("sudokus/sudoku2.txt","r");

    if( sudoku == NULL ) return;

    struct BoardInfo *board = data;

    for( int i=0; i<9; i++ )
        for( int j=0; j<9; j++ )
        {
            int value;
            fscanf(sudoku, "%d", &value );
            board->arr[i][j] = value;

            if( value > 0 && value < 10 )
            {
                GdkPixbuf *Number = gdk_pixbuf_new_from_file( img_names[value-1], NULL );

                GtkWidget *button = gtk_grid_get_child_at( GTK_GRID(board->grid1), j, i );

                GtkWidget *image = gtk_image_new_from_pixbuf( Number );
                gtk_button_set_image( GTK_BUTTON(button), image );
            }
            else if( value == 0 )
            {
                GtkWidget *button = gtk_grid_get_child_at( GTK_GRID(board->grid1), j, i );

                GtkWidget *image = gtk_image_new_from_pixbuf( Empty );
                gtk_button_set_image( GTK_BUTTON(button), image );
            }

        }

    fclose(sudoku);

    return;

}

void load_sudoku3( GtkWidget *widget, gpointer data )
{
    (void)widget;

    const char* img_names[] = { "img/one.png", "img/two.png", "img/three.png", "img/four.png", "img/five.png", "img/six.png", "img/seven.png", "img/eight.png", "img/nine.png", };
    GdkPixbuf *Empty = gdk_pixbuf_new_from_file( "img/empty.png", NULL );

    FILE *sudoku = fopen("sudokus/sudoku3.txt","r");

    if( sudoku == NULL ) return;

    struct BoardInfo *board = data;

    for( int i=0; i<9; i++ )
        for( int j=0; j<9; j++ )
        {
            int value;
            fscanf(sudoku, "%d", &value );
            board->arr[i][j] = value;

            if( value > 0 && value < 10 )
            {
                GdkPixbuf *Number = gdk_pixbuf_new_from_file( img_names[value-1], NULL );

                GtkWidget *button = gtk_grid_get_child_at( GTK_GRID(board->grid1), j, i );

                GtkWidget *image = gtk_image_new_from_pixbuf( Number );
                gtk_button_set_image( GTK_BUTTON(button), image );
            }
            else if( value == 0 )
            {
                GtkWidget *button = gtk_grid_get_child_at( GTK_GRID(board->grid1), j, i );

                GtkWidget *image = gtk_image_new_from_pixbuf( Empty );
                gtk_button_set_image( GTK_BUTTON(button), image );
            }

        }

    fclose(sudoku);

    return;

}
