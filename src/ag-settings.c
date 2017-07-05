/*
 * ag-settings.c
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

#include <gio/gio.h>

#include "ag-settings.h"

static GSettings* ag_settings_get_settings()
{
    return g_settings_new("net.bartkessels.apagenerator");
}

const gchar* ag_settings_get_apa_string_book()
{
    GSettings* settings = ag_settings_get_settings();
    return g_settings_get_string(settings, SETTINGS_KEY_APA_BOOK);
}

const gchar* ag_settings_get_apa_string_webpage()
{
    GSettings* settings = ag_settings_get_settings();
    return g_settings_get_string(settings, SETTINGS_KEY_APA_WEBPAGE);
}

void ag_settings_set_apa_string_book(const gchar* apa_string_book)
{
    GSettings* settings = ag_settings_get_settings();
    g_settings_set_string(settings, SETTINGS_KEY_APA_BOOK, apa_string_book);
}

void ag_settings_set_apa_string_webpage(const gchar* apa_string_webpage)
{
    GSettings* settings = ag_settings_get_settings();
    g_settings_set_string(settings, SETTINGS_KEY_APA_WEBPAGE, apa_string_webpage);
}