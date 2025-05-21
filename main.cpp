#include <iostream>
#include "dati.hpp"
#include "grafica.hpp"
#include <SFML/Graphics.hpp>
#include <vector>


int main ()  {
    disegna();
    sf::Image image;
    if (!image.loadFromFile("imageKitty.png")) {
        std::cerr << "Errore nel caricamento dell'immagine.\n";
        return -1;
    }

    int height = image.getSize().y;
    int width = image.getSize().x;

    std::vector<sf::Color> colori = immagineVettore(image, 64, 64);
    std::vector<int> vettore= vettore1(colori);
    std::cout << "Vettore di interi:\n";
    for (std::size_t i = 0; i < vettore.size(); ++i) {
    std::cout << "Elemento " << i << ": " << vettore[i] << "\n";
}
}