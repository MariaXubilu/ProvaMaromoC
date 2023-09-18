//Crie um vetor de 10 inteiros, use a função rand para gerar valores entre 1 e 100 para cada posição. Ao final,
//mostre na tela quantos são pares, e a soma dos ímpares
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
//Gera uma seed (a mesma do minecraft) para a função rand().
    srand(time(NULL));

    int vetor[10];
    int numPares = 0;
    int somaImpares = 0;

//Preenche o vetor com valores aleatórios entre 1 e 100.
    for (int i = 0; i < 10; i++) {
        vetor[i] = rand() % 100 + 1;
    }

//Conta os pares e calcula a soma dos ímpares.
    for (int i = 0; i < 10; i++) {
        if (vetor[i] % 2 == 0) {
            numPares++;
        } else {
            somaImpares += vetor[i];
        }
    }

//Mostra os resultados.
    printf("Valores do vetor:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Quantidade de números pares: %d\n", numPares);
    printf("Soma dos números ímpares: %d\n", somaImpares);

    return 0;
}