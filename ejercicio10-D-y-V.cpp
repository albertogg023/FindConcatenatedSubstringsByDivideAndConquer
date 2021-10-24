#include "ejercicio10-D-y-V.h"
#include <iostream>
#include <list>
using namespace std;


// Devuelve si la cadena dada es igual a alguna de las subcadenas dadas
bool esSubcadenaDyV(string cadena, string subcadenasValidas[3]){
    return cadena.compare(subcadenasValidas[0]) == 0  
        || cadena.compare(subcadenasValidas[1]) == 0
        || cadena.compare(subcadenasValidas[2]) == 0;
}

// Calcula el índice medio entre dos índices dados
int dividir(int indIzq, int indDer){  
    return (indDer+indIzq)/2 + 1;
}

// Soluciona cadenas de longitud 6
list<int> solucionCasoBase(string cadena, int ind, string subcadenasValidas[3]){
    list<int> solucion = list<int>();
    if(esSubcadenaDyV(cadena.substr(ind, 3), subcadenasValidas) 
    && esSubcadenaDyV(cadena.substr(ind + 3, 3), subcadenasValidas))
        solucion.push_back(ind);
    return solucion;
}

// Soluciona cadenas de longitud menores que 12
list<int> solucionDirecta(string cadena, int indIzq, int indDer, string subcadenasValidas[3]){ 
    list<int> solucion = list<int>();
    for(int i = indIzq; i + 5 <= indDer; ++i)
        solucion.merge( solucionCasoBase(cadena, i, subcadenasValidas) );
    return solucion;
}

// Juntamos las soluciones de cada una de las subcadenas en las que dividimos el problema,
// y añadimos las perdidas al dividir el problema
list<int> combina(string cadena, int indCorte, list<int> solucionIzq, list<int> solucionDer, string subcadenasValidas[3]){
    solucionIzq.merge(solucionDer);
    for(int i = 0; i < 5; ++i)
        solucionIzq.merge(solucionCasoBase(cadena, indCorte-i, subcadenasValidas));
    return solucionIzq;
}

// Función que devuelve la solucíon del ejercicio 10 aplicando la técnica Divide y Vencerás
list<int> concatenatedStrings_DyV_aux(string cadena, int indIzq, int indDer, string subcadenasValidas[3]){
    if((indDer - indIzq + 1) >= 12){
        int indCorte = dividir(indIzq, indDer);
        list<int> solucionIzq = concatenatedStrings_DyV_aux(cadena, indIzq, indCorte, subcadenasValidas);
        list<int> solucionDer = concatenatedStrings_DyV_aux(cadena, indCorte + 1, indDer, subcadenasValidas);
        return combina(cadena, indCorte, solucionIzq, solucionDer, subcadenasValidas);
    }
    else
        return solucionDirecta(cadena, indIzq, indDer, subcadenasValidas);
}

// Función que llama a la función que resuelve el ejercicio 10 por Divide y Vencerás
list<int> concatenatedStrings_DyV(string cadenaSolucionar, string subcadenasValidas[3]){
     return concatenatedStrings_DyV_aux(cadenaSolucionar, 0, cadenaSolucionar.size() - 1, subcadenasValidas);
}