//
// Created by martin on 6/3/20.
//
#include "raylib.h"

#ifndef SOLID_BALL_H
#define SOLID_BALL_H


class Ball {
    float x, y;
    float radius, vel_x, vel_y;

public:
    Ball(float x, float y, float velX, float velY);

    void move(int wWith, int wHeight, int beginX, int beginY, float t);

    void draw();
};


#endif //SOLID_BALL_Hf
