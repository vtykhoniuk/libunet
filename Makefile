CC              = cc
CFLAGS          = -std=c99 -I. -O1 -Wall
AR              = ar
RANLIB          = ranlib

# This libcerror path should be set in a more fency way
# Fine for now though
CERROR_INC     = ../libcerror

.PHONY : all clean
.DEFAULT_GOAL = all

readn.o: readn.c unet.h
	$(CC) -c $(CFLAGS) -I$(CERROR_INC) $<

writen.o: writen.c unet.h
	$(CC) -c $(CFLAGS) -I$(CERROR_INC) $<

libunet.a: readn.o writen.o
	$(AR) -r $@ $?
	$(RANLIB) $@

all: libunet.a

clean:
	rm -f *.o libunet.a
