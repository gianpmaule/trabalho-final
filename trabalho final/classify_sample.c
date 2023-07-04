#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "classify_sample.h"
#include "flor.h"


int compare_floats(const dist_flor* a, const dist_flor* b) {
	float arg1 = a->dist;
	float arg2 = b->dist;

	return (arg1 > arg2) - (arg1 < arg2);
	return arg1 - arg2;
}

const char* classify_KNN(flor* amostra, flor flores[], int size, int k) {
	dist_flor dists[FLORES];
	float dist_minima = 0;

	for (int i = 0; i < size; i++) {
		float dif_quadratica = 0;
		for (int j = 0; j < COLUNAS; j++) {
			dif_quadratica += pow((amostra->caracteristicas[j] - flores[i].caracteristicas[j]), 2);
		}
		float dist = sqrt(dif_quadratica);

		dists[i].dist = dist;
		dists[i].tipo = flores[i].tipo;
		printf("%f\n", dist);
	}
	qsort(dists, size, sizeof(dists[FLORES]), compare_floats);

	float sum_dists_setosa = 10000;
	float sum_dists_versicolor = 10000;
	float sum_dists_virginica = 10000;

	for (int i = 0; i < k; i++) {
		if (strcmp(dists[i].tipo, "setosa") == 0) {
			if (sum_dists_setosa == 10000) sum_dists_setosa = 0;
				sum_dists_setosa += dists[i].dist;
		}
		if (strcmp(dists[i].tipo, "versicolor") == 0) {
			if (sum_dists_versicolor == 10000) sum_dists_versicolor = 0;
			sum_dists_versicolor += dists[i].dist;
		}
		if (strcmp(dists[i].tipo, "virginica") == 0) {
			if (sum_dists_virginica == 10000) sum_dists_virginica = 0;
			sum_dists_virginica += dists[i].dist;
		}
	}

	float min_dist = min(min(sum_dists_setosa, sum_dists_versicolor), sum_dists_virginica);
	if (sum_dists_setosa == min_dist) amostra->tipo = "setosa";
	if (sum_dists_versicolor == min_dist) amostra->tipo = "versicolor";
	if (sum_dists_virginica == min_dist) amostra->tipo = "virginica";
}

void classify_sample(flor flores[], int size) {
	flor amostra = {0,0,0,0, "N.D."};
	float input;
	for (int i = 0; i < COLUNAS; i++) {
		switch (i) {
			case 0: printf("comprimento_sepala: \n"); break;
			case 1: printf("largura_sepala: \n"); break;
			case 2: printf("comprimento_petala: \n"); break;
			case 3: printf("largura_sepala: \n"); break;
		}
		scanf_s("%f", &input);
		amostra.caracteristicas[i] = input;
	}

	classify_KNN(&amostra, flores, size, 3);

	printf("%s", amostra.tipo);
}