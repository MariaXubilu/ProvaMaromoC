//Para cada nota de compra, tem-se o Nome do produto comprado, o valor e o imposto. Faça um programa
//em C que escreva o valor total bruto, o imposto total cobrado e o valor total líquido de todas as notas. Considere
//500 notas 
#include <stdio.h>
int main(){
    int total = 500;
    double valorTotal = 0.0;
    double valorBruto = 0.0;
    double impostoBruto = 0.0;

//vetor para armazenar todos os valores dos 500 produtos.
    for(int i; i <= total; i++){
        char nome[100];
        double valorNota, impostoNota;

        printf("Nota %d:\n", i);
        printf("Nome do produto: ");
        scanf("%s", nome);
        printf("Valor da nota: ");
        scanf("%lf", &valorNota);
        printf("Imposto da nota: ");
        scanf("%lf", &impostoNota);

        valorTotal += valorNota;
        impostoBruto += impostoNota;
        valorTotal += (valorNota - impostoNota);
    }
    printf("\nResumo das notas:\n");
    printf("Valor total bruto: %.2lf\n", valorTotal);
    printf("Imposto total cobrado: %.2lf\n", impostoBruto);
    printf("Valor total liquido: %.2lf\n", valorBruto);

//o professor não pediu um jeito de inserir os valores no vetor :p
return 0;
}