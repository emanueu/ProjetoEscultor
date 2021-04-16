#include "cutellipsoid.h"
#include <cmath>

cutEllipsoid::cutEllipsoid(int xcenter,int ycenter,int zcenter,int rx,int ry,int rz){
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;

    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}

void cutEllipsoid::draw(Sculptor &s){
    int x0,x1,y0,y1,z0,z1;
    int i, j, k;
    x0 = xcenter - rx;
    x1 = xcenter + rx;
    y0 = ycenter - ry;
    y1 = ycenter + ry;
    z0 = zcenter - rz;
    z1 = zcenter + rz;


    for(i=x0; i<=x1; i++){
        for(j=y0; j<=y1; j++){
            for(k=z0; k<=z1; k++){
                if((pow(i-xcenter,2)/pow(rx,2)) + (pow(j-ycenter,2)/pow(ry,2)) + (pow(k-zcenter,2)/pow(rz,2)) <= 1){
                    s.cutVoxel(i, j, k);
                }
            }
        }
    }
}
