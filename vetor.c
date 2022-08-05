#include <stdio.h>
#include <stdlib.h>

int* geraVetor(int* vetor, int elementos) {
    vetor = malloc(sizeof(int) * elementos);
    for(int i = 0; i < elementos; i++) {
        vetor[i] = (rand() % 50);
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return vetor;
}

int mediana(int* vetor, int inicio, int fim, int meio) {
    int aux, mediana;

    if(vetor[inicio] > vetor[fim]) {
        if(vetor[fim] > vetor[meio]) {
            aux = vetor[fim];
            vetor[fim] = vetor[inicio];
        }
    } else if(vetor[inicio] < vetor[fim]) {
        if(vetor[inicio] < vetor[meio]) {
            aux = vetor[meio];
            vetor[meio] = vetor[inicio];
        }
    }

    vetor[inicio] = aux;
}

void imprimeVetor(int* vetor, int inicio, int fim) {
    for(int i = inicio; i < fim; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");
}

void destroiVetor(int* vetor, int fim) {
    for(int i = 0; i < fim; i++)
        vetor[i] = 0;

    free(vetor);
}