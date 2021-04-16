#include "cutsphere.h"
#include <cmath>

cutSphere::cutSphere(int xcenter, int ycenter, int zcenter, float radius){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
}

void cutSphere::draw(Sculptor &s){
    int x0, x1, y0, y1, z0, z1;
    int i, j, k;
    x0 = xcenter - radius;
    x1 = xcenter + radius;
    y0 = ycenter - radius;
    y1 = ycenter + radius;
    z0 = zcenter - radius;
    z1 = zcenter + radius;

    for(i=x0; i<=x1; i++){
        for(j=y0; j<=y1; j++){
            for(k=z0; k<=z1; k++){
                if(((pow(i-xcenter,2)) + (pow(j-ycenter,2)) + (pow(k-zcenter,2))) <= pow(radius,2)){
                    s.cutVoxel(i, j, k);
                }
            }
        }
    }
}
