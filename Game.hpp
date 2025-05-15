

#ifndef GAME_H_
#define GAME_H_

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <stdio.h>
#include <SDL_mixer.h>

#include "Board.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "life.hpp"
#define FPS_DELAY 500

class Game {
public:
    Game();
    ~Game();

    bool Init();
    void Run();
    int count=0;

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* texture;

    // Timing
    unsigned int lasttick;


    Board* board;
    Paddle* paddle;
    Ball* ball;
    Life* life;
    Life* life2;
    Life* life3;
    bool paddlestick;
    void Score();
    void Clean();
    void Update(float delta);
    void Render(float delta);

    void NewGame();
    void ResetPaddle();
    void StickBall();

    void SetPaddleX(float x);
    void CheckBoardCollisions();
    float GetReflection(float hitx);
    void CheckPaddleCollisions();
    void CheckBrickCollisions();
    void CheckBrickCollisions2();
    void BallBrickResponse(int dirindex);
    int GetBrickCount();
};

#endif
