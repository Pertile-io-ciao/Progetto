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

sf::Image ImmagineResized::trasforma(const sf::Image& input) { int inW = input.getSize().x;
    int inH = input.getSize().y;
    int outL = 128; // Ad esempio, nuovo lato di 128 pixel

    // Usando la funzione di interpolazione bilineare
    std::vector<int> result = interpolazioneBilineare(vettore1(immagineVettore(input, inH, inW)), inW, inH, outL);

    sf::Image outputImage;
    outputImage.create(outL, outL);

    // Ricostruzione dell'immagine da output (qui potresti volere migliorare la conversione)
    for (int y = 0; y < outL; ++y) {
        for (int x = 0; x < outL; ++x) {
            outputImage.setPixel(x, y, result[y * outL + x] == 1 ? sf::Color::White : sf::Color::Black);
        }
    }

    return outputImage; }

ImmagineBW::ImmagineBW(std::string source, std::string destination)
    : ElaboratoreImmagine(source, destination) {}

sf::Image ImmagineBW::trasforma(const sf::Image& input) { int inW = input.getSize().x;
    int inH = input.getSize().y;

    // Creazione di un vettore dei pixel in bianco e nero
    std::vector<int> result = vettore1(immagineVettore(input, inH, inW));

    sf::Image outputImage;
    outputImage.create(inW, inH);

    // Ricostruzione dell'immagine da output (bianco e nero)
    for (int y = 0; y < inH; ++y) {
        for (int x = 0; x < inW; ++x) {
            outputImage.setPixel(x, y, result[y * inW + x] == 1 ? sf::Color::White : sf::Color::Black);
        }
    }

    return outputImage; }

ImmagineZoomed::ImmagineZoomed(std::string source, std::string destination)
    : ElaboratoreImmagine(source, destination) {}

sf::Image ImmagineZoomed::trasforma(const sf::Image& input) {  int inW = input.getSize().x;
    int inH = input.getSize().y;

    // Fattore di zoom (ad esempio 4x)
    int zoomFactor = 4;
    int outW = inW * zoomFactor;
    int outH = inH * zoomFactor;

    sf::Image outputImage;
    outputImage.create(outW, outH);

    // Ridimensionamento dei pixel (copiamo i pixel e li ingrandiamo)
    for (int y = 0; y < inH; ++y) {
        for (int x = 0; x < inW; ++x) {
            sf::Color pixelColor = input.getPixel(x, y);
            for (int dy = 0; dy < zoomFactor; ++dy) {
                for (int dx = 0; dx < zoomFactor; ++dx) {
                    outputImage.setPixel(x * zoomFactor + dx, y * zoomFactor + dy, pixelColor);
                }
            }
        }
    }

    return outputImage; }

int main() { return 0; }