# include <stdio.h>

int fact(int n){
    if (n <= 1){
        return n;
    }else{
        return n * fact(n-1);
    }
}

int main(){
    int n;
    printf("Digite o numero que deseja saber o fatorial: ");
    scanf("%i", &n);
    int fatorial = fact(n);
    printf("Fatorial de %i e: %i", n, fatorial);
    return 0;
}