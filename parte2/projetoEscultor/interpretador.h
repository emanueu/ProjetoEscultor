#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include "figurageometrica.h"
#include "escultor.h"
#include <string>


class Interpretador{
    int dimx, dimy, dimz;
    float r, g, b, a;
public:
    Interpretador();

    std::vector<figuraGeometrica*> parse(std::string filename);

    int getDimx();
    int getDimy();
    int getDimz();

};

#endif // INTERPRETADOR_H
