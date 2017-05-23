#include <gtk/gtk.h>

#ifndef STACK_H
#define STACK_H

struct book {
	GtkWidget *et_author;
	GtkWidget *et_year;
	GtkWidget *et_version;
	GtkWidget *et_title;
	GtkWidget *et_chapter;
	GtkWidget *et_page;
	GtkWidget *et_location;
	GtkWidget *et_publisher;
}book;

struct webpage {
	GtkWidget *et_author;
	GtkWidget *et_title;
	GtkWidget *et_date_published;
	GtkWidget *et_date_consulted;
	GtkWidget *et_url;
}webpage;

GtkStack
*create_stack();

GtkWidget
*create_stack_content_book();

GtkWidget
*create_stack_content_webpage();

struct book book_widgets;
struct webpage webpage_widgets;

#endif /* STACK_H */
