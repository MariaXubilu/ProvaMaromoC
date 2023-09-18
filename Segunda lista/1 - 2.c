//Faça um programa em C para ler base e altura de 50 triângulos e imprimir a sua área. Sabe-se que a fórmula
//para obter a área é: AREA = (BASE * ALTURA) / 2.
#include <stdio.h>

int main(){
int triangulos = 50;
int altura = 0;
int base = 0;

//vetor para contabilizar e armazenar os valores dos 50 triangulos
for(int i = 1; i <= 50; i++){
printf("Triangulo n° %d: \n", triangulos);

printf("Digite a base: ");
scanf("%d", &base);
printf("Digite a altura: ");
scanf("%d", &altura);

//formula para calculo da area
float areaT = (base * altura) / 2;

printf("Essa eh a area do %d triangulo: %.2f\n", i, areaT);
}
return 0;
}