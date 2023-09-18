//PRODUTO ESCALAR DE DOIS VETORES
//Peça ao usuário para inserir os elementos de dois vetores de tamanhos 5; Calcule o produto escalar dos dois vetores.
#include <stdio.h>
#include <string.h>
//escalagem significa multiplicação.
int main(){
    int vetor1 [5];
    int vetor2 [5];
    int escalagem = 0;

//vetorzinho básico para armazenar os 5 primeiros valores.
printf("Digite os Valores de um vetor com 5 espacos: \n");
for (int i = 0; i < 5; i++) {
        printf("Posição %d: ", i + 1);
        scanf("%d", &vetor1[i]);
    }
//vetorzinho básico para armazenar os outros 5 valores com outra variável.
printf("Digite o Valor de um outro vetor com 5 espacos: \n");
    for (int j = 0; j < 5; j++) {
        printf("Posição %d: ", j + 1);
        scanf("%d", &vetor2[j]);
    }
//os vetores se cruzam em uma matriz que não é mostrada, apenas evocada para ser escalada. A Variável escalagem recebe a multiplicação dos
//dois vetores.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
        escalagem += vetor1[i] * vetor2[j];
    }
    }

    printf("O produto escalar dos vetores é: %d\n\n", escalagem);

    return 0;
}