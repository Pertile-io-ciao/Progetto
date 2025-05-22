#include <iostream>
#include "dati.hpp"
#include "grafica.hpp"
#include <SFML/Graphics.hpp>
#include <vector>


int main ()  {

    sf::Image image;
    if (!image.loadFromFile("imageKitty.png")) {
        std::cerr << "Errore nel caricamento dell'immagine.\n";
        return -1;
    }
    sf::Texture texture;
    if (!texture.loadFromFile("imageKitty.png")) {
        std::cerr << "Errore nel caricamento di imageMiao.png\n";
        return -1;
    }

    int height = image.getSize().y;
    int width = image.getSize().x;

    std::vector<sf::Color> colori = immagineVettore(image, 64, 64);
    std::vector<int> vettore= vettore1(colori);
    std::cout << "Vettore di interi:\n";
    for (std::size_t i = 0; i < 14; ++i) {
    std::cout << "Elemento " << i << ": " << vettore[i] << "\n";
    }
    auto v=interpolazioneBilineare(vettore, width, height);
    sf::Image imagebw = vettoreInImmagine(v);
    sf::Texture texturebw;
    if (!texturebw.loadFromImage(imagebw)) {
        std::cerr << "Errore nel caricamento di imageMiao.png\n";
        return -1;
    }
    
    disegna(texture, texturebw);
}