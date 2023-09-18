#include <stdio.h>
#include <gmp.h>

int main() {
    mpz_t termoAtual; // Declara uma variável GMP para armazenar o termo atual
    mpz_init(termoAtual); // Inicializa a variável GMP

    mpz_set_ui(termoAtual, 3); // Define o valor inicial do primeiro termo da P.G.
    mpz_t razao;
    mpz_init(razao);
    mpz_set_ui(razao, 3); // Define o valor da razão da P.G.

    int contador = 1; // Contador para rastrear o termo atual

    do {
        printf("Termo %d: ", contador);
        mpz_out_str(stdout, 10, termoAtual); // Imprime o termo atual

        // Calcula o próximo termo da P.G. multiplicando o termo atual pela razão
        mpz_mul(termoAtual, termoAtual, razao);
        contador++;

        printf("\n");
    } while (contador <= 100); // Vai até o 100º termo

    // Libera a memória alocada pela variável GMP
    mpz_clear(termoAtual);
    mpz_clear(razao);

    return 0;
}