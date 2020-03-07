/**
    Example renderer class added to follow SRP principle.

    @author Marcucci, Ricardo Martin
    @version 0.1 2020-03-07
*/
#include "raylib.h"
#include "ball.h"

#ifndef SOLID_RENDER_MANAGER_RAYLIB_H
#define SOLID_RENDER_MANAGER_RAYLIB_H


class render_manager {
private:

public:
    void draw_ball(Ball &b);
};


#endif
