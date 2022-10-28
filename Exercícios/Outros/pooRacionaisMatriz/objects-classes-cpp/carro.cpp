#include <iostream>
#include <string>

using namespace std;

class Carro
{
    public:
    int id;
    string placa;
    string fabricante;
    string cor;

    Carro(int i, string p, string f, string c)
    {
        id = i;
        placa = p;
        fabricante = f;
        cor = c;
    }
        Carro()
    {
        id = -1;
        placa = "PLACEHOLDER";
        fabricante = "PLACEHOLDER";
        cor = "PLACEHOLDER";
    }

    public:
    string ToString();
    Carro* operator=(const Carro rhs);
    long long int operator=(long long int rhs);
    bool operator==(const Carro rhs);
    bool operator!=(const Carro rhs);
    void Delete();
};

string Carro::ToString() {
    
    string returnString;
    string sid = to_string(id);
    returnString = "[" + sid + ", " + placa + ", " + fabricante + ", " + cor + "]\n";

    return returnString;
}

    // OVERRIDE DO OSTREAM E DO OPERADOR << (USADOS NO COMANDO COUT). https://stackoverflow.com/questions/5171739/tostring-override-in-c
inline std::ostream & operator<<(std::ostream & Str, Carro v) { 
Str << v.ToString(); // print something from v to str, e.g: Str << v.getX();
return Str;
}

Carro* Carro::operator=(Carro rhs)
{
    this->id = rhs.id;
    this->cor = rhs.cor;
    this->fabricante = rhs.fabricante;
    this->placa = rhs.placa;
    return this;
}
bool Carro::operator==(Carro rhs)
{
    return (this->placa == rhs.placa);
}
bool Carro::operator!=(Carro rhs)
{
    return (this->placa != rhs.placa);
}
void Carro::Delete()
{
    delete this;
}