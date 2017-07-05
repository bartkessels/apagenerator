/*
 * ag-settings-content-book.c
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

#include "ag-settings-content-book.h"
#include "ag-settings.h"

G_DEFINE_TYPE(AgSettingsContentBook, ag_settings_content_book, GTK_TYPE_SCROLLED_WINDOW)

static void ag_settings_content_book_init(AgSettingsContentBook* self)
{
    // Self properties
    gtk_container_set_border_width(GTK_CONTAINER(self), 5);

    // Load elements from resources
    GtkBuilder* builder = gtk_builder_new_from_resource("/net/bartkessels/apagenerator/settings_book.ui");

    self->grd_main = GTK_WIDGET(gtk_builder_get_object(builder, "grd_main"));
    self->et_apa_string = GTK_WIDGET(gtk_builder_get_object(builder, "et_apa_string"));

    // Load apa string from settings
    const gchar* apa_string = ag_settings_get_apa_string_book();
    gtk_entry_set_text(GTK_ENTRY(self->et_apa_string), apa_string);

    // Add widgets to self
    gtk_container_add(GTK_CONTAINER(self), self->grd_main);

    g_object_unref(builder);
}

static void ag_settings_content_book_class_init(AgSettingsContentBookClass* class)
{
    GtkScrolledWindowClass* parent_class = GTK_SCROLLED_WINDOW_CLASS(class);
}

AgSettingsContentBook* ag_settings_content_book_new()
{
    return g_object_new(AG_TYPE_SETTINGS_CONTENT_BOOK, NULL);
}