CFLAGS = -O3 -fsanitize=address -fsanitize=undefined -fsanitize=leak 
GPROFFLAGS = -Wall -pg -g
CATCHFLAGS = -l Catch2Main -l Catch2
MEMCHECKFLAGS = --tool=memcheck --leak-check=yes
CACHEGRINDFLAGS =  --tool=cachegrind

OBJ= modulacion/Coffee.o modulacion/Walk.o modulacion/Calculos.o modulacion/SmallHole.o
cpps= modulacion/Coffee.cpp modulacion/Walk.cpp modulacion/Calculos.cpp modulacion/SmallHole.cpp

TARGET=plot

all: $(TARGET) 

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@	

modulacion/%.o: modulacion/%.cpp
	g++ $(CFLAGS) -c $< -o $@	

run: $(TARGET)
	./$(TARGET)

main.x: main.o $(OBJ)
	g++ $(CFLAGS) $^ -o main.x	
	./main.x >py/datos.dat

punto_1_3.x: punto_1_3.o $(OBJ)
	g++ $(CFLAGS) $^ -o p1_3.x
	./p1_3.x >py/Entropy_size.dat

punto_2.x: punto_2.o $(OBJ)
	g++ $(CFLAGS) $^ -o p2.x
	./p2.x >py/tiempos.dat
	
punto_4.x: punto_4.o $(OBJ) 
	g++ $(CFLAGS) $^ -o p4.x
	./p4.x >py/SmallHole.dat
	

plot: main.x punto_1_3.x punto_4.x
	python3 py/Tasa.py py/datos.dat
	python3 py/Entropy_size.py py/Entropy_size.dat
	rm -f *.x *.o 

gprof: 
	g++ $(GPROFFLAGS) -c main.cpp -o main.o
	g++ $(GPROFFLAGS) main.o -o gprof_report.x
	./gprof-report.x > temp.dat
	gprof gprof_report.x gmon.out > Report/gprof-report.txt
	rm gmon.out *.o *.x temp.dat

# gprof: 
# 	$(CC) $(GPROFFLAGS) -c main.cpp utils.cpp
# 	$(CC) $(GPROFFLAGS) main.o utils.o -o gprof_report.x
# 	./gprof_report.x <./inputs/input-profiling.txt>temp.dat
# 	gprof gprof_report.x gmon.out > gprof-report.txt
# 	rm gmon.out *.o *.x temp.dat

# cachegrind:
# 	g++ -g -c -O3 -fsanitize=address,undefined main.cpp modulacion/Coffee.cpp modulacion/Walk.cpp modulacion/Calculos.cpp
# 	g++ -g -O3 -fsanitize=address,undefined main.o modulacion/Coffee.o modulacion/Walk.o modulacion/Calculos.o -o main.x 
# 	# valgrind $(CACHEGRINDFLAGS) ./main.x >temp.dat
# 	# cg_annotate --auto=yes cachegrind.out.* > Report/cachegrind_report.txt
# 	rm *.o *.x cachegrind.out.* temp.dat


# memcheck: 
# 	g++ -g  -O3 -fsanitize=address -o main main.cpp modulacion/Coffee.cpp modulacion/Walk.cpp modulacion/Calculos.cpp
# 	valgrind --leak-check=full ./main >Report/temp.dat
# 	rm *.o *.x temp.dat



# test: test.cpp modulacion/Coffee.cpp
# 	g++ -c  $(CATCHFLAGS) $^
# 	g++ test.o $(OBJ) -o test.x $(CATCHFLAGS) 
# 	./test.x
# 	rm *.o 


# Regla para limpiar los archivos generados
clean:
	rm -f *.o pdf/*.pdf py/*.dat modulacion/*.o

