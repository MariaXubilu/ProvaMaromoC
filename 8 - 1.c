//VERIFICAÇÃO DE STRING COM APENAS VOGAIS
//Peça ao usuário para inserir uma string; Verifique se a string contém apenas vogais. Use um Loop e a função strchr para isso.
#include <stdio.h>
#include <string.h>
int main() {
    char texto[61];
//a função fflush força a descarga dos valores para a variável.
    fflush(stdin);
    printf("Digite um texto: \n");
    gets(texto);
//vetor que percorre a string inteira (e que tem o tamanho adaptativo), e em caso da string ser APENAS composta por UMA 
//vogal, o programa acusa que a string é formada apenas por vogais.
    for (int i = 0; i < strlen(texto); ++i) {
        switch (texto[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                continue;
            default:
                printf("Nao eh vogal \n");
                return 0;

        }
    }
    printf("Sao vogais \n");
    return 0;
}
//PS: Esse código eu peguei do meu professor, só consegui fazer funcionar de uma maneira diferente dessa vez,
//mas fui incrementar o código e acabei perdendo essa versão funcional, esse foi o único exercício que eu peguei diretamente dele.