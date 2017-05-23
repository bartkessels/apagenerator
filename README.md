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
release of APA generator using wget or your download application of choice.

```
wget https://github.com/bartkessels/apagenerator/archive/1.0/apagenerator-1.0.tar.gz
fedpkg --release f25 local
```

This will create a RPM file which you can install using your package manager.
