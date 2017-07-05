/*
 * ag-headerbar.h
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

#ifndef AG_HEADERBAR_H
#define AG_HEADERBAR_H

#include <glib-object.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _AgHeaderBar AgHeaderBar;

#define AG_TYPE_HEADER_BAR ag_header_bar_get_type()
G_DECLARE_FINAL_TYPE(AgHeaderBar, ag_header_bar, AG, HEADER_BAR, GtkHeaderBar)

struct _AgHeaderBar {
    GtkHeaderBar parent;

    /*
        Member Variables
    */
    GtkWidget* menu;
    GtkWidget* ss_main;
    GtkWidget* btn_copy_to_clipboard;
    GtkWidget* btn_settings;
    GtkWidget* mi_settings;
};

/*
    Methods
*/
AgHeaderBar* ag_header_bar_new();
void ag_header_bar_set_title(AgHeaderBar* self, const gchar* title);
void ag_header_bar_set_stack(AgHeaderBar* self, GtkStack* stack);

G_END_DECLS

#endif /* AG_HEADERBAR_H */