//Faça um programa em C para:
//a) Ler um valor x qualquer
//b) Calcular Y = ( x+1)+(x+2)+(x+3)+(x+4)+(x+5)+…(x+100).
#include <stdio.h>

int main(){
    int x = 0;
    int y = 0;

//vetor para calcular a PA
    for(int i = 1; i <= 100; i++){
        printf("Digite um valor X: ");
        scanf("%d", &x);
        do
        {
            y += (x+i);
            i++;
        } while (i <= 100);
        printf("O valor de y eh: %d", y);
    }
    //levando em conta que uma PA de 100 valores que se soma em 1 tem o resultado de 5050, o código está certo;
    return 0;
}