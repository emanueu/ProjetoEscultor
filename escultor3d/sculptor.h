#ifndef SCULPTOR_H
#define SCULPTOR_H

#include<iostream>
#include<string>

/**
 * @brief The Voxel struct:
     * Voxels (volume elements), equivalente aos pixels das imagens digitais, porém em 3 dimensões.
     * Nos Voxels é possível armazenar informações como cor e transparência da cor, necessárias para idealizar os elementos de uma escultura.
     * @param r : intensidade da cor vermelha, varia entre [0 - 255]
     * @param g : intensidade da cor vermelha, varia entre [0 - 255]
     * @param b : intensidade da cor vermelha, varia entre [0 - 255]
     * @param a : opacidade do voxel, varia entre [0 - 1]
     * @param isOn : define se o voxel esta ativo ou nao, assume como valores 0 (desativado) ou 1 (ativado)
 */
struct Voxel{
    float r,g,b; // Cores com tons de Vermelho, verde e azul
    float a; // Canal alpha
    bool isOn; // Voxel incluso ou nao
};

/**
 * @brief A classe Sculptor
 * monta uma estrutura e fornece os metodos para manipular os pixels de uma matriz tridimensional
 */
class Sculptor
{

protected:
    /**
     * @brief v: matriz 3D alocada dinamicamente que armazena todos os voxels
     */
    Voxel ***v;
     /**
     * @brief nx: dimensao em x (numero de linhas)
     */
    int nx;
    /**
     * @brief ny: dimensao em y (numero de colunas)
     */
    int ny;
    /**
     * @brief nz: dimensao em z (numero de planos)
     */
    int nz;
    /**
     * @brief r: intensidade atual da cor vermelha, varia entre [0 - 255]
     */
    float r;
    /**
     * @brief g: intensidade atual da cor verde, varia entre [0 - 255]
     */
    float g;
    /**
     * @brief b: intensidade atual da cor azul, varia entre [0 - 255]
     */
    float b;
    /**
     * @brief a: intensidade atual da opacidade, varia entre [0 - 1]
     */
    float a;
public:

    /**
     * @brief Sculptor: Construtor da classe Sculptor
     * @param _nx : dimensao em x da escultura 3D (número de linhas)
     * @param _ny : dimensao em y da escultura 3D (númer de colunas)
     * @param _nz : dimensao em z da escultura 3D (número de planos)
     */
    Sculptor(int _nx, int _ny, int _nz);

    /**
      * @brief ~Sculptor: Destrutor da classe Sculptor
    */
    ~Sculptor();

    /**
     * @brief setColor : Define a cor atual do desenho
     * @param r : intensidade da cor vermelha, varia entre [0,1]
     * @param g : intensidade da cor verde, varia entre [0,1]
     * @param b : intensidade da cor azul, varia entre [0,1]
     * @param alpha : opacidade do voxel, varia entre [0,1]
     */
    void setColor(float r, float g, float b, float alpha);

    /**
     * @brief putVoxel : Ativa o voxel na posição (x,y,z) (fazendo isOn = true) e atribui ao mesmo a cor atual de desenho
     * @param x : coordenada em relacao ao eixo x
     * @param y : coordenada em relacao ao eixo y
     * @param z : coordenada em relacao ao eixo z
     */
    void putVoxel(int x, int y, int z);

    /**
     * @brief cutVoxel : Desativa o voxel na posição (x,y,z) (fazendo isOn = false)
     * @param x : coordenada em relacao ao eixo x
     * @param y : coordenada em relacao ao eixo y
     * @param z : coordenada em relacao ao eixo z
     */
    void cutVoxel(int x, int y, int z);

    /**
     * @brief putBox : Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho
     * @param x0 : coordenada do ponto inicial no eixo x
     * @param x1 : coordenada do ponto final no eixo x
     * @param y0 : coordenada do ponto inicial no eixo y
     * @param y1 : coordenada do ponto final no eixo y
     * @param z0 : coordenada do ponto inicial no eixo z
     * @param z1 : coordenada do ponto final no eixo z
     */
    void putBox(int x0, int x1,int y0, int y1,int z0, int z1);

    /**
     * @brief cutBox : Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho
     * @param x0 : coordenada do ponto inicial no eixo x
     * @param x1 : coordenada do ponto final no eixo x
     * @param y0 : coordenada do ponto inicial no eixo y
     * @param y1 : coordenada do ponto final no eixo y
     * @param z0 : coordenada do ponto inicial no eixo z
     * @param z1 : coordenada do ponto final no eixo z
     */
    void cutBox(int x0, int x1,int y0, int y1,int z0, int z1);

    /**
     * @brief putSphere : Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho
     * @param xcenter : coordenada x do centro da esfera
     * @param ycenter : coordenada y do centro da esfera
     * @param zcenter : coordenada z do centro da esfera
     * @param radius : raio da esfera
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);

    /**
     * @brief cutSphere : Desativa todos os voxels que satisfazem a equação da esfera
     * @param xcenter : coordenada x do centro da esfera
     * @param ycenter : coordenada y do centro da esfera
     * @param zcenter : coordenada z do centro da esfera
     * @param radius : raio da esfera
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    /**
     * @brief putEllipsoid : Ativa todos os voxels que satisfazem a equação do elipsoide e atribui aos mesmos a cor atual de desenho
     * @param xcenter : coordenada x do centro do elipsoide
     * @param ycenter : coordenada y do centro do elipsoide
     * @param zcenter : coordenada z do centro do elipsoide
     * @param rx : raio na direcao x
     * @param ry : raio na direcao y
     * @param rz : raio na direcao z
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /**
     * @brief cutEllipsoid : Desativa todos os voxels que satisfazem a equação do elipsoide
     * @param xcenter : coordenada x do centro do elipsoide
     * @param ycenter : coordenada y do centro do elipsoide
     * @param zcenter : coordenada z do centro do elipsoide
     * @param rx : raio na direcao x
     * @param ry : raio na direcao y
     * @param rz : raio na direcao z
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /**
     * @brief writeOFF : grava a escultura no formato OFF no arquivo filename
     * @param filename : caminho do arquivo .off
     */
    void writeOFF(char* filename);

};

#endif // SCULPTOR_H
