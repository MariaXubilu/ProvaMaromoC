//PALÍNDROMO COM VETOR E STRINGS
//Peça ao usuário para inserir uma string; verifique se a string é um palíndromo com a função strrev
#include <stdio.h>
#include <string.h>

int main(){
//define duas variáveis para palavras, que são medidas pelos números entre parenteses.
char palavra [20], palavraContra[20];
printf("Digite uma palavra ai: ");

//%s é o jeito que o scan lê variáveis tipo string
scanf("%s", palavra);

//strcpy é a abreviação de string copy, ele copia o valor armazenado na segunda variável para a primeira.
strcpy(palavraContra, palavra);

//strrev é a abreviação de string reverse, ele reverte o que está escrito na string dentro do colchetes.
strrev(palavraContra);

//strcmp é a abreviação de string comparison, ele compara o que está armazenado em duas variáveis dentro do colchetes, se não houver
//mudança entre os valores armazenados, o valor retornado será zero.
if(strcmp(palavra,palavraContra) == 0)
printf("%s essa palavra eh um palindromo", palavra);
else
printf("%s essa palavra nao eh um palindromo", palavra);

return 0;
}