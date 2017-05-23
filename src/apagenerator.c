#include <gtk/gtk.h>
#include <string.h>

#include "apagenerator.h"
#include "stack.h"

gchar
*generate_apa_book()
{
  const gchar *author = gtk_entry_get_text(GTK_ENTRY(book_widgets.et_author));
  const gchar *year = gtk_entry_get_text(GTK_ENTRY(book_widgets.et_year));
  const gchar *version = gtk_entry_get_text(GTK_ENTRY(book_widgets.et_version));
  const gchar *title = gtk_entry_get_text(GTK_ENTRY(book_widgets.et_title));
  const gchar *chapter = gtk_entry_get_text(GTK_ENTRY(book_widgets.et_chapter));
  const gchar *page = gtk_entry_get_text(GTK_ENTRY(book_widgets.et_page));
  const gchar *location = gtk_entry_get_text(GTK_ENTRY(book_widgets.et_location));
  const gchar *publisher = gtk_entry_get_text(GTK_ENTRY(book_widgets.et_publisher));

  gchar *str_version = "";
  gchar *str_chapter = "";
  gchar *str_publisher = "";

  // Version string
  if(strcmp(version, "") && strcmp(page, "")) {
    str_version = g_strconcat("(", version, ", pp. ", page, "). ", NULL);
  } else if(strcmp(version, "")) {
    str_version = g_strconcat("(", version, "). ", NULL);
  }

  // Chapter string
  if(strcmp(chapter, "")) {
    str_chapter = g_strconcat(chapter, ". ", NULL);
  }

  // Publisher string
  if(strcmp(publisher, "") && strcmp(location, "")) {
    str_publisher = g_strconcat(location, ": ", publisher, ". ", NULL);
  }

  // Create apa string
  gchar *apa_string = g_strconcat(author, ". ", str_chapter, "(", year, "). ", title, " ", str_version, str_publisher, NULL);

  return apa_string;
}

gchar
*generate_apa_webpage()
{
  const gchar *author = gtk_entry_get_text(GTK_ENTRY(webpage_widgets.et_author));
  const gchar *title = gtk_entry_get_text(GTK_ENTRY(webpage_widgets.et_title));
  const gchar *date_published = gtk_entry_get_text(GTK_ENTRY(webpage_widgets.et_date_published));
  const gchar *date_consulted = gtk_entry_get_text(GTK_ENTRY(webpage_widgets.et_date_consulted));
  const gchar *url = gtk_entry_get_text(GTK_ENTRY(webpage_widgets.et_url));

  gchar *str_date_published = "";
  gchar *str_date_consulted = "";
  gchar *str_url = "";

  // Published string
  if(strcmp(date_published, "")) {
    str_date_published = g_strconcat("(", date_published, "). ", NULL);
  }

  // Consulted string
  if(strcmp(date_consulted, "")) {
    str_date_consulted = g_strconcat("Consulted on ", date_consulted, ", ", NULL);
  }

  // URL string
  if(strcmp(url, "")) {
    str_url = g_strconcat("at ", url, NULL);
  }

  // Create APA string
  gchar *apa_string = g_strconcat(author, ". ", str_date_published, title, ". ", str_date_consulted, str_url, NULL);

  return apa_string;
}
