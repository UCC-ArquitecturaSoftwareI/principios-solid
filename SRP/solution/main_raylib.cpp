#include "raylib.h"
#include <random>
#include <functional>
#include <cstdlib>
#include <list>
#include <sstream>
#include <iostream>

#include "ball.h"
#include "render_manager_raylib.h"

int main() {
    // Constant windows data
    const int w_width = 640;
    const int w_height = 640;
    Vector2 mousePos;
    bool mouse_before = false;

    std::list<Ball *> entities;
    render_manager rm;

    std::stringstream ss;

    // Init Window
    InitWindow(w_width, w_height, "SOLID - SRP Raylib");
    SetTargetFPS(60);
    // Init random number generator
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, w_width); // distribution in range [1, 6]

    auto random = std::bind(dist, std::ref(rng));
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !mouse_before) {
            mouse_before = true;

            mousePos = GetMousePosition();
            for (int i = 0; i < 100; i++)
                entities.push_back(new Ball(
                        mousePos.x,
                        mousePos.y,
                        (random() - w_width / 2.0),
                        (random() - w_width / 2.0)));

        } else if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            mouse_before = false;
        }


        for (auto &e: entities) {
            e->move(w_width, w_height, 0, 0, GetFrameTime());
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (auto &e: entities) {
            rm.draw_ball(*e);
        }
        ss.str("");

        ss << "Balls: " << entities.size();
        DrawText(ss.str().c_str(), 0, 0, 24, BLACK);

        EndDrawing();
    }

    return EXIT_SUCCESS;
}