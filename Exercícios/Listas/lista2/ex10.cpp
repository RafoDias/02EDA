#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node *nextNode = NULL;
    int info;
};
void PrintLista(Node* firstNode);

Node* InsereLista(Node *lista, int val)
{
    if (lista == NULL)
    {
        lista = new Node;
        lista->nextNode = lista;
        lista->info = val;
        return lista;
    }
    
    Node* node = new Node;
    node->info = val;
    node->nextNode = lista->nextNode;
    lista->nextNode = node;
    return node;
}

int main()
{
    Node *node = NULL, *lista = NULL;
    string opcao = "p";
    while (opcao[0] != 's')
    {   
        if(opcao[0] == 'p') 
        {
            PrintLista(lista);
        }
        else if (opcao[0] == 'n') {
            if (node == NULL)  
            {
                node = lista;
                if (node == NULL) {
                    cout << "";
                }
                else { 
                    cout << node->info; 
                }
            }
            else
            {
                node = node->nextNode;
                cout << endl << node->info << endl;
            }
        }
        else {
            int val = stoi(opcao);
            lista = InsereLista(lista, val);
        }
        cout << "Insira o valor a adicionar na lista, 'p' para imprimir, 's' para sair e \n'n' para caminhar para o proximo elemento da lista.\n";
        cin >> opcao;
    }
    return 0;
}

void PrintLista(Node* firstNode)
{
    Node* node = firstNode;
    if (node == NULL) return;
    
    cout << endl;
    
    do {
        cout << node->info << ", ";
        node = node->nextNode;
    } while (node != firstNode);

    cout << endl;
}