# Regla por defecto para generar la gráfica
all: compilar link plot

compilar:
	g++ -O3 main.cpp modulacion/Coffee.cpp modulacion/Walk.cpp modulacion/Calculos.cpp -o ./main.x
	g++ -O3 punto_1_3.cpp modulacion/Coffee.cpp modulacion/Walk.cpp modulacion/Calculos.cpp -o ./p1_3.x

# Regla para ejecutar el programa y generar la matriz
link: ./main.x ./p1_3.x
	./main.x >py/datos.dat
	./p1_3.x >py/Entropy_size.dat
	rm -f *.x	
plot: 
	python3 py/Tasa.py py/datos.dat
	python3 py/Entropy_size.py py/Entropy_size.dat

# Regla para limpiar los archivos generados
clean:
	rm -f *.out pdf/*.pdf py/*.dat