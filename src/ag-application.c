/*
 * ag-application.c
 *
 * Copyright (C) 2017 Bart Kessels <bartkessels@outlook.com>
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

#include <gio/gio.h>
#include <glib-object.h>
#include <gtk/gtk.h>

#include "ag-application.h"
#include "ag-mainwindow.h"
#include "ag-settingswindow.h"

G_DEFINE_TYPE(AgApplication, ag_application, GTK_TYPE_APPLICATION)

static void ag_application_mi_settings_activated(GtkWidget* caller, gpointer user_data)
{
    AgApplication* self = AG_APPLICATION(user_data);

    AgSettingsWindow* settings_window = ag_settings_window_new(AG_APPLICATION(self));
    gtk_window_present(GTK_WINDOW(settings_window));
}

static void ag_application_init(AgApplication* self) {}

static void ag_application_activate(GApplication* self)
{
    AgMainWindow* window = ag_main_window_new(AG_APPLICATION(self));
    gtk_window_present(GTK_WINDOW(window));

    // Connect signals
    g_signal_connect(window->header_bar->mi_settings, "activate", G_CALLBACK(ag_application_mi_settings_activated), self);
}

static void ag_application_class_init(AgApplicationClass* class)
{
    GApplicationClass* parent_class = G_APPLICATION_CLASS(class);

    parent_class->activate = ag_application_activate;
}

AgApplication* ag_application_new()
{
    return g_object_new(AG_TYPE_APPLICATION,
        "application-id", "net.bartkessels.apagenerator",
        "flags", G_APPLICATION_FLAGS_NONE,
        NULL);
}

void ag_application_sa_settings_clicked(GSimpleAction* action, GVariant* parameter, gpointer user_data)
{
    g_print("SETTINGS\n");
}