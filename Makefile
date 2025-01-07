TOPDIR  := ./
SRCDIR  := $(TOPDIR)src/
OBJDIR  := $(TOPDIR)build/
BINDIR  := $(TOPDIR)
NAME    := csweeper
EXE     := $(BINDIR)$(NAME)

SFILES  := cpp
OFILES  := o
CC      := gcc
CFLAGS 	:= -Wall -Wextra

SRCS    := $(shell find $(SRCDIR) -name "*.$(SFILES)")
OBJS    := $(SRCS:.c=.o)

# DEBUG
#CXXFLAGS  += -g
CXXFLAGS  += -fsanitize=address

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $^ -o $@

$(OBJDIR)%$(OFILES): $(SRCDIR)%$(SFILES) build
	$(CC) $(CFLAGS) $< -c -o $@

build:
	mkdir $(OBJDIR)

clean:
	rm -f $(OBJS) $(EXE)
