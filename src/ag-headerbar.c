/*
 * ag-headerbar.c
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

#include "ag-headerbar.h"

G_DEFINE_TYPE(AgHeaderBar, ag_header_bar, GTK_TYPE_HEADER_BAR)

static void ag_header_bar_init(AgHeaderBar* self)
{
    // Initialize widgets
    self->menu = gtk_menu_new();
    self->ss_main = gtk_stack_switcher_new();
    self->btn_copy_to_clipboard = gtk_button_new_from_icon_name("edit-copy", GTK_ICON_SIZE_LARGE_TOOLBAR);
    self->btn_settings = gtk_menu_button_new();

    // Create menu entries
    self->mi_settings = gtk_menu_item_new_with_label("Settings");

    // Add menu entries to menu
    gtk_menu_shell_append(GTK_MENU_SHELL(self->menu), self->mi_settings);

    // Button copy to clipboard properties
    gtk_widget_set_tooltip_text(self->btn_copy_to_clipboard, "Copy APA string to clipboard");

    // Button menu
    gtk_menu_button_set_popup(GTK_MENU_BUTTON(self->btn_settings), self->menu);
    gtk_menu_button_set_direction(GTK_MENU_BUTTON(self->btn_settings), GTK_ARROW_NONE);

    // Add widgets to self
    gtk_header_bar_pack_start(GTK_HEADER_BAR(self), self->ss_main);
    gtk_header_bar_pack_end(GTK_HEADER_BAR(self), self->btn_settings);
    gtk_header_bar_pack_end(GTK_HEADER_BAR(self), self->btn_copy_to_clipboard);

    // Headerbar properties
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(self), TRUE);

    // Show widgets
    gtk_widget_show_all(self->menu);
}

static void ag_header_bar_class_init(AgHeaderBarClass* class)
{
    GtkHeaderBarClass* parent_class = GTK_HEADER_BAR_CLASS(class);
}

AgHeaderBar* ag_header_bar_new()
{
    return g_object_new(AG_TYPE_HEADER_BAR, NULL);
}

void ag_header_bar_set_title(AgHeaderBar* self, const gchar* title)
{
    gtk_header_bar_set_title(GTK_HEADER_BAR(self), title);
}

void ag_header_bar_set_stack(AgHeaderBar* self, GtkStack* stack)
{
    gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(self->ss_main), stack);
}