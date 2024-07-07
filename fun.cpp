#include "canvas.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

bool poprawny_symbol(std::string w){ //dla znakow innych niz spacja-> sprawdzanie, czy wpisane zostaly we wlasciwy sposob, tj: 'znak'
    if(w.length()==3 && w[0]=='\'' && w[2]=='\'')
        return true;
    else{
        return false;
    }
}

void analiza_pliku(const std::string& filename, int& szer, int& wys, char& symbol_tla, std::string& outputFile,std::vector<std::unique_ptr<Figura>>& figury) {
    std::ifstream file(filename);
    std::string linia;
    
    if(file.is_open()){
        if(std::getline(file, linia)){    ///Czytanie 1. linijki: szerokosc_tla wysokosc_tla symbol_tla
            std::istringstream ss(linia);
            std::string a,b;
            ss>>szer>>wys>>a>>b;
            
            if((a.length()==1)&&(a[0]=='\'')&&(b[0]=='\'')&&(b.length()==1)){  //przypadek, gdy symbolem tla ma byc ' '
                symbol_tla=' ';
            }
            else{//gdy inny symbol niz spacja na tlo
                if(!poprawny_symbol(a)){
                        std::cout<<"Niepoprawny symbol dla tla\n";
                        exit(1);
                }
                symbol_tla=a[1];
            }

            if(szer<=0 || wys<=0){
                std::cout<<"Niepoprawne wymiary obrazka\n";
                exit(1);
            }
            std::cout << "Wymiary obrazka: " << szer << "x" << wys << ". Symbol tla: '" << symbol_tla<< "'\n";
        } 
        else{
            std::cout<<"Blad w odczycie wymiarow  obrazka.\n";
            exit(1);
        }

        if(std::getline(file, linia)){  //czytanie kolejne linii: nazwa_pliku_wynikowego
            outputFile = linia;
            std::cout << "Plik wynikowy: " << outputFile << '\n';
        } 
        else{
            std::cout<<"Blad w odczycie nazwy pliku wynikowego\n";
            exit(1);
        }

        //czytanie informacji o figurach do narysowania
        while(std::getline(file, linia)){
            std::istringstream ss(linia);
            std::string typ_figury;
            ss >> typ_figury;
            std::string a,b;
            char s;
            
            if(typ_figury == "PROSTOKAT"||typ_figury=="prostokat"){
                int x, y, w, h;
                ss>>x>>y>>w>>h>>a>>b;
                if((a.length()==1)&&(a[0]=='\'')&&(b[0]=='\'')&&(b.length()==1)){   //gdy figura ma byc wypelniona spacjami
                    s=' ';
                }
                else{  //gdy figura ma byc wypeniona innymi znakami niz spacja
                    if(!poprawny_symbol(a)){
                        std::cout<<"Niepoprawny symbol dla prostokata\n";
                        return;
                    }
                    s=a[1];
                }
                if(w <= 0||h <= 0){
                    std::cout<<"Niepoprawne wymiary prostokata\n";
                    return;
                }
                std::cout << "Wczytano prostokat. Wspolrzedne dolnego lewego wierzcholka: (" << x << ", " << y << "). Wymiary: " << w << "x" << h << ". Symbol wypelnienia: '" << s << "'\n";        
                figury.push_back(std::make_unique<Prostokat>(x, y,s, w, h));
            } 
            else if(typ_figury == "KWADRAT"||typ_figury=="kwadrat"){
                int x, y, bk;
                ss>>x>>y>>bk>>a>>b;
         
                if((a.length()==1)&&(a[0]=='\'')&&(b[0]=='\'')&&(b.length()==1)){
                    s=' ';
                }
                else{
                    if(!poprawny_symbol(a)){
                        std::cout<<"Niepoprawny symbol dla kwadratu\n";
                        return;
                    }
                    s=a[1];
                }
                
                if (bk <= 0) {
                    std::cout<<"Niepoprawne wymiary kwadratu\n";
                    return;
                }
                std::cout << "Wczytano kwadrat. Wspolrzedne dolnego lewego wierzcholka: (" << x << ", " << y << "). Wymiary: " << bk << "x" << bk << ". Symbol wypelniania: '" << s << "'\n";
                figury.push_back(std::make_unique<Kwadrat>(x, y, s, bk));
            } 
            else if(typ_figury == "KOLO"||typ_figury=="kolo"){
                int x, y, r;
                ss>>x>>y>>r>>a>>b;
                if((a.length()==1)&&(a[0]=='\'')&&(b[0]=='\'')&&(b.length()==1)){
                    s=' ';
                }
                else{
                    if(!poprawny_symbol(a)){
                        std::cout<<"Niepoprawny symbol dla kola\n";
                        return;
                    }
                    s=a[1];
                }
                
                if(r <= 0){
                    std::cout<<"Niepoprawny promien kola";
                    return;
                }
                std::cout << "Wczytano kolo. Wspolrzedne srodka: (" << x << ", " << y << "). Promien: " << r << ". Symbol wypelnienia: '" << s << "'\n";          
                figury.push_back(std::make_unique<Kolo>(x, y, s, r));
            } 
            else if(typ_figury == "TROJKAT"||typ_figury=="trojkat"){
                int x, y, bk;
                ss>>x>>y>>bk>>a>>b;
                if((a.length()==1)&&(a[0]=='\'')&&(b[0]=='\'')&&(b.length()==1)){
                    s=' ';
                }
                else{
                    if(!poprawny_symbol(a)){
                        std::cout<<"Nieporawny symbol trojkata\n";
                        return;
                    }
                    s=a[1];
                }
                
                if(bk<=0){
                    std::cout<<"Niepoprawne wymiary trojkata\n";
                    return;
                }
                std::cout << "Wczytano trojkat. Wspolrzedne kata prostego: (" << x << ", " << y << "). Wymiary ramienia: " << bk<< ". Symbol wypelnienia: '" << s << "'\n";
                figury.push_back(std::make_unique<Trojkat>(x, y, s, bk));
            }
            else {
                std::cout<<"Wpisano niepoprawny typ figury do narysowania\n";
                return;
            }
        }

        file.close();
    } 
    else{
        std::cout<<"Nie udalo sie otworzyc pliku: "<<filename<<std::endl;
        exit(1);
    }
}
