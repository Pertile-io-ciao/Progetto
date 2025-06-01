#include <SFML/Graphics.hpp>
#include <vector>
#include "apprendimento.hpp"
#include "dati.hpp"
std::vector<std::vector<int>> hebb(const std::vector<std::vector<int>>& v){
    int p= v.size();
    int n= v[0].size();
    std::vector<std::vector<int>> W(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sommatoria = 0;
            for (int k = 0; k < p; ++k) {
                sommatoria += v[k][i] * v[k][j];
             }
            if (i != j) {
                W[i][j] = sommatoria;
            } else {
              W[i][j] = 0; // niente auto-connessioni
         }
    }
    }
    return W; 
};