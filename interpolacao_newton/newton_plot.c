#include <stdlib.h>
#include <stdio.h>
//é necessario que o gnuplot seja instalado como variavel de ambiente
#define GNUPLOT "gnuplot -persist"	//CASO NAO TENHA O GNUPLOT DESABILITAR

typedef struct odd{
	float * fn; //contem as funcoes do tipo f[x0] ,..., f[x0],...,f[x0,...,xn]
} Odd;

typedef struct newton{
	int tam;    //contem a quantidade de respostas
	float * dn; //contem todas as respostas do dn
	float * xn; //contem todos os pontos x da fun��o
	float * yn; //contem todos as respostas da fun��o
	Odd * odd;  //operador diferen�a dividida
} newton;

// ====================== FUNCOES ==========================
newton * iniciar();
void  calcular(newton * nw, float * x, float * y);
void  exibirFuncao(newton * nw);
void  exibirFuncaox(newton * nw, float x);
float calcularx(newton * nw, float x);
void plotGnuplot(newton * nw, float xi, float xf, float step);
// =========================================================

int main(){
	newton * nw;

	float * x = (float[]){1, -2, 4};		//define os pontos de x
	float * y = (float[]){3, -3, 2};		//define os pontos f(x)
	int tam = 3; 							//quantidade de pontos
	float xi = -10, xf = 10, step = 0.1;	//configurações de plots
	
	nw = iniciar(tam);	//Cria a estrutura com um tamanho x
	calcular(nw, x, y); //x contem os pontos de x, y contem os pontos de f(x)
	exibirFuncao(nw);	//Exibe a função


	//prova que está funcionando
	printf("p2(1) = %f\n", calcularx(nw, 1));
	printf("p2(-2) = %f\n", calcularx(nw, -2));
	printf("p2(4) = %f\n\n", calcularx(nw, 4));

	//mostrando a expressão
	exibirFuncaox(nw, 1);
	exibirFuncaox(nw, -2);
	exibirFuncaox(nw, 4);

	//plota o gráfico no programa gnuplot 
	plotGnuplot(nw, xi, xf, step);

	system("pause");
	return 0;
}

newton * iniciar(int tam){
	int x = 0;
	newton * nw = calloc(1, sizeof(newton));
	
	nw->dn  = calloc(tam, sizeof(float));
	nw->xn  = NULL;
	nw->yn  = NULL;
	nw->odd = calloc(tam, sizeof(Odd));
	nw->tam = tam;
	
	do{
		nw->odd[x].fn = calloc(tam, sizeof(float));
		x++;
		tam--;
	} while(tam != 0);
	
	return nw;
}

void calcular(newton * nw, float * x, float * y){
	int i = 0;
	int cont = 0;
	int j = 0;
	
	nw->xn = x; //coloca o vetor com os pontos no vetor de pontos da estrutura
	nw->yn = y;
	cont = nw->tam;
	//enquanto i for menor que o tamanho do grau da fun��o
	while(i != nw->tam){
		j = 0;//resete o j
		//se for a primeira execuss�o
		if(i == 0){
			//atribua os valores do y para os valores de fn
			while(j != cont){
				nw->odd[i].fn[j] = nw->yn[j];
				j++; //incrementa para o proximo valor
			}
		} else {
			while(j != cont){
				nw->odd[i].fn[j] = (nw->odd[i - 1].fn[j + 1] - nw->odd[i - 1].fn[j])/(nw->xn[j+(nw->tam - cont)] - nw->xn[j]);
				j++;
			}
		}
		i++;	//incrementa a para a proxima coluna
		cont--; //decrementa a quantidade do controle
	}
		
	i = 0;
	while(i != nw->tam){
		nw->dn[i] = nw->odd[i].fn[0];
		i ++;
	}
}

void exibirFuncao(newton * nw){
	printf("Funcao: \n");
	printf("-----------------------------\n");
	printf("p%d(x) = (%.2f)", nw->tam - 1, nw->dn[0]);
	int cont = 1;
	int i;
	while(cont <= nw->tam - 1){
		i = 0;
		printf("+ (%.2f)", nw->dn[cont]);
		while(cont - i){
			printf("(x - (%.2f))", nw->xn[i]);
			i++;
		}
		cont ++;
	}
	printf("\n-----------------------------\n");
}

void exibirFuncaox(newton * nw, float x){
	printf("p%d(%.2f) = (%.2f)", nw->tam - 1, x, nw->dn[0]);
	int cont = 1;
	int i;
	while(cont <= nw->tam - 1){
		i = 0;
		printf("+ (%.2f)", nw->dn[cont]);
		while(cont - i){
			printf("(%.2f - (%.2f))",x, nw->xn[i]);
			i++;
		}
		cont ++;
	}
	printf(" = %.2f\n", calcularx(nw, x));
}
float calcularx(newton * nw, float x){
	float solucao = nw->dn[0];
	
	int cont = 1;
	int i;
	float sl, prod = 1;
	while(cont <= nw->tam - 1){
		i = 0;
		sl = nw->dn[cont];
		prod = 1;
		while(cont - i){
			prod *= (x - nw->xn[i]);
			i++;
		}
		solucao += sl * prod;
		cont ++;
	}
	
	return solucao;
}

void plotGnuplot(newton * nw, float xi, float xf, float step){
	FILE * arq;
	FILE *gp;
	arq = fopen("plot_data.txt", "w");
	fprintf(arq, "# x \t f(x) \n");
	while (xi <= xf){
		fprintf(arq, "%.2f \t %.2f \n", xi, calcularx(nw, xi));
		xi += step;
	}
	fclose(arq);

    gp = popen(GNUPLOT, "w");
    if (gp == NULL) {
        printf("Erro ao abrir pipe para o GNU plot.\n"
            "Instale com 'sudo apt-get install gnuplot'\n");
        exit(0);
    }
    fprintf(gp, "plot 'plot_data.txt'\n");
    fclose(gp);
}