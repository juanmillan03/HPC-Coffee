#pragma once
#include <cmath>
class Coffee{
    private:
        int X=0,Y=0;
        bool live=true;
    public:
        void load(int x0,int y0);
        void Muerto(void);
        int x(void){return X;};
        int y(void){return Y;};
        bool Alive(void){return live;};
        void move_x(bool plus);
        void move_y(bool plus);
        double r(void);
};
