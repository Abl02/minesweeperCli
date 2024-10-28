#ifndef BOARD_H
#define BOARD_H

#include <cstdint>
#include <utility>
#include <vector>

class Board{
  public:
    Board(int height, int width, int mines);
    ~Board();

    int getW() const;
    int getH() const;
    void printRaw();
    uint8_t getGridValue(std::pair<int,int> pos) const;
    void generateMines(std::pair<int,int> first_pos);
    std::vector<std::pair<int,int>>
      getNeigbours(std::pair<int, int> pos);
  private:
    int height_;
    int width_;
    int mines_;
    uint8_t** grid_;

    void addMine(std::pair<int,int> pos);
    bool isValidPosition(std::pair<int, int> pos);
    void setGridValue(std::pair<int,int> pos, uint8_t value);
    void addGridValue(std::pair<int,int> pos, bool add);
};

#endif
