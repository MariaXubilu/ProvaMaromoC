#include <stdio.h>
#include <string.h>
#include "hotel.h"
#include "hotel.c"


/** Função principal que gerencia o sistema de reservas do hotel.
 * Utiliza um menu de opções para interação com o usuário e chamadas às funções do sistema.
 * @return 0 ao finalizar o programa. */
int main() {
    /** Declaração da matriz de reservas e variáveis de controle.
     * Cada reserva é representada pela estrutura Reserva. */
    Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR];
    int totalReservas = 0; /** Contador do total de reservas */
    int opcao; /** Opção escolhida pelo usuário no menu */

    /** Criação da pasta "Saves" para armazenar os arquivos de reserva.
     * Garante que a pasta exista para evitar erros ao exportar ou importar reservas. */
    criarPastaSaves();

    /** Inicialização do hotel, atribuindo números aos quartos e marcando-os como livres.
     * Cada quarto é inicializado com as informações padrão de uma reserva vazia. */
    inicializarHotel(hotel); 

    /** Menu principal */
    do {
        printf("\nMenu:\n");
        printf("1. Fazer Reserva\n");
        printf("2. Realizar Check-In\n");
        printf("3. Realizar Check-Out\n");
        printf("4. Visualizar Reservas\n");
        printf("5. Bloquear Quarto\n");
        printf("6. Desbloquear Quarto\n");
        printf("7. Exportar Reservas\n");
        printf("8. Importar Reservas\n");
        printf("0. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        /** Execução da opção escolhida */
        switch (opcao) {
            case 1:
                fazerReserva(hotel, &totalReservas);
                break;
            case 2:
                realizarCheckIn(hotel);
                break;
            case 3:
                realizarCheckOut(hotel);
                break;
            case 4:
                visualizarReservas(hotel, totalReservas);
                break;
            case 5:
                bloquearQuarto(hotel);
                break;
            case 6:
                desbloquearQuarto(hotel);
                break;
            case 7:
                exportarReservas(hotel);
                break;
            case 8:
                importarReservas(hotel, &totalReservas);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
