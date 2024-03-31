#include "modulacion/Coffee.hpp" // Incluye la definición de la clase Coffee desde el directorio 'modulacion'.
#include "modulacion/Walk.hpp" // Incluye las funciones o definiciones relacionadas con el movimiento de los objetos Coffee.
#include "modulacion/Calculos.hpp" // Incluye las definiciones o funciones para calcular métricas basadas en los objetos Coffee.
#include "modulacion/SmallHole.hpp" // Es la libreria referente al punto 4
#include <iostream> // Incluye la biblioteca estándar de entrada/salida para manejar la entrada y salida de datos.
#include <random> // Incluye las funciones de la biblioteca estándar para la generación de números aleatorios.
#include<fstream> // Incluye la biblioteca para trabajar con archivos.

// Define la función principal del programa.
int main(int argc, char* argv[]) {

    std::ofstream outfile; // Crea un objeto de flujo de archivo para escribir datos.
    std::ofstream outfile2; // Crea un segundo objeto de flujo de archivo para escribir datos de entropía.
    std::ofstream outfile3; // Crea un tercer objeto de flujo de archivo para escribir datos de tamaño.
    outfile3.open("gp/tamano.dat"); // Abre un archivo para escribir datos de tamaño.
    outfile2.open("gp/entropy.dat"); // Abre un archivo para escribir datos de entropía.
    outfile.open("gp/datos.dat"); // Abre un archivo para escribir datos generales.

    std::ifstream file("input.txt"); // Abre un archivo de entrada para leer parámetros.
    if (!file) {
        std::cerr << "Unable to open file parameters.txt" << std::endl; // Muestra un mensaje de error si el archivo no se puede abrir.
        return 1; // Sale del programa si el archivo no se puede abrir.
    }

    std::vector<int> integers; // Crea un vector para almacenar los enteros leídos del archivo.
    int number; // Variable para almacenar temporalmente los enteros leídos.
    while (file >> number) { // Lee enteros del archivo y los almacena en 'number'.
        integers.push_back(number); // Añade 'number' al vector 'integers'.
    }

    file.close(); // Cierra el archivo de entrada.

    int N = integers[0]; // Extrae el número total de objetos Coffee.
    int latti = 50; //Se hace 50 debido a la indicación dada en el punto 4.
    int it = integers[2]; // Extrae el número total de iteraciones para realizar.
    int seed = integers[3]; // Extrae la semilla para la generación de números aleatorios.

    std::vector<Coffee> cup(N); // Crea un vector de objetos Coffee.
    std::mt19937 gen(seed); // Inicializa el generador de números aleatorios con la semilla.
    std::uniform_int_distribution<> dis(0, N - 1); // Crea una distribución para seleccionar objetos Coffee al azar.
    std::vector<int> Nvivas(it); //Crea un vector de tamaño igual a las iteraciones realizadas como de las particulas que quedan vivas.
    std::vector<int> tau(it); // Crea un vector de tamaño igual a las iteraciones realizadas para almacenar los tau en cada iteración
    std::vector<int> NvivasTeoricas(it/10000);
    std::vector<int> NvivasMuestra(it/10000);
    inicial(cup,N); // Inicializa las posiciones de los objetos Coffee.

    //std::pair<double, int>respuesta = getTauAndNalive(cup,N,5900000);
    //std::cout << "tau: " << respuesta.first  << ", Nalive " << respuesta.second  << std::endl;
    
    for (int i = 0; i < it; i++){ // Realiza 'it' iteraciones de movimiento y cálculo.
        moveOrDie(cup[dis(gen)],N,seed+i,latti); // Mueve un objeto Coffee seleccionado al azar.
        std::pair<double, int>respuesta = getTauAndNalive(cup,N,i); // Entrega dos valor, tau de tipo double y Nvivas de tipo int
        tau[i] = respuesta.first;
        Nvivas[i] = respuesta.second;
        //if(i%100000==0) std::cout << "Nvivas: " << Nvivas[i]  << ", time: " << i << ", Tau: " << tau[i] << std::endl;
    }
    int tauPromedio = calcularPromedio(tau);
    //std::cout << "Tau: " << tauPromedio << std::endl;
    
    for(size_t i = 0; i < NvivasTeoricas.size() ; i++ ){
        NvivasTeoricas[i] = calcularNvivasTeoricas(tauPromedio, N,i*10000);
        NvivasMuestra[i] = Nvivas[i*10000];
        //std::cout << "NvivasTeorica: " << NvivasTeoricas[i]  << ", time: " << i << std::endl;
        std::cout << (i*10000) <<"\t"<< NvivasTeoricas[i]<<"\t"<<NvivasMuestra[i]<< std::endl;
    }
    
    //std::cout << "NvivasTeorica: " << calcularNvivasTeoricas(tauPromedio,N,1) << std::endl;
    return 0; // Termina la ejecución del programa con éxito.
}