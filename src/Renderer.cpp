#include "Renderer.h"
#include "Board.h"
#include <algorithm>
#include <cstring>
#include <iostream>

#include <string>

namespace BColors {
    const std::string HEADER = "\033[95m";
    const std::string OKBLUE = "\033[94m";
    const std::string OKCYAN = "\033[96m";
    const std::string OKGREEN = "\033[92m";
    const std::string GREY = "\033[90m";
    const std::string WARNING = "\033[93m";
    const std::string FAIL = "\033[91m";
    const std::string ENDC = "\033[0m";
    const std::string BOLD = "\033[1m";
    const std::string UNDERLINE = "\033[4m";
}

using namespace BColors;

Renderer::Renderer(Board& board): board_(board) {
  height_ = board_.getH();
  width_ = board_.getW();
  grid_ = new CellState*[height_];
  for (int i = 0; i < height_; ++i) {
    grid_[i] = new CellState[width_];
    std::fill_n(grid_[i], width_, HIDDEN);
  }
}

Renderer::~Renderer() {
  for (int i = 0; i < height_; ++i) {
    delete[] grid_[i];
  }
  delete[] grid_;
}

void Renderer::render() {
  std::cout << OKBLUE << "   ";
  for (int j=0;j!=width_;++j) std::cout << " " << j << " ";
  std::cout << std::endl << "   ";
  for (int j=0;j!=width_;++j) std::cout << "---";
  std::cout << ENDC << std::endl;

  for (int i=0;i!=height_;++i) {
    std::cout << OKBLUE << i << " |" << ENDC;
    for (int j=0;j!=width_;++j) {
      std::cout << " ";
      if (getGridValue(std::pair<int,int>(j,i))==HIDDEN)
        std::cout << GREY << "*";
      else if (getGridValue(std::pair<int,int>(j,i))==FLAGGED)
        std::cout <<  WARNING << "F";
      else if (board_.getGridValue(std::pair<int,int>(j,i))==9)
        std::cout <<  FAIL << "X";
      else
        std::cout
          << static_cast<int>(board_.getGridValue(std::pair<int,int>(j,i)));
      std::cout << " " << ENDC;
    }
    std::cout << std::endl; 
  }
}

void Renderer::setGridValue(std::pair<int,int> pos, CellState value) {
  grid_[pos.second][pos.first] = value;
}

CellState Renderer::getGridValue(std::pair<int,int> pos)
  const {
  return grid_[pos.second][pos.first];
}

void Renderer::printRaw() {
  std::cout << "Render Grid :" << std::endl;
  for (int i = 0; i < height_; ++i) {
    for (int j = 0; j < width_; ++j) {
      std::cout << getGridValue(std::pair<int,int>(j,i));
    }
    std::cout << std::endl;
  }
}

