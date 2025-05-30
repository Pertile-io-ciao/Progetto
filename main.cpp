#include <iostream>
#include "dati.hpp"
#include "grafica.hpp"
#include "apprendimento.hpp"
#include "richiamo.hpp"
#include <SFML/Graphics.hpp>
#include <vector>


int main() {
    //metto la prima immagine
    sf::Image image;
    if (!image.loadFromFile("image1.png")) {
        std::cerr << "Errore nel caricamento dell'immagine.\n";
        return -1;
    }

    int width = image.getSize().x;
    int height = image.getSize().y;

    std::vector<sf::Color> colori = immagineVettore(image);  // vettore di sf::Color
    std::vector<int> vettore = bianconero(colori);            // -1 / 1

    // Applica interpolazione per ottenere vettore di dimensione l x l
    std::vector<int> v_interpolato = interpolazioneBilineare(vettore, width, height);

    std::vector<int> zoomato= zoom ( v_interpolato); 

    sf::Image imagebw= vettoreInImmagine(zoomato);

    // Crea le texture da disegnare
    sf::Texture texture, texturebw;
    texture.loadFromImage(image); // originale
    if (!texturebw.loadFromImage(imagebw)) {
        std::cerr << "Errore nel caricamento della texture bianco/nero.\n";
        return -1;
    }
    //seconda immagine
    sf::Image image1;
    if (!image1.loadFromFile("imageT.png")) {
        std::cerr << "Errore nel caricamento dell'immagine.\n";
        return -1;
    }

    int width1 = image1.getSize().x;
    int height1 = image1.getSize().y;

    std::vector<sf::Color> colori1 = immagineVettore(image1);  // vettore di sf::Color
    std::vector<int> vettore1 = bianconero(colori1);            // -1 / 1

    // Applica interpolazione per ottenere vettore di dimensione l x l
    std::vector<int> v_interpolato1 = interpolazioneBilineare(vettore1, width1, height1);

    std::vector<int> zoomato1= zoom ( v_interpolato1); 
    sf::Image imagebw1= vettoreInImmagine(zoomato1);

    // Crea le texture da disegnare
    sf::Texture texture1, texturebw1;
    texture1.loadFromImage(image1); // originale
    if (!texturebw1.loadFromImage(imagebw1)) {
        std::cerr << "Errore nel caricamento della texture bianco/nero.\n";
        return -1;
    }
    // terza immagine
sf::Image image2;
    if (!image2.loadFromFile("imageE.png")) {
        std::cerr << "Errore nel caricamento dell'immagine.\n";
        return -1;
    }

    int width2 = image2.getSize().x;
    int height2 = image2.getSize().y;

    std::vector<sf::Color> colori2 = immagineVettore(image2);  // vettore di sf::Color
    std::vector<int> vettore2 = bianconero(colori2);            // -1 / 1

    // Applica interpolazione per ottenere vettore di dimensione l x l
    std::vector<int> v_interpolato2 = interpolazioneBilineare(vettore2, width2, height2);

    std::vector<int> zoomato2= zoom ( v_interpolato2); 

    sf::Image imagebw2= vettoreInImmagine(zoomato2);

    // Crea le texture da disegnare
    sf::Texture texture2, texturebw2;
    texture2.loadFromImage(image2); // originale
    if (!texturebw2.loadFromImage(imagebw2)) {
        std::cerr << "Errore nel caricamento della texture bianco/nero.\n";
        return -1;
    }
 // quarta immagine
sf::Image image3;
    if (!image3.loadFromFile("imageF.png")) {
        std::cerr << "Errore nel caricamento dell'immagine.\n";
        return -1;
    }

    int width3 = image3.getSize().x;
    int height3 = image3.getSize().y;

    std::vector<sf::Color> colori3 = immagineVettore(image3);  // vettore di sf::Color
    std::vector<int> vettore3 = bianconero(colori3);            // -1 / 1

    // Applica interpolazione per ottenere vettore di dimensione l x l
    std::vector<int> v_interpolato3 = interpolazioneBilineare(vettore3, width3, height3);

    std::vector<int> zoomato3= zoom ( v_interpolato3); 

    sf::Image imagebw3= vettoreInImmagine(zoomato3);

    // Crea le texture da disegnare
    sf::Texture texture3, texturebw3;
    texture3.loadFromImage(image3); // originale
    if (!texturebw3.loadFromImage(imagebw3)) {
        std::cerr << "Errore nel caricamento della texture bianco/nero.\n";
        return -1;
    }


    //creo il vettore con i vari vettori interpolati (una sorta di memoria)
    //std::vector<std::vector<int>> memoria= {v_interpolato, v_interpolato1,v_interpolato2};
    //std::vector<std::vector<int>> matricePesi = hebb(memoria);

    std::vector<int> distorta = tagliaorizzontale(v_interpolato2, 64, 47, 61);
    std::vector<int> distorta2 = rumore(distorta, 0.2);
    std::vector<int> zoomdistorta= zoom(distorta2);
    sf::Image immdistorta= vettoreInImmagine(zoomdistorta);
    sf::Texture texdistorta;
    texdistorta.loadFromImage(immdistorta);
    // Mostra entrambe le texture in sequenza
    disegna(texturebw, texturebw1, texturebw2, texturebw3, texdistorta); // Assicurati che questa funzione esista
}
