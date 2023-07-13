#include <SDL.h>
#include <SDL_render.h>

constexpr int WindowWidth = 1080;
constexpr int WindowHeight = 720;

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    SDL_Log("init sdl faield!!");
  }

  SDL_Window *window = SDL_CreateWindow("sdl_demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                        WindowWidth, WindowHeight, SDL_WINDOW_SHOWN);

  SDL_Renderer *renderer = SDL_CreateRenderer(window, 1, 0);
  bool isquit = false;

  SDL_Event event;
  while (!isquit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        isquit = true;
      }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect rect{.x = 100, .y = 100, .w = 100, .h = 100};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
