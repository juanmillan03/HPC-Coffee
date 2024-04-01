#include "modulacion/Coffee.hpp"
#include "modulacion/Walk.hpp"
#include "modulacion/Calculos.hpp"
#include <iostream>
#include <random>
#include <fstream>
#include <chrono>

int main(int argc, char* argv[]) {

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Unable to open file input.txt" << std::endl;
        return 1; // Exit the program if the file cannot be opened
    }

    std::vector<int> integers;
    int number;
    while (file >> number) {
        integers.push_back(number);
    }

    file.close();

    int N = integers[0];
    int latti = integers[1]; 
    int it = integers[2];
    int seed = integers[3]; 
    int data = 10000;         //Ayuda a definir cuantos datos queremos ya que divide al tiempo total

    std::vector<Coffee> cup(N);
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, N - 1);

    std::vector<double> Entropy (it/data);     //Guarda los datos de la entropía
    std::vector<int> sizes = {60,70,80,90,100};    //Tamaños de la red
    for (const auto& nt : sizes){
        auto t_inicio = std::chrono::steady_clock::now();
        inicial(cup,N);
        for (int i = 0; i < it; i++){
            move(cup[dis(gen)],N,seed+i,nt);
            if (i%data==0){
                std::vector<double>respuesta=calculos(cup,N,latti,nt);
                Entropy[i/data] = respuesta[0];
            }
        }
        
        auto t_final = std::chrono::steady_clock::now();
        auto milisegundos = std::chrono::duration_cast<std::chrono::milliseconds>(t_final-t_inicio).count();
        std::cout << nt <<" "<< milisegundos << std::endl;
    }
    return 0;
}