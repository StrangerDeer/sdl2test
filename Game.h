#pragma once

#include <SDL.h>
#include <iostream>
#include <memory>
#include <string>
#include "ui/BoardUI.h"
#include "logic/BoardLogic.h"

class Game {
 public:
  Game()
  {
    init();
    initElements();
    initUI();
  }

  ~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
  }
  void run();

 private:
  SDL_Window* window{nullptr};
  SDL_Renderer* renderer{nullptr};
  SDL_Event event{};
  bool isRunning{true};

  const static int windowWidth{1000};
  const static int windowHeight{1000};

  std::shared_ptr<BoardLogic> board{nullptr};
  std::unique_ptr<BoardUI> boardUI{nullptr};

  void init();
  void initElements();
  void initUI();
  void handleEvents();
};
