# Estrutura de dados

# Ponteiros 
- Armazenam o **endereço** da **variavel** do tipo especificado.
#### Ex:
```c
    int *ptr; 
    int var = 10;
    ptr = &var;
    print("Endereço de ptr %d", &ptr);
    print("Endereço da variavel %d", ptr);
    print("Valor da variavel acessado pelo ponteiro! %i", *ptr);
```
O **ptr** e um ponteiro que armazena o endereço da variavel **var** = 10
- Ponteiros podem receber qualquer tipo primitivo
    - **int** 
    - **char**
    - **float**
    - **bool**

- Podem tambem ser acessados por **strutcs** ou tambem **vetores**
#### Ex: Usando structs
```c
        struct DT_ALUNO {
            char nome[80];
            float nota;
        } 

        struct DT_ALUNO *ptr;
        ptr = (struct DT_ALUNO)malloc(sizeof(struct DT_ALUNO));
        printf("Digite o nome do aluno : ");
        scanf("%s", &ptr->nome);
        printf("Digite a nota do aluno : ");
        scanf("%f", &ptr->nota);
```
- Ponteiros tambem podem ser passados como **parametros** e tambem **retornados** em **funções**
#### Ex:
```c
        int* calc(int *ptrValor){
            *ptrValor = *ptrValor * 10;
            return ptrValor;
        }
```
- Obs: **Vetores** podem ser **representados** como **ponteiros**
#### Ex:
```c
        vetor[5] = {1,2,3,4,5};
        printf("\n%ld %d\n",x, *x );
        printf("\n%ld %d\n",x+1, *(x+1));
        printf("\n%ld %d\n",x+2, *(x+2));
        printf("\n%ld %d\n",x+3, *(x+3));
        printf("\n%ld %d\n",x+4, *(x+4));
```

# Alocação dinamica de memoria de Memoria

- Alocação dinamica da memoria da maquina;
- Seja para o uso desnecessario de memoria na sua maquina ou para um uso maior de memoria;
- Muito usado para vetores e matrizes
## Funções Principais
### Malloc
- Aloca em um **endereço** **qualquer** na sua maquina o tamanho especificado na memoria
- Sintaxe:
```c
    void *malloc(int tam_bytes);
```
##### Ex:
```c
    valores = (int *)malloc(sizeof(int) * qtd);
```
```c
    int *valores;
    int qtd, i;
    int vlr;
    printf("Entre com a quantidade de numeros do seu vetor -> ");
    scanf("%i", &qtd);
    valores = (int *)malloc(sizeof(int) * qtd); // aloca na memoria o tamnho do vetor
    for(i = 0; i < qtd; i++){
        printf("Digite o valor na posição %i -> ", i+1);
        scanf("%i", &vlr);
        valores[i] = vlr;
    }

    for(i = 0; i < qtd; i++){
        printf("Valor digitado na posição %i -> %i\n", i+1, valores[i]);
    }

    free(valores); // Libera a memoria apos a execução dos loops
```

### Free
- Libera o **espaço** utilizado na **memoria** da sua **maquina**.
- **Sintaxe**:
```c
    void free(void *ponteiro);
```
##### Ex:
```c
    free(valores);
```

### Calloc
- Faz basicamento o mesmo que o **malloc** porem com uma **sintaxe** **diferente**;
- **Sintaxe**
```c
    void *calloc(int qtd, int tam);
```
##### Ex
```c
    valores = calloc(qtd, sizeof(int));
```

### Realloc 
- Pode **mudar** ou **alterar** o tamanho do **espaço** de **memoria** **utilizado** no meio do progama
- Sintaxe
```c
    void *realloc(void *pt_alocado, int novo_tam);
```

##### Ex:
```c
    p = (char *)realloc(o, 24);
```


    
