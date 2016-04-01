CC              = cc
CFLAGS          = -std=c99 -I. -O1 -Wall
AR              = ar
RANLIB          = ranlib
LIB             = libunet.a

# This libcerror path should be set in a more fency way
# Fine for now though
CERROR_INC      = ../libcerror
CFLAGS          += -I$(CERROR_INC)

SRCS            = $(wildcard *.c)
OBJS            = $(SRCS:.c=.o)

.PHONY : all clean
.DEFAULT_GOAL = all

$(LIB): $(OBJS)
	$(AR) -r $@ $?
	$(RANLIB) $@

lib: $(LIB)

all: lib

clean:
	rm -f $(OBJS) $(LIB)
