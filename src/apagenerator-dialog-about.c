/* apagenerator-dialog-about.c
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

#include "apagenerator-dialog-about.h"

struct _ApageneratorDialogAbout {
    GtkAboutDialog parent_instance;
};

G_DEFINE_TYPE (ApageneratorDialogAbout, apagenerator_dialog_about, GTK_TYPE_ABOUT_DIALOG)

/*
 * =============================================================================
 * Signatures
 *
 */
static void apagenerator_dialog_about_class_init (ApageneratorDialogAboutClass *klass);
static void apagenerator_dialog_about_init (ApageneratorDialogAbout *self);

/*
 * =============================================================================
 * Public function implementations
 *
 */
ApageneratorDialogAbout *
apagenerator_dialog_about_new (GtkWindow *parent_window)
{
    ApageneratorDialogAbout *dialog_about;

    dialog_about = g_object_new (APAGENERATOR_TYPE_DIALOG_ABOUT,
                                 "transient-for", parent_window,
                                 NULL);

    return dialog_about;
}

/*
 * =============================================================================
 * Private function implementations
 *
 */
static void
apagenerator_dialog_about_class_init (ApageneratorDialogAboutClass *klass)
{
    GtkWidgetClass *widget_class;

    widget_class = GTK_WIDGET_CLASS (klass);

    gtk_widget_class_set_template_from_resource (widget_class, "/net/bartkessels/apagenerator/dialog-about.ui");
}

static void
apagenerator_dialog_about_init (ApageneratorDialogAbout *self)
{
    g_assert (APAGENERATOR_IS_DIALOG_ABOUT (self));
    g_assert (GTK_IS_WIDGET (self));

    gtk_widget_init_template (GTK_WIDGET (self));
}
