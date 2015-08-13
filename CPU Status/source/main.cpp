#include<stdio.h>
#include<stdlib.h>
#include<GL/glew.h>

#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gprintf.h>

void print_msg(GtkWidget *widget, gpointer window) {

    g_printf("Button clicked\n");
}

GdkPixbuf *create_pixbuf(const gchar * filename){

    /*The gdk_pixbuf_new_from_file() function creates a new pixbuf by loading an image from a file.
     * The file format is detected automatically. If NULL is returned, then an error will be set.*/
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);

    //error message in case the file could not be found.
    if (!pixbuf){
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }
    return pixbuf;
}


int main(int argc, char *argv[])
{
    //program starts here...
    GdkPixbuf *icon;

    GtkWidget *window;
    GtkWidget *vbox;

    GtkWidget *menubar;
    GtkWidget *fileMenu;
    GtkWidget *fileMi;
    GtkWidget *quitMi;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_title(GTK_WINDOW(window), "MyApp");
    icon = create_pixbuf("/home/raphael/ClionProjects/CPU Status/misc/radio.png");
    gtk_window_set_icon(GTK_WINDOW(window), icon);

    vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    menubar = gtk_menu_bar_new();
    fileMenu = gtk_menu_new();

    fileMi = gtk_menu_item_new_with_label("File");
    quitMi = gtk_menu_item_new_with_label("Quit");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

    g_signal_connect(G_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    g_signal_connect(G_OBJECT(quitMi), "activate",
                     G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    //only works in full screen ubuntu 14.04

    return 0;
}

