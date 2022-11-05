#include <iostream>

using namespace std;

struct Node {
    Node *nextNode = NULL;
    int info;
};

void PrintLista(Node* lista);
Node* DivideLista(Node *firstNode, int value);

int main()
{
    int value;
    Node *firstNode = NULL;

    cout << "Insira valores para cada elemento da lista.\nInsira 0 para parar."; 
    cin >> value;

    while (value != 0)
    {
        Node *node = new Node;
        node->info = value;
        node->nextNode = firstNode;
        firstNode = node;
        cin >> value;
    }
    cout << "Lista Completa:";
    PrintLista(firstNode);

    cout << "Escolha o valor que dividira a lista em duas: ";
    cin >> value;

    Node *lista2 = DivideLista(firstNode, value);
    cout << "Lista 1:";
    PrintLista(firstNode);

    cout << "Lista 2:";
    PrintLista(lista2);

    return 0;
}

Node* DivideLista(Node *firstNode, int value)
{
    Node* node = firstNode;
    while (node != NULL && node->info != value)
    {
        node = node->nextNode;
    }

    if (node == NULL) return NULL;

    Node* lista2 = node->nextNode;
    node->nextNode = NULL;
    
    return lista2;
}

void PrintLista(Node* lista)
{
    if (lista == NULL)
    {
        cout << "\nNULL";
        return;
    }
    
    Node *node = lista;
    cout << endl;
    while (node != NULL)
    {
        cout << node-> info << ", ";
        node = node -> nextNode;
    }
    cout << endl;
}