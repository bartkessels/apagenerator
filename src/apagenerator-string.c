/*
 * ag-string.c
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

#include <glib.h>
#include <string.h>

const gchar *
apagenerator_string_replace (const gchar *original_string,
                             const gchar *string_to_replace,
                             const gchar *string_to_replace_with)
{
    g_assert_nonnull (original_string);
    g_assert_nonnull (string_to_replace);
    g_assert_nonnull (string_to_replace_with);

    gchar **splitted_string;
    gchar *final_string;

    /*
     * Check if the splitted string is not NULL, return the original string if it is
     */
    splitted_string = g_strsplit (original_string, string_to_replace, 2);
    if (splitted_string == NULL) {
        return original_string;
    }

    final_string = g_strconcat (splitted_string[0], string_to_replace_with, splitted_string[1], NULL);

    return final_string;
}
