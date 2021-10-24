#ifndef __GENERADOR_H__
#define __GENERADOR_H__
#include <iostream>
using namespace std;
#define NUM_CASOS_POR_TIPO 5


// Contiene las subcadenas validas y las cadena que representa el caso peor, promedio y mejor para ellas
struct casoPorTipo{
	string casoPeor;
	string casoPromedio;
	string casoMejor;
	string subcadenasValidas[3];
};typedef casoPorTipo CasoPorTipo;

// Es un array de la estrutura comentada anteriormente
struct casosPorTipo{
	CasoPorTipo casos[NUM_CASOS_POR_TIPO];
};typedef casosPorTipo CasosPorTipo;


// Genera una cadena aleatoria de longitud 3
string generarCadenaLongitud3Aleatoria();

// Genera la cadena que representa el peor caso del algoritmo para las subcadenas pasadas como parámetro
string generarPeorCaso(string subcadenasValidas[3], int n);

// Genera la cadena que representa el caso promedio del algoritmo para las subcadenas pasadas como parámetro
string generarCasoPromedio(string subcadenasValidas[3], int n);

// Genera la cadena que representa el mejor caso del algoritmo para las subcadenas pasadas como parámetro
string generarMejorCaso(string subcadenasValidas[3], int n);

// Genera el peor, promedio y mejor caso del algoritmo para unas subcadenas generadas aleatoriamente
CasoPorTipo generarCasoPorTipo(int n);

// Genera los peores, promedios y mejores casos del algoritmo para unas subcadenas generadas aleatoriamente
CasosPorTipo generarCasosPorTipo(int n);


#endif