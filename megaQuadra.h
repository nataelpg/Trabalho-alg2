#ifndef _MEGAQUADRA_H
#define _MEGAQUADRA_H

/*
Lê 4 apostas e insere em um vetor w[].
*/
void leApostas (int w[], int maxVal);

/*
Verifica se cada um dos 4 números escolhidos
foram utilizados
*/
int pontuacao (int v[], int w[], int tam, int *comp);

#endif