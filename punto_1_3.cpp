#include "modulacion/Coffee.hpp"
#include "modulacion/Walk.hpp"
#include "modulacion/Calculos.hpp"
#include <iostream>
#include <random>
#include<fstream>

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
    inicial(cup,N);
    for (int i = 0; i < it; i++){
        move(cup,N,seed+i,100);
        if (i%data==0)
        {
            std::vector<double>respuesta=calculos(cup,N,latti,100);
            std::cout<<i<<"\t"<<respuesta[0]<<"\t"<<respuesta[1]<<std::endl;
        }
    }
    return 0;
}