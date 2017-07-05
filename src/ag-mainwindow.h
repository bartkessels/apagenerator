/*
 * ag-mainwindow.h
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

#ifndef AG_MAINWINDOW_H
#define AG_MAINWINDOW_H

#include <glib-object.h>
#include <gtk/gtk.h>

#include "ag-application.h"
#include "ag-headerbar.h"
#include "ag-stack.h"

G_BEGIN_DECLS

typedef struct _AgMainWindow AgMainWindow;

#define AG_TYPE_MAIN_WINDOW ag_main_window_get_type()
G_DECLARE_FINAL_TYPE(AgMainWindow, ag_main_window, AG, MAIN_WINDOW, GtkApplicationWindow)

struct _AgMainWindow {
    GtkApplicationWindow parent;

    /*
        Member Variables
    */
    AgHeaderBar* header_bar;
    AgStack* stack;
};

/*
    Methods
*/
AgMainWindow* ag_main_window_new(AgApplication* app);

G_END_DECLS

#endif /* AG_MAINWINDOW_H */