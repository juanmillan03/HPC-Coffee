#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "modulacion/Coffee.hpp"
#include "cmath"

TEST_CASE( "Mean of a vector is computed", "[mean]" ) {
    Coffee p1;
    p1.move_x(true);
    REQUIRE(p1.x()==1);
    //crear vectores de prueba y comprobar los resultados con REQUIRE
}