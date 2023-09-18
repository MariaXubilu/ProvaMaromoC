//Faça um programa que receba, por parâmetro, um valor inteiro (deve ser positivo. Valide-o). Ao final
//retorne a quantidade de não divisores exatos desse valor.
//Exemplo: para o valor 9. Os divisores não exatos 2,4,5,6,7,8. Resposta do programa deve ser a quantidade, ou seja,
//neste caso: 6.

#include <stdio.h>
//aqui ja começa a putaria, eu preferi por fazer uma função fora do main pra que ficasse melhor de compreender, mas isso não vai cair nessa
//prova de agora, é só escrever a sintaxe de um jeito levemente diferente e jogar pro main que faz a msm coisa.
int contarNaoDivisoresExatos(int valor) {
    int naoDivisores = 0;

    if (valor <= 0) {
        printf("Por favor, insira um valor inteiro positivo.\n");
        return -1; 
    }

    for (int i = 2; i < valor; i++) {
        if (valor % i != 0) {
            naoDivisores++;
        }
    }

    return naoDivisores;
}

int main() {
    int valor;

    printf("Digite um valor inteiro positivo: ");
    scanf("%d", &valor);

    int resultado = contarNaoDivisoresExatos(valor);

    if (resultado >= 0) {
        printf("A quantidade de não divisores exatos de %d é: %d\n", valor, resultado);
    }

    return 0;
}