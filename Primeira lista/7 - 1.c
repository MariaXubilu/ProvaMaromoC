//SUBSTITUIÇÃO DE CARACTERES EM UMA STRING
//Peça ao usuário para inserir uma string; Pergunte ao usuário qual caractere ele deseja substituir e por qual outro caractere;
//Realize a substituição e mostre a nova string.
#include <stdio.h>
#include <string.h>

int main(){
    char string[100], caractere1, caractere2;
    
    printf("Digite uma frase ai: \n");
    fgets(string, sizeof(string), stdin);

    printf("Digite um caractere que voce queira substituir: \n");
    scanf(" %c", &caractere1);

    printf("Digite por qual caractere voce quer substituir: \n");
    scanf(" %c", &caractere2);
    
//esse vetor vai percorrer os valores armazenados na string, cada valor igual ao 'caractere1' será substituído com o valor do 'caractere2'.
    for(int i = 0; i < 100; i++){
        if (string[i] == caractere1){
            string[i] = caractere2;
        }
    }

    printf("Aqui está a nova frase: %s\n", string);

    return 0;
}