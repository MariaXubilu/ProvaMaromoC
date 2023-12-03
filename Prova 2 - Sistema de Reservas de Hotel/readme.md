# Sistema de Reservas de Hotel

## Sumário:
- [Introdução](#introdução)
- [Como Executar o Projeto](#como-executar-o-projeto)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Funções e Classes](#funções-e-classes)

## Introdução <a name="introdução"></a>

Bem-vindo ao nosso projeto de Sistema de Reservas de Hotel. Este software foi desenvolvido para simplificar a gestão de reservas, check-ins e check-outs em um hotel. Oferecemos uma interface fácil de usar para realizar essas operações de forma eficiente, proporcionando uma visão clara do status dos quartos e facilitando o controle das reservas.

## Como Executar o Projeto <a name="como-executar-o-projeto"></a>

### Requisitos:
1. Baixe o arquivo executável (`main.exe`) do [último release](https://github.com/CSeisOssos/Logica_de_programacao_C/releases/latest).
2. Certifique-se de ter um ambiente Windows para executar o arquivo executável.

### Executando o Projeto:
1. Execute o arquivo `main.exe`.
2. Siga as instruções na interface do console para interagir com o sistema.

## Estrutura do Projeto <a name="estrutura-do-projeto"></a>

O projeto está organizado da seguinte forma:
- `hotel.h`: Contém as definições de estruturas e protótipos de funções utilizadas no projeto.
- `hotel.c`: Implementações das funções definidas em `hotel.h`.
- `main.c`: Função principal que interage com o usuário, chamando as funções do hotel.

## Funções e Classes <a name="funções-e-classes"></a>

### Função: `fazerReserva`
```c
void fazerReserva(Reserva hotel[NUM_ANDARES][NUM_QUARTOS_POR_ANDAR], int* totalReservas);
