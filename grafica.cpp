#include <SFML/Graphics.hpp>
#include <vector>

#include <iostream>
#include "grafica.hpp"

int disegna(sf::Texture& texture, sf::Texture& textureBW) 
{ 
    sf::RenderWindow window(sf::VideoMode(1500, 1300), "Rete neurale di Hopfield");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);
   

    texture.setSmooth(true);
    sf::Sprite sprite(texture);
    sprite.setPosition(0, 0);
     sf::Clock clock;

    bool cambioAvvenuto = false;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Controlla se sono passati 3 secondi
        if (!cambioAvvenuto && clock.getElapsedTime().asSeconds() >= 3.0f) {
            sprite.setTexture(textureBW);  // cambia la texture del sprite
            cambioAvvenuto = true;
            std::cout << "Texture cambiata dopo 3 secondi!\n";
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
