#include "GeradorLista.cpp"

struct Node;
Node* ConcatenaLista(Node* lista1, Node* lista2);

struct Node {
    Node *nextNode = NULL;
    int info;
};

int main()
{
    Node *lista1, *lista2;
    int listSize;
    cout << "Tamanho lista1: ";
    cin >> listSize;
    lista1 = CriarListaRandomizada<Node>(listSize, 100);
    cout << "Tamanho lista2: ";
    cin >> listSize;
    lista2 = CriarListaRandomizada<Node>(listSize, 100);

    cout << "\nLista 1:\n";
    PrintLista<Node>(lista1);
    cout << "\nLista 2:\n";
    PrintLista<Node>(lista2);

    Node* listaConcatenada = ConcatenaLista(lista1, lista2);
    PrintLista<Node>(listaConcatenada);

    return 0;
}

Node* ConcatenaLista(Node* lista1, Node* lista2)
{
    Node *node = lista1;
    while (node->nextNode != NULL)
    {
        node = node->nextNode;
    }
    node->nextNode = lista2;
    
    return lista1;
}