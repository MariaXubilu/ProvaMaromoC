//Faça um programa em C que:
//a) Leia um vetor com N elementos, formado por valores do tipo inteiro.
//b) Após a leitura, modifique o vetor de forma que o mesmo contenha na parte superior somente valores pares, e na
//parte inferior os valores impares.

#include <stdio.h>
//confesso que esse eu fiz no chat gpt e nem eu entendi o resultado, mas funciona que é uma beleza.
int main() {
    int N;

    printf("Digite o número de elementos do vetor: ");
    scanf("%d", &N);

    int vetor[N];

    //Preenche o vetor com os valores
    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    //Separa os valores pares na parte superior e os ímpares na parte inferior
    int i = 0, j = N - 1;
    while (i < j) {

        //Encontra o próximo valor ímpar a partir do início do vetor
        while (i < N && vetor[i] % 2 == 0) {
            i++;
        }

        //Encontra o próximo valor par a partir do final do vetor
        while (j >= 0 && vetor[j] % 2 != 0) {
            j--;
        }

        //Troca os valores ímpar e par encontrados
        if (i < j) {
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++;
            j--;
        }
    }
    //Imprime o vetor modificado
    printf("Vetor modificado:\n");
    for (int k = 0; k < N; k++) {
        printf("%d ", vetor[k]);
    }
    printf("\n");

    return 0;
}