//
// Created by martin on 7/3/20.
//

#include "render_manager.h"

void render_manager::draw_ball(Ball &b, sf::RenderWindow *w) {
    sf::CircleShape ball;
    ball.setRadius(b.getRadius());
    ball.setFillColor(sf::Color::Red);
    ball.setOrigin(b.getRadius(), b.getRadius());
    ball.setPosition(b.getX(),b.getY());
    w->draw(ball);

}
