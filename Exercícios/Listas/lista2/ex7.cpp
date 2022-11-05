#include "GeradorLista.cpp"

struct Node {
    Node *nextNode = NULL;
    int info;
};

Node* IntercalaLista(Node* lista1, Node* lista2);

int main()
{
    Node *lista1 = CriarListaSequenciada<Node>(8, ASC);
    Node *lista2 = CriarListaSequenciada<Node>(5, DESC);

    cout << "Lista 1:";
    PrintLista(lista1);
    cout << "Lista 2:";
    PrintLista(lista2);

    Node *novaLista = IntercalaLista(lista1, lista2);

    cout << "Lista Intercalada:";
    PrintLista(novaLista);

    cout << "\nChecando se foi criada uma lista nova ou modificada a antiga\n";
    cout << "Lista 1:";
    PrintLista(lista1);
    cout << "Lista 2:";
    PrintLista(lista2);

    return 0;
}

Node* IntercalaLista(Node* lista1, Node* lista2)
{
    Node *node1 = lista1, *node2 = lista2, *novaLista = NULL, *nodePtr = NULL;

    while (node1 != NULL || node2 != NULL)
    {
        if (novaLista == NULL) {
            novaLista = new Node;
            novaLista->nextNode = novaLista;
            nodePtr = novaLista;
        }
        
        if (node1 != NULL)
        {
            nodePtr = nodePtr->nextNode;
            nodePtr->info = node1->info;
            nodePtr->nextNode = new Node;
            node1 = node1->nextNode;
        }
        
        if (node2 != NULL)
        {
            nodePtr = nodePtr->nextNode;
            nodePtr->info = node2->info;
            nodePtr->nextNode = new Node;
            node2 = node2->nextNode;
        }
    }

    delete nodePtr->nextNode;
    nodePtr->nextNode = NULL;

    return novaLista;
}