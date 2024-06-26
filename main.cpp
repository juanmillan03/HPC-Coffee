#include "modulacion/Coffee.hpp"
#include "modulacion/Walk.hpp"
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
    int it = integers[2];
    int seed = integers[3];  

    std::vector<Coffee> cup(N);
    inicial(cup,N);
    for (int i = 0; i < it; i++){
        move(cup,N,seed+i,100);
    }
    for (int i = 0; i < N; i++)
    {
        std::cout<<cup[i].x()<<"\t"<<cup[i].y()<<std::endl;
    }
   

    return 0;
}