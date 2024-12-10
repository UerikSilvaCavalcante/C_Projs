#include <stdio.h>
#include <stdlib.h>

struct ST_DADOS
{
    char nome[40];
    float salario;
    struct nascimento
    {
        int ano;
        int mes;
        int dia;
    } dt_nascimento;
    
};


int main(){
    struct ST_DADOS *p;
    p = (struct ST_DADOS *)malloc(sizeof(struct ST_DADOS));
    printf("Entre com o nome -> ");
    scanf("%s", &p->nome);
    printf("Entre com o salario -> ");
    scanf("%f", &p->salario);
    printf("Entre com o nascimento -> ");
    scanf("%i/%i/%i", &p->dt_nascimento.dia,&p->dt_nascimento.mes,&p->dt_nascimento.ano);
    printf("\n============DADOS DIGITADOS===========\n");
    printf("Nome: %s\n", p->nome);
    printf("Nome: %.2f\n", p->salario);
    printf("Nome: %i/%i/%i\n", p->dt_nascimento.dia, p->dt_nascimento.mes,p->dt_nascimento.ano);

    free(p);

    return 0;
}