#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Obs.: Não tratei todos os casos de erro, como a inserção de dados incorretos por ser uma atividade de revisão da linguagem, contudo toda a lógica segue intacta e correta, obviamente caso não insira nenhum valor conflitante;
struct Aluno
{
    char nome[50];
    int matricula;
    float media;
};
void ordenarAlf(struct Aluno alunos[], int qnts)
{
    struct Aluno temp;
    for (int i = 0; i < qnts - 1; i++)
    {
        for (int j = i + 1; j < qnts; j++)
        {
            if (strcasecmp(alunos[i].nome, alunos[j].nome) > 0)
            {
                temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
}

void ordenarMat(struct Aluno alunos[], int qnts)
{
    struct Aluno temp;
    for (int i = 0; i < qnts - 1; i++) {
        for (int j = i + 1; j < qnts; j++) {
            if (alunos[i].matricula > alunos[j].matricula) {
                temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
}

void ordenarMedia(struct Aluno alunos[], int qnts){
    struct Aluno temp;
    for (int i = 0; i < qnts - 1; i++) {
        for (int j = i + 1; j < qnts; j++) {
            if (alunos[i].media < alunos[j].media) {
                temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
}

void listar(struct Aluno alunos[], int qnts)
{
    for (int i = 0; i < qnts; i++)
    {
        printf("Nome: %s, Matricula: %d, Media: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
    }
}

int main()
{
    int qnts = 0, continuar = 0, numOrdem = 0;

    printf("Quantos elementos deseja alocar?\n");
    scanf("%d", &qnts);

    struct Aluno *alunos;
    alunos = (struct Aluno *)calloc(qnts, sizeof(struct Aluno));

    if (!alunos)
    {
        printf("Memoria nao alocada.\n Encerrando programa...\n");
        return 0;
    }

    for (int i = 0; i < qnts; i++)
    {
        while (getchar() != '\n');
        printf("Digite o nome do aluno: \n");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
        printf("Digite a matricula: \n");
        scanf("%d", &alunos[i].matricula);
        printf("Digite o media: \n");
        scanf("%f", &alunos[i].media);

        printf("Nome %s\n matricula %d\n media %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
    }

    // utilizando strcomp para ordem alfabetica

    do
    {
        printf("Em que ordem voce deseja ver a lista? Digite 1 para ordem alfabetica, 2 para ordem de matricula e 3 para ordem por media\n");
        scanf("%d", &numOrdem);
        switch (numOrdem)
        {
        case 1:
            ordenarAlf(alunos, qnts);
            listar(alunos, qnts);
            break;
        case 2:
            ordenarMat(alunos, qnts);
            listar(alunos, qnts);
            break;
        case 3:
            ordenarMedia(alunos, qnts);
            listar(alunos, qnts);
        default:
            printf("Digitar um numero correto da proxima vez\n");
            break;
        }
        printf("Quer ver novamente? Digite 1 para sim, 0 se nao\n");
        scanf("%d", &continuar);
        if(continuar ==0){
            printf("Saindo...");
        }
    } while (continuar);

    free(alunos);
}
