#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"
#include "pesquisa.h"
#include "vetor.h"

void leApostas(int w[], int maxVal) {
    int i = 1;
    int aux;
    scanf("%d", &w[0]);
    aux = w[0];

    while(i < 4) {
        scanf("%d", &w[i]);
        if(w[i] == aux) {
            printf("Valor já inserido, tente outro");
        } else if(w[i] > maxVal)
            printf("valor maior que o maximo, tente outro");
        else {
            aux = w[i];
            i++;
        }

        printf("\n");
    }
    for(i = 0; i < 4; i++) {
        printf("Aposta %d: %d\n", i + 1, w[i]);
    }
}

int pontuacao(int v[], int w[], int tam, int* comp) {
    int pontos, i = 0;
    pontos = 0;
    while(i <= 3) {
        pesqSequencial(v, w[i], tam, comp);
        if(pesqBinaria(v, w[i], tam, comp)) {
            pontos++;
        }
        i++;
    }
    return pontos;
}

int main() {
    int w[4];
    int max, N, moeda; /* variaveis de entrada */
    int comp[6];       /* variaveis de comparacao */
    int pontos;

    /* variavel de controle para saber se a pessoa ainda quer jogar */
    moeda = 1;
    while(moeda == 1) {
        for(int i = 0; i < 6; i++) {
            comp[i] = 0;
        }

        /* atualizacao da seed da funcao aleatoria para sempre gerar um vetor aleatorio novo */
        srand(time(0));
        printf("Bem vindo a Mega Quadra!\nAqui você pode dar 4 palpites e talvez sair vitorioso... mas sera que voce consegue?\nPara poder jogar primeiro insira o tamanho do vetor: ");

        scanf("%d", &N);
        /* so aceita valores de tamanho */
        while(N < 4) {
            printf("\ntamanho invalido insira outro: ");
            scanf("%d", &N);
        }

        printf("\nAgora o valor maximo dos elementos: ");
        printf("\nLendo elementos");
        scanf("%d", &max);

        int* vet = malloc(N * sizeof(int));
        int* vetOrdenar = malloc(N * sizeof(int));

        printf("Por fim as suas apostas: ");
        leApostas(w, max);

        preencheVetor(vet, N, max);

        if(!vet) {
            printf("impossivel alocar memoria\n");

            return 1;
        }

        printf("\nVetor a ser ordenado: ");
        imprimeVetor(vet, N);

        printf("\n\nRealizando ordenacao selectionSort...");
        copiaVetor(vet, vetOrdenar, N);
        selectionSort(vetOrdenar, N, comp);

        printf("\n\nRealizando ordenacao com bubbleSort...");
        copiaVetor(vet, vetOrdenar, N);
        bubbleSort(vetOrdenar, N - 1, comp);

        printf("\n\nRealizando ordenacao com quickSort recursivo...");
        copiaVetor(vet, vetOrdenar, N);
        quickSort(vetOrdenar, 0, N - 1, comp);

        printf("\n\nRealizando ordenacao com quickSort iterativo...");
        copiaVetor(vet, vetOrdenar, N);
        quickSortIterativo(vetOrdenar, 0, N - 1, comp);

        printf("\n\nVetor ordenado: ");
        imprimeVetor(vetOrdenar, N);

        printf("\n\nRealizando pesquisa sequencial e binária...\n\n");
        pontos = pontuacao(vetOrdenar, w, N, comp);

        if(pontos == 4)
            printf("\nParabens voce venceu o jogo, numero de acertos %d!", pontos);
        else
            printf("\nNao foi dessa vez :( . Numero de acertos: %d", pontos);

        /* numero de comparacoes feita entre elementos do vetor */
        printf("\nNumero de comparacoes Selection Sort: %d", comp[0]);
        printf("\nNumero de comparacoes Bubble Sort: %d", comp[1]);
        printf("\nNumero de comparacoes Quick Sort Recursivo: %d", comp[2]);
        printf("\nNumero de comparacoes Quick Sort Iterativo: %d", comp[3]);
        printf("\nNumero de comparacoes Pesquisa Sequencial: %d", comp[4]);
        printf("\nNumero de comparacoes Pesquisa Binaria: %d", comp[5]);

        free(vet);
        free(vetOrdenar);

        printf("\n\nVoce quer continuar jogando? 1 se sim, qualquer outro numero se nao.");
        scanf("%d", &moeda);
    }
    return 0;
}