#include <gtk/gtk.h>

#include "stack.h"

GtkStack
*create_stack()
{
  // Declare and initialize stack
  GtkWidget *stack = gtk_stack_new();

  // Declare content widgets
  GtkWidget *content_book;
  GtkWidget *content_webpage;

  // Initialize content widgets
  content_book = create_stack_content_book();
  content_webpage = create_stack_content_webpage();

  // Add content widgets to stack
  gtk_stack_add_titled (GTK_STACK(stack), content_book, "book", "Book");
  gtk_stack_add_titled(GTK_STACK(stack), content_webpage, "webpage", "Webpage");

  return GTK_STACK(stack);
}

GtkWidget
*create_stack_content_book()
{
  // Declare widgets
  GtkWidget *grd_main;
  GtkWidget *et_author;
  GtkWidget *et_year;
  GtkWidget *et_version;
  GtkWidget *et_title;
  GtkWidget *et_chapter;
  GtkWidget *et_page;
  GtkWidget *et_location;
  GtkWidget *et_publisher;

  // Initialize widgets
  grd_main = gtk_grid_new();
  et_author = gtk_entry_new();
  et_year = gtk_entry_new();
  et_version = gtk_entry_new();
  et_title = gtk_entry_new();
  et_chapter = gtk_entry_new();
  et_page = gtk_entry_new();
  et_location = gtk_entry_new();
  et_publisher = gtk_entry_new();

  // Set grid properties
  gtk_grid_set_column_homogeneous (GTK_GRID(grd_main), TRUE);
  gtk_grid_set_row_spacing(GTK_GRID(grd_main), 5);
  gtk_grid_set_column_spacing (GTK_GRID(grd_main), 5);

  // Add placeholders to entries
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_author), "Author");
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_year), "Year");
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_version), "Version");
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_title), "Title");
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_chapter), "Chapter");
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_page), "Page");
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_location), "Location");
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_publisher), "Publisher");

  // Add widgets to grid
  gtk_grid_attach(GTK_GRID(grd_main), GTK_WIDGET(et_author), 0, 0, 2, 1);
  gtk_grid_attach_next_to(GTK_GRID(grd_main), GTK_WIDGET(et_year), GTK_WIDGET(et_author), GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(grd_main), GTK_WIDGET(et_version), GTK_WIDGET(et_year), GTK_POS_RIGHT, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(grd_main), GTK_WIDGET(et_title), GTK_WIDGET(et_year), GTK_POS_BOTTOM, 2, 1);
  gtk_grid_attach_next_to(GTK_GRID(grd_main), GTK_WIDGET(et_chapter), GTK_WIDGET(et_title), GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(grd_main), GTK_WIDGET(et_page), GTK_WIDGET(et_chapter), GTK_POS_RIGHT, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(grd_main), GTK_WIDGET(et_location), GTK_WIDGET(et_chapter), GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(grd_main), GTK_WIDGET(et_publisher), GTK_WIDGET(et_location), GTK_POS_RIGHT, 1, 1);

  // Add widgets to struct
  struct book widgets = {et_author, et_year, et_version, et_title, et_chapter, et_page, et_location, et_publisher};
  book_widgets = widgets;

  return grd_main;
}

GtkWidget
*create_stack_content_webpage()
{
  // Declare widgets
  GtkWidget *grd_main;
  GtkWidget *et_author;
  GtkWidget *et_title;
  GtkWidget *et_date_published;
  GtkWidget *et_date_consulted;
  GtkWidget *et_url;

  // Initialize widgets
  grd_main = gtk_grid_new();
  et_author = gtk_entry_new();
  et_title = gtk_entry_new();
  et_date_published = gtk_entry_new();
  et_date_consulted = gtk_entry_new();
  et_url = gtk_entry_new();

  // Set grid properties
  gtk_grid_set_column_homogeneous (GTK_GRID(grd_main), TRUE);
  gtk_grid_set_row_spacing(GTK_GRID(grd_main), 5);
  gtk_grid_set_column_spacing (GTK_GRID(grd_main), 5);

  // Add placeholders to entries
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_author), "Author");
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_title), "Title");
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_date_published), "Date Published");
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_date_consulted), "Date Consulted");
  gtk_entry_set_placeholder_text(GTK_ENTRY(et_url), "URL");

  // Add widgets to grid
  gtk_grid_attach(GTK_GRID(grd_main), GTK_WIDGET(et_author), 0, 0, 2, 1);
  gtk_grid_attach_next_to(GTK_GRID(grd_main), GTK_WIDGET(et_title), GTK_WIDGET(et_author), GTK_POS_BOTTOM, 2, 1);
  gtk_grid_attach_next_to(GTK_GRID(grd_main), GTK_WIDGET(et_date_published), GTK_WIDGET(et_title), GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(grd_main), GTK_WIDGET(et_date_consulted), GTK_WIDGET(et_date_published), GTK_POS_RIGHT, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(grd_main), GTK_WIDGET(et_url), GTK_WIDGET(et_date_published), GTK_POS_BOTTOM, 2, 1);

  // Add widgets to struct
  struct webpage widgets = {et_author, et_title, et_date_published, et_date_consulted, et_url};
  webpage_widgets = widgets;

  return grd_main;
}
