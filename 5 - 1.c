//TRANSPOSTA DE UMA MATRIZ
//Peça ao usuário para inserir os elementos de uma matriz 3x3; Mostre a matriz transposta.
#include <stdio.h>
#include <string.h>

int main(){
    int matriz[3][3];
    int i, j;

//uma matriz nada mais é que um vetor 'cruzado' dentro do outro, a estrutura básica é a mesma de um vetor, mas dentro do primeiro vetor,
//geralmente indicado pela variável 'i', outro vetor é criado, geralmente indicado pela variável 'j'.
for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
//como as variáveis vão somando com base no número digitado, e o valor indicado na criação dos vetores é 0, precisamos desse + 1.
    printf("Digite o valor da linha %d, e da coluna %d: ", i + 1, j + 1);
    scanf("%d", &matriz[i][j]);
    }
}
    printf("\n ");

    printf("Matriz Original: \n");
for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
        printf("%d ", matriz[i][j]);
    }
    printf("\n");
}
//praticamente a unica mudança de fato da matriz original pra a matriz transposta é a inversão dos valores 'i' e 'j' no printf.
//não se pode simplesmente dar printf na matriz, é necessário evocar toda a estrutura dela antes, isso é bem chatinho.
printf("Matriz Transposta: \n");
for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
        printf("%d ", matriz[j][i]);
    }
    printf("\n");
}

    return 0;
}