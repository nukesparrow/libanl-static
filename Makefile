.DEFAULT_GOAL := all

LIB = libanl.a

INCLUDES ?= -I.

CFLAGS += $(INCLUDES) -pthread -D_GNU_SOURCE -g -Wall -Os -ffunction-sections -fdata-sections
LDLIBS += -Wl,--gc-sections

objects=gai_cancel.o gai_error.o gai_misc.o gai_notify.o gai_sigqueue.o gai_suspend.o getaddrinfo_a.o

$(LIB): $(objects)
	$(AR) rcs $(LIB) $(objects)
	
all: $(LIB)

example: example.o $(LIB)
	$(CC) $(CFLAGS) example.o $(LIB) $(LDLIBS) -o $@
	
splint:
	splint $(INCLUDES) *.c

clean:
	-rm -f $(LIB) $(objects) example example.o
