/**
    Example program for raylib without following SRP principle.

    @author Marcucci, Ricardo Martin
    @version 0.1 2020-03-07
*/
#include "raylib.h"
#include <random>
#include <functional>
#include <cstdlib>
#include <list>
#include <sstream>

#include "ball_raylib.h"

int main() {
    /// Constant windows data
    const int w_width = 640;
    const int w_height = 640;

    /// Save mouse position
    Vector2 mousePos;
    bool mouse_before = false;

    /// List of balls
    std::list<Ball *> entities;

    /// String stream to write in the window
    std::stringstream ss;

    /// Init Window
    InitWindow(w_width, w_height, "SOLID - SRP Raylib");
    SetTargetFPS(60);

    /// Init random number generator
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, w_width);
    auto random = std::bind(dist, std::ref(rng));

    /// Main game loop
    while (!WindowShouldClose()) {
        /// If mouse clicked, add new entity to the list
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !mouse_before) {
            mouse_before = true;

            mousePos = GetMousePosition();
            entities.push_back(new Ball(
                    mousePos.x,
                    mousePos.y,
                    (random() - w_width / 2.0),
                    (random() - w_width / 2.0)));

        } else if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            mouse_before = false;
        }

        /// move all entities
        for (auto &e: entities) {
            e->move(w_width, w_height, 0, 0, GetFrameTime());
        }

        /// Drawing all entities on window
        BeginDrawing();

        { // bracket only to keep idented the main drawing functions

            ClearBackground(RAYWHITE);
            for (auto &e: entities) {
                e->draw();
            }
            ss.str("");

            ss << "Balls: " << entities.size();
            DrawText(ss.str().c_str(), 0, 0, 24, BLACK);
        }

        EndDrawing();
    }

    return EXIT_SUCCESS;
}