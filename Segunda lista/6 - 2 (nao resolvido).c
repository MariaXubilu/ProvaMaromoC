//Fazer um programa em C que calcule escreva a soma dos 50 primeiros termos da seguinte série:
// S = 1 - 3 + 5 - 7 + ... - 90   (ou 1/1 - 3/2 + 5/3 - 7/5 ..... - 90/50)
//     1   2   3   5   ...   50
#include <stdio.h>
//não importa a macumba que eu fizesse pra fazer esse caralho dar certo, simplesmente não deu, talvez pelo fato de eu não ter sido ensinado
//sobre o que é uma série em matemática.

int main() {

  int i, n = 4;
  double soma = 0;
  int numerador = 1;
  int denominador = 1;


  for (i = 1; i <= n; i++) {

    soma += (numerador - denominador) / denominador;


    numerador += 2;
    denominador++;
  }

  printf("A soma dos 50 primeiros termos é %.2f\n", soma);

  return 0;
}