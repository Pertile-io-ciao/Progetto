#include "dati.hpp"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
int l= 64;



std::vector<sf::Color> immagineVettore(const sf::Image& image, int height, int width) {
    std::vector<sf::Color> risultato;

    for (int y = 0; y < height; ++y) {         
        for (int x = 0; x < width; ++x) {      
            risultato.push_back(image.getPixel(x,y));
        }
    }

    return risultato;
}   //mi trovo un vettore composto da tutti sf::Color che sono praticamente i pixel

int bianconero (const sf::Color& p) {
    double norma= std::sqrt(p.r * p.r + p.g * p.g + p.b *p.b );
    if (norma<127){
        return -1;
    }
    return 1;
} //questo fa solo 1 pixel

std::vector<int> vettore1 (const std::vector<sf::Color>& v){
    std::vector<int> risultato;
    for (std::size_t i = 0; i < v.size(); ++i) {
        risultato.push_back(bianconero(v[i]));
    }
    return risultato;
}   //vettore composto solo da -1 e 1

std::vector<int> interpolazioneBilineare(
    const std::vector<int>& input, int inW, int inH)
{
    std::vector<int> output(l * l); //nuovo vettore

    for (int y = 0; y < l; ++y) {
        for (int x = 0; x < l; ++x) {
            float gx = (x + 0.5f) * (float)inW / l - 0.5f; //gx, gy: coordinate "virtuali" continue nella vecchia immagine.
            float gy = (y + 0.5f) * (float)inH / l - 0.5f; //Spostiamo di 0.5 per centrare i pixel (effetto anti-aliasing).

            int x0 = std::clamp((int)gx, 0, inW - 2);
            int y0 = std::clamp((int)gy, 0, inH - 2);
            float dx = gx - x0;
            float dy = gy - y0;

            auto at = [&](int x, int y) -> float {
                int v = input[y * inW + x];
                return (v == 1) ? 1.0f : 0.0f;
            };

            float v00 = at(x0,     y0);
            float v10 = at(x0 + 1, y0);
            float v01 = at(x0,     y0 + 1);
            float v11 = at(x0 + 1, y0 + 1);

            // Interpolazione bilineare
            float top = v00 + dx * (v10 - v00);
            float bottom = v01 + dx * (v11 - v01);
            float value = top + dy * (bottom - top);

            output[y * l + x] = (value < 0.5f) ? -1 : 1;
        }
    }

    return output;
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
