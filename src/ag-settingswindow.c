/*
 * ag-settingswindow.c
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

#include <glib-object.h>
#include <gtk/gtk.h>

#include "ag-application.h"
#include "ag-settings-headerbar.h"
#include "ag-settings-stack.h"
#include "ag-settings.h"
#include "ag-settingswindow.h"

G_DEFINE_TYPE(AgSettingsWindow, ag_settings_window, GTK_TYPE_APPLICATION_WINDOW)

static void ag_settings_window_btn_save_clicked(GtkWidget* caller, gpointer user_data)
{
    AgSettingsWindow* self = AG_SETTINGS_WINDOW(user_data);

    // Read apa string from entries
    const gchar* apa_string_book = gtk_entry_get_text(GTK_ENTRY(self->stack->content_book->et_apa_string));
    const gchar* apa_string_webpage = gtk_entry_get_text(GTK_ENTRY(self->stack->content_webpage->et_apa_string));

    // Save apa strings
    ag_settings_set_apa_string_book(apa_string_book);
    ag_settings_set_apa_string_webpage(apa_string_webpage);

    gtk_window_close(GTK_WINDOW(self));
}

static void ag_settings_window_btn_cancel_clicked(GtkWidget* caller, gpointer user_data)
{
    gtk_window_close(GTK_WINDOW(user_data));
}

static void ag_settings_window_init(AgSettingsWindow* self)
{
    // Setup stack
    self->stack = ag_settings_stack_new();

    // Setup headerbar
    self->header_bar = ag_settings_header_bar_new();
    ag_settings_header_bar_set_title(self->header_bar, APPLICATION_NAME, "Settings");
    ag_settings_header_bar_set_stack(self->header_bar, GTK_STACK(self->stack));

    // Connect signals
    g_signal_connect(self->header_bar->btn_save, "clicked", G_CALLBACK(ag_settings_window_btn_save_clicked), self);
    g_signal_connect(self->header_bar->btn_cancel, "clicked", G_CALLBACK(ag_settings_window_btn_cancel_clicked), self);

    // Setup self
    gtk_window_set_titlebar(GTK_WINDOW(self), GTK_WIDGET(self->header_bar));
    gtk_window_set_default_size(GTK_WINDOW(self), 600, 400);
    gtk_container_add(GTK_CONTAINER(self), GTK_WIDGET(self->stack));
    gtk_widget_show_all(GTK_WIDGET(self));
}

static void ag_settings_window_class_init(AgSettingsWindowClass* class)
{
    GtkApplicationWindowClass* parent_class = GTK_APPLICATION_WINDOW_CLASS(class);
}

AgSettingsWindow* ag_settings_window_new(AgApplication* app)
{
    return g_object_new(AG_TYPE_SETTINGS_WINDOW, "application", app, NULL);
}