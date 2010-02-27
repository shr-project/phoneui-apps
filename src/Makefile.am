MAINTAINERCLEANFILES = Makefile.in

INCLUDES = -I$(top_srcdir)/libhito

AM_CPPFLAGS = -DPKGDATADIR=\"$(pkgdatadir)\" \
                @DBUS_CFLAGS@ \
                -Wall

AM_LDFLAGS = @DBUS_LIBS@

bin_PROGRAMS=phoneui-dialer phoneui-contacts phoneui-messages phoneui-quick-settings phoneui-phonelog

phoneui_contacts_SOURCES = contacts-main.c
phoneui_messages_SOURCES = messages-main.c
phoneui_dialer_SOURCES = dialer-main.c
phoneui_quick_settings_SOURCES = quick-settings-main.c
phoneui_phonelog_SOURCES = phonelog-main.c

        
