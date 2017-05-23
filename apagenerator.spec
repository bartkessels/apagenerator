Name:		apagenerator
Version:	1.0
Release:	1%{?dist}
Summary:	Generate APA source for a book or webpage

License:	GPLv3+
URL:		https://github.com/bartkessels/apagenerator
Source0:	https://github.com/bartkessels/%{name}/archive/%{version}/%{name}-%{version}.tar.gz

BuildRequires:	gtk3-devel
BuildRequires:	automake
BuildRequires:	gettext
BuildRequires:	intltool
BuildRequires:	itstool
BuildRequires:	%{_bindir}/desktop-file-install

Requires:	gtk3

%description
Application to generate APA sources for a book or webpage to include in your reports.

%global debug_package %{nil}

%prep
%autosetup -p1

%build
bash autogen.sh
%configure
make %{?_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT
%make_install
desktop-file-install data/package/%{name}.desktop

%files
%license COPYING
%{_bindir}/%{name}
%{_datadir}/applications/%{name}.ui

%changelog
* Tue May 23 Bart Kessels <b.kessels@bk-mail.com> 1.0-1
- Initial Packaging
