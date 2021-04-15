#ifndef ESCULTOR_H
#define ESCULTOR_H

#include <iostream>
#include <string>

struct Voxel{
    float r, g, b; //valores de cor de vermelho, verde e azul, respectivamente, variando de 0 a 1
    float a; //valor de opacidade, varia de 0 a 1
    bool isOn; //booleano para saber se o voxel estará ativo ou não
};

class Sculptor
{
protected:
    Voxel ***v;
    int nx, ny, nz;
    float r, g, b, a;

public:
    Sculptor(int _nx, int _ny, int _nz); //construtor de Voxel
    ~Sculptor(); //destrutor de Voxel
    void setColor(float _r, float _g, float _b, float _a); //mudar a cor que será aplicada ao voxel
    void putVoxel(int x, int y, int z); //coloca um voxel (isOn = true)
    void cutVoxel(int x, int y, int z); //retira um voxel (isOn = false)
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1); //coloca uma raixa de voxels
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); //retira uma caixa de voxels
    void putSphere(int xcenter, int ycenter, int zcenter, int radius); //coloca uma esfera de voxels
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius); //retira uma esfera de voxels
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); //coloca uma elipse
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); //retura uma elipse
    void writeOFF(char* filename); //salva o arquivo
};

#endif // ESCULTOR_H
