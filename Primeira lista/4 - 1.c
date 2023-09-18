//COMPRIMENTO TOTAL DAS STRINGS EM UM VETOR
//Peça ao usuário para inserir 5 strings; Armazene-as em um vetor e use strlen para calcular o comprimento das strings.
#include <stdio.h>
#include <string.h>

//a unica diferença na criação dessa variável 'strings' é esse [5] que serve para indicar que 5 variáveis de 100 caracteres cada serão
//armazenadas na memoria.
//é importante atribuir o valor 0 para a variável que vai medir a string, pois sem isso um valor aleatório é pego na memória e inutiliza
//completamente o resultado final, na primeira vez que eu rodei o progama o resultado saiu 49675.
int main(){
char strings[5][100];
int Tamanho = 0;

printf("Digite 5 frases separadas por um enter: \n");

//isso daqui é um vetor, a sintaxe dele é complicada a primeira vista, mas o padrão é esse: 
//for(int i=0; i [sinal de marcação] [número de elementos no vetor]; i++).
//esse vetor foi feito para armazenar e colocar na mesa de trabalho as 5 strings digitadas.
//strlen é a abreviação para string lenght, ela mede o tamanho de uma string, mesmo que seja um vetor ou matrix.
//'Tamanho +=' significa que a variável tamanho RECEBE os valores armazenados na função strlen(strings[i]).
for(int i=0; i < 5; i++){
    fgets(strings[i], sizeof (strings[i]), stdin);
Tamanho += strlen(strings[i]);
}
//o -5 aqui serve para que os '/0' das 5 strings sejam subtraídos, visto que mesmo se o usuário não entrasse com nada, o valor final seria 5.
printf("Comprimento total das strings: %d", Tamanho - 5);
return 0;
}