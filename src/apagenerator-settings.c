/* apagenerator-settings.c
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

#include "apagenerator-settings.h"

/*
 * =============================================================================
 * Signatures
 *
 */
static GSettings *apagenerator_settings_get_gsettings ();

 /*
 * =============================================================================
 * Public function implementations
 *
 */
void
apagenerator_settings_set_apa_string_book (const gchar *apa_string_book)
{
    g_assert_nonnull (apa_string_book);

    GSettings *settings;

    settings = apagenerator_settings_get_gsettings ();

    g_settings_set_string (settings, SETTINGS_KEY_APA_STRING_BOOK, apa_string_book);
}

void
apagenerator_settings_set_apa_string_webpage (const gchar *apa_string_webpage)
{
    g_assert_nonnull (apa_string_webpage);

    GSettings *settings;

    settings = apagenerator_settings_get_gsettings ();

    g_settings_set_string (settings, SETTINGS_KEY_APA_STRING_WEBPAGE, apa_string_webpage);
}

const gchar *
apagenerator_settings_get_apa_string_book ()
{
    GSettings *settings;
    const gchar *apa_string_book;

    settings = apagenerator_settings_get_gsettings ();
    apa_string_book = g_settings_get_string (settings, SETTINGS_KEY_APA_STRING_BOOK);

    return apa_string_book;
}

const gchar *
apagenerator_settings_get_apa_string_webpage ()
{
    GSettings *settings;
    const gchar *apa_string_webpage;

    settings = apagenerator_settings_get_gsettings ();
    apa_string_webpage = g_settings_get_string (settings, SETTINGS_KEY_APA_STRING_WEBPAGE);

    return apa_string_webpage;
}

const gchar *
apagenerator_settings_get_apa_string (const gchar *settings_key)
{
    g_assert_nonnull (settings_key);

    const gchar *apa_string;

    apa_string = "";

    if (g_str_equal (settings_key, SETTINGS_KEY_APA_STRING_BOOK)) {
        apa_string = apagenerator_settings_get_apa_string_book ();
    } else if (g_str_equal (settings_key, SETTINGS_KEY_APA_STRING_WEBPAGE)) {
        apa_string = apagenerator_settings_get_apa_string_webpage ();
    }

    return apa_string;
}

/*
 * =============================================================================
 * Private function implementations
 *
 */
static GSettings *
apagenerator_settings_get_gsettings ()
{
    GSettings *settings;

    settings = g_settings_new (APPLICATION_ID);

    return settings;
}
