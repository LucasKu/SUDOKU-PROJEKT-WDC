#include<gtk/gtk.h>
#include<stdlib.h>
#include<stdbool.h>
#include "functions.h"

void menu_init()
{

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *layout = gtk_layout_new(NULL, NULL);

    gtk_window_set_position( GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS );
    gtk_window_set_title( GTK_WINDOW(window), "MAIN MENU" );
    gtk_window_set_default_size( GTK_WINDOW(window), 300, 300 );

    gtk_container_add( GTK_CONTAINER(window), layout );

    struct ColorInfo *color = (struct ColorInfo*)malloc(sizeof(struct ColorInfo));

    GtkWidget **colors = (GtkWidget**)malloc(3*sizeof(GtkWidget*));

    colors[0] = (GtkWidget*)malloc(sizeof(GtkWidget));
    colors[1] = (GtkWidget*)malloc(sizeof(GtkWidget));
    colors[2] = (GtkWidget*)malloc(sizeof(GtkWidget));

    colors[0] = gtk_button_new_with_label("DEFAULT");
    colors[1] = gtk_button_new_with_label(" BLUE ");
    colors[2] = gtk_button_new_with_label(" GREEN ");

    color->colors = colors;
    color->color = 0;

    g_signal_connect( G_OBJECT(colors[0]), "clicked", G_CALLBACK(set_color), color );
    g_signal_connect( G_OBJECT(colors[1]), "clicked", G_CALLBACK(set_color), color );
    g_signal_connect( G_OBJECT(colors[2]), "clicked", G_CALLBACK(set_color), color );

    gtk_layout_put( GTK_LAYOUT(layout), colors[0], 0, 0 );
    gtk_layout_put( GTK_LAYOUT(layout), colors[1], 100, 0 );
    gtk_layout_put( GTK_LAYOUT(layout), colors[2], 200, 0 );

    GtkWidget *start_button = gtk_button_new_with_label("START");

    g_signal_connect( G_OBJECT(start_button), "clicked", G_CALLBACK(board_init), color );
    gtk_layout_put( GTK_LAYOUT(layout), start_button, 120, 120 );

    g_signal_connect( G_OBJECT(window), "destroy", G_CALLBACK(destroy_menu), color );

    gtk_widget_show_all( window );

    return;

}
