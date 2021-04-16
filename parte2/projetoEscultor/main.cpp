#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "escultor.h"
#include "interpretador.h"
#include "figurageometrica.h"

using namespace std;

int main(){

    cout << "Iniciando programa para construcao do Tardis" << endl;

    Sculptor *tardis;
    Interpretador parser;

    vector<figuraGeometrica*>figs;

    figs = parser.parse("alo.txt");

    tardis = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

    for(size_t i=0;i<figs.size();i++){
        figs[i]->draw(*tardis);
    }

    tardis->writeOFF((char*) "tardis.off");
    for(size_t i=0; i<figs.size(); i++){
        delete figs[i];
    }

    delete tardis;


    /* codigo de construção anterior
     *
    tardis->setColor(0.063, 0.137, 0.447, 1.0);
    tardis->putBox(0, 40, 0, 1, 0, 40); //base da tardis
    tardis->putBox(2, 38, 1, 50, 2, 38); //corpo da tardis

    tardis->setColor(1.0, 1.0, 1.0, 1.0);
    tardis->putBox(1, 39, 51, 55, 1, 39); //sinal luminoso

    tardis->setColor(0.063, 0.137, 0.447, 1.0);
    tardis->putBox(4, 36, 55, 59 ,4, 36); //primeira tampa
    tardis->putBox(6, 34, 59, 63, 6, 34); //segunda tampa

    //suporte da luz
    tardis->putBox(18, 22, 64, 70, 18, 22);
    tardis->setColor(1.0, 1.0, 0.0, 0.03);

//tardis->putSphere(20, 67, 20, 5);
    tardis->putBox(19, 19, 64, 69, 18, 22);
    tardis->putBox(21, 21, 64, 69, 18, 22);
    tardis->putBox(18, 22, 64, 69, 19, 19);
    tardis->putBox(18, 22, 64, 69, 21, 21);


    //janelas cut
    tardis->cutBox(9, 16, 39, 49, 2, 3);
    tardis->cutBox(25, 32, 39, 49, 2, 3);
    tardis->cutBox(9, 16, 27, 37, 2, 3);
    tardis->cutBox(25, 32, 27, 37, 2, 3);
    tardis->cutBox(9, 16, 15, 25, 2, 3);
    tardis->cutBox(25, 32, 15, 25, 2, 3);
    tardis->cutBox(9, 16, 3, 13, 2, 3);
    tardis->cutBox(25, 32, 3, 13, 2, 3);

    tardis->cutBox(2, 3, 39, 49, 9, 16);
    tardis->cutBox(2, 3, 39, 49, 25, 32);
    tardis->cutBox(2, 3, 27, 37, 9, 16);
    tardis->cutBox(2, 3, 27, 37, 25, 32);
    tardis->cutBox(2, 3, 15, 25, 9, 16);
    tardis->cutBox(2, 3, 15, 25, 25, 32);
    tardis->cutBox(2, 3, 3, 13, 9, 16);
    tardis->cutBox(2, 3, 3, 13, 25, 32);

    tardis->cutBox(9, 16, 39, 49, 37, 38);
    tardis->cutBox(25, 32, 39, 49, 37, 38);
    tardis->cutBox(9, 16, 27, 37, 37, 38);
    tardis->cutBox(25, 32, 27, 37, 37, 38);
    tardis->cutBox(9, 16, 15, 25, 37, 38);
    tardis->cutBox(25, 32, 15, 25, 37, 38);
    tardis->cutBox(9, 16, 3, 13, 37, 38);
    tardis->cutBox(25, 32, 3, 13, 37, 38);

    tardis->cutBox(37, 38, 39, 49, 9, 16);
    tardis->cutBox(37, 38, 39, 49, 25, 32);
    tardis->cutBox(37, 38, 27, 37, 9, 16);
    tardis->cutBox(37, 38, 27, 37, 25, 32);
    tardis->cutBox(37, 38, 15, 25, 9, 16);
    tardis->cutBox(37, 38, 15, 25, 25, 32);
    tardis->cutBox(37, 38, 3, 13, 9, 16);
    tardis->cutBox(37, 38, 3, 13, 25, 32);

    //janela put
    tardis->setColor(0.063, 0.137, 0.447, 1.0);
    tardis->putBox(9, 16, 39, 49, 3, 3);
    tardis->putBox(25, 32, 39, 49, 3, 3);
    tardis->putBox(9, 16, 27, 37, 3, 3);
    tardis->putBox(25, 32, 27, 37, 3, 3);
    tardis->putBox(9, 16, 15, 25, 3, 3);
    tardis->putBox(25, 32, 15, 25, 3, 3);
    tardis->putBox(9, 16, 3, 13, 3, 3);
    tardis->putBox(25, 32, 3, 13, 3, 3);

    tardis->putBox(3, 3, 39, 49, 9, 16);
    tardis->putBox(3, 3, 39, 49, 25, 32);
    tardis->putBox(3, 3, 27, 37, 9, 16);
    tardis->putBox(3, 3, 27, 37, 25, 32);
    tardis->putBox(3, 3, 15, 25, 9, 16);
    tardis->putBox(3, 3, 15, 25, 25, 32);
    tardis->putBox(3, 3, 3, 13, 9, 16);
    tardis->putBox(3, 3, 3, 13, 25, 32);

    tardis->putBox(9, 16, 39, 49, 37, 37);
    tardis->putBox(25, 32, 39, 49, 37, 37);
    tardis->putBox(9, 16, 27, 37, 37, 37);
    tardis->putBox(25, 32, 27, 37, 37, 37);
    tardis->putBox(9, 16, 15, 25, 37, 37);
    tardis->putBox(25, 32, 15, 25, 37, 37);
    tardis->putBox(9, 16, 3, 13, 37, 37);
    tardis->putBox(25, 32, 3, 13, 37, 37);

    tardis->putBox(37, 37, 39, 49, 9, 16);
    tardis->putBox(37, 37, 39, 49, 25, 32);
    tardis->putBox(37, 37, 27, 37, 9, 16);
    tardis->putBox(37, 37, 27, 37, 25, 32);
    tardis->putBox(37, 37, 15, 25, 9, 16);
    tardis->putBox(37, 37, 15, 25, 25, 32);
    tardis->putBox(37, 37, 3, 13, 9, 16);
    tardis->putBox(37, 37, 3, 13, 25, 32);

    //vidros janela
    tardis->setColor(0.529, 0.808, 0.921, 1.0);
    tardis->putBox(9, 16, 39, 49, 3, 3);
    tardis->putBox(25, 32, 39, 49, 3, 3);
    tardis->putBox(3, 3, 39, 49, 9, 16);
    tardis->putBox(3, 3, 39, 49, 25, 32);
    tardis->putBox(9, 16, 39, 49, 37, 37);
    tardis->putBox(25, 32, 39, 49, 37, 37);
    tardis->putBox(37, 37, 39, 49, 9, 16);
    tardis->putBox(37, 37, 39, 49, 25, 32);

    //adesivos
    tardis->setColor(0.8, 0.8, 0.8, 1.0);
    tardis->putBox(9, 16, 27, 37, 38, 38);
    tardis->putEllipsoid(13, 32, 38, 2, 2, 0);

    //adesivo policia


    tardis->writeOFF("tardis.off");
*/
    return 0;
}
