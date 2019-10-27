#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcao(double);

int main(void){
    double a, b;
    int possui_raizes = 0;
    double erro;
    printf("Digite um intervalo [a,b]: ");
    scanf("%lf %lf", &a, &b);
	printf("Digite uma precisao E: ");
	scanf("%lf", &erro);
    //Testa se os pontos passados sao raizes
    if(funcao(a) == 0 || funcao(b) == 0){
        printf("%.2lf eh raiz da funcao", (a == 0) ? a : b);
        //system("pause");
        return 0;
    }

    //Percorre o intervalo buscando raizes
    if((funcao(a)*funcao(b)) < 0){
        possui_raizes = 1;
    }else{
        for(b; b > a; b -= erro*10){
            if(funcao(a)*funcao(b) < 0){
                if(b == -0){
                    b = 0;
                }
                if(funcao(b) == 0){
                    printf("%.2lf eh raiz da funcao", b);
                    system("pause");
                    return 0;
                }
                possui_raizes = 1;
                break;
            }
        }

        //Testa se os pontos passados sao raizes
        if(funcao(b) == 0 || funcao(b) <= erro){
            printf("%.2lf eh raiz da funcao", b);
            system("pause");
            return 0;
        }
    }

    if(possui_raizes == 0){
        printf("Nao existem raizes nesse intervalo \n");
        return 1;
    }else{
        printf("Existem raizes nesse intervalo [%.2lf, %.2lf] \n", a, b);
    }

    //Método da bisecção
    double x = (a+b)/2;

    while((fabs(funcao(x) > erro)) || (fabs(b - a) > erro)){
        if((funcao(a)*funcao(b)) < 0){
            b = x;
        }else{
            a = x;
        }
        x = (a+b)/2;
    }

    printf("(raiz por aproximacao) x = %.2lf", x);

    system("pause");
    return 0;
}

double funcao(double x){
    return (x*x*x)-(9*x) + 3;
}
