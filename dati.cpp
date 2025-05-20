#include "dati.hpp"
#include <cmath>

int bianconero (pixel p){
    double norma= std::sqrt(p.r * p.r + p.g * p.g + p.b *p.b );
    if (norma<127){
        return -1;
    }
    return 1;
}

std::vector<pixel> immagineInVettore(pixel** matrice, int height, int width) {
    std::vector<pixel> risultato;

    for (int y = 0; y < height; ++y) {         // alto -> basso
        for (int x = 0; x < width; ++x) {      // sinistra -> destra
            risultato.push_back(matrice[y][x]);
        }
    }

    return risultato;
}           //chatgpt CHIEDI    prend ei pixel non l'immagine