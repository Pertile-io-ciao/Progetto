#include <SFML/Graphics.hpp>
#include <vector>

struct pixel
{
    double r;
    double g; 
    double b;
};



std::vector<sf::Color> immagineVettore(const sf::Image& image);
std::vector<int> bianconero (const std::vector<sf::Color>& v);
std::vector<int> interpolazioneBilineare(const std::vector<int>& input, int inW, int inH);
sf::Image vettoreInImmagine(const std::vector<int>& dati);
sf::Image vettoreInImmagine(const std::vector<int>& dati, const sf::Image& image);
std::vector<int> zoom(const std::vector<int>& v, int n);