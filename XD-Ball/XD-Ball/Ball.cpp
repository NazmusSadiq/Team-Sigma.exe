#include "Ball.h"



Ball::Ball(double x, double y,RenderWindow & window)
{
    ballPosition.x = x;
    ballPosition.y = y;
    //BallObject.setSize(Vector2f(10, 10));
    BallObject.setRadius(7.0f);
    BallObject.setPosition(ballPosition);
    tex.loadFromFile("ball.png");
    BallObject.setTexture(&tex);
    window.draw(BallObject);
    lbfr.loadFromFile("losingsound.wav");
    wbfr.loadFromFile("winningsound.wav");
    winner.setBuffer(wbfr);
    loser.setBuffer(lbfr);
}

CircleShape Ball::getBallObject()
{
    return BallObject;
}

FloatRect Ball::getBallFloatRect()
{
    return BallObject.getGlobalBounds();
}

void Ball::reboundSides()
{
    if (ballPosition.x > WindowWidth)
        ballVelocityX *= -1;

    else if (ballPosition.x < 0)
        ballVelocityX *= -1;

}

void Ball::passTopAI(Paddle paddle, AI_Paddle aipaddle)
{
    if (ballPosition.y <= 5)
    {
        playerscore++;
        if (playerscore == PointLimit)
            winner.play();
        paddle.paddleposition.x = WindowWidth / 2;
        paddle.paddleposition.y = WindowHeight - 20;
        aipaddle.AIPaddlePosition.x = WindowWidth / 2;
        aipaddle.AIPaddlePosition.y = 10;
        ballPosition.x = WindowWidth / 2;
        ballPosition.y = WindowHeight /2;
        ballVelocityX = 0.0f;
        ballVelocityY = -defaultballvelocity;
        

    }
}

void Ball::passTop(Paddle paddle1, Paddle paddle2)
{
    if (ballPosition.y <= 5)
    {
        playerscore++;
        if (playerscore == PointLimit)
            winner.play();
        paddle1.paddleposition.x = WindowWidth / 2;
        paddle1.paddleposition.y = WindowHeight - 20;
        paddle2.paddleposition.x = WindowWidth / 2;
        paddle2.paddleposition.y = 10;
        ballPosition.x = WindowWidth / 2;
        ballPosition.y = WindowHeight / 2;
        ballVelocityX = 0.0f;
        ballVelocityY = -defaultballvelocity;


    }
}

void Ball::passBottomAI(Paddle &paddle, AI_Paddle &aipaddle)
{
    if (ballPosition.y >= WindowHeight - 5)
    {
        opponentscore++;
        if(opponentscore==PointLimit)
            loser.play();
        paddle.paddleposition.x = WindowWidth / 2;
        paddle.paddleposition.y = WindowHeight - 20;
        aipaddle.AIPaddlePosition.x= WindowWidth / 2;
        aipaddle.AIPaddlePosition.y = 10;
        ballPosition.x = WindowWidth / 2;
        ballPosition.y = WindowHeight / 2;
        ballVelocityX = 0.0f;
        ballVelocityY = defaultballvelocity;
    }
}

void Ball::passBottom(Paddle& paddle1, Paddle& paddle2)
{
    if (ballPosition.y >= WindowHeight - 5)
    {
        opponentscore++;
        if (opponentscore == PointLimit)
            winner.play();
        paddle1.paddleposition.x = WindowWidth / 2;
        paddle1.paddleposition.y = WindowHeight - 20;
        paddle2.paddleposition.x = WindowWidth / 2;
        paddle2.paddleposition.y = 10;
        ballPosition.x = WindowWidth / 2;
        ballPosition.y = WindowHeight / 2;
        ballVelocityX = 0.0f;
        ballVelocityY = defaultballvelocity;
    }
}

void Ball::reboundPaddle(Paddle paddle)
{
    ballPosition.y -= (ballVelocityY * 30);
    if (paddle.paddleposition.y > 100)
        ballVelocityY = -defaultballvelocity;
    else
        ballVelocityY = defaultballvelocity;
    float contact = paddle.paddleposition.x + 75;
    ballVelocityX = (ballPosition.x-contact) * 0.015;
}

void Ball::reboundAIPaddle(AI_Paddle aipaddle)
{
    ballPosition.y -= (ballVelocityY * 30);
    ballVelocityY = defaultballvelocity;
    float contact = aipaddle.AIPaddlePosition.x + 75;
    ballVelocityX = (ballPosition.x-contact) * 0.015;
}

void Ball::update()
{

    ballPosition.x += ballVelocityX;
    ballPosition.y += ballVelocityY;

    BallObject.setPosition(ballPosition);
}

void Ball::stop()
{
    ballVelocityY = 0;
    ballVelocityX = 0;
}

void Ball::go()
{
    ballPosition.x = WindowWidth/2;
    ballPosition.y = WindowHeight/2;
    ballVelocityY= defaultballvelocity;
    ballVelocityX= 0.0f;
}
