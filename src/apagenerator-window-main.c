/* apagenerator-window-main.c
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

#include "apagenerator-window-main.h"

struct _ApageneratorWindowMain {
    GtkApplicationWindow parent_instance;

    /* Template widgets */
    GtkStack *stack_main;
    GtkButton *btn_copy;
    GtkGrid *grd_book;
    GtkGrid *grd_webpage;
};

G_DEFINE_TYPE (ApageneratorWindowMain, apagenerator_window_main, GTK_TYPE_APPLICATION_WINDOW)

/*
 * =============================================================================
 * Signatures
 *
 */
static void apagenerator_window_main_class_init (ApageneratorWindowMainClass *klass);
static void apagenerator_window_main_init (ApageneratorWindowMain *self);
const gchar *apagenerator_window_main_get_apa_string (GtkGrid *grd_entries,
                                                      const gchar *settings_key);

/* Callback functions */
static gboolean apagenerator_window_main_cb_register_shortcuts (GtkWidget   *caller,
                                                                GdkEventKey *event,
                                                                gpointer     user_data);
static void apagenerator_window_main_cb_btn_copy_clicked (GtkWidget *caller,
                                                          gpointer   user_data);

/*
 * =============================================================================
 * Public function implementations
 *
 */
ApageneratorWindowMain *
apagenerator_window_main_new (GApplication *app)
{
    g_assert (G_IS_APPLICATION (app));

    ApageneratorWindowMain *window;

    window = g_object_new (APAGENERATOR_TYPE_WINDOW_MAIN,
                           "application", app,
                           "default-width", WINDOW_WIDTH,
                           "default-height", WINDOW_HEIGHT,
                           NULL);

    return window;
}

/*
 * =============================================================================
 * Public function implementations
 *
 */
static void
apagenerator_window_main_class_init (ApageneratorWindowMainClass *klass)
{
    GtkWidgetClass *widget_class;

    widget_class = GTK_WIDGET_CLASS (klass);

    gtk_widget_class_set_template_from_resource (widget_class, "/net/bartkessels/apagenerator/window-main.ui");

    gtk_widget_class_bind_template_child (widget_class, ApageneratorWindowMain, stack_main);
    gtk_widget_class_bind_template_child (widget_class, ApageneratorWindowMain, btn_copy);
    gtk_widget_class_bind_template_child (widget_class, ApageneratorWindowMain, grd_book);
    gtk_widget_class_bind_template_child (widget_class, ApageneratorWindowMain, grd_webpage);
}

static void
apagenerator_window_main_init (ApageneratorWindowMain *self)
{
    g_assert (APAGENERATOR_IS_WINDOW_MAIN (self));
    g_assert (GTK_IS_WINDOW (self));
    g_assert (GTK_IS_WIDGET (self));

    gtk_widget_init_template (GTK_WIDGET (self));

    /* Connect signals */
    g_signal_connect (self, "key-press-event",
                      G_CALLBACK (apagenerator_window_main_cb_register_shortcuts),
                      self);
    g_signal_connect (self->btn_copy, "clicked",
                      G_CALLBACK (apagenerator_window_main_cb_btn_copy_clicked),
                      self);
}

const gchar *
apagenerator_window_main_get_apa_string (GtkGrid     *grd_entries,
                                         const gchar *settings_key)
{
    g_assert (GTK_IS_GRID (grd_entries));

    const gchar *apa_string_book;
    GList *text_entries;
    guint total_text_entries;

    apa_string_book = apagenerator_settings_get_apa_string (settings_key);
    text_entries = gtk_container_get_children (GTK_CONTAINER (grd_entries));
    total_text_entries = g_list_length (text_entries);

    for (int text_entries_iterator = 0; text_entries_iterator < total_text_entries; text_entries_iterator++) {
        gpointer current_widget;
        GtkEntry *entry;
        const gchar *entry_name;
        const gchar *entry_value;

        current_widget = g_list_nth_data (text_entries, text_entries_iterator);

        if (GTK_IS_ENTRY (current_widget)) {
            entry = GTK_ENTRY (current_widget);
            entry_name = gtk_widget_get_name (GTK_WIDGET(entry));
            entry_value = gtk_entry_get_text (entry);

            apa_string_book = apagenerator_string_replace (apa_string_book,
                                                           entry_name,
                                                           entry_value);
        }
    }

    g_list_free (text_entries);

    return apa_string_book;
}

/*
 * =============================================================================
 * Private callback implementations
 *
 */
static gboolean
apagenerator_window_main_cb_register_shortcuts (GtkWidget   *caller,
                                                GdkEventKey *event,
                                                gpointer     user_data)
{
    g_assert (APAGENERATOR_IS_WINDOW_MAIN (user_data));

    if ((event->state & GDK_CONTROL_MASK) && (event->state & GDK_MOD1_MASK)) { // CTRL + ALT + C
        apagenerator_window_main_cb_btn_copy_clicked (caller, user_data);
    }

    return FALSE;
}

static void
apagenerator_window_main_cb_btn_copy_clicked (GtkWidget *caller,
                                              gpointer   user_data)
{
    g_assert (APAGENERATOR_IS_WINDOW_MAIN (user_data));

    ApageneratorWindowMain *self;
    const gchar *current_stack;
    const gchar *apa_string = 0;
    int apa_string_length;
    GtkClipboard *clipboard;

    self = APAGENERATOR_WINDOW_MAIN (user_data);
    current_stack = gtk_stack_get_visible_child_name (self->stack_main);

    /*
     * Generate APA string based on currently selected stack
     */
    if (g_str_equal (current_stack, STACK_NAME_BOOK)) {
        apa_string = apagenerator_window_main_get_apa_string (self->grd_book,
                                                              SETTINGS_KEY_APA_STRING_BOOK);
    } else if (g_str_equal (current_stack, STACK_NAME_WEBPAGE)) {
        apa_string = apagenerator_window_main_get_apa_string (self->grd_webpage,
                                                              SETTINGS_KEY_APA_STRING_WEBPAGE);
    }

    apa_string_length = strlen (apa_string);
    clipboard = gtk_clipboard_get (GDK_SELECTION_CLIPBOARD);

    /*
     * Put APA string on the clipboard
     */
    gtk_clipboard_set_text (clipboard, apa_string, apa_string_length);
}
