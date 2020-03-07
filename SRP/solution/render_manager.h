//
// Created by martin on 7/3/20.
//
#include <SFML/Graphics.hpp>
#include "ball.h"

#ifndef SOLID_DRAW_MANAGER_H
#define SOLID_DRAW_MANAGER_H


class render_manager {
private:
    mutable sf::CircleShape base;
public:
    void draw_ball(Ball &b, sf::RenderWindow *w);
};


#endif //SOLID_DRAW_MANAGER_H
