#include <iostream>
#include "escultor.h"
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    int i, k;
    nx = _nx;
    ny = _ny;
    nz = _nz;

    if(nx < 0 || ny < 0 || ny < 0){
        nx = ny = nz = 0;
    }

    v = (Voxel***)malloc(nx * sizeof(Voxel**));

    v[0] = (Voxel**)malloc(nx * nz * sizeof(Voxel*));

    for (k=1; k<nz; k++){
        v[k] = v[k-1] + nx;
    }

    v[0][0] = (Voxel*)malloc(nx * ny * nz * sizeof(Voxel));

    int n = 0;
    for (k=0; k<nz; k++){
        for(i=0; i<nx; i++){
            v[k][i] = v[0][0] + n*ny;
            n++;
        }
    }
}

Sculptor::~Sculptor(){
    free(v[0][0]);
    free(v[0]);
    free(v);
}

void Sculptor::setColor(float _r, float _g, float _b, float _a){
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int i, j, k;

    for(k = z0; k <= z1; k++){
        for(j = y0; j <= y1; j++){
            for(i = x0; i <= x1; i++){
                putVoxel(i, j, k);
            }
        }
    }

        cutBox(x0+1, x1-1, y0+1, y1-1, z0+1, z1-1);

}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int i, j, k;

    for(k = z0; k <= z1; k++){
        for(j = y0; j <= y1; j++){
            for(i = x0; i <= x1; i++){
                cutVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    int xi, xf, yi, yf, zi, zf;
    int i, j, k;
    double dist;
    xi = (xcenter-radius) > 0 ? xcenter-radius : 0;
    yi = (ycenter-radius) > 0 ? ycenter-radius : 0;
    zi = (zcenter-radius) > 0 ? zcenter-radius : 0;

    xf = (xcenter+radius) < nx ? xcenter+radius : nx;
    yf = (ycenter+radius) < ny ? ycenter+radius : ny;
    zf = (zcenter+radius) < nz ? zcenter+radius : nz;

    for(k=zi; k<=zf; k++){
        for(j=yi; j<=yf; j++){
            for(i=xi; i<=xf; i++){
                dist = (pow(i-xcenter, 2) + pow(j-ycenter, 2) + pow(k-zcenter, 2));
                if(dist <= pow(radius, 2)){
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int xi, xf, yi, yf, zi, zf;
    int i, j, k;
    double dist;
    xi = (xcenter-radius) > 0 ? xcenter-radius : 0;
    yi = (ycenter-radius) > 0 ? ycenter-radius : 0;
    zi = (zcenter-radius) > 0 ? zcenter-radius : 0;

    xf = (xcenter+radius) < nx ? xcenter+radius : nx;
    yf = (ycenter+radius) < ny ? ycenter+radius : ny;
    zf = (zcenter+radius) < nz ? zcenter+radius : nz;

    for(k=zi; k<=zf; k++){
        for(j=yi; j<=yf; j++){
            for(i=xi; i<=xf; i++){
                dist = pow(i-xcenter, 2) + pow(j-ycenter, 2) + pow(k-zcenter, 2);
                if(dist <= pow(radius, 2)){
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int xi, xf, yi, yf, zi, zf;
    int i, j, k;
    double dist;
    xi = (xcenter-rx) > 0 ? xcenter-rx : 0;
    yi = (ycenter-ry) > 0 ? ycenter-ry : 0;
    zi = (zcenter-rx) > 0 ? zcenter-rz : 0;

    xf = (xcenter+rx) < nz ? xcenter+rz : nz;
    yf = (ycenter+ry) < nz ? ycenter+ry : nz;
    zf = (zcenter+rz) < nz ? zcenter+rz : nz;


    if(rx == 0){
        for(k=zi; k<=zf; k++){
            for(j=yi; j<=yf; j++){
                dist = (pow(j - ycenter, 2) / pow(ry, 2)) + (pow(k - zcenter, 2) / pow(rz, 2));
                if(dist <= 1){
                    putVoxel(xcenter, j, k);
                }
            }
        }
    } else if (ry == 0){
        for(k=zi; k<=zf; k++){
            for(i=xi; i<=xf; i++){
                dist = (pow(i - xcenter, 2) / pow(rx, 2)) + (pow(k - zcenter, 2) / pow(rz, 2));
                if(dist <= 1){
                    putVoxel(i, ycenter, k);
                }
            }
        }
    } else if (rz == 0){
        for(j=yi; j<=yf; j++){
            for(i=xi; i<=xf; i++){
                dist = (pow(i - xcenter, 2) / pow(rx, 2)) + (pow(j - ycenter, 2) / pow(ry, 2));
                if(dist <= 1){
                    putVoxel(i, j, zcenter);
                }
            }
        }
    } else {
        for(k=zi; k<=zf; k++){
            for(j=yi; j<=yf; j++){
                for(i=xi; i<=xf; i++){
                    dist = (pow(i - xcenter, 2) / pow(rx, 2)) + (pow(j - ycenter, 2) / pow(ry, 2)) + (pow(k - zcenter, 2) / pow (rz, 2));
                    if(dist <= 1){
                        putVoxel(i, j, k);
                    }
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int xi, xf, yi, yf, zi, zf;
    int i, j, k;
    double dist;
    xi = (xcenter-rx) > 0 ? xcenter-rx : 0;
    yi = (ycenter-ry) > 0 ? ycenter-ry : 0;
    zi = (zcenter-rx) > 0 ? zcenter-rz : 0;

    xf = (xcenter+rx) < nz ? xcenter+rz : nz;
    yf = (ycenter+ry) < nz ? ycenter+ry : nz;
    zf = (zcenter+rz) < nz ? zcenter+rz : nz;


    if(rx == 0){
        for(j=yi; j<=yf; j++){
            for(k=zi; k<=zf; k++){
                dist = (pow(j - ycenter, 2) / pow(ry, 2)) + (pow(k - zcenter, 2) / pow(rz, 2));
                if(dist <= 1){
                    cutVoxel(xcenter, j, k);
                }
            }
        }
    } else if (ry == 0){
        for(k=zi; k<=zf; k++){
            for(i=xi; i<=xf; i++){
                dist = (pow(i - xcenter, 2) / pow(rx, 2)) + (pow(k - zcenter, 2) / pow(rz, 2));
                if(dist <= 1){
                    cutVoxel(i, ycenter, k);
                }
            }
        }
    } else if (rz == 0){
        for(j=yi; j<=yf; j++){
            for(i=xi; i<=xf; i++){
                dist = (pow(i - xcenter, 2) / pow(rx, 2)) + (pow(j - ycenter, 2) / pow(ry, 2));
                if(dist <= 1){
                    cutVoxel(i, j, zcenter);
                }
            }
        }
    } else {
        for(k=zi; k<=zf; k++){
            for(j=yi; j<=yf; j++){
                for(i=xi; i<=xf; i++){
                    dist = (pow(i - xcenter, 2) / pow(rx, 2)) + (pow(j - ycenter, 2) / pow(ry, 2)) + (pow(k - zcenter, 2) / pow (rz, 2));
                    if(dist <= 1){
                        cutVoxel(i, j, k);
                    }
                }
            }
        }
    }
}

void Sculptor::writeOFF(char *filename){
    ofstream fout;

    fixed(fout);

    int aux = 0, cont=0;
    int i, j, k;

    fout.open(filename);

    if(fout.is_open()){
        cout << "salvando arquivo tardis.off" << endl;
    }
    else{
        cout << "Arquivo tardis.off não encontrado, verifique se ele encontra-se na pasta de compilação" << endl;
        exit(1);

    }

    for(i=0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    cont++;
                }
            }
        }
    }

    fout << "OFF" << endl;
    fout << cont*8<< " " << cont*6 << " 0" << endl;

    for(i=0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    fout << i-0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    fout << i-0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    fout << i+0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    fout << i+0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    fout << i-0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                    fout << i-0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    fout << i+0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    fout << i+0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                }
            }
        }
    }

    for(i=0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    fout << "4 " << aux << " " << aux + 3 << " " << aux + 2 << " " << aux + 1 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << "4 " << aux + 4 << " " << aux + 5 << " " << aux + 6 << " " << aux + 7 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << "4 " << aux << " " << aux + 1 << " " << aux + 5 << " " << aux + 4 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << "4 " << aux << " " << aux + 4 << " " << aux + 7 << " " << aux + 3 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << "4 " << aux + 3 << " " << aux + 7 << " " << aux + 6 << " " << aux + 2 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << "4 " << aux + 1 << " " << aux + 2 << " " << aux + 6 << " " << aux + 5 << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    aux+=8;
                }
            }
        }
    }

    if(fout.is_open()){
        cout << "Arquivo tardis.off foi salvo com sucesso! Confira o arquivo na pasta de compilacao."<<endl;
    }
}
