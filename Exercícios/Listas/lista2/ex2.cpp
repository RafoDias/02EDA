#include "GeradorLista.cpp"

struct Node {
    Node *nextNode = NULL;
    int info;
};

int ContarMaiorQueN(int n, Node* firstNode)
{
    int count = 0;
    Node* node = firstNode;

    while (node != NULL)
    {
        if (node->info > n) count++;
        node = node->nextNode;
    }

    return count;
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
    int tamanhoLista;
    cin >> tamanhoLista;
    Node* lista = CriarListaRandomizada<Node>(tamanhoLista, 100);
    PrintLista(lista);
    int alvo;
    cin >> alvo;
    cout << endl << ContarMaiorQueN(alvo, lista);
    return 0;
}
