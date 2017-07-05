/*
 * ag-content-book.c
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

#include "ag-content-book.h"
#include "ag-settings.h"
#include "ag-string.h"

G_DEFINE_TYPE(AgContentBook, ag_content_book, GTK_TYPE_SCROLLED_WINDOW)

static void ag_content_book_init(AgContentBook* self)
{
    // Self properties
    gtk_container_set_border_width(GTK_CONTAINER(self), 5);

    // Load elements from resources
    GtkBuilder* builder = gtk_builder_new_from_resource("/net/bartkessels/apagenerator/book.ui");

    self->grd_main = GTK_WIDGET(gtk_builder_get_object(builder, "grd_main"));
    self->et_author = GTK_WIDGET(gtk_builder_get_object(builder, "et_author"));
    self->et_year = GTK_WIDGET(gtk_builder_get_object(builder, "et_year"));
    self->et_version = GTK_WIDGET(gtk_builder_get_object(builder, "et_version"));
    self->et_title = GTK_WIDGET(gtk_builder_get_object(builder, "et_title"));
    self->et_chapter = GTK_WIDGET(gtk_builder_get_object(builder, "et_chapter"));
    self->et_page = GTK_WIDGET(gtk_builder_get_object(builder, "et_page"));
    self->et_location = GTK_WIDGET(gtk_builder_get_object(builder, "et_location"));
    self->et_publisher = GTK_WIDGET(gtk_builder_get_object(builder, "et_publisher"));

    // Add widgets to self
    gtk_container_add(GTK_CONTAINER(self), self->grd_main);

    g_object_unref(builder);
}

static void ag_content_book_class_init(AgContentBookClass* class)
{
    GtkScrolledWindowClass* parent_class = GTK_SCROLLED_WINDOW_CLASS(class);
}

AgContentBook* ag_content_book_new()
{
    return g_object_new(AG_TYPE_CONTENT_BOOK, NULL);
}

const gchar* ag_content_book_get_apa_string(AgContentBook* self)
{
    const gchar* apa_string = ag_settings_get_apa_string_book();
    apa_string = ag_string_replace(apa_string, "{{author}}", gtk_entry_get_text(GTK_ENTRY(self->et_author)));
    apa_string = ag_string_replace(apa_string, "{{year}}", gtk_entry_get_text(GTK_ENTRY(self->et_year)));
    apa_string = ag_string_replace(apa_string, "{{version}}", gtk_entry_get_text(GTK_ENTRY(self->et_version)));
    apa_string = ag_string_replace(apa_string, "{{title}}", gtk_entry_get_text(GTK_ENTRY(self->et_title)));
    apa_string = ag_string_replace(apa_string, "{{chapter}}", gtk_entry_get_text(GTK_ENTRY(self->et_chapter)));
    apa_string = ag_string_replace(apa_string, "{{page}}", gtk_entry_get_text(GTK_ENTRY(self->et_page)));
    apa_string = ag_string_replace(apa_string, "{{location}}", gtk_entry_get_text(GTK_ENTRY(self->et_location)));
    apa_string = ag_string_replace(apa_string, "{{publisher}}", gtk_entry_get_text(GTK_ENTRY(self->et_publisher)));

    return apa_string;
}