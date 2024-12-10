#include <stdio.h>
#include <stdlib.h>

void funcao(int **piParametro){
    printf("%i\n", &piParametro); //! -> mostra o endereço do ponteiro de ponteiro
    printf("%i\n", piParametro); //!  -> endereço do ponteiro armazenado
    printf("%i\n", *piParametro); //! -> valor do ponteiro armazenado
    printf("%i\n", **piParametro); //!-> valor da variavel que esse ponteiro de ponteiro estao armazenando 
}

int main(){
    int *piParametro;
    piParametro = (int *)(malloc(sizeof(int)));
    *piParametro = 20;
    printf("%i\n", &piParametro); //! -> mostra o endereço do ponteiro de ponteiro
    printf("%i\n", piParametro); //!  -> endereço do ponteiro armazenado
    printf("%i\n", *piParametro);

    funcao(&piParametro);
    return 0;
}