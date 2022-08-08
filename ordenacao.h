#ifndef _ORDENACAO_H
#define _ORDENACAO_H

/* 
Coloca o pivo na posicao certa e deixa elementos menores que o pivo
a sua esquerda e maiores a sua direita.
*/
int particionar (int v[], int ini, int fim, int *comp);

/*
Compara os elementos com base em um pivo (recursivamente).
*/
void quickSort(int v[], int ini, int fim, int *comp);

/*
Compara os elementos com base em um pivo (iterativamente).
*/
void quickSortIterativo (int v[], int ini, int fim, int *comp);

/* 
Percorre o vetor e a cada iteracao verifica o minimo 
*/
void selectionSort (int v[], int TAM, int *comp);

/* 
Compara elemento por elemento do vetor e 
realiza trocas ate o elemento chegar na posicao certa. */
void bubbleSort (int v[], int TAM, int *comp);

#endif