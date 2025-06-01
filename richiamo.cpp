#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>  // per time()

std::vector<int> rumore(std::vector<int> v, float probabilita = 0.1f) {
    std::vector<int> risultato = v;

    std::srand(static_cast<unsigned>(std::time(0)));

    for (size_t i = 0; i < risultato.size(); ++i) {
        float casuale = static_cast<float>(std::rand()) / RAND_MAX;
        if (casuale < probabilita) {
            if (risultato[i]==1){
                risultato[i]=-1;
            }else {
                risultato[i]=1;
            }
        }
    }

    return risultato;
}
std::vector <int> tagliaverticale (std::vector<int> v, int l, int inizio, int fine){
    for (int i=0; i < l; ++i) {
        for (int j=0; j <l; ++j) {
            if (j>=inizio && j<=fine) {
                v[i*l+j]=1;
            }
        }
    }
    return v;
}  // si potrebbe implementare dando errore quando inizio e fine non siano della grandezza adeguata

std::vector<int> tagliaorizzontale(std::vector<int> v, int l, int inizio,  int fine){
    for (int i=0; i< l; ++i){
        for (int j =0; j<l; ++j){
        if (i>=inizio && i<=fine) {
            v[i*l+j]=1;
        }
    }
    }
    return v;
}
   