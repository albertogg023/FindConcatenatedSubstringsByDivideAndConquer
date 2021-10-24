#ifndef __EJERCICIO_10_ITERATIVO_H__
#define __EJERCICIO_10_ITERATIVO_H__
#include <iostream>
#include <list>
using namespace std;


// Devuelve si la cadena dada es igual a alguna de las subcadenas dadas
bool esSubcadena(string cadena, string subcadenasValidas[3]);

// Soluciona cadenas de longitud 6
list<int> solucionSubcadenasConcatenadas(string cadena, int ind, string subcadenasValidas[3]);

// Función que devuelve la solucíon del ejercicio 10 resolviéndose de forma iterativa
list<int> concatenatedStrings_Iterativo(string cadena, string subcadenasValidas[3]);


#endif