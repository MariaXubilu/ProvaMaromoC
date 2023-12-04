#include <stdio.h>
#include <string.h>
#include <time.h>
#include "hotel.h"
#include <sys/types.h>
#include <sys/stat.h>
#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN "cls"
#else
#include <unistd.h>
#define CLEAR_SCREEN "clear"
#endif
#define MAX_CAMINHO_ARQUIVO 100

/** Cria a pasta "Saves" caso ela não exista.
 * Verifica se a pasta "Saves" já existe e tenta criá-la se não existir.
 * Utiliza a biblioteca sys/stat.h para verificar a existência da pasta e mkdir para criar.
 * Imprime mensagens indicando o resultado da operação. */
void criarPastaSaves() {
    /** Verifica se a pasta "Saves" já existe */
    struct stat info;
    if (stat("Saves", &info) != 0) {
        /**Se não existe, tenta criar a pasta */
        #ifdef _WIN32
        if (mkdir("Saves") != 0) {
        #else
        if (mkdir("Saves", 0777) != 0) {
        #endif
            printf("Erro ao criar a pasta 'Saves'.\n");
                system ("pause");
    system (CLEAR_SCREEN);
        } else {
            printf("Pasta 'Saves' criada com sucesso.\n");
                system ("pause");
    system (CLEAR_SCREEN);
        }
    } else {
        printf("Pasta 'Saves' esta presente.\n");
    }
}

/** Inicializa o hotel atribuindo números aos quartos e definindo-os como livres.
 * Preenche a estrutura do hotel com quartos numerados, inicialmente livres e sem reservas.
 * Utiliza loops aninhados para percorrer os andares e quartos. */
void inicializarHotel(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR]) {
    int numeroQuarto = 1;  /**< Inicializa o número do primeiro quarto. */

    /**< Loop externo percorre os andares do hotel. */
    for (int andar = 0; andar < NUM_ANDARES; andar++) {
        /**< Loop interno percorre os quartos em cada andar. */
        for (int quarto = 0; quarto < NUM_QUARTOS_POR_ANDAR; quarto++) {
            /**< Atribui o número do quarto e incrementa para o próximo. */
            hotel[andar][quarto].numeroQuarto = numeroQuarto++;
            /**< Inicialmente, todos os quartos estão livres e sem reservas. */
            hotel[andar][quarto].ocupado = 0;
            hotel[andar][quarto].diasReservados = 0;
        }
    }
}


/** Exporta as reservas para um arquivo de texto especificado pelo usuário na pasta 'Saves'.
 * Abre o arquivo especificado pelo usuário em modo de escrita e escreve os dados de reserva.
 * Utiliza loops aninhados para percorrer todos os quartos do hotel. */
void exportarReservas(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR]) {
    FILE *arquivo;  /**< Ponteiro para o arquivo onde as reservas serão exportadas. */
    char nomeArquivo[MAX_NOME_ARQUIVO];  /**< Armazena o nome do arquivo fornecido pelo usuário. */

    /**< Solicita ao usuário o nome do arquivo para exportação. */
    printf("Digite o nome do arquivo para exportar (incluindo a extensao .txt): ");
    scanf("%s", nomeArquivo);

    char caminhoArquivo[MAX_NOME_ARQUIVO + 6]; /** +6 para acomodar "/Saves" e o caractere nulo */
    /**< Constrói o caminho completo para o arquivo, incluindo a pasta 'Saves'. */
    snprintf(caminhoArquivo, sizeof(caminhoArquivo), "Saves/%s", nomeArquivo);

    /**< Abre o arquivo em modo de escrita. */
    arquivo = fopen(caminhoArquivo, "w");

    /**< Verifica se o arquivo foi aberto corretamente. */
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
            system ("pause");
    system (CLEAR_SCREEN);
        return;
    }

    /**< Escreve os dados de reserva no arquivo. */
    for (int i = 0; i < NUM_ANDARES; i++) {
        for (int j = 0; j < NUM_QUARTOS_POR_ANDAR; j++) {
            fprintf(arquivo, "%d;%s;%d;%d\n", hotel[i][j].numeroQuarto, hotel[i][j].hospede,
                    hotel[i][j].ocupado, hotel[i][j].diasReservados);
        }
    }

    /**< Fecha o arquivo após a escrita. */
    fclose(arquivo);

    /**< Informa ao usuário que as reservas foram exportadas com sucesso. */
    printf("Reservas exportadas com sucesso para %s.\n", caminhoArquivo);
        system ("pause");
    system (CLEAR_SCREEN);
}


