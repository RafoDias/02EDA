#include <iostream>

using namespace std;

int* bubbleSort(int array[], int tamanho);
int* insertionSort(int array[], int tamanho)
int* mergeSort(int array[], int inicio, int fim);

int escolheExercicio()
{
    int resp = 0;
    while (resp < 1 || resp > 3)
    {
        cout << "Escolha qual exercício será resolvido (de 1 a 3).";
        cin >> resp;
    }
    
}

int* criarArray(int resp)
{
    int size;

    switch (resp)
    {
    case 1:
        size = 50;
        break;
    case 2:
        size = 20;
        break;
    default: // resp == 3 ou qualquer outro
        size = 10;
    }

    int* array = new int[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (size * 2);
    }
    
    return array;
}

int main()
{
    int resp = escolheExercicio();

    int* array = criarArray(resp);
    
}

int* bubbleSort(int array[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j] = tmp;
            }
        }
    }
    return array;
}

int* insertionSort(int array[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (array[min] > array[j])
            {
                min = j;
            }
        }
        int tmp = array[i];
        array[i] = array[min];
        array[min] = tmp;
    }
    return array;
}

int* mergeSort(int array[], int inicio, int fim)
{
    if (inicio >= fim)
    {
        return array;
    }
    
    int meio = (inicio + fim) / 2;

    mergeSort(array, inicio, meio);
    mergeSort(array, meio + 1, fim);

    int* arrAux = new int[fim + 1];

    int i = inicio, x = inicio, y = meio + 1;
    for (; x <= meio && y <= fim; i++)
    {
        if (array[x] < array[y])
        {
            arrAux[i] = array[x];
            x++;
        }
        else
        {
            arrAux[i] = array[y];
            y++;
        }
    }

    for (; x <= meio; x++)
    {
        arrAux[i] = array[x];
        i++;
    }
    for (; y <= fim; y++)
    {
        arrAux[i] = array[y];
        i++;
    }

    for (i = inicio; i <= fim; i++)
    {
        array[i] = arrAux[i];
    }

    return array;
}

int* quicksort(int array[], int inicio, int fim)
{
    int i, j, chave;

    if (fim - inicio < 2) {
        if ((fim - inicio) == 1) {
            if (array[inicio] > a[fim])
            {
                troca (&array[inicio], &array[fim]);
            }
        }
    }

    else {
        i = inicio;
        j = fim;
        chave = array[inicio]

        while(j > i)
        {
            i++;
            while (array[i] < chave)
            {
                i++;
            }
            while (array[j] > chave)
            {
                j--;
            }
            if (j > i)
            {
                troca(&array[i], &array[j]);
            }
        }

        troca (&array[inicio], &array[j]);
        quicksort(array, inicio, j-1);
        quicksort(array, j+1, fim);
    }
}

void troca(int* x, int* y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}