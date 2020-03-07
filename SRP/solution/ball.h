//
// Created by martin on 6/3/20.
//
#include <SFML/Graphics.hpp>


#ifndef SOLID_BALL_GOOD_H
#define SOLID_BALL_GOOD_H


class Ball {
    float x, y;
    float radius, vel_x, vel_y;


public:
    Ball(float x, float y, float velX, float velY);

    void move(int wWith, int wHeight, int beginX, int beginY, float t);

    float getX() const;

    float getY() const;

    float getRadius();
};


#endif //SOLID_BALL_GOOD_Hf
