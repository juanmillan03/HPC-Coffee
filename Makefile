# Regla por defecto para generar la gráfica
all: compilar link gnuplot

# Regla para compilar el código fuente C++
compilar:
	g++ -O3 main.cpp modulacion/Coffee.cpp modulacion/Walk.cpp modulacion/Calculos.cpp

# Regla para ejecutar el programa y generar la matriz
link: 
	./a.out
	rm -f *.out
gnuplot:
	gnuplot gp/Tasa.gp
	gnuplot gp/Entropy.gp
	gnuplot gp/size.gp

# Regla para limpiar los archivos generados
clean:
	rm -f *.out *.dat *.pdf