#include<gtk/gtk.h>
#include<stdbool.h>
#include<stdlib.h>
#include "functions.h"

void click_on_board( GtkWidget *widget, gpointer data )
{

    struct BoardInfo *board = data;

    GdkPixbuf *Empty = gdk_pixbuf_new_from_file( "img/empty.png", NULL );
    GdkPixbuf *Hover = gdk_pixbuf_new_from_file( "img/hover.png", NULL );
    GtkWidget *image1 = gtk_image_new_from_pixbuf( Hover );
    GtkWidget *image2 = gtk_image_new_from_pixbuf( Empty );

    struct WidPos position = get_pos_on_board( widget, board );

    board->arr[position.y][position.x] = 0;

    struct WidPos prev_pos = get_pos_on_board( board->widget, board );
    int x = prev_pos.x;
    int y = prev_pos.y;

    if( board->widget != NULL && board->arr[y][x] < 1  )    gtk_button_set_image( GTK_BUTTON(board->widget), image2 );
    board->widget = widget;
    gtk_button_set_image( GTK_BUTTON(widget), image1 );

}

void click_on_number( GtkWidget *widget, gpointer data )
{

    struct BoardInfo *board = data;

    if( board->widget == NULL )    return;

    GdkPixbuf *One = gdk_pixbuf_new_from_file( "img/one.png", NULL );
    GdkPixbuf *Two = gdk_pixbuf_new_from_file( "img/two.png", NULL );
    GdkPixbuf *Three = gdk_pixbuf_new_from_file( "img/three.png", NULL );
    GdkPixbuf *Four = gdk_pixbuf_new_from_file( "img/four.png", NULL );
    GdkPixbuf *Five = gdk_pixbuf_new_from_file( "img/five.png", NULL );
    GdkPixbuf *Six = gdk_pixbuf_new_from_file( "img/six.png", NULL );
    GdkPixbuf *Seven = gdk_pixbuf_new_from_file( "img/seven.png", NULL );
    GdkPixbuf *Eight = gdk_pixbuf_new_from_file( "img/eight.png", NULL );
    GdkPixbuf *Nine = gdk_pixbuf_new_from_file( "img/nine.png", NULL );

    struct WidPos position = get_number( widget, board );
    int i = position.x;

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

    struct WidPos pos_board = get_pos_on_board( board->widget, board );
    int x = pos_board.x;
    int y = pos_board.y;

    board->arr[y][x] = i+1;

    GtkWidget *image = gtk_image_new_from_pixbuf( Number );
    gtk_button_set_image( GTK_BUTTON(board->widget), image );

}

void press_start( GtkWidget *widget, gpointer data )
{
    (void)widget;

    struct BoardInfo *board = data;

    int **arr2 = (int**)malloc(9 * sizeof(int*));

    for( int i=0; i<9; i++ )
        arr2[i] = (int*)malloc(9 * sizeof(int));
    for( int i=0; i<9; i++ )
        for( int j=0; j<9; j++ )
            arr2[i][j]=board->arr[i][j];

    board->arr2 = arr2;

    bool is_sudoku = true;

    for( int i=0; i<9; i++ )
    {
        if( is_sudoku == false )    break;
        for( int j=0; j<9; j++ )
        {
            if( board->arr2[i][j] != 0 && !is_safe2( board->arr2, i, j, board->arr2[i][j] ) )
            {
                is_sudoku = false;
                break;
            }
        }
    }

    if( !is_sudoku )
    {

        GtkWidget *new_window = gtk_window_new( GTK_WINDOW_TOPLEVEL );

        gtk_window_set_position( GTK_WINDOW(new_window), GTK_WIN_POS_CENTER_ALWAYS );
        gtk_window_set_title( GTK_WINDOW(new_window), "ERROR" );
        GtkWidget *label = gtk_label_new("THAT'S NOT A SUDOKU!\n");
        gtk_container_add( GTK_CONTAINER(new_window), label );

        gtk_widget_show_all(new_window);

        return;

    }

    solve_sudoku( board->arr2 );

    board->start = true;

}

void press_check( GtkWidget *widget, gpointer data )
{
    (void)widget;

    struct BoardInfo *board = data;

    if( board->start == false )    return;
    board->start = false;

    bool is_corr = true;

    for( int i=0; i<9; i++ )
    {
        if( is_corr == true )
        {
            for( int j=0; j<9; j++ )
                if( board->arr[i][j] != board->arr2[i][j] )
                {
                    is_corr = false;
                    break;
                }
        }
    }

    g_print("Your solution:\n");
    for( int i=0; i<9; i++ )
    {
        for( int j=0; j<9; j++ )
        {
            g_print("%d ",board->arr[i][j]);
        }
        g_print("\n");
    }
    g_print("\n");
    g_print("\n");

    g_print("Correct solution:\n");
    for( int i=0; i<9; i++ )
    {
        for( int j=0; j<9; j++ )
        {
            g_print("%d ",board->arr2[i][j]);
        }
        g_print("\n");
    }
    g_print("\n");

    if( is_corr )
    {

        GtkWidget *new_window = gtk_window_new( GTK_WINDOW_TOPLEVEL );

        gtk_window_set_position( GTK_WINDOW(new_window), GTK_WIN_POS_CENTER_ALWAYS );
        gtk_window_set_title( GTK_WINDOW(new_window), "RESULT" );
        GtkWidget *label = gtk_label_new("CORRECT!\n");
        gtk_container_add( GTK_CONTAINER(new_window), label );

        gtk_widget_show_all(new_window);

    }

    else
    {

        GtkWidget *new_window = gtk_window_new( GTK_WINDOW_TOPLEVEL );

        gtk_window_set_position( GTK_WINDOW(new_window), GTK_WIN_POS_CENTER_ALWAYS );
        gtk_window_set_title( GTK_WINDOW(new_window), "RESULT" );
        GtkWidget *label = gtk_label_new("INCORRECT!\n");
        gtk_container_add( GTK_CONTAINER(new_window), label );

        gtk_widget_show_all(new_window);

    }

}
