/*
 * ag-content-webpage.h
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

#ifndef AG_CONTENT_WEBPAGE_H
#define AG_CONTENT_WEBPAGE_H

#include <glib-object.h>

G_BEGIN_DECLS

typedef struct _AgContentWebpage AgContentWebpage;

#define AG_TYPE_CONTENT_WEBPAGE ag_content_webpage_get_type()
G_DECLARE_FINAL_TYPE(AgContentWebpage, ag_content_webpage, AG, CONTENT_WEBPAGE, GtkScrolledWindow)

struct _AgContentWebpage {
    GtkScrolledWindow parent;

    /*
        Member Variables
    */
    GtkWidget* grd_main;
    GtkWidget* et_author;
    GtkWidget* et_title;
    GtkWidget* et_date_published;
    GtkWidget* et_date_consulted;
    GtkWidget* et_uri;
};

/*
    Methods
*/
AgContentWebpage* ag_content_webpage_new();
const gchar* ag_content_webpage_get_apa_string(AgContentWebpage* self);

G_END_DECLS

#endif /* AG_CONTENT_WEBPAGE_H */