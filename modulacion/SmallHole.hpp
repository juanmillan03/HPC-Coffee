#pragma once
#include <vector>
#include <cmath>
#include <random>
#include <iostream>
#include "Coffee.hpp"

void moveOrDie(Coffee & cup, int N,int seed,int lattice);
bool isInAHole( int x, int y, int side, int holeCenter, int lattice);
std::pair<double, int>  getTauAndNalive(std::vector<Coffee>&cup,int N,int time);
double calcularPromedio(const std::vector<int>&tau);
int calcularNvivasTeoricas(double tau, int N0, int time);