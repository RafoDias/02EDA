#include <iostream>

using namespace std;

// Nó com as informações e o ponteiro para o próximo nó
struct Node {
    Node *nextNode = NULL;
    int info;
};

void PrintLista(Node* firstNode) // função para testes 
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

// Esses "#pragma region" servem apenas para organizar o arquivo.
// Passando o mouse à esquerda deles você pode ver que há uma setinha que 
// esconde ou mostra o código na região definida pelo comando.
// Abaixo é a região definida para o exercício 1.
#pragma region Exercicio 1
    // Essa função retorna a quantidade de nós em uma lista.
    // Nota-se que a lista pode possuir nós, mas não possuir valores atrelados a eles (dependendo de como forem criadas).
    // Essa função também conta o topo como um nó pertencente e primeiro elemento da lista.
int TamanhoLista(Node *topo)
{
    int cont = 0;
    Node *node = topo; // Queremos evitar modificar o ponteiro topo para não perder o início da lista.
    while (node != NULL)
    {
        cont++;
        node = node->nextNode;
    }
    return cont;
}

#pragma endregion

int main() // Use a função main para testar o código como preferir.
{
    return 0;
}