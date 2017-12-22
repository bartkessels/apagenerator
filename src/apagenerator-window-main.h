/* apagenerator-window-main.h
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

#include <glib/gi18n.h>
#include <gtk/gtk.h>

#include "apagenerator-settings.h"
#include "apagenerator-string.h"

G_BEGIN_DECLS

#define APAGENERATOR_TYPE_WINDOW_MAIN (apagenerator_window_main_get_type ())

G_DECLARE_FINAL_TYPE (ApageneratorWindowMain, apagenerator_window_main,
											APAGENERATOR, WINDOW_MAIN, GtkApplicationWindow)

/* Window information */
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 250

/* Stack names */
#define STACK_NAME_BOOK "content_book"
#define STACK_NAME_WEBPAGE "content_webpage"

/* Public function signatures */
ApageneratorWindowMain *apagenerator_window_main_new (GApplication *app);

G_END_DECLS
