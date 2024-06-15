#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"

int main()
{
    int escolhaMenu, escolhaQuantidadeDados, n;
    int *arr;
    srand(time(0));
    double totalTempo;
    double tempoOrdenacao = 0;
    double tempos[10] = {0};
    double tempoDescrescente[10] = {0};
    double totalTempoD = 0;

    do{
        /*Criando o menu para escolher a ordenação*/
        printf("\n\n");
        printMenu();
        scanf("%d", &escolhaMenu);

        if(escolhaMenu == 11){
            return 0;
        }

        /*Menu da quantidade de dados*/
        printQuantidadeDados();
        scanf("%d", &escolhaQuantidadeDados);

        n = escolhaQuantidade(escolhaQuantidadeDados);
        if (n == -1)
        {
            continue;
        }

        for (int i = 0; i < 10; i++)
        {
            arr = alocaArray(n);
            gerandoArray(arr, n);
            tempos[i] = medirTempo(menuOrdencao,escolhaMenu,arr, n);
            tempoDescrescente[i] = medirTempoDecrescente(menuOrdencao,escolhaMenu,arr, n);
            printf("\nTempo de ordenacao %d: %.6f e tempo decrescente %.6f  segundos\n", i, tempos[i], tempoDescrescente[i]);
            liberaArray(arr);
        }

         for (int i = 0; i < 10; i++)
        {
            totalTempo += tempos[i];
            totalTempoD += tempoDescrescente[i];
        }
        double mediaTempo = totalTempo / 10;
        double mediaTempoD = totalTempoD / 10;

        printf("\n%f mediaTempo e %f media tempo d\n", mediaTempo, mediaTempoD);

    } while (escolhaMenu != 11);

}
