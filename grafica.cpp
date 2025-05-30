#include <SFML/Graphics.hpp>
#include <iostream>
#include "grafica.hpp"
int disegna(sf::Texture& texture1, sf::Texture& texture2, sf::Texture& texture3, sf::Texture& texture4) {
    sf::RenderWindow window(sf::VideoMode(1900, 800), "Rete neurale di Hopfield");

    sf::Sprite sprite1(texture1);
    sf::Sprite sprite2(texture2);
    sf::Sprite sprite3(texture3);
    sf::Sprite sprite4(texture4);

    sprite1.setPosition(0.f, 0.f);
    sprite2.setPosition(500.f, 0.f);
    sprite3.setPosition(1000.f, 0.f);
    sprite4.setPosition(1500.f, 0.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
        window.draw(sprite4);

        window.display();
    }

    return 0;
}
