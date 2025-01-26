#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *aponta, quantos, soma = 0, *countMult6;
    printf("Quantos elementos deseja alocar?\n");
    scanf("%d", &quantos);
    aponta = (int*) calloc(quantos, sizeof(int));
    countMult6 = (int*) calloc(1, sizeof(int));
    // aponta = (int*) calloc(quantos, sizeof(int));
    if(!aponta || !countMult6) {
        printf("Memoria nao alocada.\n Encerrando programa...\n");
        return 0;
    }

    for(int x=0; x<quantos; x++){
        printf("Digite o valor: \n");
        scanf("%d", &aponta[x]);
        soma += aponta[x];
        if(aponta[x] % 6 == 0){
            *countMult6 += 1;
        }
        printf("valor %d\n", aponta[x]);
        printf("count atual de num mult 6%d\n", *countMult6);
    }
    printf("Media = %.2f\n", (float) soma/quantos);
    printf("Numero de multiplos de 6 = %d", *countMult6);
    free(aponta);
    free(countMult6);

}