#include <iostream>

using namespace std;

enum Ordem {
    ASC,
    DESC
};

template<typename T>
T* CriarListaRandomizada(int tamanho, int range)
{
    srand(time(NULL));
    int count = 0;
    T* firstNode;
    if (count < tamanho)
    {
        firstNode = new T;
        firstNode->info = (rand()%range);
        count++;
    }
    while (count < tamanho)
    {
        T* node = firstNode;
        firstNode = new T;
        firstNode->info = (rand()%range);
        firstNode->nextNode = node;
        count++;
    }
    return firstNode;
}

template<typename T>
void PrintLista(T* firstNode)
{
    T* node = firstNode;
    cout << endl;
    while (node != NULL)
    {
        cout << node->info << ", ";
        node = node->nextNode;
    }
    cout << endl;
}

template<typename T>
T* CriarListaSequenciada(int tamanho, Ordem ord)
{
    int count = 0;
    T* firstNode;
    if (ord == DESC)
    {
        if (count < tamanho)
        {
            firstNode = new T;
            firstNode->info = (count + 1);
            count++;
        }
            while (count < tamanho)
        {
            T* node = firstNode;
            firstNode = new T;
            firstNode->info = (count + 1);
            firstNode->nextNode = node;
            count++;
        }
    }
    else
    {
        int i = tamanho;
        if (i > 0)
        {
            firstNode = new T;
            firstNode->info = (i);
            i--;
        }
            while (i > 0)
        {
            T* node = firstNode;
            firstNode = new T;
            firstNode->info = (i);
            firstNode->nextNode = node;
            i--;
        }
    }
    
    return firstNode;
}