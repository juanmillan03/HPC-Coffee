#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "modulacion/Coffee.hpp"
#include "modulacion/Calculos.hpp"
#include "cmath"
const double tolerancia = 1e-3;
const int N=2;
TEST_CASE( "Creacion, moviento y calculo de la entropia del sistema para dos particulas", "[mean]" ){
    Coffee p1;
    p1.move_x(true);
    REQUIRE(p1.x()==1);

    p1.load(99,99);
    REQUIRE(p1.x()==99);

    std::vector<Coffee> cup(N);
    std::vector<double>respuesta=calculos(cup,N,1,2);
    REQUIRE(respuesta[0]==0.0);
    REQUIRE(respuesta[1]==0.0);

    cup[0].move_x(true);cup[0].move_y(true);
    double R2=cup[0].x()*cup[0].x()+cup[0].y()*cup[0].y();
    std::vector<double>respuesta2=calculos(cup,N,1,3);
    REQUIRE((respuesta2[0]-(-2*0.5*std::log(0.5)))<=tolerancia);
    REQUIRE((respuesta2[1]- std::sqrt(R2/N))<=tolerancia);

    //crear vectores de prueba y comprobar los resultados con REQUIRE
}