#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "escultor.h"
#include "figurageometrica.h"


class cutSphere : public figuraGeometrica
{
    int xcenter, ycenter, zcenter, radius;
public:
    cutSphere(int xcenter, int ycenter, int zcenter, float radius);

    ~cutSphere(){

    };
    void draw(Sculptor &s);
};

#endif // CUTSPHERE_H
