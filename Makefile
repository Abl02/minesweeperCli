TOPDIR  := ./
SRCDIR  := $(TOPDIR)src/
OBJDIR  := $(TOPDIR)build/
BINDIR  := $(TOPDIR)
NAME    := csweeper
EXE     := $(BINDIR)$(NAME)

SFILES  := c
OFILES  := o
CC      := gcc
CFLAGS 	:= -std=c11 -Wall -Wextra

SRCS    := $(shell find $(SRCDIR) -name "*.$(SFILES)")
OBJS    := $(OBJDIR)

SRCS := $(wildcard $(SRCDIR)*.c)
OBJS := $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

# DEBUG
#CXXFLAGS  += -g
#CXXFLAGS  += -fsanitize=address

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $^ -o $@

$(OBJDIR)%$(OFILES): $(SRCDIR)%$(SFILES) $(OBJDIR)
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJDIR):
	mkdir -p $@

clean:
	@rm -f $(OBJS) $(EXE)
