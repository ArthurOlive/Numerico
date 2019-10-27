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

        //Testa se os pontos passados são raízes
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
	
	//Entra com duas aproximacoes para x	
	double x_inicial, x_inicial_dois, x_iterativo = 0, x_temporario = 0;
	printf("Digite dos valores iniciais de x: ");
	scanf("%lf %lf", &x_inicial, &x_inicial_dois);
    
    //Testa se ambos os pontos sao raizes
	if(fabs(funcao(x_inicial)) <= erro || funcao(x_inicial) == 0){
		x_iterativo = x_inicial;
	}else if(fabs(funcao(x_inicial_dois)) <= erro || funcao(x_inicial_dois) == 0){
		x_iterativo = x_inicial_dois;
	}else{
		do{
			//Busca uma aproximacao para x a partir dos pontos passados
			x_iterativo = x_inicial_dois - ((funcao(x_inicial_dois) * (x_inicial_dois-x_inicial))/(funcao(x_inicial_dois) - funcao(x_inicial)));			
			x_inicial = x_inicial_dois;
			x_inicial_dois = x_iterativo;
			//Testa se o ponto eh raiz	
		}while( fabs(funcao(x_iterativo) > erro) || (fabs(x_inicial_dois - x_inicial) > erro) );
	}   

    printf("(raiz por aproximacao) x = %.4lf\n", x_iterativo);

    system("pause");
    return 0;
}

double funcao(double x){
    return (x*x*x) - (9*x) + 5;
}
