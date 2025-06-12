#include "ElaboratoreImmagine.hpp"
#include <filesystem>
#include <iostream>
#include <string>
#include "dati.hpp"

// costruttore di ElaboratoreImmagine
ElaboratoreImmagine::ElaboratoreImmagine(std::string source,
                                         std::string destination) {
  this->sourceFolder = source;
  this->destinationFolder = destination;
}

//funzione che elabora tutte le immagini che sono nella cartella di origine
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
        // carico immagine
        img.loadFromFile(path.string());

        /**
         * Chiamo il metodo specifico di trasformazine
         */
        sf::Image elaborata = trasforma(img);

        // salvo risultato in destinationFolder con lo stesso nome
        std::string outPath =
            this->destinationFolder + "/" + path.filename().string();
        elaborata.saveToFile(outPath);
      }
    }
  }
}

ImmagineResized::ImmagineResized(std::string source, std::string destination)
    : ElaboratoreImmagine(source, destination) {}

sf::Image ImmagineResized::trasforma(const sf::Image& input) { 

    std::vector<sf::Color> colori = immagineVettore(input);  // vettore di sf::Color
    std::vector<int> vettore = bianconero(colori);      
    
    int width = input.getSize().x;
    int height = input.getSize().y;      // -1 / 1
    std::vector<int> v_interpolato = interpolazioneBilineare(vettore, width, height);
    sf::Image image = vettoreInImmagine(v_interpolato);
    return image;
}

/*ImmagineBN::ImmagineBN(std::string source, std::string destination)
    : ElaboratoreImmagine(source, destination) {}

sf::Image ImmagineBN::trasforma(const sf::Image& input) { 
  int inW = input.getSize().x; 
  int inH = input.getSize().y;
    std::vector<sf::Color> colori = immagineVettore(input);  // vettore di sf::Color
    std::vector<int> vettore = bianconero(colori);            // -1 / 1
    sf::Image imagebw1= vettoreInImmagine(vettore);
    return imagebw1;
}*/

ImmagineZoomed::ImmagineZoomed(std::string source, std::string destination)
    : ElaboratoreImmagine(source, destination) {}

sf::Image ImmagineZoomed::trasforma(const sf::Image& input) {  
    std::vector<sf::Color> colori = immagineVettore(input);  // vettore di sf::Color
    std::vector<int> vettore = bianconero(colori);            // -1 / 1
    std::vector<int> vettore2 = zoom(vettore, 4);            // -1 / 1
    sf::Image image= vettoreInImmagine(vettore2);
    return image;
}

/*ImmagineNoised::ImmagineNoised(std::string source, std::string destination)
    : ElaboratoreImmagine(source, destination) {}

sf::Image ImmagineNoised::trasforma(const sf::Image& input) {  
    std::vector<sf::Color> colori = immagineVettore(input);  // vettore di sf::Color
    std::vector<int> vettore = bianconero(colori);            // -1 / 1
    std::vector<int> vettore2 = zoom(vettore, 5);            // -1 / 1
    sf::Image image= vettoreInImmagine(vettore2);
    return image;
}*/


int main() {
    /*ImmagineResized interp("images/source", "images/resized");
    interp.elabora()*/
    ImmagineZoomed zoomma("images/resized", "images/zoomed");
    zoomma.elabora();
 }