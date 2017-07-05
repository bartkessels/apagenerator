/*
 * ag-settings.h
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

#ifndef AG_SETTINGS_H
#define AG_SETTINGS_H

#include <gio/gio.h>
#include <glib.h>

#define SETTINGS_KEY_APA_BOOK "apa-string-book"
#define SETTINGS_KEY_APA_WEBPAGE "apa-string-webpage"

const gchar* ag_settings_get_apa_string_book();
const gchar* ag_settings_get_apa_string_webpage();
void ag_settings_set_apa_string_book(const gchar* apa_string_book);
void ag_settings_set_apa_string_webpage(const gchar* apa_string_webpage);

#endif /* AG_SETTINGS_H */