/*
 * ag-application.h
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

#ifndef AG_APPLICATION_H
#define AG_APPLICATION_H

#include <glib-object.h>
#include <gtk/gtk.h>

#define APPLICATION_NAME "APA Generator"

G_BEGIN_DECLS

typedef struct _AgApplication AgApplication;

#define AG_TYPE_APPLICATION ag_application_get_type()
G_DECLARE_FINAL_TYPE(AgApplication, ag_application, AG, APPLICATION, GtkApplication)

struct _AgApplication {
    GtkApplication parent;
};

/*
    Methods
*/
AgApplication* ag_application_new();

G_END_DECLS

#endif /* AG_APPLICATION_H */