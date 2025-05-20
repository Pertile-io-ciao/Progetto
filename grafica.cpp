#include <SFML/Graphics.hpp>
#include <iostream>
#include "grafica.hpp"

int main()
{ 
sf::RenderWindow window(sf::VideoMode(1500, 1300), "Rete neurale di Hopfield");
sf::Texture texture;
if (!texture.loadFromFile("imageMiao.png")) {
    std::cerr << "Errore nel caricamento di imageMiao.png\n";
    return 1;
}
texture.setSmooth(true);
sf::Sprite sprite1(texture);
sprite1.setPosition(0, 0);

}