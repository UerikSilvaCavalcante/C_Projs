# include <stdio.h>

int main(){
    float media = 0;
    int alunos;
    printf("Quantos alunos tem na sala: ");
    scanf("%i", &alunos);

    float altura[alunos];
    for (int i = 0; i < alunos; i++){
        printf("Digite a altura do aluno %i: ", i +1);
        scanf("%f", &altura[i]);
        media += altura[i];
    }
    media = media/alunos;

    printf("A media da altura desse alunos e: %.2f", media);


    return 0;
}