/*
 * ag-stack.h
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

#ifndef AG_STACK_H
#define AG_STACK_H

#include <glib-object.h>
#include <gtk/gtk.h>

#include "ag-content-book.h"
#include "ag-content-webpage.h"

G_BEGIN_DECLS

typedef struct _AgStack AgStack;

#define AG_TYPE_STACK ag_stack_get_type()
G_DECLARE_FINAL_TYPE(AgStack, ag_stack, AG, STACK, GtkStack)

struct _AgStack {
    GtkStack parent;

    /*
        Member Variables
    */
    AgContentBook* content_book;
    AgContentWebpage* content_webpage;
};

/*
    Methods
*/
AgStack* ag_stack_new();
const gchar* ag_stack_get_apa_string(AgStack* self);

G_END_DECLS

#endif /* AG_STACK_H */