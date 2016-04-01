CC              = cc
CFLAGS          = -std=c99 -I. -I/usr/local/include -O1 -Wall
AR              = ar
RANLIB          = ranlib
INSTALL         = install
LIB             = libunet.a
DST             = /usr/local
SRCS            = $(wildcard *.c)
OBJS            = $(SRCS:.c=.o)

.PHONY : all clean
.DEFAULT_GOAL = all

$(LIB): $(OBJS)
	$(AR) -r $@ $?
	$(RANLIB) $@

lib: $(LIB)

all: lib

install:
	$(INSTALL) $(LIB) $(addprefix $(DST)/, lib)
	$(INSTALL) unet.h $(addprefix $(DST)/, include)

clean:
	rm -f $(OBJS) $(LIB)
