/*
 * ag-settings-headerbar.c
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

#include "ag-settings-headerbar.h"

G_DEFINE_TYPE(AgSettingsHeaderBar, ag_settings_header_bar, GTK_TYPE_HEADER_BAR)

static void ag_settings_header_bar_init(AgSettingsHeaderBar* self)
{
    // Initialize widgets
    self->ss_main = gtk_stack_switcher_new();
    self->btn_save = gtk_button_new_with_label("Save");
    self->btn_cancel = gtk_button_new_with_label("Cancel");

    // Button save properties
    GtkStyleContext* btn_save_style_context = gtk_widget_get_style_context(self->btn_save);
    gtk_style_context_add_class(btn_save_style_context, "suggested-action");

    // Button cancel properties
    GtkStyleContext* btn_cancel_style_context = gtk_widget_get_style_context(self->btn_cancel);
    gtk_style_context_add_class(btn_cancel_style_context, "destructive-action");

    // Add widgets to self
    gtk_header_bar_pack_start(GTK_HEADER_BAR(self), self->ss_main);
    gtk_header_bar_pack_end(GTK_HEADER_BAR(self), self->btn_save);
    gtk_header_bar_pack_end(GTK_HEADER_BAR(self), self->btn_cancel);

    // Headerbar properties
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(self), FALSE);
}

static void ag_settings_header_bar_class_init(AgSettingsHeaderBarClass* class)
{
    GtkHeaderBarClass* parent_class = GTK_HEADER_BAR_CLASS(class);
}

AgSettingsHeaderBar* ag_settings_header_bar_new()
{
    return g_object_new(AG_TYPE_SETTINGS_HEADER_BAR, NULL);
}

void ag_settings_header_bar_set_title(AgSettingsHeaderBar* self, const gchar* title, const gchar* subtitle)
{
    gtk_header_bar_set_title(GTK_HEADER_BAR(self), title);
    gtk_header_bar_set_subtitle(GTK_HEADER_BAR(self), subtitle);
}

void ag_settings_header_bar_set_stack(AgSettingsHeaderBar* self, GtkStack* stack)
{
    gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(self->ss_main), stack);
}