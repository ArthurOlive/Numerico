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
    //variavel auxiliar
    double aux;

    printf("Digite o a : ");
    scanf("%f", &a);

    printf("Digite o b: ");
    scanf("%f", &b);

    printf("Digite a quantidade passos: ");
    scanf("%d", &passos);

    h = (b - a) / passos;

    //soma (f(x1) + f(x2) + ... + f(xn-1))
    for (float i = a + h; i < b; i += h){
        aux += f(i);
    }

    area = h / 2 * ( f(a) + 2 * aux + f(b));

    printf("A integral e : %lf \n", area);

    system("pause");
    return 0;
}

float f(float x){
    //f(x) = x^2
    return x * x;
}