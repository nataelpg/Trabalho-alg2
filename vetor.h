#ifndef __VETOR__
#define __VETOR__

/*
//Gera um vetor de 1 a 50, totalmente aleatório.
*/
int* geraVetor(int* vetor, int elementos);

/*
//Realiza a média do índice inicial, do meio e final.
//Retorna o vetor com o primeiro elemento trocado com a mediana.  
*/
int mediana(int* vetor, int inicio, int fim, int meio);

/*
//Imprime o vetor
*/
void imprimeVetor(int* vetor, int inicio, int fim);

/*
//Destrói o vetor
*/
void destroiVetor(int* vetor, int fim);

#endif