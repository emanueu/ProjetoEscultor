#include <iostream>
#include <fstream>
#include <sstream>
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "figurageometrica.h"
#include "interpretador.h"


Interpretador::Interpretador(){

}

std::vector<figuraGeometrica*> Interpretador::parse(std::string filename){
    std::vector<figuraGeometrica*> figs;
    std::ifstream fin;
    std::stringstream ss;
    std::string s, token;

    fin.open(filename.c_str());
    if(!fin.is_open()){
        std::cout << "erro ao abrir arquivo" << std::endl;
        exit(0);
    }

    while(fin.good()){
        std::getline(fin,s);
        ss.clear();
        ss.str(s);
        ss >> token;
        if(token.compare("dim")==0){
            ss >> dimx >> dimy >> dimz;

        }
        else if(token.compare("putvoxel")==0){
            int x,y,z;
            ss >> x >> y >> z >> r >> g >> b >> a;
            figs.push_back(new putVoxel(x,y,z,r,g,b,a));
        }
        else if(token.compare("cutvoxel")==0){
            int x,y,z;
            ss >> x >> y >> z;
            figs.push_back(new cutVoxel(x,y,z));
        }
        else if(token.compare("putbox")==0){
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figs.push_back(new putBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
        }
        else if(token.compare("cutbox")==0){
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figs.push_back(new cutBox(x0,x1,y0,y1,z0,z1));
        }
        else if(token.compare("putsphere")==0){
            int xcenter, ycenter, zcenter, radius;
            ss  >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            figs.push_back(new putSphere(xcenter,ycenter,zcenter,radius,r,g,b,a));
        }
        else if(token.compare("cutsphere")==0){
            int xcenter, ycenter, zcenter, radius;
            ss  >> xcenter >> ycenter >> zcenter >> radius;
            figs.push_back(new cutSphere(xcenter,ycenter,zcenter,radius));
        }
        else if(token.compare("putellipsoid")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            figs.push_back(new putEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz,r,g,b,a));
        }
        else if(token.compare("cutellipsoid")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            figs.push_back(new cutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz));
        }
    }
    return(figs);
}

int Interpretador::getDimx(){
    return dimx;
}

int Interpretador::getDimy(){
    return dimy;
}

int Interpretador::getDimz(){
    return dimz;
}


