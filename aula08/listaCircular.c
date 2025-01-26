#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
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

int insereListaVazia(tipoListaCircular *lista, int valor)
{
    tipoNo *novoNo = (tipoNo *)malloc(sizeof(tipoNo));
    if (novoNo == NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->proxNo = novoNo;
    lista->fim = novoNo;
    lista->quant++;
    return 1;
}

int insereNaFrente(tipoListaCircular *lista, int valor)
{
    tipoNo *novoNo;
    if (lista->fim == NULL)
    {
        insereListaVazia(lista, valor);
        return 1;
    }
    else
    {
        novoNo = (tipoNo *)malloc(sizeof(tipoNo));
        if (novoNo == NULL)
            return 0;
        novoNo->dado = valor;
        novoNo->proxNo = lista->fim->proxNo;
        lista->fim->proxNo = novoNo;
        lista->quant++;
        return 1;
    }
}

int insereNoFim(tipoListaCircular *lista, int valor)
{
    tipoNo *novoNo;
    if (lista->fim == NULL)
    {
        insereListaVazia(lista, valor);
        return 1;
    }
    else
    {
        novoNo = (tipoNo *)malloc(sizeof(tipoNo));
        if (novoNo == NULL)
            return 0;
        novoNo->dado = valor;
        novoNo->proxNo = lista->fim->proxNo;
        lista->fim->proxNo = novoNo;
        lista->fim = novoNo;
        lista->quant++;
        return 1;
    }
}

int removeNoInicio(tipoListaCircular *lista)
{
    tipoNo *aux;
    if (!lista->fim)
    {
        return 0;
    }
    else if (lista->fim->proxNo == lista->fim)
    {
        free(lista->fim);
        lista->fim = NULL;
        lista->quant--;
        return 1;
    }
    else
    {
        aux = lista->fim->proxNo;
        lista->fim->proxNo = aux->proxNo;
        free(aux);
        lista->quant--;
        return 1;
    }
}

int removeNoFim(tipoListaCircular *lista)
{
    tipoNo *aux, *atual;
    int i = 0;
    if (lista->fim == NULL)
    {
        return 0;
    }
    else if (lista->fim == lista->fim->proxNo)
    {
        free(lista->fim);
        lista->fim = NULL;
        lista->quant--;
        return 1;
    }
    else
    {
        aux = lista->fim;
        atual = lista->fim->proxNo;
        while (atual->proxNo != lista->fim)
        {
            atual = atual->proxNo;
            i++;
        }
        atual->proxNo = lista->fim->proxNo;
        lista->fim = atual;
        free(aux);
        lista->quant--;
        return 1;
    }
}

/*Função de exibição da lista encadeada circular*/
int exibeLista(tipoListaCircular *lista, int quant)
{
    tipoNo *atual; // Variável que será usada para percorrer a lista*/
    int i = 0;
    if (lista->fim == NULL)
        return 0;
    atual = lista->fim->proxNo;
    printf("\nLista encadeada circular: ");
    while (i < quant)
    {
        printf("%8d", atual->dado);
        atual = atual->proxNo;
        i++;
    }
    return 1;
}

int main()
{
    int resp, op;
    tipoListaCircular *lista = (tipoListaCircular *)malloc(sizeof(tipoListaCircular));
    inicializarLista(lista);
    int leitor;

    do
    {
        printf("\nEscolha uma opcao\n1 - Inserir em lista vazia\n2 - Inserir no inicio");
        printf("\n3 - Inserir no fim\n4 - Remove no inicio\n5 - Remove no fim");
        printf("\n8 - Exibir Lista\n0 - Sair do programa");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite um elemento: ");
            scanf("%d", &leitor);
            resp = insereListaVazia(lista, leitor);
            if (!resp)
                printf("Memoria nao alocada!");
            printf("Elemento guardado: %d", lista->fim->dado);
            break;
        case 2:
            printf("\nDigite outro elemento para inserir na frente: ");
            scanf("%d", &leitor);
            resp = insereNaFrente(lista, leitor);
            exibeLista(lista, lista->quant);
            break;
        case 3:
            printf("\nDigite outro elemento para inserir no fim: ");
            scanf("%d", &leitor);
            resp = insereNoFim(lista, leitor);
            exibeLista(lista, lista->quant);
            break;
        case 4:
            resp = removeNoInicio(lista);
            if (resp)
            {
                printf("Item removido com sucesso do inicio da lista!");
            }
            else
                printf("Lista vazia, não há elementos para serem removidos.");
            exibeLista(lista, lista->quant);
            break;
        case 5:
            resp = removeNoFim(lista);
            if (resp)
            {
                printf("Item removido com sucesso do fim da lista!");
            }
            else
                printf("Lista vazia, não há elementos para serem removidos.");
            exibeLista(lista, lista->quant);
            break;
        // case 6: printf("\nDigite o elemento que deseja procurar:");
        //         scanf("%d",&aux);
        //         resp = pesqBin(lista, aux);
        //         if(resp == -1)
        //             printf("\nElemento nao encontrado");
        //         else
        //             printf("\nElemento encontrado na posicao %d do vetor.",resp);
        //         break;
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
    // printf("Digite um elemento: ");
    // scanf("%d",&leitor);
    // int resp = insereListaVazia(&lista, leitor);
    // if(!resp)
    //   printf("Memoria nao alocada!");
    // printf("Elemento guardado: %d",lista.inicio->dado);
    // printf("\nDigite outro elemento para inserir na frente: ");
    // scanf("%d",&leitor);
    // resp = insereNaFrente(&lista,leitor);
    // exibeLista(&lista, lista->quant);
    // printf("\nDigite outro elemento para inserir no fim: ");
    // scanf("%d",&leitor);
    // resp = insereNoFim(&lista, leitor);
    // exibeLista(&lista, lista->quant);
}