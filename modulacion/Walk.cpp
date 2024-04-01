#include "Walk.hpp"

void move(std::vector<Coffee>& cup, int N,int seed,int L){
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, N-1);
    int n=dis(gen);
    switch (dis(gen)%4)
    {
    case 0: 
    if (cup[n].x()<L-1)
    { cup[n].move_x(true);};break;
    case 1:
    if (cup[n].x()>-L+1)
    { cup[n].move_x(false);};break;
    case 2:
    if (cup[n].y()<L-1)
    { cup[n].move_y(true);};break;
    case 3: 
    if (cup[n].y()>-L+1)
    { cup[n].move_y(false);};break;
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
