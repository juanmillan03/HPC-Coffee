#include "modulacion/Coffee.hpp"
#include "modulacion/Walk.hpp"
#include "modulacion/Calculos.hpp"
#include <iostream>
#include <random>
#include<fstream>

int main(int argc, char* argv[]) {

    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return 2;
    }
    std::ofstream outfile;
    std::ofstream outfile2;
    std::ofstream outfile3;
    outfile3.open("gp/tamano.dat");
    outfile2.open("gp/entropy.dat");
    outfile.open("gp/datos.dat");
    int N = std::atoi(argv[1]);
    int latti = std::atoi(argv[2]); 
    int it = std::atoi(argv[3]);
    int seed = std::atoi(argv[4]); 

    std::vector<Coffee> cup(N);
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, N - 1);

    inicial(cup,N);
    for (int i = 0; i < it; i++){
        move(cup[dis(gen)],N,seed+i);
        if (i%10000==0)
        {
            std::vector<double>respuesta=calculos(cup,N,latti);
            outfile2<<i<<" "<<respuesta[0]<<std::endl;
            outfile3<<i<<" "<<respuesta[1]<<std::endl;
        }
    }
    for (int i = 0; i < N; i++)
    {
        outfile<<cup[i].x()<<" "<<cup[i].y()<<std::endl;
    }
    outfile.close();
    outfile2.close();
    outfile3.close();

    return 0;
}