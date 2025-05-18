#include <iostream>
#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("SDL Window", 640, 640, SDL_WINDOW_OPENGL);
    if (!win) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }

    SDL_Delay(5000);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}