/*
 * ag-content-book.h
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

#ifndef AG_CONTENT_BOOK_H
#define AG_CONTENT_BOOK_H

#include <glib-object.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _AgContentBook AgContentBook;

#define AG_TYPE_CONTENT_BOOK ag_content_book_get_type()
G_DECLARE_FINAL_TYPE(AgContentBook, ag_content_book, AG, CONTENT_BOOK, GtkScrolledWindow)

struct _AgContentBook {
    GtkScrolledWindow parent;

    /*
        Member Variables
    */
    GtkWidget* grd_main;
    GtkWidget* et_author;
    GtkWidget* et_year;
    GtkWidget* et_version;
    GtkWidget* et_title;
    GtkWidget* et_chapter;
    GtkWidget* et_page;
    GtkWidget* et_location;
    GtkWidget* et_publisher;
};

/*
    Methods
*/
AgContentBook* ag_content_book_new();
const gchar* ag_content_book_get_apa_string(AgContentBook* self);

G_END_DECLS

#endif /* AG_CONTENT_BOOK_H */