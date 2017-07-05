/*
 * ag-content-webpage.c
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

#include "ag-content-webpage.h"
#include "ag-settings.h"
#include "ag-string.h"

G_DEFINE_TYPE(AgContentWebpage, ag_content_webpage, GTK_TYPE_SCROLLED_WINDOW)

static void ag_content_webpage_init(AgContentWebpage* self)
{
    // Self properties
    gtk_container_set_border_width(GTK_CONTAINER(self), 5);

    // Load elements from resources
    GtkBuilder* builder = gtk_builder_new_from_resource("/net/bartkessels/apagenerator/webpage.ui");

    self->grd_main = GTK_WIDGET(gtk_builder_get_object(builder, "grd_main"));
    self->et_author = GTK_WIDGET(gtk_builder_get_object(builder, "et_author"));
    self->et_title = GTK_WIDGET(gtk_builder_get_object(builder, "et_title"));
    self->et_date_published = GTK_WIDGET(gtk_builder_get_object(builder, "et_date_published"));
    self->et_date_consulted = GTK_WIDGET(gtk_builder_get_object(builder, "et_date_consulted"));
    self->et_uri = GTK_WIDGET(gtk_builder_get_object(builder, "et_uri"));

    // Add widgets to self
    gtk_container_add(GTK_CONTAINER(self), self->grd_main);

    g_object_unref(builder);
}

static void ag_content_webpage_class_init(AgContentWebpageClass* class)
{
    GtkScrolledWindowClass* parent_class = GTK_SCROLLED_WINDOW_CLASS(class);
}

AgContentWebpage* ag_content_webpage_new()
{
    return g_object_new(AG_TYPE_CONTENT_WEBPAGE, NULL);
}

const gchar* ag_content_webpage_get_apa_string(AgContentWebpage* self)
{
    const gchar* apa_string = ag_settings_get_apa_string_webpage();
    apa_string = ag_string_replace(apa_string, "{{author}}", gtk_entry_get_text(GTK_ENTRY(self->et_author)));
    apa_string = ag_string_replace(apa_string, "{{title}}", gtk_entry_get_text(GTK_ENTRY(self->et_title)));
    apa_string = ag_string_replace(apa_string, "{{date_published}}", gtk_entry_get_text(GTK_ENTRY(self->et_date_published)));
    apa_string = ag_string_replace(apa_string, "{{date_consulted}}", gtk_entry_get_text(GTK_ENTRY(self->et_date_consulted)));
    apa_string = ag_string_replace(apa_string, "{{uri}}", gtk_entry_get_text(GTK_ENTRY(self->et_uri)));

    return apa_string;
}