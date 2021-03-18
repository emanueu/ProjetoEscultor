#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "sculptor.h"

using namespace std;

int main(){

            Sculptor *tardis;
            int x=120, y=120, z=120;

            tardis = new Sculptor(x,y,z);

            tardis->setColor(0.063, 0.137, 0.447, 1.0);
            tardis->putBox(0, 40, 0, 1, 0, 40); //base da tardis
            tardis->putBox(2, 38, 1, 50, 2, 38); //corpo da tardis

            tardis->setColor(1.0, 1.0, 1.0, 1.0);
            tardis->putBox(1, 39, 51, 55, 1, 39); //sinal luminoso

            tardis->setColor(0.063, 0.137, 0.447, 1.0);
            tardis->putBox(4, 36, 55, 59 ,4, 36); //primeira tampa
            tardis->putBox(6, 34, 59, 63, 6, 34); //segunda tampa
            tardis->putBox(18, 22, 64, 70, 18, 22); //suporte da luz

            tardis->setColor(1.0, 1.0, 0.0, 0.03);
            tardis->putSphere(20, 67, 20, 5); //luz

            //janelas
            tardis->cutBox(9, 15, 42, 48, 2, 3);
            tardis->cutBox(25, 31, 42, 48, 2, 3);
            tardis->cutBox(9, 15, 33, 39, 2, 3);
            tardis->cutBox(25, 31, 33, 39, 2, 3);
            tardis->cutBox(9, 15, 24, 30, 2, 3);
            tardis->cutBox(25, 31, 24, 30, 2, 3);
            tardis->cutBox(9, 15, 15, 21, 2, 3);
            tardis->cutBox(25, 31, 15, 21, 2, 3);

            tardis->cutBox(2, 3, 42, 48,9, 15);
            tardis->cutBox(2, 3, 42, 48, 25, 31);
            tardis->cutBox(2, 3, 33, 39, 9, 15);
            tardis->cutBox(2, 3, 33, 39, 25, 31);
            tardis->cutBox(2, 3, 24, 30, 9, 15);
            tardis->cutBox(2, 3, 24, 30, 25, 31);
            tardis->cutBox(2, 3, 15, 21, 9, 15);
            tardis->cutBox(2, 3, 15, 21, 25, 31);

            tardis->cutBox(9, 15, 42, 48, 37, 38);
            tardis->cutBox(25, 31, 42, 48, 37, 38);
            tardis->cutBox(9, 15, 33, 39, 37, 38);
            tardis->cutBox(25, 31, 33, 39, 37, 38);
            tardis->cutBox(9, 15, 24, 30, 37, 38);
            tardis->cutBox(25, 31, 24, 30, 37, 38);
            tardis->cutBox(9, 15, 15, 21, 37, 38);
            tardis->cutBox(25, 31, 15, 21, 37, 38);

            tardis->cutBox(37, 38, 42, 48,9, 15);
            tardis->cutBox(37, 38, 42, 48, 25, 31);
            tardis->cutBox(37, 38, 33, 39, 9, 15);
            tardis->cutBox(37, 38, 33, 39, 25, 31);
            tardis->cutBox(37, 38, 24, 30, 9, 15);
            tardis->cutBox(37, 38, 24, 30, 25, 31);
            tardis->cutBox(37, 38, 15, 21, 9, 15);
            tardis->cutBox(37, 38, 15, 21, 25, 31);




/*           v3->setColor(1.0, 1.0, 1.0, 1.0);  //branco da mesa
             v3->putBox(0,90,0,50,0,0);     //parte vertical da mesa

             v3->setColor(0,0,0,0.5);        //preto da carcaça da tela
             v3->putBox(20,70,1,40,1,2);     //carcaça da tela
             v3->setColor(0,0,0.1,0.5);       //azul da tela
             v3->putBox(25,65,5,35,1,2);     //tela
             v3->setColor(0,0,0,0.5);        //preto da carcaça do teclado
             v3->putBox(20,70,1,2,1,40);     //carcaça do teclado

             //mousepad
             v3->setColor(1.0, 1.0, 1.0, 1.0);    // cinza do mousepad
             v3->putBox(37,53,1,2,30,35);     // mousepad
             v3->putBox(37,44,1,2,37,38);     // mousepad
             v3->putBox(46,53,1,2,37,38);     // mousepad


             v3->setColor(1.0, 1.0, 1.0, 1.0); //branco das teclas
            //teclas de cima
             v3->putBox(26,28,2,2,4,6);
             v3->putBox(30,32,2,2,4,6);
             v3->putBox(34,36,2,2,4,6);
             v3->putBox(38,40,2,2,4,6);
             v3->putBox(42,44,2,2,4,6);
             v3->putBox(46,48,2,2,4,6);
             v3->putBox(50,52,2,2,4,6);
             v3->putBox(54,56,2,2,4,6);
             v3->putBox(58,60,2,2,4,6);
             v3->putBox(62,64,2,2,4,6);

             //teclas de baixo
             int a1 = 28;
             for(int i=0; i<=7;i++){
                 v3->putBox(a1+2,a1+4,2,2,12,13);
                 v3->putBox(a1+2,a1+4,2,2,15,16);
                 v3->putBox(a1+2,a1+4,2,2,18,19);
                 v3->putBox(a1+2,a1+4,2,2,21,22);
                 v3->putBox(a1+2,a1+4,2,2,24,25);
                 v3->putBox(a1+2,a1+4,2,2,27,28);
                 a1+=4;
             }

             //tecla de espaço
             v3->putBox(38,50,2,2,27,28);


             //mouse
             v3->setColor(0.1,0.2,0.3,0.8);        // cor do mouse
             v3->putEllipsoid(80,-2,40,3,1,5);  // dimensões do elipsóide (x, y, z, rx, ry, rz)


             //abajur
             v3->setColor(1.0,1.0,0.0,0.8);        // amarelo do abajur
             v3->putSphere(8,25,10,9);           // abajur
             v3->setColor(1.0,0.0,0.0,0.8);       // vermelho do abajur
             v3->putBox(8,10,1,25,8,12);       //suporte abajur
             v3->setColor(0.8,0.8,0.8,0.8);   // cinza da base do abajur
             v3->putEllipsoid(9,1,10,6,3,3); //base do abajur

             //mesa
              v3->setColor(1.0, 1.0, 1.0, 1.0);  // branco da mesa
              v3->putBox(0,90,0,0,0,50);     // parte horizontal da mesa
*/

            tardis->writeOFF("tardis.off");
    return 0;
}
