#include "vetor.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVetor(int vet[], int tam, int maxVal) {
    char ja_consta;

    for(int i = 0; i < tam; i++) {
        vet[i] = rand() % maxVal + 1;
        ja_consta = 'N';
        for(int j = 0; j < i && ja_consta == 'N'; j++) {
            if(vet[i] == vet[j])
                ja_consta = 'S';
        }
        if(ja_consta == 'S')
            i--;
    }
}

void imprimeVetor(int v[], int TAM) {
    int i;
    for(i = 0; i < TAM; i++) {
        printf("%d ", v[i]);
    }
}

void troca(int v[], int a, int b) {
    int aux = v[b];
    v[b] = v[a];
    v[a] = aux;
}

void copiaVetor(int vetFonte[], int vetDestino[], int TAM) {
    for(int i = 0; i < TAM; i++)
        vetDestino[i] = vetFonte[i];
}

void pivoMediana(int v[], int ini, int fim) {
    int m = (ini + fim) / 2;
    int medIndice = 0;

    if(v[ini] < v[m])
        if(v[m] < v[fim])
            // ini < meio e meio < fim
            medIndice = m;
        else if(v[ini] < v[fim])
            // ini < fim e fim <= meio
            medIndice = fim;
        else
            // fim <= ini e ini < meio
            medIndice = ini;
    else if(v[fim] < v[m])
        // fim < meio e meio <= ini
        medIndice = m;
    else if(v[fim] < v[ini])
        // meio <= fim e fim <= ini
        medIndice = fim;
    else
        // meio <= ini e ini <= fim
        medIndice = ini;
    troca(v, medIndice, fim);
}