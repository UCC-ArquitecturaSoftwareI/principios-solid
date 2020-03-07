/**
    Example program for sfml without following SRP principle.

    @author Marcucci, Ricardo Martin
    @version 0.1 2020-03-07
*/
#include <SFML/Graphics.hpp>
#include <random>
#include <functional>
#include <cstdlib>
#include <list>
#include <sstream>

#include "ball_sfml.h"

int main() {
    /// Constant windows data
    const int w_width = 640;
    const int w_height = 640;
    const int bpp = 32;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    /// list of balls
    std::list<Ball *> entities;

    /// String stream to write in the window
    std::stringstream ss;

    /// Init Window
    sf::RenderWindow window(sf::VideoMode(w_width, w_height, bpp), "SOLID - SRP SFML", sf::Style::Default, settings);

    /// Init random number generator
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, w_width);
    auto random = std::bind(dist, std::ref(rng));

    /// Init text entity to write to window
    sf::Font font;
    if (!font.loadFromFile("Roboto-Regular.ttf"))
        return EXIT_FAILURE;
    sf::Text text;

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    /// Main game loop
    sf::Clock clock;
    sf::Time elapsed = clock.restart();
    const sf::Time update_ms = sf::seconds(1.f / 30.f);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                window.close();
                break;


            /// If mouse clicked, add new entity to the list
            } else if (event.type == sf::Event::MouseButtonPressed &&
                       event.mouseButton.button == sf::Mouse::Left) {
                auto p = sf::Mouse::getPosition(window);
                entities.push_back(new Ball(
                        p.x,
                        p.y,
                        (random() - w_width / 2.0),
                        (random() - w_width / 2.0)));
            }
        }

        elapsed += clock.restart();

        /// move all entities
        while (elapsed >= update_ms) {
            for (auto &e: entities) {
                e->move(w_width, w_height, 0, 0, update_ms.asSeconds());
            }
            elapsed -= update_ms;
        }
        window.clear(sf::Color(255, 255, 255));

        /// Drawing all entities on window
        for (auto &e: entities) {
            e->draw(&window);
        }
        ss.str("");
        ss << "Balls: " << entities.size();

        text.setString(ss.str());

        window.draw(text);
        window.display();
    }

    return EXIT_SUCCESS;
}