//SOMA DE MATRIZES
//Peça ao usuário para inserir os elementos de duas matrizes 3x3; Calcule a Matriz resultante da soma das duas matrizes e exiba-a.
#include <stdio.h>
#include <string.h>
int main() {
    int matriz1 [3][3];
    int matriz2 [3][3];
    int somatoria1 = 0;
    int somatoria2 = 0;

//dois vetores básicos para guardar os valores da primeira matriz, depois esse valor bruto vai ser jogado para a variável 'somatória1'.
    for(int a = 0; a < 3; a++){
    for(int b = 0; b < 3; b++){

    printf("Digite o valor da linha %d, e da coluna %d da primeira matriz: ", a + 1, b + 1);
    scanf("%d", &matriz1[a][b]);
        somatoria1 += matriz1[a][b];
    }
}
    printf("\n ");

//dois vetores básicos para guardar os valores da segunda matriz, depois esse valor bruto vai ser jogado para a variável 'somatória2'.
    for(int c = 0; c < 3; c++){
    for(int d = 0; d < 3; d++){
    
    printf("Digite o valor da linha %d, e da coluna %d da segunda matriz: ", c + 1, d + 1);
    scanf("%d", &matriz2[c][d]);
        somatoria2 += matriz2[c][d];
}
}
//essa sintaxe de criança de 5 anos caiu como uma luva, antes eu tava tentando cruzar 4 vetores mas a sintaxe ficou muito complexa.
    printf("O Resultado da somatoria de todos os valores dessas duas matrizes é: %d", somatoria1 + somatoria2);
    return 0;
}