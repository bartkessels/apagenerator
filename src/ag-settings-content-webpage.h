/*
 * ag-settings-content-webpage.h
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

#ifndef AG_SETTINGS_CONTENT_WEBPAGE_H
#define AG_SETTINGS_CONTENT_WEBPAGE_H

#include <glib-object.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _AgSettingsContentWebpage AgSettingsContentWebpage;

#define AG_TYPE_SETTINGS_CONTENT_WEBPAGE ag_settings_content_webpage_get_type()
G_DECLARE_FINAL_TYPE(AgSettingsContentWebpage, ag_settings_content_webpage, AG, SETTINGS_CONTENT_WEBPAGE, GtkScrolledWindow)

struct _AgSettingsContentWebpage {
    GtkScrolledWindow parent;

    /*
        Member Variables
    */
    GtkWidget* grd_main;
    GtkWidget* et_apa_string;
};

/*
    Methods
*/
AgSettingsContentWebpage* ag_settings_content_webpage_new();

G_END_DECLS

#endif /* AG_SETTINGS_CONTENT_WEBPAGE_H */