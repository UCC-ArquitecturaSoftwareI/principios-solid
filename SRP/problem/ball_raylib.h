/**
    Example of ball implementation for raylib without following SRP principle.

    @author Marcucci, Ricardo Martin
    @version 0.1 2020-03-07
*/
#include "raylib.h"

#ifndef SOLID_BALL_RAYLIB_H
#define SOLID_BALL_RAYLIB_H


class Ball {
    float x, y;
    float radius, vel_x, vel_y;

public:
    Ball(float x, float y, float velX, float velY);

    void move(int wWith, int wHeight, int beginX, int beginY, float t);

    void draw();
};

#endif
