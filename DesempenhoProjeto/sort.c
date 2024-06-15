#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "sort.h"

int* alocaArray(int n)
{
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    return arr;
}

void liberaArray(int *arr)
{
    free(arr);
}

void transformarEmDecrescente(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

double medirTempoDecrescente(void(*menuOrdencao)(int, int[], int), int escolha, int *arr, int n)
{
    struct timeval tempo_antes, tempo_depois;
    double delta_D;

    transformarEmDecrescente(arr, n);

    gettimeofday(&tempo_antes, NULL);

    menuOrdencao(escolha, arr, n);

    gettimeofday(&tempo_depois, NULL);

    delta_D = (tempo_depois.tv_sec + tempo_depois.tv_usec / 1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_usec / 1000000.0);
    printf("O tempo de execucao decrescente foi de %f\n\n", delta_D);


    return delta_D;
}

double medirTempo(void(*menuOrdencao)(int, int[], int), int escolha, int *arr, int n)
{

    struct timeval tempo_antes, tempo_depois;
    double delta_T;

    gettimeofday(&tempo_antes, NULL);

    menuOrdencao(escolha, arr, n);

    gettimeofday(&tempo_depois, NULL);

    delta_T = (tempo_depois.tv_sec + tempo_depois.tv_usec / 1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_usec / 1000000.0);
    printf("O tempo de execucao foi de %f\n", delta_T);

    return delta_T; // Retornamos a diferença de tempo em segundos
}

void gerandoArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}

/****************FUNÇÕES DE ORDENAÇÃO*****************/

/*BubbleSort*/

void bubbleSort(int *v, int n)
{
    int i, continua, aux, fim = n;
    do
    {
        continua = 0;
        for (i = 0; i < fim - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
    }
    while (continua != 0);
}


