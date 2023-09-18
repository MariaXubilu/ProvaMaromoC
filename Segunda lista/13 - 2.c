//Dado uma variável string com um conteúdo qualquer, imprimir o número de caracteres ‘a’ encontrados na mesma.
#include <stdio.h>
#include <string.h>

//aqui também preferi por fazer uma função ao invés de colocar tudo no main, tentei colocar antes mas ficou parecendo uma sopinha de letras.
int contarCaracterA(const char *str) {
    int contador = 0;
    int comprimento = strlen(str);

//vetor para contar a quantidade de caracteres a numa string, se o valor armazenado na string tiver 'a' o contador sobe um.
    for (int i = 0; i < comprimento; i++) {
        if (str[i] == 'a' || str[i] == 'A') {
            contador++;
        }
    }

    return contador;
}

int main() {
    char minhaString[100]; 

    printf("Digite uma string: ");
    fgets(minhaString, sizeof(minhaString), stdin);

//aqui a função é puxada de fora do main.
    int numA = contarCaracterA(minhaString);

    printf("Numero de caracteres 'a' encontrados: %d\n", numA);

    return 0;
}