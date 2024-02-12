
#include "Game.h"

void Game::init() {
  window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth,windowHeight,
                            SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
  if (!window) {
    std::cerr << "Error: Unable to create window!" << SDL_GetError() << std::endl;
    return;
  }

  renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);

  if (!renderer) {
    std::cerr << "Error: Unable to create renderer!" << SDL_GetError() << std::endl;
    return;
  }
}

void Game::initElements() {
  board = std::make_shared<BoardLogic>(windowWidth, windowHeight);
}

void Game::initUI() {
  std::cout<<std::to_string(windowHeight)<<std::endl;
  boardUI = std::make_unique<BoardUI>(renderer, board, 0,0,SDL_Color{255,255,255,255});
}

void Game::run() {
  while(isRunning){
    handleEvents();
    boardUI->print(renderer);
    SDL_Delay(25);
  }
}

void Game::handleEvents() {
  while (SDL_PollEvent(&event)){
    if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE){
      isRunning = false;
    }
  }
}

