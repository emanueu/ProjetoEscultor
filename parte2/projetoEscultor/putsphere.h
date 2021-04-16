#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "escultor.h"
#include "figurageometrica.h"

class putSphere : public figuraGeometrica {
    int xcenter, ycenter, zcenter, radius;
public:
    putSphere(int xcenter,int ycenter,int zcenter,int radius,float r, float g, float b, float a);
    ~putSphere(){

    };
    void draw(Sculptor &s);
};

#endif // PUTSPHERE_H
