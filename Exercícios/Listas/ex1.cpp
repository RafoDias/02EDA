#include <iostream>

using namespace std;

struct Node;
Node* CriarListaRandomizada(int tamanho);
int TamanhoLista(Node* firstNode);

int main()
{
    int tamanhoLista;
    cin >> tamanhoLista;
    Node* lista = CriarListaRandomizada(tamanhoLista);
    cout << TamanhoLista(lista);
    return 0;
}

struct Node {
    Node *nextNode = NULL;
    int valor;
};

Node* CriarListaRandomizada(int tamanho)
{
    srand(time(NULL));
    int count = 0;
    Node* firstNode;
    if (count < tamanho)
    {
        firstNode = new Node;
        firstNode->valor = (rand()%100);
        count++;
    }
    while (count < tamanho)
    {
        Node* node = firstNode;
        firstNode = new Node;
        firstNode->valor = (rand()%100);
        firstNode->nextNode = node;
        count++;
    }
    return firstNode;
}

int TamanhoLista(Node* firstNode)
{
    int count = 0;
    Node *node = firstNode;
    while(node != NULL)
    {
        count++;
        node = node->nextNode;
    }
    return count;
}