//CONCATENAÇÃO E COMPARAÇÃO DE STRINGS
//Peça ao usuário para inserir duas strings; Use strcat para concatená-las;
//Compare as duas strings originais usando strcmp e informe ao usuário se elas são iguais ou diferentes.
#include <stdio.h>
#include <string.h>

int main() {
    char string1[100];
    char string2[100];
    char resultado[200];

    printf("Digite a primeira string: ");
    fgets(string1, sizeof(string1), stdin);

    printf("Digite a segunda string: ");
    fgets(string2, sizeof(string2), stdin);

//use strcat para concatenar as duas strings, strcpy copia a primeira string para 'resultado,
//strcat concatena a segunda string para 'resultado'.
    strcpy(resultado, string1); 
    strcat(resultado, string2); 

//Compara as duas strings originais usando strcmp, se o resultado for 0 as duas strings são iguais.
    if (strcmp(string1, string2) == 0) {
        printf("As duas strings originais são iguais.\n");
    } else {
        printf("As duas strings originais são diferentes.\n");
    }

    printf("A concatenação das duas strings é: %s\n", resultado);

    return 0;
}