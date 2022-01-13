#include<gtk/gtk.h>
#include "functions.h"

void click_on_board( GtkWidget *widget, gpointer data )
{

    struct BoardInfo *board = data;

    GdkPixbuf *Empty = gdk_pixbuf_new_from_file( "img/empty.png", NULL );
    GdkPixbuf *Hover = gdk_pixbuf_new_from_file( "img/hover.png", NULL );
    GtkWidget *image1 = gtk_image_new_from_pixbuf( Hover );
    GtkWidget *image2 = gtk_image_new_from_pixbuf( Empty );

    struct WidPos position = get_pos_on_board( widget, board );
    g_print("row: %d col: %d\n", position.y, position.x);

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
