#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// Funções para a inicialização dos vetores
void criarVetorOrdenadoCrescente(long int vet[]);
void criarVetorOrdenadoDecrescente(long int vet[]);
void criarVetorDecrescenteCrescente(long int vet[]);
void criarVetorCrescenteDecrescente(long int vet[]);
void criarVetorDesordenado(long int vet[]);

void imprimirVetor(long int vet[]);

// Método de ordenação Shellsort
void shellSort(long int vet[], int tamanho);

int main() {
	long int vetOrdenadoCrescente[10],
		vetOrdenadoDecrescente[10],
		vetDecrescenteCrescente[10],
		vetCrescenteDecrescente[10],
		vetDesordenado[10];

	// Inicialização dos vetores
	printf("Vetor ordenado crescentemente sem SHELLSORT\n");
	criarVetorOrdenadoCrescente(vetOrdenadoCrescente);
	imprimirVetor(vetOrdenadoCrescente);
	getch();
	printf("Vetor ordenado crescentemente com SHELLSORT\n");
	shellSort(vetOrdenadoCrescente, 10);
	imprimirVetor(vetOrdenadoCrescente);
	getch();
	system("cls");

	printf("\nVetor ordenado decrescentemente sem SHELLSORT\n");
	criarVetorOrdenadoDecrescente(vetOrdenadoDecrescente);
	imprimirVetor(vetOrdenadoDecrescente);
	getch();
	printf("Vetor ordenado decrescentemente com SHELLSORT\n");
	shellSort(vetOrdenadoDecrescente, 10);
	imprimirVetor(vetOrdenadoDecrescente);
	getch();
	system("cls");

	printf("\nVetor ordenado decrescente/crescente sem SHELLSORT\n");
	criarVetorDecrescenteCrescente(vetDecrescenteCrescente);
	imprimirVetor(vetDecrescenteCrescente);
	getch();
	printf("Vetor ordenado decrescente/crescente com SHELLSORT\n");
	shellSort(vetDecrescenteCrescente, 10);
	imprimirVetor(vetDecrescenteCrescente);
	getch();
	system("cls");

	printf("\nVetor ordenado crescente/decrescente sem SHELLSORT\n");
	criarVetorCrescenteDecrescente(vetCrescenteDecrescente);
	imprimirVetor(vetCrescenteDecrescente);
	getch();
	printf("Vetor ordenado crescente/decrescente com SHELLSORT\n");
	shellSort(vetCrescenteDecrescente, 10);
	imprimirVetor(vetCrescenteDecrescente);
	getch();
	system("cls");

	printf("\nVetor desordenado sem SHELLSORT\n");
	criarVetorDesordenado(vetDesordenado);
	imprimirVetor(vetDesordenado);
	getch();
	printf("Vetor desordenado com SHELLSORT\n");
	shellSort(vetDesordenado, 10);
	imprimirVetor(vetDesordenado);

	return 0;
}

void shellSort(long int vet[], int tamanho) {
    long int i, j, valor;
    int h = 1;

    // Cálculo do valor de h(s), onde s representa o taamnho do vetor
    for(h = 1; h < tamanho; h = (3 * h + 1));

    //
    while(h > 1){
    	h /= 3;
    	for(i = h; i < tamanho; i++){
    		valor = vet[i];
    		j = i - h;

    		while(j >= 0 && valor < vet[j]){
    			vet[j + h] = vet[j];
    			j -= h;
			}

			vet[j + h] = valor;
		}
	}
}

// Funções para a inicialização dos vetores
void criarVetorOrdenadoCrescente(long int vet[]){
	for(long int i = 0; i < 10; i++){
		vet[i] = i + 1;
	}
}

void criarVetorOrdenadoDecrescente(long int vet[]){
	for(long int i = 0; i < 10; i++){
		vet[i] = 10 - i;
	}
}

void criarVetorDecrescenteCrescente(long int vet[]){
	for(long int i = 0; i < 5; i++){
		vet[i] = 5 - i;
	}
	for(long int i = 5; i < 10; i++){
		vet[i] = i + 1;
	}
}

void criarVetorCrescenteDecrescente(long int vet[]){
	for(long int i = 0; i < 5; i++){
		vet[i] = i + 1;
		vet[i + 5] = 10 - i;
	}
}

void criarVetorDesordenado(long int vet[]){
	long int i, valor;

	// Garantir que rand() gere um valor aleatória sempre que rodar o programa
	srand((unsigned)time(NULL));

	// Iniciar todas as posições com 0
	for(i = 0; i < 10; i++){
		vet[i] = 0;
	}

	// Adicionar um valor em uma posição aleatória
	for(i = 0; i < 10; i++){

		do{
			valor = rand() % 10;
		}while(vet[valor] != 0);

		vet[valor] = i + 1;
	}
}

void imprimirVetor(long int vet[]){
	for(long int i = 0; i < 10; i++){
		printf("%ldª: %ld\n", i+1, vet[i]);
	}

	printf("\n");
}