/** Importa reservas de um arquivo de texto especificado pelo usuário na pasta 'Saves'.
 * Abre o arquivo especificado pelo usuário em modo de leitura e lê os dados de reserva.
 * Limpa as reservas existentes e carrega os dados do arquivo para a estrutura do hotel.
 * Utiliza loops e fscanf para ler os dados formatados do arquivo. */
void importarReservas(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR], int *totalReservas) {
    FILE *arquivo;  /**< Ponteiro para o arquivo de onde as reservas serão importadas. */
    char nomeArquivo[MAX_NOME_ARQUIVO];  /**< Armazena o nome do arquivo fornecido pelo usuário. */

    /**< Solicita ao usuário o nome do arquivo para importação. */
    printf("Digite o nome do arquivo para importar (incluindo a extensao .txt): ");
    scanf("%s", nomeArquivo);

    char caminhoArquivo[MAX_NOME_ARQUIVO + 6]; /** +6 para acomodar "/Saves" e o caractere nulo */
    /**< Constrói o caminho completo para o arquivo, incluindo a pasta 'Saves'. */
    snprintf(caminhoArquivo, sizeof(caminhoArquivo), "Saves/%s", nomeArquivo);

    /**< Abre o arquivo em modo de leitura. */
    arquivo = fopen(caminhoArquivo, "r");

    /**< Verifica se o arquivo foi aberto corretamente. */
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
            system ("pause");
    system (CLEAR_SCREEN);
        return;
    }

    /**< Laço duplo para percorrer todos os quartos do hotel e limpar suas reservas. */
    for (int i = 0; i < NUM_ANDARES; i++) {
        for (int j = 0; j < NUM_QUARTOS_POR_ANDAR; j++) {
            /**< Limpa os dados de reserva para o quarto atual. */
            strcpy(hotel[i][j].hospede, "");
            hotel[i][j].ocupado = 0;
            hotel[i][j].diasReservados = 0;
        }
    }

    /**< Laço para ler os dados do arquivo enquanto não atingir o limite total de reservas. */
    while (*totalReservas < NUM_ANDARES * NUM_QUARTOS_POR_ANDAR &&
           /**< Usa fscanf para ler os dados formatados do arquivo. */
           fscanf(arquivo, "%d;%[^;];%d;%d\n",
                  &hotel[*totalReservas / NUM_QUARTOS_POR_ANDAR]
                        [*totalReservas % NUM_QUARTOS_POR_ANDAR].numeroQuarto,
                  hotel[*totalReservas / NUM_QUARTOS_POR_ANDAR]
                        [*totalReservas % NUM_QUARTOS_POR_ANDAR].hospede,
                  &hotel[*totalReservas / NUM_QUARTOS_POR_ANDAR]
                        [*totalReservas % NUM_QUARTOS_POR_ANDAR].ocupado,
                  &hotel[*totalReservas / NUM_QUARTOS_POR_ANDAR]
                        [*totalReservas % NUM_QUARTOS_POR_ANDAR].diasReservados) == 4) {
        (*totalReservas)++;
    }

    /**< Fecha o arquivo após a leitura. */
    fclose(arquivo);

    /**< Informa ao usuário que as reservas foram importadas com sucesso. */
    printf("Reservas importadas com sucesso de %s.\n", caminhoArquivo);
    system ("pause");
    system (CLEAR_SCREEN);
}


/** Realiza uma reserva em um quarto específico do hotel.
 * Solicita ao usuário o andar e quarto desejados, verifica a disponibilidade e efetua a reserva.
 * São 5 andares com 10 quartos cada, o programa divide isso em uma matriz de 10x5.
 * Utiliza a estrutura Reserva e verifica se o quarto já está ocupado ou bloqueado. */
