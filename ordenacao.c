#include<stdio.h>   
#include<stdlib.h>  
#include<time.h>

#include "ordenacao.h"
#include "vetor.h"

int particionar (int v[], int ini, int fim){
    int pivo = v[fim];
    int i, m = ini;
    for (i = ini; i < fim; i++){
        if (v[i] <= pivo){
            troca (v, m, i);
            m++;
        }
    }
    troca (v, m, fim);
    return m;
}

void quickSort(int v[], int ini, int fim){
	if (ini>=fim)
		return;
		
	// posPivo		
	int m = particionar (v, ini, fim);
	quickSort(v, ini, m-1);
	quickSort (v, m+1, fim);
	
	return;
}

void quickSortIterativo (int v[], int ini, int fim) {
	int pilha[fim - ini + 1];
	int topo = -1;
	
	pilha[++topo] = ini;
	pilha[++topo] = fim;
	
	while (topo >= 0){
		fim = pilha[topo--];
		ini = pilha[topo--];
		
		int m = particionar(v, ini, fim);
		if (m - 1 > ini){
			pilha[++topo] = ini;
			pilha[++topo] = m - 1;
		}
		if (m + 1 < fim) {
			pilha [++topo] = m + 1;
			pilha [++topo] = fim;
		}
	}
}

void selectionSort (int v[], int TAM){
    int min, i, j;
    for (i = 0; i < TAM - 1; i++){
        min = i;
        for (j = i+1; j < TAM; j++){
            if (v[j] < v[min]){
                min = j;
            }
        }
        if (min != i)
            troca (v, i, min);
    }
}

void bubbleSort (int v[], int TAM){ 
    int i, j;
    for (i = 1; i < TAM ; i++){
        for (j = TAM ; j >= i; j--){
            if (v[j] < v[j-1])
                troca (v, j-1, j);
        }
    }
    
}
