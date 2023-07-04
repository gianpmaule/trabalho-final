#pragma once
#include "flor.h"

typedef struct dist_flor {
	float dist;
	const char* tipo;
} dist_flor;

const char* classify_KNN(flor* amostra, flor flores[], int size, int k);

void classify_sample(flor flores[], int size);