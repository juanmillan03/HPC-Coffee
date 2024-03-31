#include"Calculos.hpp"
std::vector<double> calculos(std::vector<Coffee>&cup,int N,int latti){
    int L=200/latti;
    std::vector<double>result(2,0);
    std::vector<double>suma(L*L,0);
    double suma_r=0;
    for (int i = 0; i < N; i++)
    {
        int ii =(cup[i].x()+100)/latti;
        int jj =(cup[i].y()+100)/latti;
        suma[jj*L+ii]=suma[jj*L+ii]+1.0/N;
        suma_r+=cup[i].r()*cup[i].r();
    }
    double E=0;
    for (int i = 0; i < L*L; i++)
    {
        if (suma[i]!=0)
        {E+=suma[i]*std::log(suma[i]);} 
    }
    result[0]=E*(-1);
    result[1]=std::sqrt(suma_r/N);
    return result;
}

double TiempoEquilibrio(std::vector<double>&num, double accuracy, int it, int data){
    double value = std::accumulate(num.end() - 500000/data, num.end(), 0.0)/(500000.0/data);
    double t_eq = 0;
    for (int i = 0; i < it/data; i++){
        if (std::fabs(num[i]-0.97*value) < accuracy){
            t_eq = i*data;
        }
    }

    return t_eq;
}