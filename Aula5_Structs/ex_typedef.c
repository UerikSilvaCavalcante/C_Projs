#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_aluno
    {
        int id;
        char name[80];
        enum en_turno{
            M = 1,
            V = 2,
            N = 3
        } turno;
        float media;
    } ALUNO;


int IdCount(FILE *fptr){
    int id = 1;
    ALUNO backup;
    fptr = fopen("db.txt", "r");
    while (fread(&backup, sizeof(ALUNO), 1, fptr))
    {
        if (backup.id >= id){
            id = backup.id;
        }
    }
    
    return id;
}

void addStudent(int id, ALUNO aluno, ALUNO backup, FILE *fptr){
    fptr = fopen("db.txt", "a+");
    while (1)
    {
        id ++;
        aluno.id = id;
        printf("\nEntre com o nome do aluno:\t\t");
        fgets(aluno.name, sizeof(aluno.name), stdin);
        aluno.name[strcspn(aluno.name, "\n")] = '\0';

        if (strcmp(aluno.name, "FIM") == 0){
            break;
        }

        printf("Entre com o Turno (M/V/N):\t\t");
        char turno;
        scanf("%c", &turno);
        switch (turno)
        {
        case 'M':
            aluno.turno = M;
            break;
        case 'V':
            aluno.turno = V;
            break;
        case 'N':
            aluno.turno = N;
            break;
        default:
            printf("Turno invalido. Usando Matutino como padrao.\n");
            aluno.turno = M;
            break;
        }

        printf("Entre com a media desse aluno:\t\t");
        scanf("%f", &aluno.media);

        backup = aluno;
        printf("Nome: %s\n", backup.name);
        switch (backup.turno)
        {
        case M:
            printf("Matutino\n");
            break;
        case V:
            printf("Vespertino\n");
            break;
        case N:
            printf("Noturno\n");
            break;
        default:
            break;
        }
        printf("Media: %f", aluno.media);
        getchar();

        fwrite(&backup, sizeof(ALUNO), 1, fptr);

    }
    fclose(fptr);
}

void listStudents(FILE *fptr, ALUNO backup){
    fptr = fopen("db.txt", "r");
    while (fread(&backup, sizeof(ALUNO), 1, fptr))
    {
        printf("Id: %d\n", backup.id);
        printf("Nome do aluno: %s\n", backup.name);
        switch (backup.turno)
        {
        case M:
            printf("Matutino\n");
            break;
        case V:
            printf("Vespertino\n");
            break;
        case N:
            printf("Noturno\n");
            break;
        default:
            break;
        }
        printf("Media do aluno: %.2f\n", backup.media);
        printf("--------------------------\n");
    }
    
    // return id;
}

int main(){
    FILE *fptr;
    // char linha [80];
    int id;
    
    ALUNO aluno, backup;
    fptr = fopen("db.txt", "a+");
    if (fptr == NULL){
        printf("\nErro ao abrir arquivo.");
        exit(0);
    }

    id = IdCount(fptr);
    printf("%i", id);
    int opcao;
    while(1)
    {
        printf("Escolha uma das opcoes: \n");
        printf("Adicionar ALuno\t-\t1\nListar Alunos\t-\t2\nSair\t-\t3");
        printf("\nOpcao: ");
        scanf("%i",&opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            addStudent(id, aluno, backup, fptr);
            break;
        case 2:
            listStudents(fptr, backup);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Opcao invalida!!");
            exit(0);
            break;
        }
    }
    // printf()
    
    return 0;
}