#include "dati.hpp"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
int l= 100;



std::vector<sf::Color> immagineVettore(const sf::Image& image) {
    int width = image.getSize().x;
    int height = image.getSize().y;

   std::vector<sf::Color> risultato;
    risultato.reserve(width * height);

    for (int y = 0; y < height; ++y) {         
        for (int x = 0; x < width; ++x) {      
            risultato.push_back(image.getPixel(x, y));
        }
    }

    return risultato;
}
 //mi trovo un vettore composto da tutti sf::Color che sono praticamente i pixel


std::vector<int> bianconero(const std::vector<sf::Color>& v) {
    std::vector<int> risultato;

    for (std::size_t i = 0; i < v.size(); ++i) {
        const sf::Color& c = v[i];

        // Ignora completamente i pixel trasparenti (opzionale)
        if (c.a < 10) {
            risultato.push_back(-1);  // considera come bianco
            continue;
        }

        // Calcola la luminanza percepita
        double luminanza = (0.299 * c.r + 0.587 * c.g + 0.114 * c.b);
        int h = (luminanza < 127) ? 1 : -1;
        risultato.push_back(h);
    }

    return risultato;
}
 std::vector<int> interpolazioneBilineare(
    const std::vector<int>& input, int inW, int inH, int out)
{
    std::vector<int> output(out * out);

    for (int y = 0; y < out; ++y) {
        for (int x = 0; x < out; ++x) {
            // Mappatura continua dei pixel: niente -0.5, niente (out - 1)
            float gx = ((x + 0.5f) * inW) / out - 0.5f;
            float gy = ((y + 0.5f) * inH) / out - 0.5f;

            // Clamp per evitare fuori-bordo
            int x0 = std::clamp((int)gx, 0, inW - 2);
            int y0 = std::clamp((int)gy, 0, inH - 2);
            int x1 = x0 + 1;
            int y1 = y0 + 1;

            float dx = gx - x0;
            float dy = gy - y0;

            auto at = [&](int x, int y) -> float {
                int v = input[y * inW + x];
                return (v > 0) ? 1.0f : 0.0f;
            };

            float v00 = at(x0, y0);
            float v10 = at(x1, y0);
            float v01 = at(x0, y1);
            float v11 = at(x1, y1);

            float value =
                v00 * (1 - dx) * (1 - dy) +
                v10 * dx * (1 - dy) +
                v01 * (1 - dx) * dy +
                v11 * dx * dy;

            output[y * out + x] = (value < 0.5f) ? -1 : 1;
        }
    }

    return output;
}

std::vector<int> zoom (std::vector<int> v, int l, int n){
    std::vector<int> zoom (l*l*n*n);
    std::vector<int> provvisorio (n);
    while (!v.empty()) {
    for (int x=0; x<l; ++x) {
        provvisorio.push_back(v[x]);   
    }    
    for (int x=0; x<l; ++x) {
        v.erase(v.begin() + x);
    }
    for (int i=0; i<n; ++i){
        for (int j=0; j<l; ++j){
            for (int z=0; z<n; ++z){
                zoom.push_back(provvisorio[j]);
            }
        }
    }
    provvisorio.clear();
}

}


sf::Image vettoreInImmagine(const std::vector<int>& dati) {
    sf::Image image;
    image.create(l, l);

    for (int y = 0; y < l; ++y) {
        for (int x = 0; x < l; ++x) {
            int valore = dati[y * l + x];
            sf::Color colore = (valore == 1) ? sf::Color::Black : sf::Color::White;
            image.setPixel(x, y, colore);
        }
    }

    return image;
}
