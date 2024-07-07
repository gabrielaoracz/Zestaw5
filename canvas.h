#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include <string>
#include <memory>

class Canvas{
    protected:
    int liczba_linii;
    int liczba_znakow_w_linii;

    public:
    Canvas(int lz, int ll): liczba_znakow_w_linii(lz),liczba_linii(ll) {}
    virtual ~Canvas() {} 
    virtual void wyswietl() = 0;
    virtual void wypelnij(int, int , char)=0;
    virtual void zapisz()=0;
};

class ASCIICanvas : public Canvas{
    private:
    std::vector<char> obrazek;
    char znak;
    std::string output_file;

    public:
    ASCIICanvas(int lz, int ll, char z, std::string o) : Canvas(lz, ll), znak(z), obrazek(ll * lz, z), output_file(o) {} 
    void wyswietl() override;
    void wypelnij(int x, int y, char s)override;
    void zapisz() override;        
    ~ASCIICanvas() {}  
};

class Figura{
    protected:
    int wx;
    int wy;
    char symbol;

    public:
    virtual ~Figura(){}
    Figura(int x, int y, char s):wx(x), wy(y), symbol(s){}
    virtual void rysuj(Canvas &o)=0;
};

class Kolo: public Figura{
    private:
    int promien;

    public:
    Kolo(int x, int y, char s, int p): Figura(x,y,s), promien(p){}
    void rysuj(Canvas &c) override;
    ~Kolo(){}
};

class Prostokat: public Figura{
    private:
    int bok_a;

    protected:
    int bok_b;

    public:
    Prostokat(int x, int y, char s, int a, int b): Figura(x,y,s), bok_a(a), bok_b(b){}
    ~Prostokat(){}
    void rysuj(Canvas &o) override;
};


class Kwadrat:public Prostokat{
    public:
    Kwadrat(int x, int y, char s, int b): Prostokat(x,y,s,b,b){}
    ~Kwadrat(){}
};


class Trojkat:public Figura{
    private:
    int ramie;

    public:
    Trojkat(int x, int y, char s, int r): Figura(x,y,s), ramie(r){}
    void rysuj(Canvas &o) override;
    ~Trojkat(){}
};

void analiza_pliku(const std::string& filename, int& width, int& height, char& bgSymbol, std::string& outputFile, std::vector<std::unique_ptr<Figura>>& figures);
bool poprawny_symbol(std::string);

#endif


