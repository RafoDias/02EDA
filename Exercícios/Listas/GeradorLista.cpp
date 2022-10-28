#include <iostream>

using namespace std;

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