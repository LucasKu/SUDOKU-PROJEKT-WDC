#include<gtk/gtk.h>
#include<stdbool.h>
#include "functions.h"

int main(int argc, char **argv)
{

    gtk_init(&argc, &argv);

    menu_init();

    gtk_main();

}
