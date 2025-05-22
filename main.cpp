#include <iostream>
#include "dati.hpp"
#include "grafica.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

int main() {
    sf::Image image;
    if (!image.loadFromFile("imageKitty.png")) {
        std::cerr << "Errore nel caricamento dell'immagine.\n";
        return -1;
    }

    int width = image.getSize().x;
    int height = image.getSize().y;

    std::vector<sf::Color> colori = immagineVettore(image);  // vettore di sf::Color
    std::vector<int> vettore = bianconero(colori);            // -1 / 1

    // Applica interpolazione per ottenere vettore di dimensione l x l
    std::vector<int> v_interpolato = interpolazioneBilineare(vettore, width, height, 100);

    std::vector<int> zoom( v_interpolato , 100, 10); 

    // Converti il vettore in immagine (bianco e nero)
    sf::Image imagebw = vettoreInImmagine(zoom);

    // Crea le texture da disegnare
    sf::Texture texture, texturebw;
    texture.loadFromImage(image); // originale
    if (!texturebw.loadFromImage(imagebw)) {
        std::cerr << "Errore nel caricamento della texture bianco/nero.\n";
        return -1;
    }

    // Mostra entrambe le texture in sequenza
    disegna(texture, texturebw); // Assicurati che questa funzione esista
    return 0;
}
