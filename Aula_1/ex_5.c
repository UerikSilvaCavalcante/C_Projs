# include <stdio.h>

int main(){
    int n;
    float media = 0.0;

    printf("Digite um valor para n: ");
    scanf("%i", &n);
    for (int i = 0; i < n; i ++){
        media += i;
    }

    media = media / n;
    printf("Media de N termos: %.2f", media);


    return 0;
}