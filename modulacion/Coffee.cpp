#include "Coffee.hpp"

void Coffee::Muerto(void){
    live=false;
}
void Coffee::load(int x0,int y0){
    X=x0;Y=y0;
}
void Coffee::move_x(bool plus){
    if (plus == true)
    {X+=1;}
    else{X-=1;}
}
void Coffee::move_y(bool plus){
    if(plus == true)
    {Y+=1;}
    else{Y-=1;}
}
double Coffee::r(void){
    double R2=X*X+Y*Y;
    return R2;
}