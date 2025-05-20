#include "dati.hpp"
#include <cmath>
#include  <SFML/Graphics.hpp>



std::vector<sf::Color> immagineVettore(const sf::Image& image, int height, int width) {
    std::vector<sf::Color> risultato;

    for (int y = 0; y < height; ++y) {         
        for (int x = 0; x < width; ++x) {      
            risultato.push_back(image.getPixel(x,y));
        }
    }

    return risultato;
}

int bianconero (immagineVettore p){
    double norma= std::sqrt(p.r * p.r + p.g * p.g + p.b *p.b );
    if (norma<127){
        return -1;
    }
    return 1;
}
