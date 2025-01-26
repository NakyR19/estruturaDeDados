#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Atleta
    {
        char nome[50];
        int idade;
        float peso;
    };

int main()
{
    int qnts = 0, somaMenorIdade = 0;
    float somaPeso = 0;

    printf("Quantos elementos deseja alocar?\n");
    scanf("%d", &qnts);

    struct Atleta *atletas;
    atletas = (struct Atleta *)calloc(qnts, sizeof(struct Atleta));

    if (!atletas)
    {
        printf("Memoria nao alocada.\n Encerrando programa...\n");
        return 0;
    }

    for (int i = 0; i < qnts; i++)
    {
        while (getchar() != '\n');
        printf("Digite o nome do atleta: \n");
        fgets(atletas[i].nome, sizeof(atletas[i].nome), stdin);
        atletas[i].nome[strcspn(atletas[i].nome, "\n")] = '\0';
        printf("Digite a idade: \n");
        scanf("%d", &atletas[i].idade);
        printf("Digite o peso: \n");
        scanf("%f", &atletas[i].peso);

        somaPeso += atletas[i].peso;

        if (atletas[i].idade < 18)
        {
            somaMenorIdade += 1;
        }

        printf("Nome %s\n Idade %d\n Peso %.2f", atletas[i].nome, atletas[i].idade, atletas[i].peso);
        printf("Count menores %d\n", somaMenorIdade);
    }
    printf("Media de peso = %.2f\n", (float)somaPeso / qnts);
    printf("Quantidade de atletas menores de idade %d\n", somaMenorIdade);

    free(atletas);
}