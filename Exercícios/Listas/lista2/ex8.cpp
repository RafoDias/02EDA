#include "GeradorLista.cpp"

struct Node {
    Node *nextNode = NULL;
    int info;
};

bool ComparaListas(Node* lista1, Node* lista2);

int main()
{
    Node *lista1 = CriarListaSequenciada<Node>(5, ASC);
    Node *lista2 = CriarListaSequenciada<Node>(5, ASC);
    Node *lista3 = CriarListaSequenciada<Node>(5, DESC);
    Node *lista4 = CriarListaSequenciada<Node>(8, ASC);

    bool bl12, bl13, bl14, bl42;

    cout << "Lista 1:";
    PrintLista(lista1);
    cout << "Lista 2:";
    PrintLista(lista2);
    cout << "Lista 3:";
    PrintLista(lista3);
    cout << "Lista 4:";
    PrintLista(lista4);

    cout << "\nComparando as listas...\n";
    bl12 = ComparaListas(lista1, lista2);    
    cout << "Lista 1 e 2: ";
    cout << std::boolalpha << bl12 << endl;

    bl13 = ComparaListas(lista1, lista3);
    cout << "Lista 1 e 3: ";
    cout << std::boolalpha << bl13 << endl;

    bl14 = ComparaListas(lista1, lista4);
    cout << "Lista 1 e 4: ";
    cout << std::boolalpha << bl14 << endl;
    
    bl42 = ComparaListas(lista4, lista2);
    cout << "Lista 4 e 2: ";
    cout << std::boolalpha << bl42 << endl;

    return 0;
}

bool ComparaListas(Node* lista1, Node* lista2)
{
    Node *node1 = lista1, *node2 = lista2;

    while (node1 != NULL && node2 != NULL)
    {
        if (node1->info != node2->info) return false;
        node1 = node1->nextNode;
        node2 = node2->nextNode;
    }
    if (node1 != node2) return false;

    return true;
}