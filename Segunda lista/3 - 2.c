//3) Faça um programa em C para gerar os termos da seguinte P.G.: 3,9,27,81,…,calcule o 100º termo
#include <stdio.h>

int main(){

//o problema aqui é que uma PG de 3 que vai até o 100º número não pode ser armazenada em nenhuma variável da biblioteca padrão de c.
long long int termoA = 3;
int razao = 3;
int cont = 1;

    do
    {
        printf("Termo %d: %lld\n", cont, termoA);
        termoA *= razao;
        cont++;
    } while (cont <= 100);
    
printf("O quarto termo de uma pg de 3 eh: %lld\n", termoA);
//o numero continua sendo muito grande, mas apenas com uma biblioteca e sintaxes específicas como GMP poderíamos imprimir um valor tão alto.
return 0;
}