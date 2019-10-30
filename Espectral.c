#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

double ** transpose(double ** matrix, int m, int n) {
	double ** tMatrix = (double**) malloc(n * sizeof(double*));
	
	int i, j;
	for (i = 0; i < n; ++i) {
		tMatrix[i] = (double*) malloc(m * sizeof(double));

		for (j = 0; j < m; ++j) {
			tMatrix[i][j] = matrix[j][i];
		}
	}
	
	return tMatrix;
}

double ** multiply(double ** matrixA, double ** matrixB, int m, int n) {
	int i, j, k;
	
	double ** rMatrix = (double**) malloc(m * sizeof(double*));
	
	for (i = 0; i < m; ++i) {
		rMatrix[i] = (double*) malloc(n * sizeof(double));
		
		for (j = 0; j < n; ++j) {
			double sum = 0;
			
			for (k = 0; k < n; ++k) {
				sum += matrixA[i][k] * matrixB[k][j]; 
			}
			
			rMatrix[i][j] = sum;
		}
	}
	
	return rMatrix;
}

double trace(double ** matrix, int m) {
	double res;
	
	int i;
	for (i = 0; i < m; ++i) {
		res += matrix[i][i];
	}
	
	return res;
}

double determinant(double ** matrix, int m) {
	int i, j, count, i_count, j_count, det = 0;
	double r;
	
	if (m == 1) {
		return matrix[0][0];
	}
	
	if (m == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	
	return det;
}

double maxEigenValue(double ** matrix, int m) {
	if (m == 2) {
		double tr = trace(matrix, 2) * -1;
		double det = determinant(matrix, m);
		
		double delta = pow(tr, 2) - 4 * det;
		double x1 = ( (tr * -1) + sqrt(delta) ) / 2;
		double x2 = ( (tr * -1) - sqrt(delta) ) / 2;
		
		return x1 > x2 ? x1 : x2;
	}
}

int main() {
	setlocale(LC_ALL, "");
	
	// Criar matriz NxN
	// m = linhas
	// n = colunas
	int m, n;
	
	printf("Número de linhas: ");
	scanf("%d", &m);
	
	printf("Número de colunas: ");
	scanf("%d", &n);
	
	// TODO: juntar só num for pro relatório
	double ** matrix = (double**) malloc(m * sizeof(double*));
	int i;
	for (i = 0; i < m; ++i) {
		matrix[i] = (double*) malloc(n * sizeof(double));
	}
	
	
	// Popular
	for (i = 0; i < m; ++i) {
		int j;
		for (j = 0; j < n; ++j) {
			printf("\nElemento de A[%d][%d]: \n", i, j);
			scanf("%lf", &matrix[i][j]);
		}
	}
	
	// Obtém a transposta da matriz
	double ** tMatrix = transpose(matrix, m, m);
	
	// Multiplica a matriz pela transposta
	double ** rMatrix = multiply(matrix, tMatrix, m, m);
	
	// Obtém a determinante da multiplicação de A pela sua
	// transposta
	
	double max = maxEigenValue(rMatrix, m);
	printf("\nDeterminante: %lf\n", determinant(rMatrix, m));
	printf("Autovalor: %lf\n", max);
	printf("Norma espectral: %lf\n", sqrt(max));
	
	return 0;
}
