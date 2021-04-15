#include "putellipsoid.h"
#include <cmath>

putEllipsoid::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;

    this->rx=rx;
    this->ry=ry;
    this->rz=rz;

    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}

void putEllipsoid::draw(Sculptor &s){
    int x0, x1, y0, y1, z0, z1;
    int i, j, k;
    x0=xcenter-rx;
    x1=xcenter+rx;
    y0=ycenter-ry;
    y1=ycenter+ry;
    z0=zcenter-rz;
    z1=zcenter+rz;

    for(i=x0; i<=x1; i++){
        for(j=y0; j<=y1; j++){
            for(k=z0; k<=z1; k++){
                if((pow(i-xcenter,2)/pow(rx,2)) + (pow(j-ycenter,2)/pow(ry,2)) + (pow(k-zcenter,2)/pow(rz,2)) <= 1){
                    s.putVoxel(i, j, k);
                }
            }
        }
    }

    s.cutEllipsoid(xcenter, ycenter, zcenter, rx-1, ry-1, rz-1);
}
