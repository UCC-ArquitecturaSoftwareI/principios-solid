/**
    Example program for SFML following SRP principle.

    @author Marcucci, Ricardo Martin
    @version 0.1 2020-03-07
*/
#include <SFML/Graphics.hpp>
#include <random>
#include <functional>
#include <cstdlib>
#include <list>
#include <sstream>

#include "ball.h"
#include "render_manager.h"

int main() {
    // Constant windows data
    const int w_width = 640;
    const int w_height = 640;
    const int bpp = 32;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    std::list<Ball *> entities;
    render_manager rm;

    // Init Window
    sf::RenderWindow window(sf::VideoMode(w_width, w_height, bpp), "SOLID - SRP SFML", sf::Style::Default, settings);

    sf::Font font;
    if (!font.loadFromFile("Roboto-Regular.ttf"))
        return EXIT_FAILURE;
    sf::Text text;

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    std::stringstream ss;

    // Init random number generator
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, w_width); // distribution in range [1, 6]

    auto random = std::bind(dist, std::ref(rng));

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
            } else if (event.type == sf::Event::MouseButtonPressed &&
                       event.mouseButton.button == sf::Mouse::Left) {
                auto p = sf::Mouse::getPosition(window);
                for (int i = 0; i < 100; i++)
                    entities.push_back(new Ball(
                            p.x,
                            p.y,
                            (random() - w_width / 2.0),
                            (random() - w_width / 2.0)));
            }
        }

        elapsed += clock.restart();
        while (elapsed >= update_ms) {
            for (auto &e: entities) {
                e->move(w_width, w_height, 0, 0, update_ms.asSeconds());
            }
            elapsed -= update_ms;
        }
        window.clear(sf::Color(255, 255, 255));

        for (auto &e: entities) {
            rm.draw_ball(*e, &window);
        }
        ss.str("");
        ss << "Balls: " << entities.size();

        text.setString(ss.str());

        window.draw(text);
        window.display();
    }

    return EXIT_SUCCESS;
}