#include <stdio.h>
#include <stdlib.h>

int **aloca(int i, int j);
void libera(int **p, int i, int j);
void leitura(int **p, int i, int j);
void imprime(int **p, int i, int j);


int main(){
    int **p;
    int **p1;
    p = aloca(3,2);
    leitura(p,3,2);

    p1 = aloca(2,3);
    leitura(p1,2,3);

    imprime(p,3,2);
    imprime(p1,2,3);

    libera(p,3,2);
    libera(p1,2,3);

    return 0;
}

int **aloca(int i, int j){

    int **matriz = calloc(i,sizeof(int)); //! crie e aloca o ponteiro para a matriz dinamica
    int x;

    if(matriz == NULL){
        printf("Erro na alocacao de memoria!!");
        exit(1);
    }
    for (x = 0; x< i; x++){
        matriz[x] = calloc(j,sizeof(int)); //! aloca o segundo vetor no caso as colunas
        if(matriz[x] == NULL){
            printf("Erro na alocacao de memoria!!");
            exit(1);
        }
    }
    return matriz;
}

void leitura(int **p, int i, int j){
    int n,m;
    for(n=0; n<i;n++){
        for(m=0;m<j;m++){
            printf("\nDigite o numero da matriz na posicao (%i,%i) -> ", n+1,m+1);
            scanf("%i",&p[n][m]);
        }
    }
}

void imprime(int **p, int i, int j){
    int n,m;
    for(n=0; n< i;n++){
        printf("[");
        for (m = 0; m < j; m++)
        {
            printf(" %i ", p[n][m]);
        }
        printf("]\n");
    }
}

void libera(int **p, int i, int j){
    int n, m;
    for(n = 0; n < i; n++){
        for(m =0; m<j;m++){
            free(p[n][m]); //! libera memoria de cada vetor dentro do vetor
        }
        free(p[n]);
    }
    free(p);
}