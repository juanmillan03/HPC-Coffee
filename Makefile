# Definición de variables de compilación
CFLAGS = -fsanitize=address -fsanitize=undefined -fsanitize=leak -O3
CATCHFLAGS = -l Catch2Main -l Catch2
GPROFFLAGS = -Wall -pg -g
# Definición de objetivos y fuentes
OBJDIR = modulacion
OBJ = $(OBJDIR)/Coffee.o $(OBJDIR)/Walk.o $(OBJDIR)/Calculos.o $(OBJDIR)/SmallHole.o
cpps = $(OBJDIR)/Coffee.cpp $(OBJDIR)/Walk.cpp $(OBJDIR)/Calculos.cpp $(OBJDIR)/SmallHole.cpp

# Regla para compilar todos los objetivos
all: plot

# Regla para compilar archivos .o a partir de archivos .cpp en el directorio modulacion
$(OBJDIR)/%.o: $(OBJDIR)/%.cpp
	g++ $(CFLAGS) -c $< -o $@

# Regla para ejecutar el programa
run: plot

# Regla para compilar y ejecutar main.x
main.x: main.o $(OBJ)
	g++ $(CFLAGS) $^ -o main.x
	./main.x input.txt >py/datos.dat

# Regla para compilar y ejecutar punto_1_3.x
punto_1_3.x: punto_1_3.o $(OBJ)
	g++ $(CFLAGS) $^ -o punto_1_3.x
	./punto_1_3.x input.txt >py/Entropy_size.dat

# Regla para compilar y ejecutar punto_2.x
punto_2.x: punto_2.o $(OBJ)
	g++ $(CFLAGS) $^ -o punto_2.x
	./punto_2.x input.txt >py/tiempos.dat

# Regla para compilar y ejecutar punto_4.x
punto_4.x: punto_4.o $(OBJ)
	g++ $(CFLAGS) $^ -o punto_4.x
	./punto_4.x input.txt >py/SmallHole.dat

# Regla para ejecutar los scripts de Python y limpiar
plot: main.x punto_1_3.x punto_2.x punto_4.x 
	python3 py/Tasa.py py/datos.dat
	python3 py/Entropy_size.py py/Entropy_size.dat
	python3 py/SmallHole.py py/SmallHole.dat
	python3 py/tiempos.py py/tiempos.dat
	rm -f *.x *.o modulacion/*.o

# Regla para compilar y ejecutar pruebas
test: test.cpp $(cpps)
	g++ -O3 $^ -o test
	./test
	rm -f test

# Regla para compilar y generar el reporte de profiling
profiling:
	g++ $(GPROFFLAGS) -c punto_1_3.cpp modulacion/Coffee.cpp modulacion/Walk.cpp modulacion/Calculos.cpp
	g++ $(GPROFFLAGS) punto_1_3.o Coffee.o Walk.o Calculos.o -o gprof_report.x
	./gprof_report.x input-profiling.txt > output_profiling.dat
	gprof gprof_report.x gmon.out > grpof-report.txt
	rm gmon.out *.o *.x output_profiling.dat

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) *.o $(OBJDIR)/*.o test
