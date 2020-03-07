/**
    Example of ball implementation for sfml without following SRP principle.

    @author Marcucci, Ricardo Martin
    @version 0.1 2020-03-07
*/
#include <SFML/Graphics.hpp>

#ifndef SOLID_BALL_H
#define SOLID_BALL_H


class Ball {
    float x, y;
    float radius, vel_x, vel_y;
    sf::CircleShape circle;

public:
    Ball(float x, float y, float velX, float velY);

    void move(int wWith, int wHeight, int beginX, int beginY, float t);

    void draw(sf::RenderWindow *w);
};

#endif