void fazerReserva(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR], int* totalReservas) {
    /**< Verifica se há espaço disponível para mais reservas. */
    if (*totalReservas < NUM_ANDARES * NUM_QUARTOS_POR_ANDAR) {
        printf("Numero do andar: ");
        int andar;
        scanf("%d", &andar);

        /**< Verifica se o andar fornecido é válido. */
        if (andar < 1 || andar > NUM_ANDARES) {
            printf("Andar invalido. Escolha um andar entre 1 e %d.\n", NUM_ANDARES);
            system ("pause");
            system (CLEAR_SCREEN);
            return;
        }

        printf("Numero do quarto no andar %d: ", andar);
        int quarto;
        scanf("%d", &quarto);

        /**< Verifica se o quarto fornecido é válido. */
        if (quarto < 1 || quarto > NUM_QUARTOS_POR_ANDAR) {
            printf("Quarto invalido. Escolha um quarto entre 1 e %d.\n", NUM_QUARTOS_POR_ANDAR);
            system ("pause");
            system (CLEAR_SCREEN);
            return;
        }

        /**< Obtém um ponteiro para o quarto selecionado. */
        Reserva* quartoSelecionado = &hotel[andar - 1][quarto - 1];

        /**< Define a string do hospede como vazia. */
        quartoSelecionado->hospede[0] = '\0';

        /**< Verifica o status do quarto e toma decisões com base nisso. */
        if (quartoSelecionado->ocupado == 0) {
            printf("Nome do hospede (Escreva tudo junto): ");
            scanf(" %[^\n]", quartoSelecionado->hospede);
            printf("Dias a serem reservados (Em numerais): ");
            scanf("%d", &quartoSelecionado->diasReservados);
            quartoSelecionado->ocupado = 1;
            (*totalReservas)++;
            printf("Reserva efetuada com sucesso!\n");
            system ("pause");
            system (CLEAR_SCREEN);
        } else {
            printf("Quarto ocupado ou bloqueado. Escolha outro quarto.\n");
            system ("pause");
            system (CLEAR_SCREEN);
        }
    } else {
        printf("Numero maximo de reservas atingido. Nao e possivel fazer mais reservas.\n");
        system ("pause");
        system (CLEAR_SCREEN);
    }
}

/** Realiza o check-in de um hóspede em um quarto específico do hotel.
 * Solicita ao usuário o andar e quarto desejados, verifica a disponibilidade e efetua o check-in.
 * Utiliza a estrutura Reserva e verifica se o quarto está ocupado ou bloqueado. */
void realizarCheckIn(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR]) {
    /** Solicita ao usuário o número do andar desejado */
    printf("Digite o numero do andar: ");
    int andar;
    scanf("%d", &andar);

    /** Verifica se o andar fornecido é válido */
    if (andar < 1 || andar > NUM_ANDARES) {
        printf("Andar invalido. Escolha um andar entre 1 e %d.\n", NUM_ANDARES);
            system ("pause");
    system (CLEAR_SCREEN);
        return;
    }

    /** Solicita ao usuário o número do quarto desejado no andar informado */
    printf("Digite o numero do quarto no andar %d: ", andar);
    int quarto;
    scanf("%d", &quarto);

    /** Verifica se o número do quarto fornecido é válido */
    if (quarto < 1 || quarto > NUM_QUARTOS_POR_ANDAR) {
        printf("Quarto invalido. Escolha um quarto entre 1 e %d.\n", NUM_QUARTOS_POR_ANDAR);
            system ("pause");
    system (CLEAR_SCREEN);
        return;
    }

    /** Obtém o ponteiro para o quarto selecionado na matriz de reservas */
    Reserva* quartoSelecionado = &hotel[andar - 1][quarto - 1];

    /** Verifica o estado do quarto */
    if (quartoSelecionado->ocupado == 1) {
        printf("Quarto ja ocupado. Escolha outro quarto.\n");
            system ("pause");
    system (CLEAR_SCREEN);
    } else if (quartoSelecionado->ocupado == 2) {
        printf("Quarto bloqueado. Nao e possível realizar check-in.\n");
            system ("pause");
    system (CLEAR_SCREEN);
    } else {
        /** Solicita e armazena o nome do hóspede */
        printf("Nome do hospede: ");
        scanf(" %[^\n]", quartoSelecionado->hospede);

        /** Solicita e armazena a quantidade de dias de reserva */
        printf("Dias a serem reservados (Em numerais): ");
        scanf("%d", &quartoSelecionado->diasReservados);

        /** Exibe mensagem de check-in bem-sucedido */
        printf("Check-in realizado para o quarto %d no andar %d. Bem-vindo, %s!\n",
            quartoSelecionado->numeroQuarto, andar, quartoSelecionado->hospede);

        /** Marca o quarto como ocupado após o check-in */
        quartoSelecionado->ocupado = 1;
            system ("pause");
    system (CLEAR_SCREEN);
    }
}


/** Realiza o check-out de um hóspede de um quarto específico do hotel.
 * Solicita ao usuário o andar e quarto desejados, verifica se o quarto está ocupado e efetua o check-out.
 * Se o quarto estiver bloqueado, informa ao usuário que não é possível disponibilizá-lo.
 * Utiliza a estrutura Reserva e marca o quarto como livre após o check-out. */
