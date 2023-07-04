#include "statistics.h"
#include "flor.h"
#include <stdio.h>
#include <math.h>

void statistics(flor flores[], int size) {
	for (int i = 0; i < COLUNAS; i++) {
		float minimo = flores[0].caracteristicas[i];
		float maximo = 0;
		float soma = 0;
		for (int j = 0; j < size; j++) {
			if (flores[j].caracteristicas[i] < minimo) minimo = flores[j].caracteristicas[i];
			if (flores[j].caracteristicas[i] > maximo) maximo = flores[j].caracteristicas[i];
			soma += flores[j].caracteristicas[i];
		}
		float media = soma / size;
		float somatorio = 0;
		for (int j = 0; j < size; j++) {
			somatorio += pow((flores[j].caracteristicas[i] - media), 2);
		}
		float desvio_padrao = sqrt(somatorio / size);
		switch (i) {
			case 0: printf("comprimento_sepala: \n"); break;
			case 1: printf("largura_sepala: \n"); break;
			case 2: printf("comprimento_petala: \n"); break;
			case 3: printf("largura_sepala: \n"); break;
		}
		printf("Minimo: %f\nMaximo: %f\nMedia: %f\nDesvio padrao: %f\n\n", minimo, maximo, media, desvio_padrao);
	}
	
}