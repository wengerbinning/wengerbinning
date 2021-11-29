CFLAGS = -fPIC -O0 -DUBUS_MAX_MSGLEN=1048576 -DUBUS_UNIX_SOCKET=\"/var/run/ubus.sock\"

#CROSS_COMPILE=arm-openwrt-linux-
CC=$(CROSS_COMPILE)gcc

OBJS_LIBUBUS = \
    libubus-acl.o \
    libubus.o \
    libubus-io.o \
    libubus-obj.o \
    libubus-req.o \
    libubus-sub.o

OBJS_UBUSD = \
    ubusd_acl.o \
    ubusd.o \
    ubusd_event.o \
    ubusd_id.o \
    ubusd_obj.o \
    ubusd_proto.o

OBJS_UBUS = \
    cli.o

RELEASE ?= temp_build
STICKY ?= no_sticky

.SUFFIXES: .c

%.o: %.c
    $(CC) -g -c $(CFLAGS) -o $@ $<

.PHONY: all clean libubus ubusd ubus

all:
    make clean
    make libubus
    make ubusd
    make ubus

clean:
    rm -f *.o
    rm -f *.so
    rm -f ubusd
    rm -f ubus

libubus: $(OBJS_LIBUBUS)
    $(CC) -shared -Wl,-soname,libubus.so -o libubus.so $(OBJS_LIBUBUS)

ubusd: $(OBJS_UBUSD)
    $(CC) -o ubusd $(OBJS_UBUSD) -lubox -ljson-c -lblobmsg_json -lm

ubus: $(OBJS_UBUS)
    $(CC) -o ubus $(OBJS_UBUS) -lubox -ljson-c libubus.so -lblobmsg_json -lm



