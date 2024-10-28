#ifndef RENDER_H
#define RENDER_H

#include <utility>

enum CellState {
  HIDDEN,
  DISCOVERED,
  FLAGGED
};

class Board;

class Renderer{
  public:
    Renderer(Board& board);
    ~Renderer();

    void render();
    void printRaw();
    CellState getGridValue(std::pair<int,int> pos) const;
    void setGridValue(std::pair<int,int> pos, CellState value);
  private:
    Board& board_;
    int height_;
    int width_;
    CellState** grid_;
};

#endif
