#include "modulacion/Coffee.hpp"
#include "modulacion/Walk.hpp"
#include "modulacion/Calculos.hpp"
#include <iostream>
#include <random>
#include<fstream>

int main(int argc, char* argv[]) {

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
    std::vector<Coffee> cup(N);
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, N - 1);
    inicial(cup,N);
    for (int i = 0; i < it; i++){
        move(cup[dis(gen)],N,seed+i);
        if (i%10000==0)
        {
            std::vector<double>respuesta=calculos(cup,N,latti);
            std::cout<<i<<"\t"<<respuesta[0]<<"\t"<<respuesta[1]<<std::endl;
        }
    }
    return 0;
}