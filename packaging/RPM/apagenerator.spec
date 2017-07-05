Name:		apagenerator
Version:	2.0
Release:	1%{?dist}
Summary:	Generate APA source for a book or webpage

License:	GPLv3+
URL:		https://github.com/bartkessels/apagenerator
Source0:	https://github.com/bartkessels/%{name}/archive/%{version}/%{name}-%{version}.tar.gz

BuildRequires:  gcc
BuildRequires:	gtk3-devel
BuildRequires:	automake

Requires:	gtk3

%description
Application to generate APA sources for a book or webpage to include in your reports.

%global debug_package %{nil}

%prep
%autosetup -p1

%build
%configure
make %{?_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT
%make_install

%files
%license COPYING
%{_bindir}/%{name}
%{_datadir}/applications/%{name}.desktop

%changelog
* Wed Jul 05 2017 Bart Kessels <bartkessels@bk-mail.com> 2.0-1
- Rewrite to GObject
- Allow user to change APA strings

* Tue May 23 2017 Bart Kessels <bartkessels@bk-mail.com> 1.0-1
- Initial Packaging