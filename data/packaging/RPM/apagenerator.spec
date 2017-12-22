Name:		apagenerator
Version:	2.5
Release:	1%{dist}
Summary:	APA Generator is an application to generate APA strings

License:	GPLv3+
URL:		https://github.com/bartkessels/apagenerator
Source0:	https://github.com/bartkessels/%{name}/archive/%{version}/%{name}-%{version}.tar.gz

BuildRequires:	gcc
BuildRequires:	meson
BuildRequires:	gtk3-devel
BuildRequires:	gettext

Requires:	gtk3

%description
Generate APA strings based on the values you provide, no longer do
you have to memorize the APA format!

%global debug_package %{nil}

%prep
%autosetup -p1

%build
%meson
%meson_build

%install
rm -rf $RPM_BUILD_ROOT
%meson_install
%find_lang %{name}

%files -f %{name}.lang
%{_bindir}/%{name}
%{_datadir}/applications/net.bartkessels.%{name}.desktop
%{_datadir}/glib-2.0/schemas/net.bartkessels.%{name}.gschema.xml
%{_datadir}/appdata/net.bartkessels.%{name}.appdata.xml
%{_datadir}/icons/hicolor/*/apps/net.bartkessels.%{name}.png
%{_datadir}/icons/hicolor/*/apps/net.bartkessels.%{name}-symbolic.png
%{_datadir}/icons/hicolor/*/actions/%{name}-copy-symbolic.png

%changelog
* Fri Dec 22 2017 Bart Kessels <bartkessels@bk-mail.com> 2.5
- Ship own icons
- Cleanup code
- Move menu in application to global app menu
- Add about screen
- Add shortcuts screen
- Give preferences screen overhaul

* Fri Sep 29 2017 Bart Kessels <bartkessels@bk-mail.com> 2.1-1
- Move build system to Meson
- Fix wrong font in Settings window
- Fix possible bug

* Wed Jul 05 2017 Bart Kessels <bartkessels@bk-mail.com> 2.0-1
- Rewrite to GObject
- Allow user to change APA strings

* Tue May 23 2017 Bart Kessels <bartkessels@bk-mail.com> 1.0-1
- Initial Packaging
