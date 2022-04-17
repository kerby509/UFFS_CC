//feito por Rafael Gama Fernandes e Eduardo Lazaretti para a disciplina de Cálculo I
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * pow(a,b) = a^b
 * M_E = aproximação da constante neperiana da biblioteca math.h
 */

//definindo f(x) = e^x + 2
double f(double x)
{
	return (pow(M_E, x) + (double) 2);
}

//pré-definindo a soma de Riemann de f(x)
double riemann(double x_inicial, double x_final, int numero_particoes)
{
                //instanciando a variável "soma" que vai guardar os adendos até eventualmente o valor total da soma
	double soma = 0,
                //instanciando "base", que guarda a largura fixa dos retângulos
                base = (x_final - x_inicial) / numero_particoes,
                //intanciando "lim_esq", que determinará o lado esquerdo de cada retângulo
				lim_esq = x_inicial,
				//instanciando "ci", que determinará o ponto a partir do qual será calculado a altura de cada retângulo
				ci;

	//o somatório em si
	for(int i = 1; i <= numero_particoes; i++)
	{
		//atualiza o ci para o valor no meio da base do retângulo atual
		ci = lim_esq + (base / 2);

		//adiciona o módulo da altura (f(ci)) vezes base à variável "soma"
		soma += f(ci) * base;

		//atualiza os lado esquerdo do triângulo para a próxima iteração
		lim_esq += base;

		// descomentar isso para ver os resultados do passo a passo
		// printf("ret %d: ci = %lf, base = %lf, lim_esq = %lf e soma = %lf\n", i, ci, base, lim_esq, soma);
	}

	return soma;
}

//programa em si
int main()
{
	double inicio, fim;
	int num_particoes;

	printf("\n\t............ SOMA DE RIEMANN ............\t\n\n");

	//solicita o intervalo a ser aplicada a soma de Riemann
	printf("Digite n irracional inicial e tecle Enter: ");
	scanf("%lf", &inicio);

	printf("Digite n irracional final e tecle Enter: ");
	scanf("%lf", &fim);

	printf("Digite o numero de particoes e tecle Enter: ");
	scanf("%d", &num_particoes);

    printf("\tinicio: %lf\n\tfim: %lf \n\tparticoes: %ld\n", inicio, fim, num_particoes);

	//atribui o resultado da soma de Riemann de f(x) de "inicio" a "fim" para a variável "resultado"
	double resultado = riemann(inicio, fim, num_particoes);

	//imprime o valor de "resultado"
	printf("Resultado aproximado: %lf unidades de area.\n", resultado);

	//segura o programa aberto até que se aperte algum botão
	scanf("\n");

	//protocolo padrão da linguagem
	return 0;
}
