#include <iostream>
#include <string>
#include <filesystem>
#include "ElaboratoreImmagine.hpp"


ElaboratoreImmagine::ElaboratoreImmagine(std::string source, std::string destination) {
    this->sourceFolder = source;
    this->destinationFolder = destination;
}

void ElaboratoreImmagine::elabora() {
    
    
    if (!std::filesystem::exists(this->destinationFolder)) {
        std::filesystem::create_directories(this->destinationFolder);
    }

    /**
     * Itero su tutti i file png della cartella sorgente
     */
    for (const auto& entry : std::filesystem::directory_iterator(this->sourceFolder)) {
        /**
         * Verifico che sia un file 
         * e che sia png
         */
        if (entry.is_regular_file()) {
            auto path = entry.path();
            std::string ext = path.extension().string();
            if (ext == ".png") {
                sf::Image img;
                //carico immagine
                img.loadFromFile(path.string());

                /**
                 * Chiamo il metodo specifico di trasformazine
                 */
                sf::Image elaborata = trasforma(img);

                //salvo risultato in destinationFolder con lo stesso nome
                std::string outPath = this->destinationFolder + "/" + path.filename().string();
                elaborata.saveToFile(outPath);
            }
        }
    }
}

ImmagineResized::ImmagineResized(std::string source, std::string destination)
    : ElaboratoreImmagine(source, destination) {}

sf::Image ImmagineResized::trasforma(const sf::Image& input) {
    return input;
}

ImmagineBW::ImmagineBW(std::string source, std::string destination)
    : ElaboratoreImmagine(source, destination) {}

sf::Image ImmagineBW::trasforma(const sf::Image& input) {
    return input;
}

ImmagineZoomed::ImmagineZoomed(std::string source, std::string destination)
    : ElaboratoreImmagine(source, destination) {}

sf::Image ImmagineZoomed::trasforma(const sf::Image& input) {
    return input;
}

 
int main() {
    return 0;
}