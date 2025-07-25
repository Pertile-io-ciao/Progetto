#include "image_processor.hpp"
#include <filesystem>
#include <iostream>
#include <string>
#include "dates.hpp"

// costruttore di ElaboratoreImmagine (image_processor)
ImageProcessor::ImageProcessor(std::string source,
                                         std::string destination) {
  this->sourceFolder = source;
  this->destinationFolder = destination;
}

//funzione che elabora tutte le immagini che sono nella cartella di origine
void ImageProcessor::process() {
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
      auto path = entry.path(); //path=percorso
      std::string ext = path.extension().string();
      if (ext == ".png") {
        sf::Image img;
        // carico immagine
        img.loadFromFile(path.string());

        /**
         * Chiamo il metodo specifico di trasformazine
         */
        sf::Image elaborated = trasform(img);

        // salvo risultato in destinationFolder con lo stesso nome
        std::string outPath = //outpath=percorso per l'output
            this->destinationFolder + "/" + path.filename().string();
        elaborated.saveToFile(outPath);
      }
    }
  }
}

ImmagineResized::ImmagineResized(std::string source, std::string destination)
    : ImageProcessor(source, destination) {}

sf::Image ImmagineResized::trasform(const sf::Image& input) { 

    std::vector<sf::Color> colors = vector_from_image(input);  // vettore di sf::Color
    std::vector<int> vector1 = blacknwhite(colors);      
    
    int width = input.getSize().x;
    int height = input.getSize().y;      // -1 / 1
    std::vector<int> v_interpolated = bilinear_interpolation(vector1, width, height);
    sf::Image image = image_from_vector(v_interpolated);
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
    : ImageProcessor(source, destination) {}

sf::Image ImmagineZoomed::trasform(const sf::Image& input) {  
    std::vector<sf::Color> colori = vector_from_image(input);  // vettore di sf::Color
    std::vector<int> vector1 = blacknwhite(colori);            // -1 / 1
    std::vector<int> vector2 = zoom(vector1, 4);            // -1 / 1
    sf::Image image= image_from_vector(vector2);
    return image;
}

/*ImmagineNoised::ImmagineNoised(std::string source, std::string destination)
    : ElaboratoreImmagine(source, destination) {}

sf::Image ImmagineNoised::trasforma(const sf::Image& input) {  
    std::vector<sf::Color> colori = immagineVettore(input);  // vettore di sf::Color
    std::vector<int> vettore = bianconero(colori);            // -1 / 1
    std::vector<int> vettore2 = zoom(vettore, 5);            // -1 / 1
    sf::Image image= vetimage processortoreInImmagine(vettore2);
    return image;
}*/


int main() {
    /*ImmagineResized interp("images/source", "images/resized");
    interp.elabora()*/
    ImmagineZoomed zoomma("images/resized", "images/zoomed");
    zoomma.process();
 }