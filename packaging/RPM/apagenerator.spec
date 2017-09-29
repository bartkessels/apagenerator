Name:		apagenerator
Version:	2.1
Release:	1%{?dist}
Summary:	Generate APA source for a book or webpage

License:	GPLv3+
URL:		https://github.com/bartkessels/apagenerator
Source0:	https://github.com/bartkessels/%{name}/archive/%{version}/%{name}-%{version}.tar.gz

BuildRequires:  gcc
BuildRequires:	meson
BuildRequires:  python3
BuildRequires:	gtk3-devel
BuildRequires:	glib-devel

Requires:	gtk3
Requires:	glib

%description
Application to generate APA sources for a book or webpage to include in your reports.

%prep
%autosetup -c

%build
%meson
%meson_build

%install
rm -rf $RPM_BUILD_ROOT
%meson_install

%files
%{_bindir}/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/glib-2.0/schemas/net.bartkessels.%{name}.gschema.xml

%changelog
* Fri Sep 29 2017 Bart Kessels <bartkessels@bk-mail.com> 2.1-1
- Move build system to Meson
- Fix wrong font in Settings window
- Fix possible bug

* Wed Jul 05 2017 Bart Kessels <bartkessels@bk-mail.com> 2.0-1
- Rewrite to GObject
- Allow user to change APA strings

* Tue May 23 2017 Bart Kessels <bartkessels@bk-mail.com> 1.0-1
- Initial Packaging
