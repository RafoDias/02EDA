#include <iostream>
#include "lista.cpp"

using namespace std;

struct Carro {
    int id;
    string placa;
    string fabricante;
    string cor;
};

int Busca_Binaria(Carro* array, int inicio, int fim, int id);
Carro* Criar_Array(int tamanho);
void Print_Array(Carro* array, int inicio, int tamanho);
Carro* Busca_Sequencial(Carro* array, int tamanhoArray, string alvo, int propriedade);
int Busca_Sequencial(Carro* array, int tamanhoArray, int id);
void Shuffle_Array(Carro* array, int tamanhoArray);
Carro* QuickSort(Carro* array, int inicio, int fim);

int main()
{
    int tamanhoArray;
    Carro* array;
    cout << "Qual o tamanho do array?\n";
    cin >> tamanhoArray;
    array = Criar_Array(tamanhoArray);
    bool ordenado = true;

    int opcao = 10;
    while (opcao != 0)
    {
        cout << "\n1. Imprimir array. | 2. Embaralhar array. | 3. Ordenar array. | 4. Buscar por id." 
        << "\n5. Buscar por placa. | 6. Buscar por cor. | 7. Buscar por fabricante. | 0. Sair.\n";

        cin >> opcao;

        if (opcao == 1) Print_Array(array, 0, tamanhoArray);
        else if (opcao == 2) {
            Shuffle_Array(array, tamanhoArray);
            ordenado = false;
        }
        else if (opcao == 3) { 
            QuickSort(array, 0, tamanhoArray - 1);
            ordenado = true;
            cout << "Ordenado.\n";
        }
        else if (opcao == 4) {
            int id, index = -1;
            cout << "Qual o id a ser buscado? ";
            cin >> id;
            if (id >= 0)
            {
                if (ordenado = true)
                {
                    index = Busca_Binaria(array, 0, (tamanhoArray - 1), id);
                }
                else
                {
                    index = Busca_Sequencial(array, tamanhoArray, id);
                }
                if (index >= 0) Print_Array(array, index, index + 1);
                else cout << "Não encontrado no array.\n";
            }
            else cout << "Não há ID menor que zero.\n";
        }
        else if (opcao == 5) {
            string placa;
            cout << "Qual a placa a ser buscada? ";
            cin >> placa;
            Busca_Sequencial(array, tamanhoArray, placa, 0);
        }
        else if (opcao == 6) {
            string cor;
            cout << "Qual a cor a ser buscada? ";
            cin >> cor;
            Busca_Sequencial(array, tamanhoArray, cor, 1);
        }
        else if (opcao == 7) {
            string fabricante;
            cout << "Qual o fabricante a ser buscado? ";
            cin >> fabricante;
            Busca_Sequencial(array, tamanhoArray, fabricante, 2);
        }
    }
    
    
    return 0;
}

int Busca_Binaria(Carro* array, int inicio, int fim, int id)
{ // Ideal para listas ordenadas. Funciona para buscar IDs, caso estejam ordenados
    int meio = (inicio + fim) / 2;

    if (id == array[meio].id) return meio;
    else if (id > array[meio].id) 
        return Busca_Binaria(array, meio, fim, id);
    else if (id < array[meio].id) 
        return Busca_Binaria(array, inicio, meio, id);
    else
        return -1;
}

Carro* Busca_Sequencial(Carro* array, int tamanhoArray, string alvo, int propriedade)
{
    // 0 = Placa , 1 = Cor, 2 = Fabricante
    struct BuscaCarro
    {
        Carro carro;
        BuscaCarro* next = NULL;
    };

    ListaEncadeada<Carro> *lista = new ListaEncadeada<Carro>();
    
    int count = 0;
    if (propriedade == 0) {
        for (int i = tamanhoArray - 1; i >= 0; i--)
        {
            if (array[i].placa == alvo)
            {
                lista.Insert_First(array[i]);
            }
        }
    }
    else if (propriedade == 1) {
        for (int i = tamanhoArray - 1; i >= 0; i--)
        {
            if (array[i].cor == alvo)
            {
                lista.Insert_First(array[i]);
            }
        }
    }
    else if (propriedade == 2) {
        for (int i = tamanhoArray - 1; i >= 0; i--)
        {
            if (array[i].fabricante == alvo)
            {
                lista.Insert_First(array[i]);
            }
        }
    }

    cout << "Total encontrado: " << lista.size << endl;
    if (lista.size > 0) {


        Carro* tmpArray = new Carro[count];
        for (int i = 0; i < count; i++)
        {
            tmpArray[i] = lista->firstNode.item;

            if (lista->firstNode != NULL) lista.Remove_First();
        }
        lista.Clear();
        Print_Array(tmpArray, 0, count);
        return tmpArray;
    }

    else {
        cout << "\nNenhum item encontrado.\n";
        return NULL;
    }
}

int Busca_Sequencial(Carro* array, int tamanhoArray, int id)
{
    for (int i = tamanhoArray - 1; i >= 0; i--)
        {
            if (array[i].id == id)
            {
                return i;
            }
        }
    return -1;
}

Carro* Criar_Array(int tamanho)
{
    srand(time(NULL));
    char letras[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z' };

    Carro* array = new Carro[tamanho];
    int id = 0;
    string cor[] = {"AZUL", "PRETO", "VERMELHO", "AMARELO"};
    string fabricante[] = {"FORD", "TOYOTA", "HYUNDAI", "RENAULT"};

    for (id; id < tamanho; id++)
    {
        array[id].cor = cor[rand()%4];
        array[id].fabricante = fabricante[rand() % 4];
        string placa = ""; //LLLNLNN

        for (int i = 0; i < 7; i++) {
            if (i < 3 || i == 4)
                placa += letras[(rand() % 26)];
            else {
                int c = rand() % 10;
                placa += std::to_string(c);
            }
        }
        array[id].placa = placa;
        array[id].id = id;
    }

    return array;
}

void Print_Array(Carro* array, int inicio, int tamanho)
{
    for (int i = inicio; i < tamanho; i++)
    {
        cout << "[" << array[i].id << ", " << 
        array[i].placa << ", " << array[i].fabricante << ", "
        << array[i].cor << "]\n";
    }
    cout << endl;
}

void Shuffle_Array(Carro* array, int tamanhoArray)
{
    srand(time(NULL));
    for (int i = 0; i < tamanhoArray; i++)
    {
        int a = (rand() % tamanhoArray), b = (rand() % tamanhoArray);
        Carro tmp;
        tmp = array[a];
        array[a] = array[b];
        array[b] = tmp;
    }
    cout << "Embaralhado.\n";
}

Carro* QuickSort(Carro* array, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivot = array[inicio].id;

        int count = 0;
        for (int i = inicio + 1; i <= fim; i++)
        {
            if (array[i].id <= pivot) count++;
        }

        int pivotIndex = inicio + count;
        Carro tmp = array[pivotIndex];
        array[pivotIndex] = array[inicio];
        array[inicio] = tmp;

        int i = inicio, j = fim;

        while (j > i)
        {
            while (array[i].id <= pivot) { i++; }
            while (array[j].id > pivot) { j--; }

            if (j > i) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }

        QuickSort(array, inicio, j - 1);

        QuickSort(array, j + 1, fim);
    }
    return array;
}