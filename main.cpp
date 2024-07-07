/*////////////////////////////////////////////////////////////////////
Gabriela Oracz, GRUPA 7, ZESTAW 5                            07.07.24
///////////////////////////////////////////////////////////////////*/

#include "canvas.h"
#include <iostream>
#include <string>
#include <memory>

int main(int argc, char *argv[]) {
    if(argc!=2){
        std::cout<<"Podaj nazwe pliku konfiguracyjnego jako parametr programu\n";
        return 1;
    }

    int szer, wys;
    char  bgSymbol;
    std::string outputFile;
    std::vector<std::unique_ptr<Figura>> figury;

    analiza_pliku(argv[1], szer, wys, bgSymbol, outputFile, figury);

    ASCIICanvas c1(szer, wys, bgSymbol, outputFile);

    for (auto& figura : figury) {
        figura->rysuj(c1);
    }

    std::cout<<"\nTwoj obrazek: "<<std::endl;
    c1.wyswietl();
    c1.zapisz();
        
    return 0;
}
