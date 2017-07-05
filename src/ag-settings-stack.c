/*
 * ag-settings-stack.c
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
#include "ag-settings-content-webpage.h"
#include "ag-settings-stack.h"

G_DEFINE_TYPE(AgSettingsStack, ag_settings_stack, GTK_TYPE_STACK)

static void ag_settings_stack_init(AgSettingsStack* self)
{
    // Self properties
    gtk_stack_set_transition_type(GTK_STACK(self), GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);

    // Add stacks
    self->content_book = ag_settings_content_book_new();
    self->content_webpage = ag_settings_content_webpage_new();

    gtk_stack_add_titled(GTK_STACK(self), GTK_WIDGET(self->content_book), "content_book", "Book");
    gtk_stack_add_titled(GTK_STACK(self), GTK_WIDGET(self->content_webpage), "content_webpage", "Webpage");
}

static void ag_settings_stack_class_init(AgSettingsStackClass* class)
{
    GtkStackClass* parent_class = GTK_STACK_CLASS(class);
}

AgSettingsStack* ag_settings_stack_new()
{
    return g_object_new(AG_TYPE_SETTINGS_STACK, NULL);
}