/*
 *  Copyright (C) 2007 Openmoko, Inc.
 *
 *  Authored by:
 *    quickdev
 *    Klaus 'mrmoku' Kurzmann <mok@fluxnetz.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Public License as published by
 *  the Free Software Foundation; version 2 of the license or any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser Public License for more details.
 */

#include <dbus/dbus-glib.h>


int
main(int argc, char **argv)
{
	GError *error = NULL;
	DBusGConnection *bus;
	DBusGProxy *proxy;

	g_type_init();

	bus = dbus_g_bus_get(DBUS_BUS_SYSTEM, &error);
	if (bus == NULL) {
		g_printerr ("Failed to open connection to bus: %s\n",
			error->message);
		g_error_free (error);
		return (1);
	}

	proxy = dbus_g_proxy_new_for_name (bus,
			"org.shr.phoneui",
			"/org/shr/phoneui/Contacts",
			"org.shr.phoneui.Contacts");

	GHashTable *filter = g_hash_table_new(g_str_hash, g_str_equal);
	if (!dbus_g_proxy_call (proxy, "DisplayList", &error,
			dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE),
			filter, G_TYPE_INVALID, G_TYPE_INVALID)) {
		if (error->domain == DBUS_GERROR &&
			error->code == DBUS_GERROR_REMOTE_EXCEPTION) {
			g_printerr ("Caught remote method exception %s: %s",
				dbus_g_error_get_name (error),
				error->message);
		}
		else {
			g_printerr ("Error: %s\n", error->message);
		}
		g_error_free (error);
		return (1);
	}

	return (0);
}
