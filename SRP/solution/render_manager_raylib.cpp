/**
    Example renderer class added to follow SRP principle.

    @author Marcucci, Ricardo Martin
    @version 0.1 2020-03-07
*/
#include "render_manager_raylib.h"

void render_manager::draw_ball(Ball &b) {

    Vector2 ballPosition = {b.getX(),b.getY()};
    DrawCircleV(ballPosition, b.getRadius(), RED);
}
