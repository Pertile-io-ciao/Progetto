#ifndef ELABORATOREIMMAGINE_HPP
#define ELABORATOREIMMAGINE_HPP

#include <string>
#include  <SFML/Graphics.hpp>

class ElaboratoreImmagine {
protected:
    std::string sourceFolder;
    std::string destinationFolder;

public:
    ElaboratoreImmagine(std::string source, std::string destination);
    void elabora();
    
    /**
     * Metodo specifico di trasformazione
     */
    virtual sf::Image trasforma(const sf::Image& input) = 0; 
};

#endif