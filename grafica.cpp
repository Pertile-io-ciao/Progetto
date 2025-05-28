#include <SFML/Graphics.hpp>
#include <iostream>
#include "grafica.hpp"

int disegna(sf::Texture& textureOriginale, sf::Texture& textureBN) 
{
    sf::RenderWindow window(sf::VideoMode(1500, 1300), "Rete neurale di Hopfield");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);

    // Attiva l'anti-aliasing solo se vuoi immagini morbide (opzionale)
    textureOriginale.setSmooth(true);
    textureBN.setSmooth(true);

    // Crea due sprite distinti per le due texture
    sf::Sprite spriteOriginale(textureOriginale);
    sf::Sprite spriteBN(textureBN);
    spriteOriginale.setPosition(0, 0);
    spriteBN.setPosition(0, 0);

    sf::Clock clock;
    bool cambioAvvenuto = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Chiudi con la X della finestra
            if (event.type == sf::Event::Closed)
                window.close();

            // Chiudi anche con ESC
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        // Dopo 3 secondi cambia immagine
        if (!cambioAvvenuto && clock.getElapsedTime().asSeconds() >= 3.0f) {
            cambioAvvenuto = true;
            std::cout << "Texture cambiata dopo 3 secondi!\n";
        }

        window.clear();

        // Mostra l'immagine giusta
        if (!cambioAvvenuto)
            window.draw(spriteOriginale);
        else
            window.draw(spriteBN);

        window.display();
    }

    return 0;
}
