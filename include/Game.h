#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Renderer.h"
#include <string>
#include <utility>

class Board;
class Renderer;

class Game{
  public:
    Game(int height, int width, int mines);

    void click(std::pair<int,int> pos);
    void flag(std::pair<int,int> pos);
  private:
    std::pair<std::pair<int,int>,char> parseInput(std::string input);
    std::pair<std::pair<int,int>,char> getInput();
    void processInput(std::pair<std::pair<int,int>,char> input);
    void propagateClick(std::pair<int,int> pos);
    void gameLoop();

    bool isWin();
    void checkLose(std::pair<int,int>);

    Board board_;
    Renderer renderer_;
    bool run_;
};

#endif
