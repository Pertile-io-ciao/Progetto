#include <iostream>
#include <SFML/Graphics.hpp>

int main () {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Crea un cerchio di raggio 50 e lo colora di rosso
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(375, 275); // Posizione centrata nella finestra

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); // Pulisce la finestra
        window.draw(circle); // Disegna il cerchio
        window.display(); // Mostra la finestra aggiornata
    }

    return 0;
}