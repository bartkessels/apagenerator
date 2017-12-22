/* apagenerator-dialog-settings.c
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

#include "apagenerator-dialog-settings.h"

struct _ApageneratorDialogSettings {
    GtkDialog parent_instance;

    /* Template widgets */
    GtkTextView *tv_book_apa_string;
    GtkTextView *tv_webpage_apa_string;
    GtkTextBuffer *tb_book_apa_string;
    GtkTextBuffer *tb_webpage_apa_string;
    GtkButton *btn_apply;
    GtkButton *btn_cancel;
};

G_DEFINE_TYPE (ApageneratorDialogSettings, apagenerator_dialog_settings, GTK_TYPE_DIALOG)

/*
 * =============================================================================
 * Signatures
 *
 */
static void apagenerator_dialog_settings_class_init (ApageneratorDialogSettingsClass *klass);
static void apagenerator_dialog_settings_init (ApageneratorDialogSettings *self);
const gchar *apagenerator_dialog_settings_get_apa_string_book (ApageneratorDialogSettings *self);
const gchar *apagenerator_dialog_settings_get_apa_string_webpage (ApageneratorDialogSettings *self);

/* Callback functions */
static void apagenerator_dialog_settings_cb_btn_apply_clicked (GtkWidget *caller,
                                                               gpointer   user_data);
static void apagenerator_dialog_settings_cb_btn_cancel_clicked (GtkWidget *caller,
                                                                gpointer   user_data);

/*
 * =============================================================================
 * Public function implementations
 *
 */
ApageneratorDialogSettings *
apagenerator_dialog_settings_new (GtkWindow *parent_window)
{
    g_assert (GTK_IS_WINDOW (parent_window));

    ApageneratorDialogSettings *dialog_settings;

    dialog_settings = g_object_new (APAGENERATOR_TYPE_DIALOG_SETTINGS,
                                    "transient-for", parent_window,
                                    NULL);

    return dialog_settings;
}

/*
 * =============================================================================
 * Private function implementations
 *
 */
static void
apagenerator_dialog_settings_class_init (ApageneratorDialogSettingsClass *klass)
{
    GtkWidgetClass *widget_class;

    widget_class = GTK_WIDGET_CLASS (klass);

    gtk_widget_class_set_template_from_resource (widget_class, "/net/bartkessels/apagenerator/dialog-settings.ui");

    gtk_widget_class_bind_template_child (widget_class, ApageneratorDialogSettings, tb_book_apa_string);
    gtk_widget_class_bind_template_child (widget_class, ApageneratorDialogSettings, tb_webpage_apa_string);
    gtk_widget_class_bind_template_child (widget_class, ApageneratorDialogSettings, btn_apply);
    gtk_widget_class_bind_template_child (widget_class, ApageneratorDialogSettings, btn_cancel);
}

static void
apagenerator_dialog_settings_init (ApageneratorDialogSettings *self)
{
    g_assert (GTK_IS_WIDGET (self));
    g_assert (APAGENERATOR_IS_DIALOG_SETTINGS (self));

    const gchar *apa_string_book;
    const gchar *apa_string_webpage;

    /* Load settings */
    apa_string_book = apagenerator_settings_get_apa_string_book ();
    apa_string_webpage = apagenerator_settings_get_apa_string_webpage ();

    gtk_widget_init_template (GTK_WIDGET (self));

    g_signal_connect (self->btn_apply, "clicked",
                      G_CALLBACK (apagenerator_dialog_settings_cb_btn_apply_clicked),
                      self);
    g_signal_connect (self->btn_cancel, "clicked",
                      G_CALLBACK (apagenerator_dialog_settings_cb_btn_cancel_clicked),
                      self);

    /* Display settings in UI */
    gtk_text_buffer_set_text (self->tb_book_apa_string, apa_string_book, -1);
    gtk_text_buffer_set_text (self->tb_webpage_apa_string, apa_string_webpage, -1);
}

const gchar *
apagenerator_dialog_settings_get_apa_string_book (ApageneratorDialogSettings *self)
{
    g_assert (APAGENERATOR_IS_DIALOG_SETTINGS (self));

    const gchar *apa_string_book;
    GtkTextIter iter_start;
    GtkTextIter iter_end;

    gtk_text_buffer_get_bounds (self->tb_book_apa_string, &iter_start, &iter_end);

    apa_string_book = gtk_text_buffer_get_text (self->tb_book_apa_string,
                                                &iter_start, &iter_end, FALSE);

    return apa_string_book;
}

const gchar *
apagenerator_dialog_settings_get_apa_string_webpage (ApageneratorDialogSettings *self)
{
    g_assert (APAGENERATOR_IS_DIALOG_SETTINGS (self));

    const gchar *apa_string_webpage;
    GtkTextIter iter_start;
    GtkTextIter iter_end;

    gtk_text_buffer_get_bounds (self->tb_webpage_apa_string, &iter_start, &iter_end);

    apa_string_webpage = gtk_text_buffer_get_text (self->tb_webpage_apa_string,
                                                   &iter_start, &iter_end, FALSE);

    return apa_string_webpage;
}

/*
 * =============================================================================
 * Callback function implementations
 *
 */
static void
apagenerator_dialog_settings_cb_btn_apply_clicked (GtkWidget *caller,
                                                   gpointer   user_data)
{
    g_assert (GTK_IS_BUTTON (caller));
    g_assert (APAGENERATOR_IS_DIALOG_SETTINGS (user_data));

    ApageneratorDialogSettings *self;
    const gchar *apa_string_book;
    const gchar *apa_string_webpage;

    self = APAGENERATOR_DIALOG_SETTINGS (user_data);
    apa_string_book = apagenerator_dialog_settings_get_apa_string_book (self);
    apa_string_webpage = apagenerator_dialog_settings_get_apa_string_webpage (self);

    apagenerator_settings_set_apa_string_book (apa_string_book);
    apagenerator_settings_set_apa_string_webpage (apa_string_webpage);

    gtk_dialog_response (GTK_DIALOG (self), GTK_RESPONSE_OK);
}

static void
apagenerator_dialog_settings_cb_btn_cancel_clicked (GtkWidget *caller,
                                                    gpointer   user_data)
{
    g_assert (GTK_IS_BUTTON (caller));
    g_assert (APAGENERATOR_IS_DIALOG_SETTINGS (user_data));

    gtk_dialog_response (GTK_DIALOG (user_data), GTK_RESPONSE_CANCEL);
}
