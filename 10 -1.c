//ORDENAÇÃO DE STRINGS EM UM VETOR
//Peça ao usuário para inserir 5 strings; Armazene-as em um vetor; Ordene o vetor alfabeticamente e exiba as strings ordenadas.
#include <stdio.h>
#include <string.h>

int main() {
    char strings[5][100];
    printf("Digite 5 strings:\n");
//vetorzinho básico pra armazenar as 5 strings.
    for (int i = 0; i < 5; i++) {
        printf("String %d: ", i + 1);
        fgets(strings[i], sizeof(strings[i]), stdin);
    }

//vetorzinho pra colocar as strings em ordem alfabética, strcmp vai percorrer todos os caracteres das duas strings, strcpy vai copiar
//os valores armazenados na primeira string para uma variável temporária, depois a primeira string recebe a segunda, e a temporária recebe
//a segunda string, fazendo com que a primeira string fique ordenada alfabeticamente.
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(strings[i], strings[j]) > 0) {
                char temp[100];
                strcpy(temp, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }

//Exibe as strings ordenadas alfabeticamente.
    printf("\nStrings ordenadas alfabeticamente:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}