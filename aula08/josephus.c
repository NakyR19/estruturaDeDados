#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Rafael Santos Silva
// Jackson Junior
typedef struct pessoa
{
    char nome[50];
    char cpf[12];
} Pessoa;

typedef struct no
{
    Pessoa dado;
    struct no *proxNo;
} tipoNo;

typedef struct
{
    tipoNo *fim;
    int quant;
} tipoListaCircular;

void inicializarLista(tipoListaCircular *lista)
{
    lista->fim = NULL;
    lista->quant = 0;
}

int insereListaVazia(tipoListaCircular *lista, Pessoa pessoa)
{
    tipoNo *novoNo = (tipoNo *)malloc(sizeof(tipoNo));
    if (novoNo == NULL)
        return 0;
    novoNo->dado = pessoa;
    novoNo->proxNo = novoNo;
    lista->fim = novoNo;
    lista->quant++;
    return 1;
}

int inserirPessoa(tipoListaCircular *lista, Pessoa pessoa)
{
    tipoNo *novoNo;
    if (lista->fim == NULL)
    {
        int resp = insereListaVazia(lista, pessoa);
        if (resp)
            return 1;
        else
            return 0;
    }
    else
    {
        novoNo = (tipoNo *)malloc(sizeof(tipoNo));
        if (novoNo == NULL)
            return 0;
        novoNo->dado = pessoa;
        novoNo->proxNo = lista->fim->proxNo;
        lista->fim->proxNo = novoNo;
        lista->fim = novoNo;
        lista->quant++;
        return 1;
    }
}

int realizarSorteio(tipoListaCircular *lista, int numAleatorio)
{

    if (lista->fim == NULL)
    {
        printf("A lista esta vazia!\n");
        return 0;
    }

    tipoNo *aux = lista->fim->proxNo;
    tipoNo *anterior = lista->fim;

    if (lista->fim == lista->fim->proxNo)
    {
        printf("Favor inserir mais participantes para realizar o sorteio!!\n");
        return 0;
    }
    // menor que, pois o i começa do 0;
    for (int i = 0; i < numAleatorio; i++)
    {
        anterior = aux;
        aux = aux->proxNo;
    }

    anterior->proxNo = aux->proxNo;
    lista->fim = anterior;
    printf("O participante eliminado foi: %s", aux->dado.nome);
    printf("O CPF do participante eh: %s\n", aux->dado.cpf);
    free(aux);
    lista->quant--;
    if (lista->fim == lista->fim->proxNo)
    {
        printf("TEMOS UM GANHADOR JAQUELINE!\n");
        printf("O participante vencedor foi: %s", lista->fim->dado.nome);
        printf("O CPF do participante vencedor eh: %s\n", lista->fim->dado.cpf);
    }
    return 1;
}

/*Função de exibição da lista encadeada circular*/
int exibeLista(tipoListaCircular *lista, int quant)
{
    tipoNo *atual; // Variável que será usada para percorrer a lista*/
    int i = 0;
    if (lista->fim == NULL)
        return 0;
    atual = lista->fim->proxNo;
    printf("\nLista de Participantes: \n");
    while (i < quant)
    {
        printf("Participante %d: %s", i + 1, atual->dado.nome);
        printf("Participante %d: %s\n", i + 1, atual->dado.cpf);
        atual = atual->proxNo;
        i++;
    }
    return 1;
}

int main()
{
    int resp, op;
    Pessoa pessoa;
    tipoListaCircular *lista;
    inicializarLista(lista);

    do
    {
        printf("\nVoce quer jogar o jogo?\n1 - Inserir nome\n2 - Realizar sorteio");
        printf("\n8 - Exibir lista de participantes\n0 - Sair do programa");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nDigite o nome do participante: \n");
            fflush(stdin);
            fgets(pessoa.nome, 50, stdin);
            printf("Digite o CPF do participante: \n");
            fflush(stdin);
            fgets(pessoa.cpf, 12, stdin);
            resp = inserirPessoa(lista, pessoa);
            if (resp)
            {
                printf("Participante inserido com sucesso!\n");
            }
            else
            {
                printf("Erro ao inserir participante!\n");
            }
            break;
        case 2:
            int numAleatorio = (rand() % lista->quant) + 1;
            printf("\nE o numero sorteado foi...: %d!!\n", numAleatorio);
            while (lista->quant > 1)
            {
                resp = realizarSorteio(lista, numAleatorio);
                if (resp)
                {
                    printf("Participante removido com sucesso!\n");
                }
                else
                {
                    printf("Erro ao remover participante!\n");
                }
                exibeLista(lista, lista->quant);
            }
            break;
        case 8:
            exibeLista(lista, lista->quant);
            break;
        case 0:
            printf("\nEncerrando programa.\n");
            break;
        default:
            printf("\n\nOpcao indisponivel. Selecione uma nova opcao.\n");
            break;
        }
    } while (op != 0);
    return 0;
}