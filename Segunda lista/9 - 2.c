//Faça um programa em C que leia 10 valores numéricos inteiros. Após a leitura emita um relatório com cada
//valor diferente e o número de vezes que o mesmo apareceu no vetor.

#include <stdio.h>

int main() {
    int tamanho = 10;
    int vetor[tamanho];
    int valoresDiferentes[10]; 
    int contagem[10] = {0}; 
    int numValoresDiferentes = 0; 
    
//Solicita ao usuário inserir 10 valores inteiros.
    printf("Digite 10 valores inteiros:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

//Matriz que verifica e conta os valores diferentes.
    for (int i = 0; i < tamanho; i++) {
        int valorAtual = vetor[i];
        int encontrado = 0;

//Verifica se o valor já foi encontrado antes.
        for (int j = 0; j < numValoresDiferentes; j++) {
            if (valoresDiferentes[j] == valorAtual) {
                encontrado = 1;
                break;
            }
        }

//Se não foi encontrado, adiciona à lista de valores diferentes.
        if (!encontrado) {
            valoresDiferentes[numValoresDiferentes] = valorAtual;
            numValoresDiferentes++;
        }

//Incrementa a contagem para o valor atual.
        contagem[numValoresDiferentes - 1]++;
    }

//Emite o relatório.
    printf("\nRelatorio:\n");
    for (int i = 0; i < numValoresDiferentes; i++) {
        printf("Valor %d apareceu %d veze(s).\n", valoresDiferentes[i], contagem[i]);
    }

    return 0;
}