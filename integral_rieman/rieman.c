#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x);

int main(){
    //ponto inical e final
    float a, b;
    //distancia dos pontos
    double h, area = 0;
    //quantidade de passos de a ate b
    int passos;

    printf("Digite o a : ");
    scanf("%f", &a);

    printf("Digite o b: ");
    scanf("%f", &b);

    printf("Digite a quantidade passos: ");
    scanf("%d", &passos);

    h = (b - a) / passos;

    
    if( h == 0 ){
        printf("Estorou o tamanho maximo do tipo double");
    }
    
    printf("passo : %lf \n", h);

    for (int i = 0; i < passos; i ++){
        area += f(a) * h;
        a += h;
    }

    printf("A integral e : %lf \n", area);

    system("pause");
    return 0;
}

float f(float x){
    //f(x) = x^2
    return x * x;
}