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

int pontuacao (int v[], int w[], int tam, int *comp){
    int pontos, i = 0;
    pontos = 0;
    while (i < 4){
        if (pesqBinaria(v, w[i], tam, comp)){
            pontos++;
        }
        i++;
    }
    return pontos;
}


int main() {
    int w[4];
    int  max, N, moeda; /* variaveis de entrada */
    int comp[6]; /* variaveis de comparacao */ 

    for (int i = 0; i < 6; i++){
        comp[i] = 0;
    }
    
    /* variavel de controle para saber se a pessoa ainda quer jogar */
    moeda = 1;
    while (moeda == 1){
        /* atualizacao da seed da funcao aleatoria para sempre gerar um vetor aleatorio novo */
        srand(time(0));
        printf ("Bem vindo a Mega Quadra! Aqui você pode dar 4 palpites e talvez sair vitorioso, mas sera que voce consegue? Para poder jogar primeiro insira o tamanho do vetor: ");
        
        scanf ("%d", &N);
        /* so aceita valores de tamanho */
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


        printf ("\nVetor a ser ordenado: ");
        imprimeVetor (vet, N);

        copiaVetor(vet, vetOrdenar, N);
        selectionSort (vetOrdenar, N, comp);
        
        copiaVetor(vet, vetOrdenar, N);
        bubbleSort (vetOrdenar, N-1, comp);
        
            printf("ponteiro de comp[0] %p", &comp[0]);
    printf("ponteiro de comp[2] %p", &comp[2]);

        copiaVetor(vet, vetOrdenar, N);
        quickSort(vetOrdenar, 0, N-1, comp);

        copiaVetor(vet, vetOrdenar, N);
        /*quickSortIterativo(vetOrdenar, 0, N-1, comp); */
        
        printf ("\nVetor ordenado: ");
        imprimeVetor (vetOrdenar, N);

        pesqSequencial(vetOrdenar, max, N, comp);
        pesqBinaria(vetOrdenar, max, N, comp); 

/* numero de comparacoes feita entre elementos do vetor */
        printf ("\nNumero de comparacoes Selection Sort: %d", comp[0]);
        printf ("\nNumero de comparacoes Bubble Sort: %d", comp[1]);
        printf ("\nNumero de comparacoes Quick Sort Recursivo: %d", comp[2]);
        printf ("\nNumero de comparacoes Quick Sort Iterativo: %d", comp[3]); 
        printf ("\nNumero de comparacoes Pesquisa Sequencial: %d", comp[4]);
        printf ("\nNumero de comparacoes Pesquisa Binaria: %d", comp[5]);
        
        

        if (pontuacao (vetOrdenar, w, N, comp) == 4)
            printf ("\nparabens voce venceu o jogo, numero de acertos %d!", pontuacao(vetOrdenar, w, N, comp));
        else
            printf ("\nNao foi dessa vez :( . Numero de acertos: %d", pontuacao(vetOrdenar, w, N, comp)); 

        free (vet);
        free (vetOrdenar);

        printf ("\n\nVoce quer continuar jogando? 1 se sim, qualquer outro numero se nao.");
        scanf("%d", &moeda);
    }
    return 0;
}