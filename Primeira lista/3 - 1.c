//PRIMEIRA OCORRÊNCIA DE UM CARACTERE
//Peça ao usuário para inserir uma string e um caractere; Use strchr para encontrar a primeira ocorrência do caractere na string e
//informe a posição ao usuário.
#include <stdio.h>
#include <string.h>

//novamente o básico, a unica diferença é que a variável que vai dar segmento para a função strchr precisa ser um ponteiro
//então é só adicionar um '*' antes do nome e tudo certo.
int main(){
char string[100], caractere, *posicao;

printf("Digite uma frase: \n");
//fgets lê o que o usuário digita e armazena na variável dentro do parenteses, parecido com scanf.
//sizeof obtem o tamanho da variável em bytes, é importante pra não ocorrer overflow e inutilizar o programa.
//stdin é um caractere especial que indica que o sistema de entrada (ou leitura) deve ser o padrão, no caso, o teclado.
fgets(string, sizeof(string), stdin);

printf("Agora me fala um caractere presente nessa frase que: \n");
scanf(" %c", &caractere);

//o ponteiro 'posicao' recebe o resultado de strchr.
//strchr é usado para encontrar o primeiro caractere em uma string.
posicao = strchr(string, caractere);

//se a variável 'posicao' NÃO estiver vazia, uma variável int será criada, cuja função é numerar a posição do caractere digitado.
//a função int subtrai o valor da 'string' do valor indicado na 'posicao', gerando um valor numérico que corresponde a posição do
//caractere na frase, no entanto esse valor acaba vindo com uma subtração de 1, imagino eu por causa do caractere '\0' que é usado para
//sinalizar o fim da string e que é colocado automaticamente depois do usuário digitar a frase e que não é contado, por isso o (indice + 1).
if (posicao !=  NULL) {
    int indice = posicao - string;
    printf("O caractere '%c' fica na posicao: %d \n", caractere, (indice + 1));
} else{
    printf(" '%c' nao foi encontrado na frase \n", caractere);
}

return 0;
}
