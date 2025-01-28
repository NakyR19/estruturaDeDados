//Programa de Lista Duplamente Encadeada gerenciada por nó cabeça
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
int dado;
struct no *proxNo, *antNo;
}tipoNo;

typedef struct listaGerenciada{
tipoNo *fim, *inicio;
int quant;
}tipoLista;

void inicializa(tipoLista *listaEnc){
    listaEnc->fim = NULL;
    listaEnc->inicio = NULL;
    listaEnc->quant = 0;
    }

int insereListaVazia(tipoLista *listaEnc, int valor){
tipoNo *novoNo = (tipoNo *)malloc(sizeof(tipoNo));
if(novoNo == NULL)
    return 0;
novoNo->dado = valor;
novoNo->proxNo = NULL;
novoNo->antNo = NULL;
listaEnc->inicio = novoNo;
listaEnc->fim = novoNo;
listaEnc->quant++;
return 1;
}

int insereNaFrente(tipoLista *listaEnc, int valor){
tipoNo *novoNo;
if(listaEnc->inicio==NULL)
    insereListaVazia(listaEnc, valor);
else{
    novoNo = (tipoNo*)malloc(sizeof(tipoNo));
    if(novoNo==NULL)
        return 0;
    novoNo->dado=valor;
    novoNo->antNo = NULL;
    novoNo->proxNo=listaEnc->inicio;
    listaEnc->inicio->antNo = novoNo;
    listaEnc->inicio=novoNo;
    listaEnc->quant++;
    return 1;
}
}

void exibeLista(tipoLista *listaEnc){
tipoNo *atual;  /*Variável que será usada para percorrer a lista*/
atual = listaEnc->inicio;
printf("\nLista encadeada: ");
while(atual !=NULL){
    printf("%8d",atual->dado);
    atual = atual->proxNo;
}
}

int insereNoFim(tipoLista *listaEnc, int valor){
tipoNo *novoNo;
if(listaEnc->inicio == NULL)
    insereListaVazia(listaEnc, valor);
else{
    novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if(novoNo == NULL)
        return 0;
    novoNo->dado=valor;
    novoNo->proxNo=NULL;
    listaEnc->fim->proxNo = novoNo;
    novoNo->antNo = listaEnc->fim;
    listaEnc->fim = novoNo;
    listaEnc->quant++;
    return 1;
}
}

int inserirDeterminadaPos(tipoLista *lista, int dado, int pos)
{
    tipoNo *novoNo;
    tipoNo *atual;
   
    if (lista->inicio == NULL)
    {
        insereListaVazia(lista, dado);
    }
    else
    {
        novoNo = (tipoNo *)malloc(sizeof(tipoNo));
        if (novoNo == NULL)
            return 0;
        atual = lista->inicio;
        novoNo->dado = dado;
        if(lista->quant < pos){
            printf("Favor inserir em posição existente na lista");
            return 0;
        }
        for(int i = 0; i < pos; i++){
            atual = atual->proxNo;
        }
        if(pos == 0){
            insereNaFrente(lista, dado);
        }
        else if (lista->quant == pos){
           insereNoFim(lista, dado);
        } else {
            atual->antNo->proxNo = novoNo;
            novoNo->antNo = atual->antNo;
            novoNo->proxNo = atual;
            atual->antNo = novoNo;
            lista->quant++;
        }
        return 1;
    }
}

int main(){
    tipoLista lista;
    int aux, aux2, op;
    inicializa(&lista);
    do{
        printf("\nMenu");
        printf("\n1 - Insere na lista vazia");
        printf("\n2 - Insere na frente da lista");
        printf("\n3 - Exibe lista");
        printf("\n4 - Insere em determinada pos");
        printf("\n5 - Insere no final");
        printf("\n0 - Encerrar programa");
        printf("\nDigite sua opcao:");
        scanf("%d",&op);
        switch(op){
        case 1: printf("\nDigite um numero inteiro:");
            scanf("%d",&aux);
            if(insereListaVazia(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");
            break;
        case 2: printf("\nDigite um numero inteiro:");
            scanf("%d",&aux);
            if(insereNaFrente(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");
            break;
        case 3: exibeLista(&lista);
            break;
        case 4: printf("\nDigite um numero inteiro:");
            scanf("%d",&aux);
            printf("\nDigite a posição:");
            scanf("%d",&aux2);
            if(inserirDeterminadaPos(&lista, aux, aux2))
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");
            break;
        case 5: printf("\nDigite um numero inteiro:");
            scanf("%d",&aux);
            if(insereNoFim(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");
            break;
        case 0:
            printf("\nEncerrando programa...");
            break;
        default: printf("\nOpcao invalida. Escolha outra opcao.");
            break;
        }
    }while(op != 0);
return 0;
}
