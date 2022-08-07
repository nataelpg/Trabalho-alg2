#include<stdio.h>   
#include<stdlib.h>  
#include<time.h>
#define N 50
void preencheVetor (int vet[], int tam, int maxVal) {
    for (int i =0; i < tam; i++)
        vet[i] =rand()%maxVal;
}

void imprimeVetor(int v[], int TAM){
    int i;
    for (i = 0; i < TAM; i++){
        printf("%d ", v[i]);
    }
}

void copiaVetor (int vetFonte[], int vetDestino[], int TAM) {
    for (int i = 0; i < TAM; i++)
        vetDestino[i] = vetFonte[i];
}

void troca (int v[], int a, int b){
    int aux = v[b];
    v[b] = v[a];
    v[a] = aux;
}

void pivoMediana (int v[], int ini, int fim){
	int m = (ini + fim)/2;
	int medIndice = 0;
	
	if (v[ini] < v[m])
		if (v[m] < v[fim])
            //ini < meio e meio < fim 
			medIndice = m;
		else
            //ini < fim e fim <= meio
			if (v[ini] < v[fim])
				medIndice = fim;
			else
                // fim <= ini e ini < meio
                medIndice = ini;            
    else
        if (v[fim] < v[m])
            // fim < meio e meio <= ini
            medIndice = m;
        else
            if (v[fim] < v[ini])
            // meio <= fim e fim <= ini
                medIndice = fim;
            else
            // meio <= ini e ini <= fim
                medIndice = ini;
    troca(v, medIndice, fim);
}

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
    int i, j;
    for (i = 0; i < TAM - 1; i++){
        int min = i;
        for (j = i+1; j < TAM; j++){
            if (v[j] < v[min]){
                min = j;
            }
        }
        troca (v, i, min);
    }
}

void bubbleSort (int v[], int TAM){ /* nao esquecer de passar n - 1 como parametro e nao n para nao dar erro */
    int i, j;
    for (i = 1; i < TAM ; i++){
        for (j = TAM ; j >= i; j--){
            if (v[j] < v[j-1])
                troca (v, j-1, j);
        }
    }
    
}


int main() {
    int* vet = malloc(N*sizeof(int));
    int* vetOrdenar = malloc(N*sizeof(int));
    int  n1, n2, n3, n4, max;
    
    srand(time(0));
    printf ("Bem vindo à Mega Quadra! Aqui você pode dar 4 palpites e sair vitorioso, mas sera que voce consegue? Por favor, digite primeiro o valor maximo no vetor e depois suas apostas!");
    
    scanf ("%d, %d, %d, %d, %d", &max, &n1, &n2, &n3, &n4);
    preencheVetor(vet, N, max);

    if (!vet) {
        printf ("impossivel alocar memoria"); 
        
        return 1;
    }

    copiaVetor(vet, vetOrdenar, N-1);
    printf("Ordenando com Selection Sort\n");
    selectionSort (vetOrdenar, N-1);
    imprimeVetor(vetOrdenar, N-1);

    copiaVetor(vet, vetOrdenar, N-1);
    printf("Ordenando com Bubble Sort\n");
    bubbleSort (vetOrdenar, N-1);
    imprimeVetor(vetOrdenar, N-1);

    copiaVetor(vet, vetOrdenar, N-1);
    printf("Ordenando com Quick Sort Recursivo\n");
    quickSort(vetOrdenar, 0, N-1);
    imprimeVetor(vetOrdenar, N-1);

    copiaVetor(vet, vetOrdenar, N-1);
    printf("Ordenando com Quick Sort Iterativo\n");
    quickSortIterativo(vetOrdenar, 0, N - 1);
    imprimeVetor(vetOrdenar, N-1);


    free (vet);
    return 0;
}