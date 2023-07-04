#pragma once

//quantidade de amostras de flores no arquivo iris.csv
#define FLORES 150

//quantidade de colunas de caracteristicas no arquivo iris.csv
#define COLUNAS 4

typedef struct flor {
	//0 comprimento_sepala
	//1 largura_sepala
	//2 comprimento_petala
	//3 largura_petala
	float caracteristicas[COLUNAS];
	const char* tipo;
} flor;