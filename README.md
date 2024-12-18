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

# Alocação de memoria dinamica com vetor e matriz
- Criar um vetor dinamico (ou seja que possa se adequar ao tamanho desejado pelo usuario)
#### Ex:
```c
    struct produto {
        char nome[80];
        float preco;
    }

    int n, i;
    printf("Digite a quantidade de produtos desejado");
    scanf("%i", &n);
    struct produto *ptrProduto = (struct produto *)malloc(n * sizeof(struct     produto)). // Cria um vetor do tipo da struct produto com o tamanho de n que foi passsado pelo usuario
    for( i = 0; i < n; i++){
        printf("Nome do Produto %i: ", i+1);
        scanf("%s", &ptrProduto[i].nome);
        printf("Preço do Produto %i: ", i+1);
        scanf("%f", &ptrProduto[i].preco);
    }

    for(i = 0; i < n; i++){
        printf("Produto %i\n", i+1);
        printf("Nome: %s\n", ptrProduto[i].nome);
        printf("Preço: %f\n", ptrProduto[i].preco);
        printf("-------------------------------");
        
    }

    free(ptrProdutos); // libera espaço na memoria

```
- Criar uma matriz dinamica tambem e possivel;
#### Ex: 
```c
    int linhas, colunas , i, j;
    int **matriz;
    printf("Digite o numero de linhas: ");
    scanf("%i", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%i", &colunas);

    matriz = (int *)malloc(linhas * sizeof(int));
    for (i = 0; i < linhas; i ++){
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }
    for (i = 0; i < linhas; i ++){
        for (j = 0; j < colunas; j++){
            print("Digite um valor para a matriz na posicao (%i,%i): ", i +1 , j+1);
            scanf("%i", &matriz[i][j]);
        }
    }

```

#### Ex
```c
    int *criaVetor(int n){
        int *vetor = (int *)malloc((n +1) * sizeof(int));
        if (vetor == NULL){
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }
        return vetor;
    }

    void calcularFatorial(int *vetor, int n){
        vetor[0] = 1
        int i;
        for(i = 1; i <= n ; i++){
            vetor[i] = vetor[i - 1] * i;
            // i = 1
            // vetor[1] = vetor[1-1] * 1 = vetor[0] * 1 = 1 * 1 = 1
            // vetor[2] = vetor[2-1] * 2 = vetor[1] * 2 = 1 * 2 = 2
            // vetor[3] = vetor[3-1] * 3 = vetor[2] * 3 = 2 * 3 = 6
            // vetor[4] = vetor[4-1] * 4 = vetor[3] * 4 = 6 * 4 = 24
            // vetor[5] = vetor[5-1] * 5 = vetor[4] * 5 = 24 * 5 = 120
        }
    }

    voi exibiVetor(int *vetor, int n){
        int i;
        for (i = 0; i< n; i++){
            printf("%d = %d\n", i, vetor[i]);
        }
    }

    int numero;
    printf("Digite um numero para calcular seu fatorial: ");
    scanf("%i", &numero);
    int *fatorial = criarVetor(numero);
    calcularFatorial(fatorial, numero);
    exibirVetor(fatorial, numero);
    free(fatorial);
``` 
