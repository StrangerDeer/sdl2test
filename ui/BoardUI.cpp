#include "BoardUI.h"

void BoardUI::print(SDL_Renderer *renderer) {
  SDL_QueryTexture(texture, nullptr, nullptr, &boardUIRect.w, &boardUIRect.h);

  SDL_RenderCopy(renderer, texture, nullptr, &boardUIRect);
}

