project('APA Generator', 'c', version: '2.1')

# Imports
gnome = import('gnome')

# Compile resources
agresources = gnome.compile_resources(
    'ag-resources', 'src/apagenerator.gresource.xml',
    source_dir: 'src',
    c_name: 'ag_resources'
)

# Dependencies
deps = [
    dependency('gtk+-3.0'),
    dependency('glib-2.0')
]

# Source files
src = [
    agresources,
    'src/ag-application.c',
    'src/ag-content-book.c',
    'src/ag-content-webpage.c',
    'src/ag-headerbar.c',
    'src/ag-mainwindow.c',
    'src/ag-settings-content-book.c',
    'src/ag-settings-content-webpage.c',
    'src/ag-settings-headerbar.c',
    'src/ag-settings-stack.c',
    'src/ag-settings.c',
    'src/ag-settingswindow.c',
    'src/ag-stack.c',
    'src/ag-string.c',
    'src/main.c'
]

# Desktop file
install_data('data/package/apagenerator.desktop', install_dir: join_paths(get_option('datadir'), 'applications'))

# Gsettings schemas
install_data('data/gschemas/net.bartkessels.apagenerator.gschema.xml', install_dir: join_paths(get_option('datadir'), 'glib-2.0', 'schemas'))
meson.add_install_script('data/gschemas/compile_schemas.py')

# Executable information
executable('apagenerator', src, dependencies: deps, install: true)