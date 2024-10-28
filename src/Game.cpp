#include "Game.h"
#include "Renderer.h"
#include "Board.h"
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>


Game::Game(int height, int width, int mines)
  :board_(Board(height,width,mines)),
   renderer_(Renderer(board_)),
   run_(true) {
  gameLoop();
}

void Game::click(std::pair<int,int> pos) {
  if (renderer_.getGridValue(pos) == HIDDEN ||
      renderer_.getGridValue(pos) == FLAGGED) {
    renderer_.setGridValue(pos, DISCOVERED);
    checkLose(pos);
    propagateClick(pos);
  }
}

void Game::flag(std::pair<int,int> pos) {
  if (renderer_.getGridValue(pos) == HIDDEN) {
    renderer_.setGridValue(pos, FLAGGED);
  }
  else if (renderer_.getGridValue(pos) == FLAGGED) {
    renderer_.setGridValue(pos, HIDDEN);
  }
}

void Game::gameLoop() {
  renderer_.render();
  std::pair<std::pair<int,int>,char> action; 
  action = getInput();
  
  board_.generateMines(action.first);

  processInput(action);
  renderer_.render();
  while (run_) {
    action = getInput();
    processInput(action);
    renderer_.render();
  }
}

bool Game::isWin() {
  return 0;
}

void Game::checkLose(std::pair<int,int> pos) {
  if (board_.getGridValue(pos) == 9) {
    run_ = false;
    std::cout << "Loser !" << std::endl;
  }
}

void Game::propagateClick(std::pair<int,int> pos) {
  if (board_.getGridValue(pos) == 0) {
    for (auto n: board_.getNeigbours(pos)) {
      if (renderer_.getGridValue(n) == HIDDEN) {
        click(n);
      }
    }
  }
}

void Game::processInput(std::pair<std::pair<int,int>,char> input) {
  switch (input.second) {
    case 'x':
      exit(0);
      break;
    case 'X':
      exit(0);
      break;
    case 'f':
      flag(input.first);
      break;
    case 'F':
      flag(input.first);
      break;
    default:
      click(input.first);
  }
}

std::pair<std::pair<int,int>,char> Game::getInput() {
  std::string input;
  std::getline(std::cin, input);
  return parseInput(input);
}

std::pair<std::pair<int,int>,char> Game::parseInput(std::string input) {
  std::pair<int,int> pos = {-1,-1};
  char action = '\0';
  char i1 = '\0', i2 ='\0', i3 = '\0';

  std::stringstream sinput(input);
  sinput >> i1;
  if (sinput) sinput >> i2;
  if (sinput) sinput >> i3;

  if (std::isalpha(i1)) {
    action = i1;
    if (std::isdigit(i2) && std::isdigit(i3)) {
      pos.first = i2 - '0';
      pos.second = i3 - '0';
    }
  }
  else if (std::isdigit(i1) && std::isdigit(i2)) {
    pos.first = i1 - '0';
    pos.second = i2 - '0';
    if (std::isalpha(i3)) {
      action = i3;
    }
  }
  return std::pair<std::pair<int,int>,char>(pos, action);
}


