#include <stdlib.h>
#include <stdio.h>

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
    // b passa a ser o primeiro ponto depois de a
    b = a + h;

    for (int i = 0; i < passos; i ++){
        area += (f(a) + f(b)) * h / 2;
        a += h;
        b += h;
    }

    printf("A integral e : %lf \n", area);

    system("pause");
    return 0;
}

float f(float x){
    //f(x) = x^2
    return x * x;
}