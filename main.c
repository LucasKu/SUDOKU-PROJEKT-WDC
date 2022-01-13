#include<gtk/gtk.h>
#include "functions.h"

int main(int argc, char **argv)
{

    gtk_init(&argc, &argv);

    board_init();

    gtk_main();

}
