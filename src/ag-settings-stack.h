/*
 * ag-settings-stack.h
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

#ifndef AG_SETTINGS_STACK_H
#define AG_SETTINGS_STACK_H

#include <glib-object.h>
#include <gtk/gtk.h>

#include "ag-settings-content-book.h"
#include "ag-settings-content-webpage.h"

G_BEGIN_DECLS

typedef struct _AgSettingsStack AgSettingsStack;

#define AG_TYPE_SETTINGS_STACK ag_settings_stack_get_type()
G_DECLARE_FINAL_TYPE(AgSettingsStack, ag_settings_stack, AG, SETTINGS_STACK, GtkStack)

struct _AgSettingsStack {
    GtkStack parent;

    /*
        Member Variables
    */
    AgSettingsContentBook* content_book;
    AgSettingsContentWebpage* content_webpage;
};

/*
    Methods
*/
AgSettingsStack* ag_settings_stack_new();

G_END_DECLS

#endif /* AG_SETTINGS_STACK_H */