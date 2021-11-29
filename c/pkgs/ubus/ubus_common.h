/*
 * Copyright (C) 2011 Felix Fietkau <nbd@openwrt.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 2.1
 * as published by the Free Software Foundation
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __UBUS_COMMON_H
#define __UBUS_COMMON_H
#include <syslog.h>

#define UBUS_SIGNATURE_METHOD    (BLOBMSG_TYPE_LAST + 1)
#define UBUS_SIGNATURE_END        (BLOBMSG_TYPE_LAST + 2)

#define ubus_log(LOG_LEVEL, fmt, ...) do { syslog( LOG_LEVEL, "%s: " fmt, __func__, ##__VA_ARGS__ ); } while ( 0 );

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif

#endif
