#include "canvas.h"
#include <iostream>
#include <fstream>

void ASCIICanvas::wyswietl(){  //wyswietl obrazek
    for(int i = 0; i < liczba_linii; i++){
        for(int j = 0; j < liczba_znakow_w_linii; j++){
            std::cout << obrazek[i * liczba_znakow_w_linii + j]; 
        }
        std::cout << std::endl;
    }
}

void ASCIICanvas::zapisz(){   //zapisz obraz do pliku
    std::ofstream plik(output_file);
    if(!plik){
        std::cout<<"Blad podczas otwierania pliku: "<<output_file<<"\n";
        return;
    }
    for(int i=0; i<liczba_linii; i++){
        for(int j=0; j<liczba_znakow_w_linii; j++){
            plik<<obrazek[i*liczba_znakow_w_linii+j];
        }
        plik<<std::endl;
    }
    plik.close();
}

void ASCIICanvas::wypelnij(int x, int y, char s){
    if(x>=0 && x<liczba_znakow_w_linii && y>=0 && y<liczba_linii){
        obrazek[liczba_znakow_w_linii*(liczba_linii-y-1)+x] = s; //wypelnij pole symbolem
    }
}

void Kolo::rysuj(Canvas &c){   //rysowanie kola
   for(int y = wy - promien; y <= wy + promien; y++){
        for(int x = wx - promien; x <= wx + promien; x++){
            if((x-wx)*(x-wx)+(y-wy)*(y-wy)<=promien*promien){
                c.wypelnij(x, y, symbol);
            }
        }
    }
}

void Prostokat::rysuj(Canvas &o){   //rysowanie prostokata
    for(int i=0; i<bok_a; i++){
        for(int j=0; j<bok_b; j++){
            int x=wx+i;
            int y=wy+j;
            o.wypelnij(x,y,symbol);
        }
    }
}

void Trojkat:: rysuj(Canvas &o){   //rysowanie trojkata
    for(int i=0; i<=ramie; i++){
        for(int j=0; j<i; ++j){
            int x=wx+j;
            int y=wy+i-ramie;
            o.wypelnij(x,y,symbol);
        }
    }
}
