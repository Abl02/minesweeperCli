CXX = gcc
CXXFLAGS = -Wall
SRCS = src/main.c src/board.c src/render.c src/config.c
OBJS = $(SRCS:.cpp=.o)

all: minesweeper

minesweeper: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) minesweeper
