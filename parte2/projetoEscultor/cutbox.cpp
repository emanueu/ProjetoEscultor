#include "cutbox.h"

cutBox::cutBox(int x0,int x1,int y0,int y1,int z0,int z1){
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
    this->z0 = z0;
    this->z1 = z1;
}

void cutBox::draw(Sculptor &s){
    int i, j, k;

    s.setColor(r, g, b, a);

    for(i=x0; i<=x1; i++){
        for(j=y0; j<=y1; j++){
            for(k=z0; k<=z1; k++){
                s.cutVoxel(i, j, k);
            }
        }
    }
}
