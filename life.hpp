
#ifndef LIFE_H_
#define LIFE_H_

#include "Entity.hpp"

class Life: public Entity {
public:
    Life(SDL_Renderer* renderer, int x);
    ~Life();

    void Update(float delta);
    void Render(float delta);

private:
    SDL_Texture* texture;
    int a;
};

#endif