#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "flor.h"
#include "loadcsv.h"

//carrega o arquivo csv com o formato especificado em iris.csv
//molda o par�metro flores[] de acordo com as especifica��es do tipo flor
//se n�o houver erros, retorna 0
int loadcsv(const char* name, flor flores[], int size) {
	//tenta abrir o arquivo com as amostras
	FILE* file = NULL;
	errno_t err = fopen_s(&file, name, "r");
	if (err) return 1;

	//cria um buffer de cada linha do arquivo (at� cada newline \\n)
	char buffer[BUFFER];
	for (int i = -1; fgets(buffer, BUFFER, file) != NULL; i++) {
		//pula a linha com os nomes das colunas
		if (i == -1) continue;

		//utiliza a fun��o strtok_s para iterar cada caracter�stica da flor atual e armazena
		//no struct flor de acordo com a coluna
		char* nexttoken = NULL;
		char* token = strtok_s(buffer, ",", &nexttoken);
		for (
			int j = 0;
			j < 4;
			token = strtok_s(NULL, ",", &nexttoken), j++
		) {
			flores[i].caracteristicas[j] = atof(token);
		}
		//giomar por favor aceite este favo de mel a seguir:
		//token tinha um caractere a mais (setosa, por exemplo, tinha 7 caracteres, um mais antes de '\0')
		//por isso, ao inv�s de strlen(token), eu utilizei strlen(token) - 1
		const int strsize = strlen(token) - 1;
		char* tipo = malloc(strsize);
		memcpy(tipo, token, strsize);
		tipo[strsize] = 0;
		flores[i].tipo = tipo;
		//fim do favo de mel
	}
	return 0;
}
