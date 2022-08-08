#ifndef _PESQUISA_H
#define _PESQUISA_H

/*
Pesquisa sequencialmente um elemento X dentro de um vetor de tamanho N.
*/
int pesqSequencial(int v[], int x, int n, int *comp);

/*
Pesquisa (dividindo o vetor pela metade) a fim de encontrar
um elemento X dentro de um vetor de tamanho N
*/
int pesqBinaria (int v[], int x, int n, int *comp);
#endif