# APA Generator

Application to create APA sources to include in your reports.

## Screenshots

![APA Generator - Book](data/screenshots/book.png)
![APA Generator - Webpage](data/screenshots/webpage.png)

## What can I do with it?

You can easily create an APA source for a book or webpage by simply
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

You first need to download the latest
release of APA generator using spectool.

```
$ cd packaging/RPM
$ spectool -g apagenerator.spec
$ fedpkg --release f26 local
```

This will create a RPM file which you can install using your package manager.

## COPR

If you have Fedora and don't want to build APA Generator from source you can easily install it using dnf copr.

```
$ dnf copr enable bartkessels/apagenerator
$ dnf install apagenerator
```
