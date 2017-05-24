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

- gtk3-devel
- automake
- gettext
- intltool
- itstool
- libtool
- desktop-file-utils

### Installing

- gtk3

## Features

- Create APA source for a book
- Create APA source for a webpage

## How to build

```
bash autogen.sh
./configure
sudo make install
```

And then run `./src/apagenerator`

## Generate RPM package

You first need to download the latest
release of APA generator using spectool.

```
spectool -g apagenerator.spec
fedpkg --release f25 local
```

This will create a RPM file which you can install using your package manager.

## COPR

If you have Fedora and don't want to build APA Generator from source you can easily install it using dnf copr.

```
sudo dnf copr enable bartkessels/apagenerator
sudo dnf install apagenerator
```
