#include <gtk/gtk.h>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define APP_TITLE "APA Generator"
#define APP_SUBTITLE "Generate APA Sources"

void
activate_application(GtkApplication *app,
                     gpointer        user_data);

void
btn_copy_clipboard_clicked(GtkWidget *button,
                           gpointer  *selected_stack);

void
copy_to_clipboard(gchar *string);

#endif /* MAINWINDOW_H */
