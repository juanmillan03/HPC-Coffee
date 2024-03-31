#include "modulacion/Coffee.hpp"
#include "modulacion/Walk.hpp"
#include "modulacion/Calculos.hpp"
#include <iostream>
#include <random>
#include <fstream>

int main() {

    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Unable to open file parameters.txt" << std::endl;
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
    std::vector<double> sizes = {4, 5, 10, 20, 40, 50};    //Tamaños de la red
    

    

    for (const auto& nt : sizes){
        inicial(cup,N);
        for (int i = 0; i < it; i++){
            move(cup[dis(gen)],N,seed+i);
            if (i%data==0){
                std::vector<double>respuesta=calculos(cup,N,nt);
                Entropy[i/data] = respuesta[0];
            }
        }
        std::cout << nt*nt <<" "<<TiempoEquilibrio(Entropy, 1e-2, it, data) << std::endl;
    }

    return 0;
}
