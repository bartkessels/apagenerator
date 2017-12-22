apagenerator_sources = [
	'main.c',
	'apagenerator-application.c',
	'apagenerator-dialog-about.c',
	'apagenerator-dialog-settings.c',
	'apagenerator-settings.c',
	'apagenerator-string.c',
	'apagenerator-window-main.c',
	'apagenerator-window-shortcuts.c'
]

apagenerator_deps = [
	dependency('gtk+-3.0'),
	dependency('glib-2.0')
]

gnome = import('gnome')

apagenerator_sources += gnome.compile_resources('apagenerator-resources',
	'apagenerator.gresource.xml',
	c_name: 'apagenerator'
)

executable('apagenerator', apagenerator_sources,

	dependencies: apagenerator_deps,
	install: true,
)
