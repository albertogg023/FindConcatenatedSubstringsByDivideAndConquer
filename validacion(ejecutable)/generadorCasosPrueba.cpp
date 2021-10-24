#include "generadorCasosPrueba.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


// Genera una cadena aleatoria de longitud 3
string generarCadenaLongitud3Aleatoria(){
	string cadena = "";
	cadena += char('a'+rand()%25);
	cadena += char('a'+rand()%25);
	cadena += char('a'+rand()%25);
	return cadena;
}

// Genera la cadena que representa el peor caso del algoritmo para las subcadenas pasadas como parámetro
string generarPeorCaso(string subcadenasValidas[3], int n){
	string resultado;
	for(int i=0; i<n; ++i)
		resultado = resultado + subcadenasValidas[2] + subcadenasValidas[2] + subcadenasValidas[2]; // para que en el 'if' de 'esSubcadena' llegue hasta la ultima comprobación y se ejecute su cuerpo.
	return resultado;																				// Además, hace que se ejecute el cuerpo del 'if' en la función 'solucionCasoBase' también
}

// Genera la cadena que representa el caso promedio del algoritmo para las subcadenas pasadas como parámetro
string generarCasoPromedio(string subcadenasValidas[3], int n){
	string resultado = "";
	for(int i=0; i<n; ++i)
		resultado = resultado + generarCadenaLongitud3Aleatoria() + generarCadenaLongitud3Aleatoria() + generarCadenaLongitud3Aleatoria();
	return resultado;
}

// Genera la cadena que representa el mejor caso del algoritmo para las subcadenas pasadas como parámetro
string generarMejorCaso(string subcadenasValidas[3], int n){
	string resultado;
	for(int i=0; i<n; ++i)
		resultado = resultado + subcadenasValidas[0] + subcadenasValidas[0] + subcadenasValidas[0]; // para que en el 'if' de 'esSubcadena' termine en la primera comprobación y no se ejecute su cuerpo.
	return resultado;																				// Además, también evita que se ejecute el cuerpo del if en 'solucionCasoBase'
}

// Genera el peor, promedio y mejor caso del algoritmo para unas subcadenas generadas aleatoriamente
CasoPorTipo generarCasoPorTipo(int n){
	CasoPorTipo resultado;
	resultado.subcadenasValidas[0] = generarCadenaLongitud3Aleatoria();
	resultado.subcadenasValidas[1] = generarCadenaLongitud3Aleatoria();
	resultado.subcadenasValidas[2] = generarCadenaLongitud3Aleatoria();
	resultado.casoPeor = generarPeorCaso(resultado.subcadenasValidas, n);
	resultado.casoPromedio = generarCasoPromedio(resultado.subcadenasValidas, n);
	resultado.casoMejor = generarMejorCaso(resultado.subcadenasValidas, n);
	return resultado;
}

// Genera los peores, promedios y mejores casos del algoritmo para unas subcadenas generadas aleatoriamente
CasosPorTipo generarCasosPorTipo(int n){
	srand((int)time(0));
	CasosPorTipo casosDePrueba;
	for(int i=0; i<NUM_CASOS_POR_TIPO; ++i)
		casosDePrueba.casos[i] = generarCasoPorTipo(n);
	return casosDePrueba;
}
