/* apagenerator-settings.h
 *
 * Copyright © 2017 Bart Kessels <bartkessels@bk-mail.com>
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
 */

#pragma once

#include <gio/gio.h>
#include <glib.h>

#include "apagenerator-app.h"

/* Settings keys */
#define SETTINGS_KEY_APA_STRING_BOOK "apa-string-book"
#define SETTINGS_KEY_APA_STRING_WEBPAGE "apa-string-webpage"

/* Public function signatures */
void apagenerator_settings_set_apa_string_book (const gchar *apa_string_book);
void apagenerator_settings_set_apa_string_webpage (const gchar *apa_string_webpage);

const gchar *apagenerator_settings_get_apa_string_book ();
const gchar *apagenerator_settings_get_apa_string_webpage ();
const gchar *apagenerator_settings_get_apa_string (const gchar *settings_key);
