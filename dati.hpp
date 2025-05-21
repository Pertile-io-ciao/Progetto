#include <SFML/Graphics.hpp>
#include <vector>

struct pixel
{
    double r;
    double g; 
    double b;
};

std::vector<sf::Color> immagineVettore(const sf::Image& image, int height, int width);
int bianconero (pixel p);
std::vector<int> vettore1 (const std::vector<sf::Color>& v);

sf::Image interpolazioneBilineare(const sf::Image& src, unsigned int newWidth, unsigned int newHeight);