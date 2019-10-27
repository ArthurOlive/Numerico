#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcao(double);
double derivada(double);

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
        for(b; b > a; b -= erro){
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

        //Testa se os pontos passados sÃ£o raÃ­zes
        if(funcao(b) == 0 || funcao(b) <= erro){
            printf("%.2lf eh raiz da funcao", b);
            system("pause");
            return 0;
        }
    }

	//Notifica o usuário se há ou não raízes
    if(possui_raizes == 0){
        printf("Nao existem raizes nesse intervalo \n");
        return 1;
    }else{
        printf("Existem raizes no [%.2lf, %.2lf] \n", a, b);
    }
	
	//Entrada de um palpite inicial para x
	double x_inicial, x_iterativo = 0, x_temporario = 0;
	printf("Digite um x inicial: ");
	scanf("%lf", &x_inicial);
    
	if(fabs(funcao(x_inicial)) <= erro){
		x_iterativo = x_inicial;
	}else{
		do{
			x_temporario = x_inicial;
			//novo ponto x para cada iteracao
			x_iterativo = x_temporario - (funcao(x_temporario)/derivada(x_temporario));			
			x_inicial = x_iterativo;			
		}while( fabs(funcao(x_iterativo) > erro) || (fabs(x_iterativo - x_temporario) > erro) );
	}   

    printf("(raiz por aproximacao) x = %.4lf\n", x_iterativo);

    system("pause");
    return 0;
}

double funcao(double x){
    return (x*x*x) - (9*x) + 5;
}

double derivada(double x){
	return 3*(x*x)-9;
}
