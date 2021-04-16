#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "escultor.h"
#include "figurageometrica.h"

class cutEllipsoid : public figuraGeometrica {
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~cutEllipsoid(){

    };
    void draw(Sculptor &s);
};

#endif // CUTELLIPSOID_H
