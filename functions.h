#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct BoardInfo {
    GtkWidget *widget;
    GtkWidget *grid1;
    GtkWidget *grid2;
};

void click_on_board( GtkWidget *widget, gpointer data );
void click_on_number( GtkWidget *widget, gpointer data );
void board_init();

#endif // FUNCTIONS_H_INCLUDED
