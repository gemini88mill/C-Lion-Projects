#include <iostream>
//#include "GTK+_defs.h"
#include <gtk-3.0/gtk/gtk.h>

GdkPixbuf *create_pixbuf(const gchar * filename) {

    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);

    if (!pixbuf) {
        //error messages when an icon could not be found
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }

    return pixbuf;
}

int main(int argc, char *argv[]) {

    int height = 800;
    int width = 600;


    //variables from GTK+
    GtkWidget *window;
    GtkWidget *vbox;

    GtkWidget *menubar;
    GtkWidget *fileMenu;
    GtkWidget *fileMi;
    GtkWidget *quitMi;

    GtkWidget *button;
    GtkWidget *table;



    GdkPixbuf *icon;

    //initializes the gtk+ gui
    gtk_init(&argc, &argv);

    //
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "icon");
    gtk_window_set_default_size(GTK_WINDOW(window), height, width);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    //vbox = gtk_vbox_new(FALSE, 0); //deprecated find alternative
    //gtk_container_add(GTK_CONTAINER(window), vbox);

    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    table = gtk_table_new(4, 4, TRUE);
    gtk_table_set_row_spacings(GTK_TABLE(table), 2);
    gtk_table_set_col_spacings(GTK_TABLE(table), 2);
    button = gtk_button_new_with_label("hello");



    // creates a new menubar
    menubar = gtk_menu_bar_new();
    //creates a new gtk menu
    fileMenu = gtk_menu_new();


    fileMi = gtk_menu_item_new_with_label("File");
    quitMi = gtk_menu_item_new_with_label("Quit");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

    icon = create_pixbuf("/home/raphael/ClionProjects/StarDust/media/icons/radio.png");
    gtk_window_set_icon(GTK_WINDOW(window), icon);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(quitMi), "activate", G_CALLBACK(gtk_main_quit), NULL);

    gtk_container_add(GTK_CONTAINER(window), table);

    gtk_widget_show_all(window);

    g_object_unref(icon);

    gtk_main();

    printf("Hello world");
    return 0;
}