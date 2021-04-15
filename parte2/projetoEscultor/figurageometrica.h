#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "escultor.h"

class figuraGeometrica{
protected:
    float r, g, b, a;
public:

    virtual ~figuraGeometrica(){}
    virtual void draw(Sculptor &s)=0;

    figuraGeometrica();
};

#endif // FIGURAGEOMETRICA_H
