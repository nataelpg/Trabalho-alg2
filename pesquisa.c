
#include<stdio.h>   
#include<stdlib.h>  
#include<time.h>

#include "pesquisa.h"
int pesqSequencial(int v[], int x, int n){
    int i = 0;
    while (v[i] != x && i < n){
        i++;
    }

    if (v[i] == x)
        return 1;
    return 0;
}

int pesqBinaria (int v[], int x, int n){
    int inicio = 0;
    int fim = n;

    while(inicio <= fim) {
        int meio = ((inicio + fim) / 2);

        if(x == v[meio])
            /* elemento foi encontrado */
            return 1;
        if(x < v[meio]) 
            /* elemento esta na esquerda do meio */
            fim = meio - 1;
        else if(x > v[meio])
            /* elemento esta na direita do meio */
            inicio = meio + 1;
    }

    return 0;
}
