#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1800, 1800), "Due Immagini con SFML");

    // TEXTURE 1
    sf::Texture texture1;
    if (!texture1.loadFromFile("imageMiao.png")) {
        std::cerr << "Errore nel caricamento di image1.png\n";
        return 1;
    }

    texture1.setSmooth(true);
    sf::Sprite sprite1(texture1);
    float side = std::min(texture1.getSize().x, texture1.getSize().y);
    sprite1.setPosition(0, 0); // posizione personalizzabile

    // TEXTURE 2
    sf::Texture texture2;
    if (!texture2.loadFromFile("image2.png")) {
        std::cerr << "Errore nel caricamento di image2.png\n";
        return 1;
    }
    sf::Sprite sprite2(texture2);
    sprite2.setPosition(1000, 0); // posizione spostata a destra

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(sprite1);
        window.draw(sprite2);
        window.display();
    }

    return 0;
}
