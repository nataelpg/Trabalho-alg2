#include <stdio.h>

int main() {
    int* vetor;
    int chave, i, meio, n, soma, fim, inicio;

    soma = 0;

    printf("Insira o tamanho:\n");
    scanf("%d", &n);
    printf("\n");

    printf("Insira um valor:\n");
    scanf("%d", &chave);
    printf("\n");

    for(i = 0; i < n; i++) {
        soma = soma + 2;
        vetor[i] = soma + 2;
    }

    for(i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    inicio = 0;
    fim = n - 1;

    while(inicio < fim) {
        meio = (((inicio + fim) + 1) / 2);

        if(chave < vetor[meio]) {
            fim = meio;
        } else if(chave > vetor[meio]) {
            inicio = meio + 1;
        }else {
            break;
        }

    }

    if(vetor[meio] == chave) {
        printf("\nindice %d\n\n", meio + 1);
    } else {
        printf("\nnão encontrado\n\n");
    }
}