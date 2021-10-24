validacion: validador.o generadorCasosPrueba.o ejercicio10-D-y-V.o ejercicio10-Iterativo.o
	g++ -o validacion -Wall validador.o generadorCasosPrueba.o ejercicio10-D-y-V.o ejercicio10-Iterativo.o

validador.o: validador.cpp ejercicio10-D-y-V.h ejercicio10-Iterativo.h generadorCasosPrueba.h
	g++ -c validador.cpp

ejercicio10-D-y-V.o: ejercicio10-D-y-V.cpp ejercicio10-D-y-V.h
	g++ -c ejercicio10-D-y-V.cpp

ejercicio10-Iterativo.o: ejercicio10-Iterativo.cpp ejercicio10-Iterativo.h
	g++ -c ejercicio10-Iterativo.cpp

generadorCasosPrueba.o: generadorCasosPrueba.cpp generadorCasosPrueba.h
	g++ -c generadorCasosPrueba.cpp

clean:
	rm -f *.o validacion

run:
	./validacion