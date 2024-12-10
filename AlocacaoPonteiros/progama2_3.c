#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    int i, k, n;
    printf("Digite a quantidade de numeros que serao digitados -> ");
    scanf("%i", &i);
    p = (int *) (malloc(i*sizeof(int)));
    if (p == NULL){
        printf("Erro ao alocar memoria!");
        exit(1);
    }
    for (k = 0; k<i; k++){
        printf("Digite o numero para o indice %i -> ", k);
        scanf("%i", &p[k]);
    }
    for (k = 0; k<i; k++){
        printf("O numero para o indice %i -> %i\n", k, p[k]);
    }

    printf("Digite uma nova quantidade de numeros que serao digitados -> ");
    scanf("%i", &n);
    p = (int *)(realloc(p,(n+i)*sizeof(int)));
    for (k = 0; k<(i+n); k++){
        printf("Digite o numero para o indice %i -> ", k);
        scanf("%i", &p[k]);
    }
    for (k = 0; k<(i+n); k++){
        printf("O numero para o indice %i -> %i\n", k, p[k]);
    }


    return 0;
}