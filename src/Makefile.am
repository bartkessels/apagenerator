bin_PROGRAMS = apagenerator

ag-resources.c: apagenerator.gresource.xml
	$(AM_V_GEN)
	glib-compile-resources \
		--sourcedir=$(srcdir) \
		--generate-source \
		--target=$@ \
		$(srcdir)/apagenerator.gresource.xml

BUILT_RESOURCES = \
		ag-resources.c

apagenerator_SOURCES = \
					$(BUILT_RESOURCES) \
					ag-application.c \
					ag-content-book.c \
					ag-content-webpage.c \
					ag-headerbar.c \
					ag-mainwindow.c \
					ag-settings-content-book.c \
					ag-settings-content-webpage.c \
					ag-settings-headerbar.c \
					ag-settings-stack.c \
					ag-settings.c \
					ag-settingswindow.c \
					ag-stack.c \
					ag-string.c \
					main.c

apagenerator_CPPFLAGS = @GTK_CFLAGS@ @GIO_CFLAGS@ @GLIB_CFLAGS@
apagenerator_LDFLAGS = @GTK_LIBS@ @GIO_LIBS@ @GLIB_LIBS@