
public class matrizes_triangulares {

	public static double[] matrizTriangularSuperior(double matriz[][], int linhas, int colunas) {
		double incognitas[] = new double[colunas - 1]; // salva as variáveis (x y z etc) 
		int indexIncognitas = colunas - 2; // salva qual variável estamos calculando
		for (int i = linhas - 1; i >= 0; --i) {
			incognitas[indexIncognitas] = matriz[i][colunas - 1]; // começamos com o valor da incógnita igual a b
			for (int j = colunas - 2; j >= i; --j) {
				if (i == j) {
					incognitas[indexIncognitas] /= matriz[i][j];
				} else {
					incognitas[indexIncognitas] -= matriz[i][j] * incognitas[j];   
				}
			}
			--indexIncognitas;
		}
		return incognitas;
	}
	
	public static double[] matrizTriangularInferior(double matriz[][], int linhas, int colunas) {
		double incognitas[] = new double[colunas - 1]; // salva as variáveis (x y z etc) 
		int indexIncognitas = 0; // salva qual variável estamos calculando
		for (int i = 0; i < linhas; ++i) {
			incognitas[indexIncognitas] = matriz[i][colunas - 1]; // começamos com o valor da incógnita igual a b
			for (int j = 0; j <= i; ++j) {
				if (i == j) {
					incognitas[indexIncognitas] /= matriz[i][j];
				} else {
					incognitas[indexIncognitas] -= matriz[i][j] * incognitas[j];   
				}
			}
			++indexIncognitas;
		}
		return incognitas;
	}
	
	public static void main(String[] args) {
		
		final int linhas = 3;
		final int colunas = 4;
		
		// Matriz triangular superior de exemplo
		final double matriz[][] = {
			{2, -3, 2, 1},
			{0, 1, -4, 8},
			{0, 0, 1, 35},
		};
		final double incognitas[] = matrizTriangularSuperior(matriz, linhas, colunas);

		System.out.println("Resultado da matriz superior: ");
		for (int i = 0; i < incognitas.length; ++i)
			System.out.printf("x%d = %.1f\n", i, incognitas[i]);
		System.out.println();
		
		// Matriz triangular inferior de exemplo
		final double matriz2[][] = {
			{2, 0, 0, 2},
			{3, 4, 0, 15},
			{4, 5, 6, 49},	
		};
		final double incognitas2[] = matrizTriangularInferior(matriz2, linhas, colunas);
		
		System.out.println("Resultado da matriz inferior: ");
		for (int i = 0; i < incognitas.length; ++i)
			System.out.printf("x%d = %.1f\n", i, incognitas2[i]);
	}

}
