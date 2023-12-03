#ifndef HOTEL_H
#define HOTEL_H

#define NUM_ANDARES 5
#define NUM_QUARTOS_POR_ANDAR 10
#define MAX_NOME_HOSPEDE 100
#define MAX_NOME_ARQUIVO 100

/** Estrutura que representa uma reserva em um quarto do hotel.
 * Contém informações como número do quarto, nome do hóspede, status de ocupação e dias reservados. */
typedef struct {
    int numeroQuarto;
    char hospede[MAX_NOME_HOSPEDE];
    int ocupado; /**0 para livre, 1 para ocupado, 2 para bloqueado */
    int diasReservados;
} Reserva;

/** Função para realizar uma reserva em um quarto específico do hotel.
 * @param hotel Matriz que representa os quartos do hotel.
 * @param totalReservas Ponteiro para a variável que armazena o total de reservas feitas. */
void fazerReserva(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR], int* totalReservas);

/** Função para realizar o check-in de um hóspede em um quarto específico do hotel.
 * @param hotel Matriz que representa os quartos do hotel. */
void realizarCheckIn(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR]);

/** Função para realizar o check-out de um hóspede de um quarto específico do hotel.
 * @param hotel Matriz que representa os quartos do hotel. */
void realizarCheckOut(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR]);

/** Função para visualizar a lista de reservas, indicando o status de ocupação de cada quarto.
 * @param hotel Matriz que representa os quartos do hotel. @param totalReservas Total de reservas feitas. */
void visualizarReservas(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR], int totalReservas);

/** Função para bloquear um quarto específico do hotel, impedindo futuras reservas ou check-ins.
 * @param hotel Matriz que representa os quartos do hotel. */
void bloquearQuarto(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR]);

/** Função para desbloquear um quarto específico do hotel, permitindo futuras reservas ou check-ins. 
 * @param hotel Matriz que representa os quartos do hotel. */
void desbloquearQuarto(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR]);

#endif // HOTEL_H
