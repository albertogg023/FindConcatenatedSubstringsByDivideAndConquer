#ifndef __EJERCICIO10_D_Y_V_H__
#define __EJERCICIO10_D_Y_V_H__
#include <iostream>
#include <list>
using namespace std;


// Devuelve si la cadena dada es igual a alguna de las subcadenas dadas
bool esSubcadenaDyV(string cadena, string subcadenasValidas[3]);

// Calcula el índice medio entre dos índices dados
int dividir(int indIzq, int indDer);

// Soluciona cadenas de longitud 6
list<int> solucionCasoBase(string cadena, int ind, string subcadenasValidas[3]);

// Soluciona cadenas de longitud menores que 12
list<int> solucionDirecta(string cadena, int indIzq, int indDer, string subcadenasValidas[3]);

// Juntamos las soluciones de cada una de las subcadenas en las que dividimos el problema,
// y añadimos las perdidas al dividir el problema
list<int> combina(string cadena, int indCorte, list<int> solucionIzq, list<int> solucionDer, string subcadenasValidas[3]);

// Función que devuelve la solucíon del ejercicio 10 aplicando la técnica Divide y Vencerás
list<int> concatenatedStrings_DyV_aux(string cadena, int indIzq, int indDer, string subcadenasValidas[3]);

// Función que llama a la función que resuelve el ejercicio 10 por Divide y Vencerás
list<int> concatenatedStrings_DyV(string cadenaSolucionar, string subcadenasValidas[3]);


#endif