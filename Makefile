CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude
SRCS = src/main.cpp src/Board.cpp src/Game.cpp src/Renderer.cpp
OBJS = $(SRCS:.cpp=.o)

all: minesweeper

minesweeper: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) minesweeper
