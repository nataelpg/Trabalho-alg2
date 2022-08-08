#ifndef _VETOR_H
#define _VETOR_H

/* 
Recebe um valor maximo e preenche o vetor 
com elementos de valor menor ou igual do valor maximo.
*/
void preencheVetor (int vet[], int tam, int maxVal);

/* 
Imprime todos os elementos de um vetor qualquer
*/
void imprimeVetor(int v[], int TAM);

/*
Copia o vetor original para um a ser ordenado.
*/
void copiaVetor (int vetFonte[], int vetDestino[], int TAM);

/*
Compara tres elementos de um vetor,
um do começo, meio e fim, e tira a mediana entre eles
*/
void pivoMediana (int v[], int ini, int fim);

/*
Troca o elemento a com o elemento b no vetor v.
*/
void troca (int v[], int a, int b);

#endif