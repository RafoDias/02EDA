#include <iostream>

using namespace std;

template<typename T>
struct Node {
        Node<T> *nextNode = NULL, *previousNode = NULL;
        T item;
    };

template<typename T>
class ListaEncadeada
{
    public:

    Node<T> *firstNode;
    Node<T> *lastNode;
    int size;
    

    ListaEncadeada()
    {
        firstNode = NULL;
        lastNode = NULL;
        size = 0;
    }

    public:
    void InsertFirst(T item);
    void InsertLast(T item);
    void RemoveFirst();
    void RemoveLast();
    int GetIndex(T item);
    T GetItemFrom(int index);
    string ToString();
    void Delete();
};

template<typename T>
void ListaEncadeada<T>::InsertFirst(T item)
{
    Node<T> *node = new Node<T>;
    node->item = item;
    node->nextNode = firstNode;
    firstNode = node;
    size++;
    // throw std::invalid_argument("Objeto inválido.");
}

template<typename T>
void ListaEncadeada<T>::InsertLast(T item)
{
    Node<T> *node = new Node<T>;
    node->item = item;
    node->previousNode = lastNode;
    lastNode = node;
    size++;
}

template<typename T>
void ListaEncadeada<T>::RemoveFirst()
{
    Node<T> *node = firstNode;
    firstNode = node->nextNode;
    delete node;
    firstNode->previousNode = NULL;
    size--;
}

template<typename T>
void ListaEncadeada<T>::RemoveLast()
{
    Node<T> *node = lastNode->previousNode;
    delete lastNode;
    lastNode = node;
    lastNode->nextNode = NULL;
    size--;
}

template<typename T>
int ListaEncadeada<T>::GetIndex(T item)
{
    int count = 0;
    Node<T> *node = firstNode;

    while (count < size)
    {
        if (item == node->item)
        {
            return count;
        }
        else
        {
            node = node->nextNode;
            count++;
        }
    }
    throw std::invalid_argument("Objeto inválido.");
    return -1;
}

template<typename T>
T ListaEncadeada<T>::GetItemFrom(int index)
{
    int count = 0;
    Node<T> *node = firstNode;
    while (count < index)
    {
        node = node->nextNode;
        count++;
    }
    return node->item;
}

template<typename T>
string ListaEncadeada<T>::ToString()
{
    int count = 0;
    Node<T> *node = firstNode;
    string retStr = "";
    while (node != NULL)
    {
        string s = "[" +  to_string(count) + "] ";
        string s2 = node->item.ToString();
        string s3 = s + s2 + " \n";
        retStr += s3;
        node = node->nextNode;
        count++;
    }
    return retStr;
}
template<typename T>
void ListaEncadeada<T>::Delete()
{
    Node<T> *node = lastNode;
    while (node != NULL)
    {
        Node<T> *ptr = node;
        node = node->previousNode;
        delete ptr;
    }
    delete this;
}