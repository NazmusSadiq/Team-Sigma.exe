#pragma once
#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Window.hpp>
#include "Paddle.h"
#include "AI_Paddle.h"

#define PointLimit 5
#define WindowWidth 960
#define WindowHeight 720

#define defaultballvelocity 1.25f

using namespace sf;
class Ball
{
private:

    CircleShape BallObject;
    Vector2f ballPosition;
    Texture tex;
public:
    CircleShape getBallObject();
    Ball(double x, double y, RenderWindow & window);
    FloatRect getBallFloatRect();
    void reboundSides();
    void passTopAI(Paddle paddle,AI_Paddle aipaddle);
    void passTop(Paddle paddle1, Paddle paddle2);
    Vector2f getBallPosition;
    void passBottomAI(Paddle &paddle, AI_Paddle &aipaddle);
    void passBottom(Paddle& paddle1, Paddle& paddle2);
    int playerscore = 0, opponentscore = 0;
    void reboundPaddle(Paddle paddle);
    void reboundAIPaddle(AI_Paddle aipaddle);
    void update();
    double ballVelocityX = 0.0f;
    double ballVelocityY = defaultballvelocity;
    void stop();
    void go();
    Sound loser,winner;
    SoundBuffer lbfr,wbfr;
};

