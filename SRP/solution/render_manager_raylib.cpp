//
// Created by martin on 7/3/20.
//

#include "render_manager_raylib.h"

void render_manager::draw_ball(Ball &b) {

    Vector2 ballPosition = {b.getX(),b.getY()};
    DrawCircleV(ballPosition, b.getRadius(), RED);
}
