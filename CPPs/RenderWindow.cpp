#include "RenderWindow.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

SDL_Renderer* RenderWindow::renderer = nullptr;

RenderWindow::RenderWindow(const char* title, int wWidth, int wHeight) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wWidth, wHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::loadTexture(const char* path) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, path);

    return texture;
}

void RenderWindow::clear() {
    SDL_RenderClear(renderer);
}

void RenderWindow::drawColor(int red, int green, int blue) {
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
}

void RenderWindow::render(SDL_Texture* texture) {
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}

void RenderWindow::close() {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    IMG_Quit();
    SDL_Quit();
}