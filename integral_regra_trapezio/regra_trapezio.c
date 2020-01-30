#include <stdlib.h>
#include <stdio.h>

float f(float x);

int main(){
     //ponto inical e final
    float a, b;
    //distancia dos pontos
    double h, area = 0;

    printf("Digite o a : ");
    scanf("%f", &a);

    printf("Digite o b: ");
    scanf("%f", &b);

    h = (b - a);

    area += (f(a) + f(b)) * h / 2;

    printf("A integral e : %lf \n", area);

    system("pause");
    return 0;
}

float f(float x){
    //f(x) = x^2
    return x * x;
}