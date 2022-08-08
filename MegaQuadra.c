#include<stdio.h>   
#include<stdlib.h>  
#include<time.h>

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


    /* recebe um valor maximo e preenche o vetor com elementos de valor menor ou igual do valor maximo */
void preencheVetor (int vet[], int tam, int maxVal) {
    for (int i =0; i < tam; i++)
        vet[i] =rand()%maxVal+1;
}

    /* imprime todos os elementos de um vetor qualquer */
void imprimeVetor(int v[], int TAM){
    int i;
    for (i = 0; i < TAM; i++){
        printf("%d ", v[i]);
    }
}

/* copia o vetor original para um a ser ordenado */
void copiaVetor (int vetFonte[], int vetDestino[], int TAM) {
    for (int i = 0; i < TAM; i++)
        vetDestino[i] = vetFonte[i];
}

void troca (int v[], int a, int b){
    int aux = v[b];
    v[b] = v[a];
    v[a] = aux;
}

/* compara tres elementos de um vetor, um do começo, meio e fim, e tira a mediana entre eles */
void pivoMediana (int v[], int ini, int fim){
	int m = (ini + fim)/2;
	int medIndice = 0;
	
	if (v[ini] < v[m])
		if (v[m] < v[fim])
            //ini < meio e meio < fim 
			medIndice = m;
		else
			if (v[ini] < v[fim])
            //ini < fim e fim <= meio
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

/* coloca o pivo na posicao certa e deixa elementos menores que o pivo a sua esquerda e maiores a sua direita */
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

int pesqSequencial(int v[], int x, int n){
    int i = 0;
    while (v[i] != x && i < n){
        i++;
    }

    if (v[i] == x)
        return 1;
    return 0;
}

int pesqBinaria (int v[], int x, int n){
    int inicio = 0;
    int fim = n;

    while(inicio <= fim) {
        int meio = ((inicio + fim) / 2);

        if(x == v[meio])
            /* elemento foi encontrado */
            return 1;
        if(x < v[meio]) 
            /* elemento esta na esquerda do meio */
            fim = meio - 1;
        else if(x > v[meio])
            /* elemento esta na direita do meio */
            inicio = meio + 1;
    }

    return 0;
}

/* compara os elementos com base em um pivo */
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

/* percorre o vetor e a cada iteracao verifica o minimo */
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

/* compara elemento por elemento do vetor e vai fazendo trocas ate o elemento chegar na posicao certa */
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