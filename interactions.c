#include<gtk/gtk.h>
#include<stdbool.h>
#include<stdlib.h>
#include "functions.h"
#include<time.h>

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

    const char* img_names[] = { "img/one.png", "img/two.png", "img/three.png", "img/four.png", "img/five.png", "img/six.png", "img/seven.png", "img/eight.png", "img/nine.png", };

    struct WidPos position = get_number( widget, board );
    int i = position.x;

    GdkPixbuf *Number = gdk_pixbuf_new_from_file( img_names[i], NULL );

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

    board->start_t = clock();

    for( int i=0; i<9; i++ )
        for( int j=0; j<9; j++ )
            board->arr2[i][j]=board->arr[i][j];

    if( !check_if_sudoku(board) )
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

    board->end_t = clock();

    if( board->start == false )    return;
    board->start = false;

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

    bool is_corr = check_if_correct(board);

    if( is_corr )
    {

        GtkWidget *new_window = gtk_window_new( GTK_WINDOW_TOPLEVEL );

        gtk_window_set_position( GTK_WINDOW(new_window), GTK_WIN_POS_CENTER_ALWAYS );
        gtk_window_set_title( GTK_WINDOW(new_window), "RESULT" );
        GtkWidget *label = gtk_label_new("CORRECT!");
        g_print("TIME (in seconds): %d\n", (int)((board->end_t - board->start_t)/CLOCKS_PER_SEC) );
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

void destroy_board( GtkWidget *window, gpointer data )
{
    (void)window;

    struct BoardInfo *board = data;
    for( int i=0; i<9; i++ )
    {
        free(board->arr[i]);
        free(board->arr2[i]);
    }
    free(board->arr);
    free(board->arr2);
    free(board);

    return;
}

void destroy_menu( GtkWidget *window, gpointer data )
{
    (void)window;

    struct ColorInfo *color = data;

    free(color->colors);
    free(color);

    gtk_main_quit();

    return;
}
