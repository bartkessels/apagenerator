/*
 * ag-settingswindow.h
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

#ifndef AG_SETTINGSWINDOW_H
#define AG_SETTINGSWINDOW_H

#include <glib-object.h>
#include <gtk/gtk.h>

#include "ag-application.h"
#include "ag-settings-headerbar.h"
#include "ag-settings-stack.h"

G_BEGIN_DECLS

typedef struct _AgSettingsWindow AgSettingsWindow;

#define AG_TYPE_SETTINGS_WINDOW ag_settings_window_get_type()
G_DECLARE_FINAL_TYPE(AgSettingsWindow, ag_settings_window, AG, SETTINGS_WINDOW, GtkApplicationWindow)

struct _AgSettingsWindow {
    GtkApplicationWindow parent;

    /*
        Member Variables
    */
    AgSettingsHeaderBar* header_bar;
    AgSettingsStack* stack;
};

/*
    Methods
*/
AgSettingsWindow* ag_settings_window_new();

G_END_DECLS

#endif /* AG_SETTINGSWINDOW_H */