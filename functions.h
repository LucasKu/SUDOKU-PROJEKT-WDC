#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct BoardInfo {
    GtkWidget *widget;
    GtkWidget *grid1;
    GtkWidget *grid2;
    int **arr;
};

struct WidPos {
    int x,y;
};

void click_on_board( GtkWidget *widget, gpointer data );
void click_on_number( GtkWidget *widget, gpointer data );
void board_init();
struct WidPos get_pos_on_board( GtkWidget *widget, struct BoardInfo *board );
struct WidPos get_number( GtkWidget *widget, struct BoardInfo *board );

#endif // FUNCTIONS_H_INCLUDED
