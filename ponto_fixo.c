#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcao(double);
double funcao_iteracao(double);

int main(void){
    double a, b;
    int possui_raizes = 0;
    double erro;
    
	printf("Digite um intervalo [a,b]: ");
    scanf("%lf %lf", &a, &b);
	printf("Digite uma precisao E: ");
	scanf("%lf", &erro);
	
    //Testa se os pontos passados são raízes
    if(funcao(a) == 0 || funcao(b) == 0){
        printf("%.2lf eh raiz da funcao", (a == 0) ? a : b);
        system("pause");
        return 0;
    }

    //Percorre o intervalo buscando raízes
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

        //Testa se os pontos passados são raízes
        if(funcao(b) == 0 || funcao(b) <= erro){
            printf("%.2lf eh raiz da funcao", b);
            //system("pause");
            return 0;
        }
    }

    if(possui_raizes == 0){
        printf("Nao existem raizes nesse intervalo \n");
        return 1;
    }else{
        printf("Existem raizes no [%.2lf, %.2lf] \n", a, b);
    }

	double x_inicial, x_iterativo = 0, x_temporario = 0;
	printf("Digite um x inicial: ");
	scanf("%lf", &x_inicial);
    
	if(fabs(funcao(x_inicial)) <= erro || fabs(funcao(x_inicial)) == 0){
		x_iterativo = x_inicial;
	}else{
		do{
			//Calcula um valor para x aproximado a partir da funcao de iteracao
			x_iterativo = funcao_iteracao(x_inicial);
			x_temporario = x_inicial;
			x_inicial = x_iterativo;
			//Testa se o valor satisfaz a condicao de ser raiz			
		}while( fabs(funcao(x_iterativo) > erro) || (fabs(x_iterativo - x_temporario) > erro) );
	}   

    printf("(raiz por aproximacao) x = %.3lf", x_iterativo);

    system("pause");
    return 0;
}

double funcao(double x){
    return (x*x*x) + (8*x) - 7;
}

double funcao_iteracao(double x){
	return (7-(x*x*x))/8;
}
