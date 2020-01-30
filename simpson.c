#include <stdio.h>
#include <math.h>

// Função a ser integrada
double f(double x) {
    return exp(x);
}

// Usado para calcular um intervalo
double simpson_base(double a, double b) {
    double h = (b - a) / 2;
    return (h / 3) * (f(a) + 4 * f(a + h) + f(b));
}

// Usado para calcular um intervalo dividindo em subintervalos
double simpson(double a, double b, unsigned vezes) {
	double total = 0;
	double h = (b - a) / vezes;
	printf("h: %.2lf\n", h);
	for (unsigned i = 0; i < vezes; ++i) {
		double intervalo_a = a + i * h;
		double intervalo_b = intervalo_a + h;
		double valor_no_intervalo = simpson_base(intervalo_a, intervalo_b);
		printf("[%.2lf,  %.2lf] = %.2lf\n", intervalo_a, intervalo_b, valor_no_intervalo);
		total += valor_no_intervalo;
	}
	return total;
}

int main() {
	// Calculando integral de e^x em [0, 10] com 4 subintervalos
    double valor = simpson(0, 10, 4);
    printf("Total: %.2lf\n", valor);
}