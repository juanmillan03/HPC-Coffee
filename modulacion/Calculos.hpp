#pragma once
#include <cmath>
#include "Coffee.hpp"
#include <vector>
#include <numeric>
#include <ostream>
#include <iostream>

std::vector<double> calculos(std::vector<Coffee>&cup,int N,int latti);
double TiempoEquilibrio(std::vector<double>&num, double accuracy, int it, int data);