#include <stdio.h>
#include <stdbool.h>

#include "simplex.h"

int main(){
    int vars, rest; // Numero de variaveis e restricoes

	vars = 2;
    rest = 2;
    float z[2] = {3, 2};
    float a[2][2] = {{1, 1}, {5, 2}};
    float b[2] = {6, 20};

    /*
	vars = 3;
    rest = 4;

    float z[3] = {10, 20, 30};
    float a[4][3] = {{2, 2, 4}, {0, 4, 3}, {1, 0, 0}, {4, 3, 0}};
    float b[4] = {300, 200, 20, 50};
    */

	float maximo = 0;

    printf(" Tabela inicial: ");

    mostrar_tabela (rest, vars, a, z, b);

    simplex( rest, vars, z, a, b, maximo );
}

