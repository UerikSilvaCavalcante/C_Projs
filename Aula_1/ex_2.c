# include <stdio.h>

int main(){
    float maior, menor, media;
    float notas[10];
    int i;
    for (i = 0; i < 10; i ++){
        printf("Digite a nota %i do aluno: ", i + 1);
        scanf("%f", &notas[i]);
    }

    int tamanho = sizeof(notas) / sizeof(notas[0]);

    media = 0;
    maior = notas[0]; 
    menor = notas[0];

    for (i = 0; i< tamanho; i ++){
        if (notas[i] < menor){
            menor = notas[i];
        }else if (notas[i] > maior){
            maior = notas[i];
        }else{
            continue;
        } 
        media += notas[i];
    }

    media = media / tamanho;

    printf("A media desse Aluno e: %.2f\nE sua maior nota e: %.2f\nE menor e: %.2f", media, maior,menor);
    return 0;
}