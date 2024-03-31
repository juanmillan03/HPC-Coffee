# Definición de variables de compilación
CFLAGS = -fsanitize=address -fsanitize=undefined -fsanitize=leak -O3

# Definición de objetivos y fuentes
OBJDIR = modulacion
OBJ = $(OBJDIR)/Coffee.o $(OBJDIR)/Walk.o $(OBJDIR)/Calculos.o $(OBJDIR)/SmallHole.o
cpps = $(OBJDIR)/Coffee.cpp $(OBJDIR)/Walk.cpp $(OBJDIR)/Calculos.cpp $(OBJDIR)/SmallHole.cpp
TARGET = plot

# Regla para compilar todos los objetivos
all: $(TARGET)

# Regla para compilar archivos .o a partir de archivos .cpp en el directorio modulacion
$(OBJDIR)/%.o: $(OBJDIR)/%.cpp
	g++ $(CFLAGS) -c $< -o $@

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)

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
$(TARGET): main.x punto_1_3.x punto_2.x punto_4.x 
	python3 py/Tasa.py py/datos.dat
	python3 py/Entropy_size.py py/Entropy_size.dat
	python3 py/SmallHole.py py/SmallHole.dat
	rm -f *.x *.o

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) *.o $(OBJDIR)/*.o

