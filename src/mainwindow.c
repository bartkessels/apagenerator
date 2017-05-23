#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <string.h>

#include "apagenerator.h"
#include "mainwindow.h"
#include "stack.h"

void
activate_application(GtkApplication *app,
                     gpointer        user_data)
{
  GtkStack *stack;
  GtkWidget *stack_switcher;
  GtkWidget *btn_copy_clipboard;
  GtkWidget *header_bar;
  GtkWidget *scrolled_window;
  GtkWidget *window;

  // Create stack
  stack = create_stack ();

  // Create stack_switcher
  stack_switcher = gtk_stack_switcher_new();
  gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(stack_switcher), stack);

  // Create copy to clipboard button
  btn_copy_clipboard = gtk_button_new_from_icon_name("edit-copy", GTK_ICON_SIZE_LARGE_TOOLBAR);
  g_signal_connect(btn_copy_clipboard, "clicked", G_CALLBACK(btn_copy_clipboard_clicked), stack);

  // Create header_bar
  header_bar = gtk_header_bar_new();
  gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header_bar), TRUE);
  gtk_header_bar_set_title(GTK_HEADER_BAR(header_bar), APP_TITLE);
  gtk_header_bar_set_subtitle(GTK_HEADER_BAR(header_bar), APP_SUBTITLE);
  gtk_header_bar_pack_start(GTK_HEADER_BAR(header_bar), stack_switcher);
  gtk_header_bar_pack_end(GTK_HEADER_BAR(header_bar), btn_copy_clipboard);

  // Allow window to scroll
  scrolled_window = gtk_scrolled_window_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(scrolled_window), GTK_WIDGET(stack));

  // Create window
  window = gtk_application_window_new(app);
  gtk_window_set_titlebar(GTK_WINDOW(window), header_bar);
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
  gtk_container_set_border_width(GTK_CONTAINER(window), 5);
  gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(scrolled_window));

  gtk_widget_show_all(window);
}

void
btn_copy_clipboard_clicked(GtkWidget *button,
                           gpointer  *selected_stack)
{
  const gchar *stack_name = gtk_stack_get_visible_child_name(GTK_STACK(selected_stack));
  gchar *apa_string;

  if(strcmp(stack_name, "book") == 0) {
    apa_string = generate_apa_book();
  } else if(strcmp(stack_name, "webpage") == 0) {
    apa_string = generate_apa_webpage();
  }

  if(apa_string != NULL) {
    copy_to_clipboard(apa_string);
  }
}

void
copy_to_clipboard(gchar *string)
{
  // Get clipboard
  GtkClipboard *clipboard;
  clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);

  // Get length of string
  int string_length;
  string_length = strlen(string);

  // Put string to clipboard
  gtk_clipboard_set_text(clipboard, string, string_length);
}
