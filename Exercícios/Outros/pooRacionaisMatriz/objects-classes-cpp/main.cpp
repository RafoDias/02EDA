#include <iostream>
#include "matrizes.cpp"
#include "racionais.cpp"
#include "carro.cpp"
#include "lista.cpp"

using namespace std;

char letras[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                      'H', 'I', 'J', 'K', 'L', 'M', 'N',
                      'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                      'V', 'W', 'X', 'Y', 'Z' };

string cores[4] = {"AZUL", "PRETO", "VERMELHO", "AMARELO"};
string fabricantes[4] = {"FORD", "TOYOTA", "HYUNDAI", "RENAULT"};


int main()
{
    srand(time(NULL));
    ListaEncadeada<Carro> *lista = new ListaEncadeada<Carro>();
    
    int count = 0, total = 5;
    while (count < total)
    {
        int id = count;
        string tcor = cores[rand()%4];
        string tfab = fabricantes[rand()%4];

        string placa = ""; //LLLNLNN
        for (int i = 0; i < 7; i++) {
            if (i < 3 || i == 4)
                placa += letras[(rand() % 26)];
            else {
                int c = rand() % 10;
                placa += std::to_string(c);
            }
        }

        Carro *carro = new Carro(id, placa, tfab, tcor);
        lista->InsertFirst(*carro);
        delete carro;
        count++;
    }
    
    string strLista = lista->ToString();
    cout << strLista;
    lista->Delete();
    
    return 0;
}