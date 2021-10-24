#include "ejercicio10-Iterativo.h"
#include <iostream>
#include <list>
using namespace std;


// Devuelve si la cadena dada es igual a alguna de las subcadenas dadas
bool esSubcadena(string cadena, string subcadenasValidas[3]){
    return cadena.compare(subcadenasValidas[0]) == 0  
        || cadena.compare(subcadenasValidas[1]) == 0
        || cadena.compare(subcadenasValidas[2]) == 0;
}

// Soluciona cadenas de longitud 6
list<int> solucionSubcadenasConcatenadas(string cadena, int ind, string subcadenasValidas[3]){
    list<int> solucion = list<int>();
    if(esSubcadena(cadena.substr(ind,3), subcadenasValidas) 
    && esSubcadena(cadena.substr(ind+3,3), subcadenasValidas))
        solucion.push_back(ind);
    return solucion;
}

// Función que devuelve la solucíon del ejercicio 10 resolviéndose de forma iterativa
list<int> concatenatedStrings_Iterativo(string cadena, string subcadenasValidas[3]){
    list<int> solucion = list<int>();
    for(int i = 0; i + 5 <= cadena.size()-1; ++i){
        solucion.merge( solucionSubcadenasConcatenadas(cadena, i, subcadenasValidas) );
    }
    return solucion;
}