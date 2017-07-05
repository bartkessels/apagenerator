/*
 * ag-settings-headerbar.h
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

#ifndef AG_SETTINGS_HEADERBAR_H
#define AG_SETTINGS_HEADERBAR_H

#include <glib-object.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _AgSettingsHeaderBar AgSettingsHeaderBar;

#define AG_TYPE_SETTINGS_HEADER_BAR ag_settings_header_bar_get_type()
G_DECLARE_FINAL_TYPE(AgSettingsHeaderBar, ag_settings_header_bar, AG, SETTINGS_HEADER_BAR, GtkHeaderBar)

struct _AgSettingsHeaderBar {
    GtkHeaderBar parent;

    /*
        Member Variables
    */
    GtkWidget* ss_main;
    GtkWidget* btn_save;
    GtkWidget* btn_cancel;
};

/*
    Methods
*/
AgSettingsHeaderBar* ag_settings_header_bar_new();
void ag_settings_header_bar_set_title(AgSettingsHeaderBar* self, const gchar* title, const gchar* subtitle);
void ag_settings_header_bar_set_stack(AgSettingsHeaderBar* self, GtkStack* stack);

G_END_DECLS

#endif /* AG_SETTINGS_HEADERBAR_H */