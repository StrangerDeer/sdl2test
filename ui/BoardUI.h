#pragma once

#include <memory>
#include "TextureCreator.h"
#include "../logic/BoardLogic.h"

class BoardUI : public TextureCreator {
 public:
  BoardUI(SDL_Renderer* renderer, std::shared_ptr<BoardLogic> board,int x, int y, SDL_Color color) :
      TextureCreator(renderer, board->width, board->height, color)
  {
    boardUIRect.x = x;
    boardUIRect.y = y;
  }

  void print(SDL_Renderer* renderer) override;

 private:
  SDL_Rect boardUIRect{0,0,0,0};
};
