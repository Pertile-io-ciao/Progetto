#ifndef ELABORATOREIMMAGINE_HPP
#define ELABORATOREIMMAGINE_HPP

#include <string>
#include  <SFML/Graphics.hpp>

class ElaboratoreImmagine {
public:
    std::string sourceFolder;
    std::string destinationFolder;

    ElaboratoreImmagine(std::string source, std::string destination);
    void elabora();
    
    /**
     * Metodo specifico di trasformazione
     */
    virtual sf::Image trasforma(const sf::Image& input) = 0; 
};

class ImmagineResized : public ElaboratoreImmagine {
public:

ImmagineResized(std::string source, std::string destination);
    sf::Image trasforma(const sf::Image& input) override;
};

// Bianco e nero
class ImmagineBW : public ElaboratoreImmagine {
public:
    ImmagineBW(std::string source, std::string destination);
    sf::Image trasforma(const sf::Image& input) override;
};

// Zoom
class ImmagineZoomed : public ElaboratoreImmagine {
public:
    ImmagineZoomed(std::string source, std::string destination);
    sf::Image trasforma(const sf::Image& input) override;
};

#endif