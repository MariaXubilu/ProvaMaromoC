//Faça um programa em C para calcular a área de N quadriláteros. Fórmula: Área = Lado * Lado
#include <stdio.h>

int main() {
//de longe o exercício com a sintáxe e lógica mais fáceis dessa lista, literalmente captar os valores digitados dentro das variáveis
//a única diferença é o vetor que está ai para podermos calcular o número variável de quadriláteros.
    int quadrados; 
    printf("Digite o numero de quadrilateros para calcular: ");
    scanf("%d", &quadrados);

    for (int i = 1; i <= quadrados; i++) {
        double lado1;
        double lado2;
        printf("Digite o valor do primeiro lado do quadrilatero %d: ", i);
        scanf("%lf", &lado1);
        printf("Digite o valor do segundo lado do quadrilatero %d: ", i);
        scanf("%lf", &lado2);

        double area = lado1 * lado2;

        printf("Area do quadrilatero %d: %.2lf\n", i, area);
    }

    return 0;
}