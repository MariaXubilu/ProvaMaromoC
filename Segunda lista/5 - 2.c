//Faça um programa em C para somar os restos da divisão por 3 de 200 números.
#include <stdio.h>

int main() {
    int numeros = 200;
    int vetor[numeros];
    int soma_restos = 0;

//a variável está inserida na string pois eu estava fazendo um teste anterior com uma amostragem menor de números
    printf("Digite os %d números:\n", numeros);
    
//vetor para escanear todos os números e armazená-los na variável vetor, contador i.
//soma restos recebe o valor do resto da divisão por 3 dos valores armazenados na variável vetor.
    for (int i = 0; i < numeros; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
        soma_restos += vetor[i] % 3;
    }

    printf("A soma dos restos da divisao por 3 dos %d numeros é: %d\n", numeros, soma_restos);

    return 0;
}
