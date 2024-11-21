# include <stdio.h>

int fibonacci(int n){
    if (n <= 1){
        return n;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }

}

int main(){
    int n;
    printf("Digite o numero de termos da sequencia fibonacci: ");
    scanf("%i", &n);
    for (int i = 0; i < n; i++){
        printf("F%i=%i - ", i, fibonacci(i));
    }


    return 0;
}