#include<stdio.h>   
#include<stdlib.h>  
#include<time.h>

void preencheVetor (int vet[], int tam, int maxVal) {
    for (int i =0; i < tam; i++)
        vet[i] =rand()%maxVal;
}

void copiaVetor (int vetFonte[], int vetDestino[], int TAM) {
    for (int i = 0; i < TAM; i++)
        vetDestino[i] = vetFonte[i];
}

int main() {
    int n1, n2, n3, n4;
    int* vet = malloc(N*sizeof(int));
    int* vetOrdenar = malloc(N*sizeof(int));
    if (!vet) {
        printf ("impossivel alocar memoria");

        return 1;
    }
    srand(time(0));

    copiaVetor (vet, vetOrdenar, N);
    imprimeVetor (vet, vetOrdenar, N);
    printf ("digite suas apostas");
    scanf ("%d, %d, %d, %d", &n1, &n2, &n3, &n4);

    free (vet);
}