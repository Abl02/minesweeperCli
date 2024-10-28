#include "Board.h"
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>

Board::Board(int height, int width, int mines)
    : height_(height), width_(width), mines_(mines) {
  grid_ = new uint8_t*[height_];
  for (int i = 0; i < height_; ++i) {
    grid_[i] = new uint8_t[width_];
    memset(grid_[i], 0, width_ * sizeof(uint8_t));
  }
}

Board::~Board() {
  for (int i = 0; i < height_; ++i) {
    delete[] grid_[i];
  }
  delete[] grid_;
}

void Board::generateMines(std::pair<int,int> first_pos) {
  srand((unsigned)time(0));
  for (int i = 0; i<mines_; ++i) {
    int x = rand() % width_;
    int y = rand() % height_;
    std::pair<int,int> pos = {x,y};
    std::vector<std::pair<int,int>>
      safe_zone = getNeigbours(first_pos);
    if (getGridValue(pos)==9) {
      i--;
    }
    else if (std::find(safe_zone.begin(), safe_zone.end(), pos)
        != safe_zone.end() || pos == first_pos) {
      i--;
    }
    else {
      addMine(pos);
    }
  }
}

void Board::addMine(std::pair<int,int> pos) {
  setGridValue(pos,9);
  for (auto n : getNeigbours(pos)) {
    addGridValue(n, 1);
  }
}

bool Board::isValidPosition(std::pair<int, int> pos) {
  return (pos.first >= 0 && pos.first < width_ && pos.second >= 0 && pos.second < height_);
}

std::vector<std::pair<int,int>>
Board::getNeigbours(std::pair<int, int> pos) {
  std::vector<std::pair<int,int>> neighbors;
  for (int i = pos.second-1;i<=pos.second+1;++i) {
    for (int j = pos.first-1;j<=pos.first+1;++j) {
      std::pair<int,int> neighbor = {j, i};
      if (isValidPosition(neighbor) && getGridValue(neighbor) < 9) {
        neighbors.push_back(neighbor);
      }
    }
  }
  return neighbors;
}

uint8_t Board::getGridValue(std::pair<int,int> pos)
  const {
  return grid_[pos.second][pos.first];
}

void Board::setGridValue(std::pair<int,int> pos, uint8_t value) {
  grid_[pos.second][pos.first] = value;
}

void Board::addGridValue(std::pair<int,int> pos, bool add) {
  if (add) grid_[pos.second][pos.first]++;
  else grid_[pos.second][pos.first]--;
}

void Board::printRaw() {
  std::cout << "Board Grid :" << std::endl;
  for (int i = 0; i < height_; ++i) {
    for (int j = 0; j < width_; ++j) {
      std::cout << (int)getGridValue(std::pair<int,int>(j,i));
    }
    std::cout << std::endl;
  }
}

int Board::getW() const { return width_; }

int Board::getH() const { return height_; }
