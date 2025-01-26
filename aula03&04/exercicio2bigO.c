#include <stdio.h>

int main(){
    int n = 3;
    int soma = 0;
    for(int i = 1; i <= n; i++){
        soma = soma + i;
    }
    printf("%d", soma);
    return 0;
}