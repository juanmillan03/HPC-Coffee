#include "Walk.hpp"

void move(Coffee & cup, int N,int seed,int L){
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, 3);
    switch (dis(gen))
    {
    case 0: 
    if (cup.x()<L-1)
    { cup.move_x(true);};break;
    case 1:
    if (cup.x()>-L+1)
    { cup.move_x(false);};break;
    case 2:
    if (cup.y()<L-1)
    { cup.move_y(true);};break;
    case 3: 
    if (cup.y()>-L+1)
    { cup.move_y(false);};break;
    }
}
void inicial(std::vector<Coffee> & cup,int N){
    int largo =std::sqrt(N);
    for (int i = 0; i < largo-1; i++){
        for (int j = 0; j < largo-1; j++)
        {
            cup[j*largo+i].load(i-largo/2+1,j-largo/2+1);
        }
    }
}
