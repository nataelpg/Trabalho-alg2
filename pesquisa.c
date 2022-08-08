
#include<stdio.h>   
#include<stdlib.h>  
#include<time.h>

#include "pesquisa.h"
int pesqSequencial(int v[], int x, int n, int *comp){
    int i = 0;
    while (v[i] != x && i < n-1){
        i++;
        comp[4]++;
    }

    if (v[i] == x)
        return 1;
    return 0;
}

int pesqBinaria (int v[], int x, int n, int *comp){
    int inicio = 0;
    int fim = n;

    while(inicio <= fim) {
        int meio = ((inicio + fim) / 2);

        if(x == v[meio]){
            /* elemento foi encontrado */
            comp[5]++;
            return 1;
        }
        if(x < v[meio]) {
            /* elemento esta na esquerda do meio */
            comp[5]++;
            fim = meio - 1;
        }
        else if(x > v[meio]){
            /* elemento esta na direita do meio */
            comp[5]++;
            inicio = meio + 1;
        }
    }

    return 0;
}