void realizarCheckOut(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR]) {
    /** Solicita ao usuário o número do andar desejado */
    printf("Digite o numero do andar: ");
    int andar;
    scanf("%d", &andar);

    /** Verifica se o andar fornecido é válido */
    if (andar < 1 || andar > NUM_ANDARES) {
        printf("Andar invalido. Escolha um andar entre 1 e %d.\n", NUM_ANDARES);
        system("pause");
        system (CLEAR_SCREEN);
        return;
    }

    /** Solicita ao usuário o número do quarto desejado no andar informado */
    printf("Digite o numero do quarto no andar %d: ", andar);
    int quarto;
    scanf("%d", &quarto);

    /** Verifica se o número do quarto fornecido é válido */
    if (quarto < 1 || quarto > NUM_QUARTOS_POR_ANDAR) {
        printf("Quarto invalido. Escolha um quarto entre 1 e %d.\n", NUM_QUARTOS_POR_ANDAR);
        system("pause");
        system (CLEAR_SCREEN);
        return;
    }

    /** Obtém o ponteiro para o quarto selecionado na matriz de reservas */
    Reserva* quartoSelecionado = &hotel[andar - 1][quarto - 1];

    /** Verifica o estado do quarto */
    if (quartoSelecionado->ocupado == 0) {
        printf("Quarto nao ocupado. Nao e possível realizar check-out.\n");
            system ("pause");
    system (CLEAR_SCREEN);
    } else if (quartoSelecionado->ocupado == 2) {
        printf("Quarto bloqueado. Nao e possível disponibiliza-lo no momento.\n");
            system ("pause");
    system (CLEAR_SCREEN);
    } else {
        /** Exibe a mensagem de check-out com o nome do hóspede */
        printf("Check-out realizado para o quarto %d no andar %d. Obrigado por se hospedar, %s!\n",
            quartoSelecionado->numeroQuarto, andar, quartoSelecionado->hospede);

        /** Marca o quarto como livre após o check-out */
        quartoSelecionado->ocupado = 0;
        strcpy(quartoSelecionado->hospede, ""); /** Limpa o nome do hóspede */
        quartoSelecionado->diasReservados = 0;

        system("pause");
        system(CLEAR_SCREEN);
    }
}



/** Exibe a lista de reservas, indicando o status de ocupação de cada quarto.
 * Percorre a estrutura do hotel e exibe informações sobre cada quarto, indicando se está livre, ocupado ou bloqueado.
 * Mesmo o 'int totalReservas' estando marcado como inútil, após tirarmos ele da declaração da função visualizarReservas
 * e ajustarmos a sua chamada no Main, o programa não compilava, então é melhor só deixá-lo aí mesmo */
void visualizarReservas(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR], int totalReservas) {
    /**< Cabeçalho da lista de reservas. */
    printf("\n ////////////////////////// Lista de Reservas: //////////////////////////\n");
    printf("Quarto         Hospede             Status         Dias Reservados\n");

    /**< Itera sobre os andares e quartos para exibir as informações de cada quarto. */
    for (int andar = 0; andar < NUM_ANDARES; andar++) {
        for (int quarto = 0; quarto < NUM_QUARTOS_POR_ANDAR; quarto++) {
            /**< Obtém um ponteiro para o quarto atual. */
            Reserva *quartoAtual = &hotel[andar][quarto];

            /**< Exibe o número do quarto. */
            printf("%-15d", quartoAtual->numeroQuarto);

            /**< Verifica o status do quarto e formata a exibição de acordo. */
            if (quartoAtual->ocupado == 1) {
                /**< Formata o nome do hóspede e exibe. */
                char nomeFormatado[MAX_NOME_HOSPEDE + 1];
                snprintf(nomeFormatado, MAX_NOME_HOSPEDE + 1, "%-20s", quartoAtual->hospede);
                printf("%s", nomeFormatado);

                /**< Exibe o status 'Ocupado' e os dias reservados. */
                printf("%-15s", "Ocupado");
                printf("%-20d", quartoAtual->diasReservados);
            } else if (quartoAtual->ocupado == 2) {
                /**< Exibe o status 'Bloqueado' quando o quarto está bloqueado. */
                printf("%-15s", "");
                printf("%-15s", "     Bloqueado");
                printf("%-20s", "");
            } else {
                /**< Exibe o status 'Livre' quando o quarto está livre. */
                printf("%-15s", "");
                printf("%-15s", "     Livre");
                printf("%-20s", "");
            }

            /**< Pula para a próxima linha após exibir as informações do quarto atual. */
            printf("\n");
        }
    }

    /**< Pausa a execução para aguardar a interação do usuário antes de fechar a janela. */
    system("pause");
    system (CLEAR_SCREEN);
}


