#include "dati.hpp"
#include <cmath>

int bianconero (pixel p){
    double norma= std::sqrt(p.r * p.r + p.g * p.g + p.b *p.b );
    if (norma<127){
        return -1;
    }
    return 1;
}
