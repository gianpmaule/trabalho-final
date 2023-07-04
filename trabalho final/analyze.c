#include <stdio.h>
#include "flor.h"
#include "loadcsv.h"

#include "statistics.h"
#include "classify_sample.h"

void analyze() {
	//tenta preencher o array flores.
	flor flores[FLORES];
	int error = loadcsv("iris.csv", flores, FLORES);
	if (error) return;
	printf("Dados carregados.\n");

	int input;
	printf("[1] Mostrar estatisticas\n[2] Classificar amostra\n[3] Sair\n");
	scanf_s("%d", &input);

	switch(input) {
		case 1: statistics(flores, FLORES); break;
		case 2: classify_sample(flores, FLORES); break;
		case 3: return;
	}

}