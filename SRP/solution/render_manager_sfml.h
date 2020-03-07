/**
    Example renderer class added to follow SRP principle.

    @author Marcucci, Ricardo Martin
    @version 0.1 2020-03-07
*/
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
