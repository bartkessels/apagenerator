/*
 * ag-mainwindow.c
 *
 * Copyright (C) 2017 Bart Kessels <bartkessels@bk-mail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <gdk/gdk.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <string.h>

#include "ag-application.h"
#include "ag-headerbar.h"
#include "ag-mainwindow.h"
#include "ag-stack.h"
#include "ag-string.h"

G_DEFINE_TYPE(AgMainWindow, ag_main_window, GTK_TYPE_APPLICATION_WINDOW)

static void ag_main_window_btn_copy_to_clipboard_clicked(GtkWidget* caller, gpointer user_data)
{
    AgMainWindow* self = AG_MAIN_WINDOW(user_data);

    // Get APA string
    const gchar* apa_string = ag_stack_get_apa_string(self->stack);

    // Put APA string to clipboard
    GtkClipboard* clipboard;
    clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);

    // Get length of string
    int string_length;
    string_length = strlen(apa_string);

    // Put string to clipboard
    gtk_clipboard_set_text(clipboard, apa_string, string_length);
}

static void ag_main_window_init(AgMainWindow* self)
{
    // Setup stack
    self->stack = ag_stack_new();

    // Setup headerbar
    self->header_bar = ag_header_bar_new();
    ag_header_bar_set_title(self->header_bar, APPLICATION_NAME);
    ag_header_bar_set_stack(self->header_bar, GTK_STACK(self->stack));

    // Connect signals
    g_signal_connect(self->header_bar->btn_copy_to_clipboard, "clicked", G_CALLBACK(ag_main_window_btn_copy_to_clipboard_clicked), self);

    // Setup self
    gtk_window_set_titlebar(GTK_WINDOW(self), GTK_WIDGET(self->header_bar));
    gtk_window_set_default_size(GTK_WINDOW(self), 550, 250);
    gtk_container_add(GTK_CONTAINER(self), GTK_WIDGET(self->stack));
    gtk_widget_show_all(GTK_WIDGET(self));
}

static void ag_main_window_class_init(AgMainWindowClass* class)
{
    GObjectClass* parent_class = G_OBJECT_CLASS(class);
}

AgMainWindow* ag_main_window_new(AgApplication* app)
{
    return g_object_new(AG_TYPE_MAIN_WINDOW, "application", app, NULL);
}