#include <stdio.h>
#include <stdlib.h>
// PILHA

typedef struct no
{
    char dado[100];
    struct no *proxNo;
} tipoNo;

typedef struct
{
    tipoNo *inicio;
    tipoNo *fim;
    int quant;
} tipoLista;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void inicializa(tipoLista *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quant = 0;
}

int insereListaVazia(tipoLista *lista, char* valor)
{
    tipoNo *novoNo = (tipoNo *)malloc(sizeof(tipoNo));
    if (novoNo == NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->proxNo = NULL;
    lista->inicio = novoNo;
    lista->fim = novoNo;
    lista->quant++;
    return 1;
}

int insereNaFrente(tipoLista *lista, int valor)
{
    tipoNo *novoNo;
    if (lista->inicio == NULL)
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
        novoNo->proxNo = lista->inicio;
        lista->inicio = novoNo;
        return 1;
    }
    return 0;
}

int removerNaFrente(tipoLista *lista)
{
    tipoNo *aux;
    if (lista->inicio == NULL)
        return 0;
    else
    {
        aux = lista->inicio;
        if (lista->inicio->proxNo)
            lista->inicio = lista->inicio->proxNo;
        else
            lista->inicio = NULL;
        free(aux);
        return 1;
    }
}
void mostraVetorInvertido(int *vetor, int qntd)
{
    printf("\nConversão:");
    for (int x = qntd - 1; x >= 0; x--)
        printf("%d", vetor[x]);
}

/*Função de exibição da lista simplesmente encadeada*/
int exibeLista(tipoLista *lista)
{
    tipoNo *atual; // Variável que será usada para percorrer a lista*/
    if (lista->inicio == NULL)
        return 0;
    atual = lista->inicio;
    while (atual != NULL)
    {
        printf("%8d", atual->dado);
        atual = atual->proxNo;
    }
    return 1;
}

int converteBinario(tipoLista *lista)
{

    tipoLista *listaAux = (tipoLista *)malloc(sizeof(tipoLista));
    inicializa(listaAux);

    if (!lista->inicio)
        return 0;
    int num = lista->inicio->dado;
    printf("O numero convertido foi: %d", num);
    removerNaFrente(lista);

    if (num == 0)
    {
        printf("O resultado da conversão foi: 0");
        return 1;
    }

    while (num >= 1)
    {
        if ((num % 2) == 0)
        {
            num /= 2;
            insereNaFrente(listaAux, 0);
        }
        else
        {
            num /= 2;
            insereNaFrente(listaAux, 1);
        }
    }
    printf("\nO resultado da conversão foi:");
    exibeLista(listaAux);
    return 1;
}

int main()
{
    int resp, op;
    tipoLista *lista = (tipoLista *)malloc(sizeof(tipoLista));
    inicializa(lista);
    int leitor;

    do
    {
        printf("\nEscolha uma opcao\n1 - Inserir numero");
        printf("\n2 - Remover Numero\n3 - Converter primeiro numero para binario\n 4 - Converter primeiro numero para octal");
        printf("\n8 - Exibir Lista\n0 - Sair do programa");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite um elemento: ");
            scanf("%d", &leitor);
            resp = insereNaFrente(lista, leitor);
            if (!resp)
                printf("Memoria nao alocada!");
            printf("Elemento guardado: %d", lista->inicio->dado);
            break;
        case 2:
            resp = removerNaFrente(lista);
            if (resp)
            {
                printf("Item removido com sucesso do inicio da lista!");
            }
            else
                printf("Lista vazia, não há elementos para serem removidos.");
            exibeLista(lista);
            break;
        case 3:
            resp = converteBinario(lista);
            if (resp)
            {
                printf("\nEsse item foi removido da pilha.");
            }
            else
                printf("\nLista vazia, não há elementos para serem removidos.");
            exibeLista(lista);
            break;
        case 4:
            resp = converteOctal(lista);
            if (resp)
            {
                printf("\nEsse item foi removido da pilha.");
            }
            else
                printf("\nLista vazia, não há elementos para serem removidos.");
            exibeLista(lista);
            break;
        case 8:
            exibeLista(lista);
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