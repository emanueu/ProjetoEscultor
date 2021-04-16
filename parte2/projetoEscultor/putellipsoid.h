#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "escultor.h"
#include "figurageometrica.h"


class putEllipsoid : public figuraGeometrica {
    int xcenter, ycenter,zcenter,rx,ry,rz;
public:
    putEllipsoid(int xcenter,int ycenter,int zcenter,int rx,int ry,int rz,float r,float g,float b,float a);
    ~putEllipsoid(){

    };
    void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_H
