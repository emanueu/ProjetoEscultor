#include <iostream>

using namespace std;

int main(){

    float r,g,b;
    float novoR, novoG, novoB;

    cin>>r>>g>>b;

    novoR = r/255;

    novoG = g/255;

    novoB = b/255;

    cout << "Cores para esculpir: " << novoR << " " << novoG << " "<< novoB << endl;
    return 0;
}
