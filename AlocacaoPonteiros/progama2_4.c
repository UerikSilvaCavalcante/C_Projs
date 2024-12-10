#include <stdio.h>
#include <stdlib.h>

int main(){
    int **p;
    int i,j,k,x;
    printf("Digite as dimensoes da matriz -> ");
    scanf("%i %i", &i,&j);
    p = calloc(i, sizeof(int));
    if (p == NULL){
        printf("Erro ao alocar memoria!");
        exit(1);
    }

    for (k=0;k<i;k++){
        p[k] = calloc(j,sizeof(int));
        if(p[k] == NULL){
            printf("Erro ao alocar memoria!");
            exit(1);
        }
    }

    for (k=0;k<i;k++){
        for(x=0;x<j;x++){
            printf("Digite o numero para o indice [%i][%i] -> ", k+1,x+1);
            scanf("%i", &p[k][x]);
        }
    }

    for (k=0;k<i;k++){
        for(x=0;x<j;x++){
            printf("O numero para o indice [%i][%i] -> %i\n", k+1,x+1, p[k][x]);
        }
    }

    printf("Liberando memoria!!!");
    for (k = 0; k<i; k++){
        free(p[k]);
    }
    free(p);

    return 0;
}