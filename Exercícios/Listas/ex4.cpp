#include "GeradorLista.cpp"

struct Node {
    Node* nextNode = NULL;
    int info;
};

Node* RemoveNodesComN(int n, Node* firstNode);

int main()
{
    Node* lista;
    int listSize, x;

    cout << "Tamanho da lista: ";
    cin >> listSize;
    lista = CriarListaRandomizada<Node>(listSize, 3);
    PrintLista(lista);
    
    cout << "Valor a ser retirado: ";
    cin >> x;
    lista = RemoveNodesComN(x, lista);
    PrintLista(lista);

    return 0;
}

Node* RemoveNodesComN(int n, Node* firstNode)
{
    Node *node = firstNode;
    if(firstNode->nextNode != NULL)
        firstNode->nextNode = RemoveNodesComN(n, firstNode->nextNode);

    if (firstNode->info == n)
    {
        node = firstNode->nextNode;
        delete firstNode;
        firstNode = NULL;
    }
    
    return node;
}