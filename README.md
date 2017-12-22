# APA Generator

Application to create APA strings to include in your reports.

## Screenshots

![APA Generator - Book](data/screenshots/book.png)
![APA Generator - Webpage](data/screenshots/webpage.png)

## What can I do with it?

You can easily create an APA strings for a book or webpage by simply
filling in the fields.

## Required packages

### Building

- gcc
- meson
- python3
- gtk3-devel
- glib-devel

### Installing

- gtk3
- glib

## Features

- Create APA source for a book
- Create APA source for a webpage
- Change APA string for both the book and the webpage

## How to build

```
$ meson build
$ cd build
$ ninja install
```

And then run `apagenerator`

## Generate RPM package

```
$ cd packaging/RPM
$ spectool -g apagenerator.spec
$ fedpkg --release f27 local
```

This will create a RPM file which you can install using your package manager.

## Generate flatpak bundle

```
$ cd data/packaging/flatpak
$ flatpak-builder --repo=apagenerator_repo apagenerator net.bartkessels.apagenerator.json
$ flatpak build-bundle apagenerator_repo apagenerator.flatpak net.bartkessels.apagenerator
```

This will create a flatpak bundle called `apagenerator.flatpak`. To install the flatpak bundle
just run the flatpak install command.

```
$ flatpak install apagenerator.flatpak
```

## COPR

If you have Fedora and don't want to build APA Generator from source you can easily install it using dnf copr.

```
$ dnf copr enable bartkessels/apagenerator
$ dnf install apagenerator
```
