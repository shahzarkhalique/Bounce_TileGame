
#ifndef BALL_H_
#define BALL_H_

#include "Entity.hpp"

#include <math.h>

// ball speed in pixels per second
const float BALL_SPEED = 500;

class Ball: public Entity {
public:
    Ball(SDL_Renderer* renderer);
    ~Ball();

    void Update(float delta);
    void Render(float delta);

    void SetDirection(float dirx, float diry);

    float dirx, diry;

private:
    SDL_Texture* texture;

};

#endif
