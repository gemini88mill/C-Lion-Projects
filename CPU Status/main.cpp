#include<stdio.h>
#include<stdlib.h>
#include<GL/glew.h>

#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gprintf.h>

GdkPixbuf *create_pixbuf(const gchar * filename){
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);

    if (!pixbuf){
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }
    return pixbuf;
}


int main(int argc, char *argv[])
{
    //program starts here...
    GtkWidget *window;
    GdkPixbuf *icon;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "Center");
    gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    icon = create_pixbuf("/home/raphael/ClionProjects/CPU Status/misc/radio.png");
    gtk_window_set_icon(GTK_WINDOW(window), icon);

    gtk_widget_show(window);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    g_object_unref(icon);

    gtk_main();

    g_printf("GTK+ version: %d.%d.%d\n", gtk_major_version,
             gtk_minor_version, gtk_micro_version);
    g_printf("Glib version: %d.%d.%d\n", glib_major_version,
             glib_minor_version, glib_micro_version);
    return 0;
}

