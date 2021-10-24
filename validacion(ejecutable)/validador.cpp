#include "generadorCasosPrueba.h"
#include "ejercicio10-D-y-V.h"
#include "ejercicio10-Iterativo.h"
#include <iostream>
#include <list>
using namespace std;
#define NUM_CADENAS_L9_MAX_VALIDACION 10000


// Procedimiento que imprime por pantalla el resultado de aplicar el algoritmo del ejercicio 10
void imprimeSolucion(list<int> solucion){
    if(!solucion.empty()){
        cout << "La solución es: " << solucion.size() << endl<< "Se encuentran en las posiciones:" << endl;
        list<int>::iterator it = solucion.begin();
        while( it != solucion.end() ){
            cout << " " << *it+1 << endl; 
            ++it;
        }
    }
    else
        cout << "No hay ninguna solución";
    cout << endl;

}

// Función que comprueba si dos listas son iguales
bool solucionesIguales(list<int> solucion_D_Y_V, list<int> solucionIterativa){
    if( ( solucion_D_Y_V.empty() && solucionIterativa.empty() ) || ( !solucion_D_Y_V.empty() && !solucionIterativa.empty() ) )
    	return true;
    else{
        list<int>::iterator it_D_Y_V = solucion_D_Y_V.begin();
        list<int>::iterator itIterativo = solucionIterativa.begin();
        while( it_D_Y_V != solucion_D_Y_V.end() && itIterativo != solucionIterativa.end() ){
            if(*it_D_Y_V != *itIterativo)
            	return false;
            ++it_D_Y_V; ++itIterativo;
        }
        return it_D_Y_V == solucion_D_Y_V.end() && itIterativo == solucionIterativa.end();
    }

}


// Programa principal que:
// 1. Genera numerosos casos de prueba para cada tamaños,
//    cada caso de prueba tiene sus subcadenas válidas (generadas aleatoriamente),
//    así como una cadena que representa el tiempo peor, otra el promedio y otra el mejor
// 2. Obtiene la solución para cada caso, tanto por el método iterativo como por aquel
//    que emplea la técnica Divide y Vencerás
// 3. Comprueba que las soluciones sean iguales para ambos métodos
// 4. Si todos las soluciones para de todos los casos de prueba son iguales para ambos métodos y no surgen errores,
//    todo funciona perfectamente
// Aclaración. Téngase en cuenta que se hacen resuelven casos de tamaños desde muy pequeños, 9 carácteres (1 numSubcadenaL9),
//             hasta tamaños muy grandes 90000 carácteres (10000 numSubcadenaL9).
//             Así como también, para cada uno de estos tamaños, se generar varios casos de prueba y cada uno de ellos tiene
//             un caso peor, promedio y mejor.
//             Por tanto, el proceso validación tarda un tiempo considerable (3 min aprox.) debido al grandísimo volumen de los tests
int main(){
	bool ok = true;
    CasosPorTipo casosDePrueba;
    for(int numSubcadenasL9 = 1; numSubcadenasL9 <= NUM_CADENAS_L9_MAX_VALIDACION; numSubcadenasL9 = numSubcadenasL9*10){
    	casosDePrueba = generarCasosPorTipo(numSubcadenasL9    );
	    for(int i=0; i<NUM_CASOS_POR_TIPO; ++i){
	         if ( !solucionesIguales( concatenatedStrings_DyV(casosDePrueba.casos[i].casoPeor, casosDePrueba.casos[i].subcadenasValidas),
	        		concatenatedStrings_Iterativo(casosDePrueba.casos[i].casoPeor, casosDePrueba.casos[i].subcadenasValidas) )
	        		|| !solucionesIguales( concatenatedStrings_DyV(casosDePrueba.casos[i].casoPromedio, casosDePrueba.casos[i].subcadenasValidas),
	        		concatenatedStrings_Iterativo(casosDePrueba.casos[i].casoPromedio, casosDePrueba.casos[i].subcadenasValidas) )
	        		|| !solucionesIguales( concatenatedStrings_DyV(casosDePrueba.casos[i].casoMejor, casosDePrueba.casos[i].subcadenasValidas),
	        		concatenatedStrings_Iterativo(casosDePrueba.casos[i].casoMejor, casosDePrueba.casos[i].subcadenasValidas) )
	        	)
	         {
	         	ok = false; cout << "ERROR: no coinciden las soluciones" << endl;
	         }
             else{
                cout << "CORRECTO: coinciden las soluciones" << endl;
             }
	    } 
    }
    if(ok)
        cout << "ÉXITO: el algoritmo que emplea la técnica Divide y Vencerás da los mismos resultados que el algoritmo iterativo para todos los casos de prueba" << endl; 
    else
        cout << "ERROR: el algoritmo que emplea la técnica Divide y Vencerás no da los mismos resultados que el algoritmo iterativo" << endl; 
    return 0;
}
