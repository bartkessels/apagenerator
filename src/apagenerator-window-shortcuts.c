/* apagenerator-window-shortcuts.c
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

#include "apagenerator-window-shortcuts.h"

struct _ApageneratorWindowShortcuts {
    GtkShortcutsWindow parent_instance;
};

G_DEFINE_TYPE (ApageneratorWindowShortcuts, apagenerator_window_shortcuts, GTK_TYPE_SHORTCUTS_WINDOW)

/*
 * =============================================================================
 * Signatures
 *
 */
static void apagenerator_window_shortcuts_class_init (ApageneratorWindowShortcutsClass *klass);
static void apagenerator_window_shortcuts_init (ApageneratorWindowShortcuts *self);

 /*
 * =============================================================================
 * Public function implementations
 *
 */
ApageneratorWindowShortcuts *
apagenerator_window_shortcuts_new (GtkWindow *parent_window)
{
    g_assert (GTK_IS_WINDOW (parent_window));

    ApageneratorWindowShortcuts *window_shortcuts;

    window_shortcuts = g_object_new (APAGENERATOR_TYPE_WINDOW_SHORTCUTS,
                                     "transient-for", parent_window,
                                     NULL);

    return window_shortcuts;
}

 /*
 * =============================================================================
 * Private function implementations
 *
 */
static void
apagenerator_window_shortcuts_class_init (ApageneratorWindowShortcutsClass *klass)
{
    GtkWidgetClass *widget_class;

    widget_class = GTK_WIDGET_CLASS (klass);

    gtk_widget_class_set_template_from_resource (widget_class, "/net/bartkessels/apagenerator/window-shortcuts.ui");
}

static void
apagenerator_window_shortcuts_init (ApageneratorWindowShortcuts *self)
{
    g_assert (GTK_IS_WIDGET (self));

    gtk_widget_init_template (GTK_WIDGET (self));
}
