#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

double norm(double ** matrix, int m, int n) {
	double res = 0;
	
	int i, j;
	for (i = 0; i < m; ++i) {
		double temp;
		
		for (j = 0; j < m; ++j)
			temp += abs(matrix[j][i]);
		
		printf("%dª linha: %lf \n", i + 1, temp);
		
		res = temp > res ? temp : res;
		temp = 0;
	}
	
	return res;
}

double normInf(double ** matrix, int m, int n) {
	double res = 0;
	
	int i, j;
	for (i = 0; i < m; ++i) {
		double temp;
		
		for (j = 0; j < m; ++j)
			temp += abs(matrix[i][j]);
		
		printf("%dª linha: %lf \n", i + 1, temp);
		
		res = temp > res ? temp : res;
		temp = 0;
	}
	
	return res;
}

double frobeniusNorm(double ** matrix, int m, int n) {
	double sum = 0;
	
	int i, j;
	for (i = 0; i < m; ++i) {
		for (j = 0; j < m; ++j) {
			sum += pow(matrix[i][j], 2);
		}
	}
			
	return sqrt(sum);
}

int main() {
	setlocale(LC_ALL,"");
	
	int m, n;
	
	printf("Número de linhas: ");
	scanf("%d", &m);
	
	printf("Número de colunas: ");
	scanf("%d", &n);
	
	double ** matrix = (double**) malloc(m * sizeof(double*));
	int i;
	for (i = 0; i < m; ++i) {
		matrix[i] = (double*) malloc(n * sizeof(double));
	}
	
	for (i = 0; i < m; ++i) {
		int j;
		for (j = 0; j < n; ++j) {
			printf("\nElemento de A[%d][%d]: \n", i, j);
			scanf("%lf", &matrix[i][j]);
		}
	}
	
	printf("Resultado norma_1: %lf \n\n", norm(matrix, m, n));
	printf("Resultado norma_infinito: %lf \n", normInf(matrix, m, n));
	printf("Resultado norma de Frobenius: %lf \n", frobeniusNorm(matrix, m, n));

	return 0;
}
