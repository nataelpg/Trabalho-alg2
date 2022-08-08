#include<stdio.h>   
#include<stdlib.h>  
#include<time.h>

#include "vetor.h"
#include "ordenacao.h"
#include "pesquisa.h"

void leApostas (int w[], int maxVal){
    int i = 0;
    while (i < 4){
        scanf("%d", &w[i]);
        if (w[i] > maxVal)  
            printf ("valor maior que o maximo, tente outro");
        else
            i++;      
    }
    for (i = 0; i < 4; i++){
        printf ("Aposta %d: %d\n", i+1, w[i]);
    }
}

int pontuacao (int v[], int w[], int tam){
    int pontos, i = 0;
    pontos = 0;
    while (i < 4){
        if (pesqBinaria(v, w[i], tam)){
            pontos++;
        }
        i++;
    }
    return pontos;
}

int main() {
    int w[4];
    int  n1, n2, n3, n4, max, N, moeda; /* variaveis de entrada */
    int c1, c2, c3, c4, c5, c6; /* variaveis de comparacao */ 
    
    /* atualizacao da seed da funcao aleatoria para sempre gerar um vetor aleatorio novo */
    moeda = 1;
    while (moeda == 1){
        srand(time(0));
        printf ("Bem vindo a Mega Quadra! Aqui você pode dar 4 palpites e sair vitorioso, mas sera que voce consegue? Para poder jogar primeiro insira o tamanho do vetor: ");
        
        scanf ("%d", &N);
        while (N < 4){
            printf ("\ntamanho invalido insira outro: ");
            scanf("%d", &N);
        }

        printf ("Agora o valor maximo dos elementos: ");
        scanf("%d", &max);

        int* vet = malloc(N*sizeof(int));
        int* vetOrdenar = malloc(N*sizeof(int));
        

        printf ("Por fim as suas apostas: ");

        leApostas (w, max);

        preencheVetor(vet, N, max);

        if (!vet) {
            printf ("impossivel alocar memoria"); 
            
            return 1;
        }

        c1 = 0; c2 = 0; c3 = 0; c4 = 0; c5 = 0; c6 = 0;

        copiaVetor(vet, vetOrdenar, N);
        printf("\nOrdenando com Selection Sort ");
        selectionSort (vetOrdenar, N);
        imprimeVetor(vetOrdenar, N);

        copiaVetor(vet, vetOrdenar, N);
        printf("\nOrdenando com Bubble Sort ");
        bubbleSort (vetOrdenar, N-1);
        imprimeVetor(vetOrdenar, N);

        copiaVetor(vet, vetOrdenar, N);
        printf("\nOrdenando com Quick Sort Recursivo ");
        quickSort(vetOrdenar, 0, N-1);
        imprimeVetor(vetOrdenar, N);

        copiaVetor(vet, vetOrdenar, N);
        printf("\nOrdenando com Quick Sort Iterativo ");
        quickSortIterativo(vetOrdenar, 0, N - 1);
        imprimeVetor(vetOrdenar, N);

        pesqSequencial(vetOrdenar, max, N);
        pesqBinaria(vetOrdenar, max, N); 

        if (pontuacao (vetOrdenar, w, N) == 4)
            printf ("\nparabens voce venceu o jogo, numero de acertos %d!", pontuacao(vetOrdenar, w, N));
        else
            printf ("\nnao foi dessa vez :(, numero de acertos %d", pontuacao(vetOrdenar, w, N)); 

        free (vet);
        free (vetOrdenar);

        printf ("\n\nVoce quer continuar jogando? 1 para sim, qualquer outro numero para nao.");
        scanf("%d", &moeda);
    }
    return 0;
}