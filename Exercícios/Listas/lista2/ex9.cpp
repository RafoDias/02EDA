#include "GeradorLista.cpp"
#include <string>

using namespace std;

struct Node {
    Node *nextNode = NULL;
    int info;
};

Node* CriaListaPadrao()
{
    Node *node, *lista;
    lista = new Node;
    node = lista->nextNode = new Node;
    lista->info = 15;
    node->info = 1;
    return lista;
}

Node* InsereDecrescente(Node* firstNode, int valor)
{
    Node *node, *prevNode;
    Node *newNode  = new Node;
    newNode->info = valor;

    prevNode = firstNode;
    node = prevNode->nextNode;
    if (valor >= prevNode->info)
    {
        newNode->nextNode = prevNode;
        return newNode;
    }
    while (valor < node->info && node != NULL)
    {
        prevNode = node;
        node = node->nextNode;
    }
    prevNode->nextNode = newNode;
    newNode->nextNode = node;
    return firstNode;
}

void PrintLista(Node* firstNode)
{
    Node* node = firstNode;
    cout << endl;
    while (node != NULL)
    {
        cout << node->info << ", ";
        node = node->nextNode;
    }
    cout << endl;
}

int main()
{
    Node *lista;
    string opcao = "p";
    lista = CriaListaPadrao();
    while (opcao[0] != 's')
    {
        if(opcao[0] == 'p') PrintLista(lista);
        else
        {
            int val = stoi(opcao);
            lista = InsereDecrescente(lista, val);
        }
        cout << "Insira o valor a adicionar na lista, p para imprimir e s para sair.\n";
        cin >> opcao;
        

        
    }
    return 0;
}