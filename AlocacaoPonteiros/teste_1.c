#include <stdio.h>
#include <stdlib.h>
void imprime_array_elemento(int *ptrArray, int iElement){
    printf("Elemento na posicao %i -> %i\n", iElement, ptrArray[iElement]);
}

int main(){
    int *p;
    int i = 5, x;
    int index;
    p = (int *)(malloc(i* sizeof(int)));
    if (p == NULL){
        printf("Erro ao alocar memoria!!");
        exit(1);
    }
    for (x = 0; x<i; x++){
        printf("Digite um numero para o vetor na posicao %i -> ", x);
        scanf("%i", &p[x]);
    }

    printf("\nDigite a posição do numero que deseja acessar -> ");
    scanf("%i", &index);
    
    imprime_array_elemento(p, index);


    return 0;
}