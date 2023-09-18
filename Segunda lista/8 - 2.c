//Dados Nome e notas (total de 5) de N alunos, faça um programa em C que:
//a) Imprima Nome e média dos alunos aprovados. Média > = 7.0.
//b) Imprima Nome e média dos alunos em recuperação. 5.0 >= Média <7.0.
//c) Imprima Nome e média dos alunos reprovados. Média <5.0.

#include <stdio.h>
//isso aqui dá mais trabalho do que depende de lógica, é literalmente só ficar criando vetor atrás de vetor.

int main() {
    int N;
    printf("Digite o número de alunos: ");
    scanf("%d", &N);

    char nomes[N][50];
    double notas[N][5];
    double media;

//uma matriz feita para armazenar os nomes dos alunos digitados e suas notas.
    for (int i = 0; i < N; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", nomes[i]);
        
        printf("Notas (5 notas separadas por espaço): ");
        for (int j = 0; j < 5; j++) {
            scanf("%lf", &notas[i][j]);
        }
    }

//a lógica matemática é simples, pena que tem que ficar evocando as matrizes pra qualquer coisinha.
    printf("\nAlunos aprovados:\n");
    for (int i = 0; i < N; i++) {
        media = 0.0;
        for (int j = 0; j < 5; j++) {
            media += notas[i][j];
        }
        media /= 5.0;

        if (media >= 7.0) {
            printf("Nome: %s, Média: %.2lf\n", nomes[i], media);
        }
    }

    printf("\nAlunos em recuperação:\n");
    for (int i = 0; i < N; i++) {
        media = 0.0;
        for (int j = 0; j < 5; j++) {
            media += notas[i][j];
        }
        media /= 5.0;

        if (media >= 5.0 && media < 7.0) {
            printf("Nome: %s, Média: %.2lf\n", nomes[i], media);
        }
    }

    printf("\nAlunos reprovados:\n");
    for (int i = 0; i < N; i++) {
        media = 0.0;
        for (int j = 0; j < 5; j++) {
            media += notas[i][j];
        }
        media /= 5.0;

        if (media < 5.0) {
            printf("Nome: %s, Média: %.2lf\n", nomes[i], media);
        }
    
    return 0;
}
}