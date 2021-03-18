#include "sculptor.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

// Construtor da classe Sculptor
Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx; ny = _ny; nz = _nz;

    // Verifica se as quantidades de linhas, colunas e planos sao positivas
    if (nx <= 0 || ny <= 0 || nz <= 0){
        nx = ny = nz = 0;
    }
//malloc(n * sizeof(int));
     v = (Voxel***)malloc(nx * sizeof(Voxel**)); //alocação dos planos

    v[0] = (Voxel**)malloc(nx * nz * sizeof(Voxel*)); //alocação das linhas

    for (int z=1; z<nz; z++){ //contagem dos planos
        v[z] = v[z-1] + nx;  //adicionando linhas nos planos
    }

    v[0][0] = (Voxel*)malloc(nx * ny * nz * sizeof(Voxel)); //alocação de cada Voxel na matriz 3D

    //adicionando colunas entre as linhas e os planos
    int n = 0;
    for (int z=0; z<nz; z++){ // contagem de planos
        for(int x=0; x<nx; x++){ //contagem de linhas
            v[z][x] = v[0][0] + n*ny; //adição de colunas
            n++;
        }
    }
}


// Destrutor da classe Sculptor
Sculptor::~Sculptor(){
    //free(vet);
    free(v[0][0]); //liberaçao dos Voxels
    free(v[0]);   //liberação das linhas
    free(v);      //liberação da escultura
}

void Sculptor::setColor(float vermelho, float verde, float azul, float alpha){
   r = vermelho; //tons de vermelho
   g = verde;   //tons de verde
   b = azul;    //tons de azul
   a = alpha;   //opacidade [0-1]
}

// Ativa o voxel na posição (x,y,z) (fazendo isOn = true) e atribui ao mesmo a cor atual de desenho
void Sculptor::putVoxel(int x, int y, int z){

    v[x][y][z].isOn = true; //habilita o Voxel da posição
    v[x][y][z].r = r;       //atribuição de tom de vermelho
    v[x][y][z].g = g;       //atribuição de tom de verde
    v[x][y][z].b = b;       //atribuição de tem de azul
    v[x][y][z].a = a;       //Opacidade do Voxel atual

}

//Desativa o voxel na posição (x,y,z) (fazendo isOn = false)
void Sculptor::cutVoxel(int x, int y, int z){
    v[z][y][x].isOn = false; //desabilita o Voxel da posição
}


// Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    for(int z=z0; z<=z1; z++){            //percorrendo planos
        for(int y=y0; y<=y1; y++){        //percorrendo colunas
            for(int x=x0; x<=x1; x++){    //percorrendo linhas

                putVoxel(x,y,z); //habilita os Voxels no intervalo

            }
        }
    }

}

// Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){

    for(int z=z0; z<=z1; z++){            //percorrendo planos
        for(int x=x0; x<=x1; x++){        //percorrendo linhas
            for(int y=y0; y<=y1; y++){    //percorrendo colunas
                cutVoxel(x,y,z); //desabilita os Voxels no intervalo
            }
        }
    }

}

//Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){

    double distancia;

    for(int z=0; z<=nz; z++){            //percorrendo planos
        for(int y=0; y<=ny; y++){        //percorrendo colunas
            for(int x=0; x<=nz; x++){    //percorrendo linhnas

                distancia = pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2) ;
                if(distancia <= pow(radius,2) ){

                    putVoxel(x, y, z);  //habilita os Voxels no intervalo
                }
            }
        }
    }
}

//Desativa todos os voxels que satisfazem à equação da esfera
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){

    double distancia;

    for(int z=0; z<=nz; z++){            //percorrendo planos
        for(int y=0; y<=ny; y++){        //percorrendo colunas
            for(int x=0; x<=nx; x++){    //percorrendo linhas

                distancia = pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2) ;
                if(distancia <= pow(radius,2) ){

                    cutVoxel(x, y, z);  //desabilita os Voxels no intervalo
                }
            }
        }
    }
}

//Ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    double distancia;

    if(rx == 0){
        for(int z=0; z<=nz; z++){
            for(int y=0; y<=ny; y++){

                distancia = pow(y - ycenter, 2)/pow(ry, 2) + pow(z - zcenter, 2)/pow(rz, 2);

                if(distancia <=1){

                    putVoxel(xcenter, y, z); //habilita os Voxels no intervalo
                }

            }
         }

    }else if(ry == 0){

        for(int z=0; z<=nz; z++){
            for(int x=0; x<=nx; x++){

                distancia = pow(x - xcenter, 2)/pow(rx, 2) + pow(z - zcenter, 2)/pow(rz, 2);

                if(distancia <=1){

                    putVoxel(x, ycenter, z); //habilita os Voxels no intervalo
                }

            }
         }

    }else if(rz == 0){

        for(int x=0; x<=nx; x++){
            for(int y=0; x<=ny; y++){

                distancia = pow(x - xcenter, 2)/pow(rx, 2) + pow(y - ycenter, 2)/pow(ry, 2);

                if(distancia <=1){

                    putVoxel(x, y, zcenter); //habilita os Voxels no intervalo
                }

            }
         }

    }else{

        for(int z=0; z<=nz; z++){
            for(int y=0; y<=ny; y++){
                for(int x=0; x<=ny; x++){

                    distancia = pow(x - xcenter, 2)/pow(rx, 2) + pow(y - ycenter, 2)/pow(rz, 2) + pow(z - zcenter, 2)/pow(rz, 2);
                    if(distancia <= 1){

                        putVoxel(x, y, z); //habilita os Voxels no intervalo

                    }
                }
            }
        }
    }

}

//Desativa todos os voxels que satisfazem à equação do elipsóide
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    double distancia;

    if(rx == 0){
        for(int z=0; z<=nz; z++){
            for(int y=0; y<=ny; y++){

                distancia = pow(y - ycenter, 2)/pow(ry, 2) + pow(z - zcenter, 2)/pow(rz, 2);

                if(distancia <=1){

                    cutVoxel(xcenter, y, z); //desabilita os Voxels no intervalo
                }

            }
         }

    }else if(ry == 0){

        for(int z=0; z<=nz; z++){
            for(int x=0; x<=nx; x++){

                distancia = pow(x - xcenter, 2)/pow(rx, 2) + pow(z - zcenter, 2)/pow(rz, 2);

                if(distancia <=1){

                    cutVoxel(x, ycenter, z); //desabilita os Voxels no intervalo
                }

            }
         }

    }else if(rz == 0){

        for(int x=0; x<=nx; x++){
            for(int y=0; x<=ny; y++){

                distancia = pow(x - xcenter, 2)/pow(rx, 2) + pow(y - ycenter, 2)/pow(ry, 2);

                if(distancia <=1){

                    cutVoxel(x, y, zcenter); //desabilita os Voxels no intervalo
                }

            }
         }

    }else{

        for(int z=0; z<=nz; z++){
            for(int x=0; x<=nx; x++){
                for(int y=0; y<=ny; y++){

                    distancia = pow(x - xcenter, 2)/pow(rx, 2) + pow(y - ycenter, 2)/pow(rz, 2) + pow(z - zcenter, 2)/pow(rz, 2);
                    if(distancia <= 1){

                        cutVoxel(x, y, z); //desabilita os Voxels no intervalo

                    }
                }
            }
        }
    }

}


void Sculptor::writeOFF(char* filename){
    ofstream fout;

    fixed(fout); // para corrigir precisão de casas decimais no arquivo .OFF

    int Nvertices=0;
    int Nfaces=0;
    int aux=0;
    fout.open(filename);

    if(fout.is_open()){
        cout << "Aguarde...Salvando o arquivo OFF.\n";
    }
    else{
        cout << "Arquivo OFF nao foi aberto\n";
        exit(1);
    }

    fout<<"OFF"<<endl;

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn){
                    Nvertices=Nvertices+8;
                    Nfaces=Nfaces+6;
                }
            }
        }
    }

    fout<<Nvertices<<" "<<Nfaces<<" "<<0<<endl;


    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn){


                        fout<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                        fout<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                        fout<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                        fout<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                        fout<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                        fout<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                        fout<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                        fout<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;

                }
            }
        }
    }

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn){
                    fout<<4<<" "<<aux+0<<" "<<aux+3<<" "<<aux+2<<" "<<aux+1<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+4<<" "<<aux+5<<" "<<aux+6<<" "<<aux+7<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+0<<" "<<aux+1<<" "<<aux+5<<" "<<aux+4<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+0<<" "<<aux+4<<" "<<aux+7<<" "<<aux+3<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+3<<" "<<aux+7<<" "<<aux+6<<" "<<aux+2<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+1<<" "<<aux+2<<" "<<aux+6<<" "<<aux+5<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    aux=aux+8;
                }
            }
        }
    }

    if(fout.is_open()){
        cout << "Arquivo.OFF salvo com sucesso!"<<endl;
    }

}
//********************************************************
    /*IMPRESSÃO DOS PLANOS
    for(int z=0; z<nz; z++){ // contagem de planos
            cout << "Plano " << z << endl;
            for(int y=0; y<ny; y++){ //contagem de colunas
                for (int x=0; x<nx; x++) { //contagem de linhas

                        cout << v[z][y][x].isOn << " "; //exibindo toda a estutura 3D

                }
                cout << endl;
            }
            cout << "*****************" << endl;
     }
     */
//*********************************************************