/** Bloqueia um quarto específico do hotel, impedindo futuras reservas ou check-ins.
 * Solicita ao usuário o andar e quarto desejados, verifica se o quarto está livre e bloqueia.
 * Utiliza a estrutura Reserva e define o status do quarto como bloqueado. */
void bloquearQuarto(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR]) {
    /** Solicita ao usuário o número do andar desejado */
    printf("Digite o numero do andar: ");
    int andar;
    scanf("%d", &andar);

    /** Verifica se o andar fornecido é válido */
    if (andar < 1 || andar > NUM_ANDARES) {
        printf("Andar invalido. Escolha um andar entre 1 e %d.\n", NUM_ANDARES);
        system("pause");
        system (CLEAR_SCREEN);
        return;
    }

    /** Solicita ao usuário o número do quarto desejado no andar informado */
    printf("Digite o numero do quarto no andar %d: ", andar);
    int quarto;
    scanf("%d", &quarto);

    /** Verifica se o número do quarto fornecido é válido */
    if (quarto < 1 || quarto > NUM_QUARTOS_POR_ANDAR) {
        printf("Quarto invalido. Escolha um quarto entre 1 e %d.\n", NUM_QUARTOS_POR_ANDAR);
        system("pause");
        system (CLEAR_SCREEN);
        return;
    }

    /** Obtém o ponteiro para o quarto selecionado na matriz de reservas */
    Reserva* quartoSelecionado = &hotel[andar - 1][quarto - 1];

    /** Verifica o estado do quarto */
    if (quartoSelecionado->ocupado == 1) {
        printf("Quarto ocupado. Desocupe o quarto antes de bloquear.\n");
    } else if (quartoSelecionado->ocupado == 2) {
        printf("Quarto ja bloqueado.\n");
    } else {
        /** Bloqueia o quarto, definindo o status como bloqueado e limpando os dados associados */
        quartoSelecionado->ocupado = 2;
        strcpy(quartoSelecionado->hospede, "--------");
        quartoSelecionado->diasReservados = 0;

        printf("Quarto %d no andar %d bloqueado com sucesso.\n", quartoSelecionado->numeroQuarto, andar);
    }
    system("pause");
    system (CLEAR_SCREEN);
}

/** Desbloqueia um quarto específico do hotel, permitindo futuras reservas ou check-ins.
 * Solicita ao usuário o andar e quarto desejados, verifica se o quarto está bloqueado e desbloqueia.
 * Utiliza a estrutura Reserva e define o status do quarto como livre. */
void desbloquearQuarto(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR]) {
    /**< Solicita ao usuário o número do andar. */
    printf("Digite o numero do andar: ");
    int andar;
    scanf("%d", &andar);

    /**< Verifica se o número do andar é válido. */
    if (andar < 1 || andar > NUM_ANDARES) {
        printf("Andar invalido. Escolha um andar entre 1 e %d.\n", NUM_ANDARES);
        system("pause");
        system (CLEAR_SCREEN);
        return;
    }

    /**< Solicita ao usuário o número do quarto no andar especificado. */
    printf("Digite o numero do quarto no andar %d: ", andar);
    int quarto;
    scanf("%d", &quarto);

    /**< Verifica se o número do quarto é válido. */
    if (quarto < 1 || quarto > NUM_QUARTOS_POR_ANDAR) {
        printf("Quarto invalido. Escolha um quarto entre 1 e %d.\n", NUM_QUARTOS_POR_ANDAR);
        system("pause");
        system (CLEAR_SCREEN);
        return;
    }

    /**< Obtém um ponteiro para o quarto selecionado. */
    Reserva* quartoSelecionado = &hotel[andar - 1][quarto - 1];

    /**< Verifica se o quarto está bloqueado antes de desbloquear. */
    if (quartoSelecionado->ocupado == 2) {
        /**< Define o status do quarto como livre (0). */
        quartoSelecionado->ocupado = 0;
        printf("Quarto %d no andar %d desbloqueado com sucesso.\n", quartoSelecionado->numeroQuarto, andar);
        system("pause");
        system (CLEAR_SCREEN);
    } else {
        /**< Informa que o quarto não está bloqueado ou não foi encontrado. */
        printf("Quarto nao encontrado ou nao esta bloqueado.\n");
        system("pause");
        system (CLEAR_SCREEN);
    }
}
