#include <SFML/Graphics.hpp>
#include <vector>

#include <iostream>
#include "grafica.hpp"

int disegna() 
{ 
    sf::RenderWindow window(sf::VideoMode(1500, 1300), "Rete neurale di Hopfield");

    sf::Texture texture;
    if (!texture.loadFromFile("imageKitty.png")) {
        std::cerr << "Errore nel caricamento di imageMiao.png\n";
        return -1;
    }

    texture.setSmooth(true);
    sf::Sprite sprite1(texture);
    sprite1.setPosition(0, 0);

    // Event loop per tenere aperta la finestra
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite1);
        window.display();
    }

    return 0;
}
