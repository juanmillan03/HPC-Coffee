# Regla por defecto para generar la gráfica
all: compilar link gnuplot

# Regla para compilar el código fuente C++
compilar:
	g++ -O3 main.cpp modulacion/Coffee.cpp modulacion/Walk.cpp modulacion/Calculos.cpp -o ./main.o
	g++ -O3 punto_1_3.cpp modulacion/Coffee.cpp modulacion/Walk.cpp modulacion/Calculos.cpp -o ./p1_3.o

# Regla para ejecutar el programa y generar la matriz
link: 
	./main.exe |Out-File -Encoding ascii gp/datos.dat
	./p1_3.exe |Out-File -Encoding ascii gp/Entropy_size.dat
	rm -f *.out 	
gnuplot:
	gnuplot gp/Tasa.gp
	gnuplot gp/Entropy.gp
	gnuplot gp/size.gp

# Regla para limpiar los archivos generados
clean:
	rm -f *.out 