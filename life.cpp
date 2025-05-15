#include "life.hpp"

Life::Life(SDL_Renderer* renderer, int x): Entity(renderer) {
    SDL_Surface* surface = IMG_Load("life.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    a = x;
    width = 30;
    height = 30;

}

Life::~Life() {
    // Clean resources
    SDL_DestroyTexture(texture);
}


void Life::Update(float delta) {

}

void Life::Render(float delta) {
    SDL_Rect rect;
        rect.x = (a);
        rect.y = (5);
        rect.w = width;
        rect.h = height;
        SDL_RenderCopy(renderer, texture, 0, &rect);

}