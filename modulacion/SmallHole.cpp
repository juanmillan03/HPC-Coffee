#include "SmallHole.hpp"

bool isInAHole( int x, int y, int side, int holeCenter, int lattice){
    //side=1 significa lado superior del cuadrado, side=2 significa lado derecho, side=3 significa lado inferior, side=4 significa lado izquierdo
    int limit = lattice/2; //Indica los limites del cuadrado
    int holeRadius = 5; //es el ancho o radio del agujero en la pared
    int holeStart = holeCenter - holeRadius;
    int holeEnd = holeCenter + holeRadius;
    if( holeStart <= -limit || holeStart >= limit){ //En caso de que las dimensiones esten por fuera del cuadrado
        holeStart = -holeRadius;
        holeEnd = holeRadius;
    }
    switch(side){
        case 1: //lado superior del cuadrado
            return ( y >= limit && (x>=holeStart && x<=holeEnd ) );//Si esta dentro de la linea del agujero retorna verdadero, sino falso
            break;
        case 2: //lado derecho del cuadrado
            return ( x >= limit && (y>=holeStart && y<=holeEnd ) );//Si esta dentro de la linea del agujero retorna verdadero, sino falso
            break;
        case 3: //lado inferior del cuadrado
            return ( y <= -limit && (x>=holeStart && x<=holeEnd ) );//Si esta dentro de la linea del agujero retorna verdadero, sino falso
            break;
        case 4: //lado izquierdo del cuadrado
            return ( y >= limit && (x>=holeStart && x<=holeEnd ) );//Si esta dentro de la linea del agujero retorna verdadero, sino falso
            break;
        default: // Si el numero esta por fuera del rango, por defecto lo deja como lado superior.
            return ( x <= -limit && (y>=holeStart && y<=holeEnd ) );//Si esta dentro de la linea del agujero retorna verdadero, sino falso
            break;
    }
}

// Define la función 'move', que mueve un objeto 'Coffee' en una dirección aleatoria dentro de un espacio limitado.
void moveOrDie(Coffee&cup, int N,int seed,int lattice){
    std::mt19937 gen(seed); // Inicializa un generador de números aleatorios con la semilla proporcionada por 'seed'.
    std::uniform_int_distribution<> dis(0, 3); // Crea una distribución uniforme para números enteros entre 0 y 3, incluidos.

    int side = 1; //El agujero estara en la parte superior del cuadrado
    int holeCenter = 0; //El agujero estara en el medio de la pared del cuadrado
    int limit = (lattice/2);//Obtiene los limites donde se ubican las paredes del cuadrado

    if( cup.Alive() ){ //¿La particula sigue viva?
        //Si la particula sigue viva entonces la mueve
        switch (dis(gen)) // Genera un número aleatorio usando 'gen' y 'dis', y usa ese número para seleccionar un caso en el switch.
        {
            case 0: // Caso 0: Intenta mover el objeto 'Coffee' hacia la derecha.
                if (cup.x()<(limit-1) ) // Verifica si el objeto 'Coffee' está dentro de los límites en el eje x para moverse hacia la derecha.
                    cup.move_x(true); // Mueve el objeto 'Coffee' hacia la derecha si está dentro de los límites.
                else{ //En caso de pasarse
                    if(isInAHole( cup.x() + 1, cup.y(), side, holeCenter, lattice)){ // verifica si entra en un hueco
                        cup.move_x(true); // la mueve al hueco
                        cup.Muerto(); //la desaparece del cuadrado
                    }
                }
                break;
            case 1: // Caso 1: Intenta mover el objeto 'Coffee' hacia la izquierda.
                if (cup.x()>-(limit-1)) // Verifica si el objeto 'Coffee' está dentro de los límites en el eje x para moverse hacia la izquierda.
                    cup.move_x(false); // Mueve el objeto 'Coffee' hacia la izquierda si está dentro de los límites.
                else{ //En caso de pasarse
                    if(isInAHole( cup.x() - 1, cup.y(), side, holeCenter, lattice)){ // verifica si entra en un hueco
                        cup.move_x(false); // la mueve al hueco
                        cup.Muerto(); //la desaparece del cuadrado
                    }
                }
                break;
            case 2: // Caso 2: Intenta mover el objeto 'Coffee' hacia arriba.
                if (cup.y()<(limit-1)) // Verifica si el objeto 'Coffee' está dentro de los límites en el eje y para moverse hacia arriba.
                    cup.move_y(true); // Mueve el objeto 'Coffee' hacia arriba si está dentro de los límites.
                else{ //En caso de pasarse
                    if(isInAHole( cup.x(), cup.y() + 1, side, holeCenter, lattice)){ // verifica si entra en un hueco
                        cup.move_y(true); // la mueve al hueco
                        cup.Muerto(); //la desaparece del cuadrado
                    }
                }
                break;
            case 3: // Caso 3: Intenta mover el objeto 'Coffee' hacia abajo.
                if (cup.y()>-(limit-1)) // Verifica si el objeto 'Coffee' está dentro de los límites en el eje y para moverse hacia abajo.
                    cup.move_y(false);// Mueve el objeto 'Coffee' hacia abajo si está dentro de los límites.
                else{ //En caso de pasarse
                    if(isInAHole( cup.x(), cup.y() - 1, side, holeCenter, lattice)){ // verifica si entra en un hueco
                        cup.move_y(false); // la mueve al hueco
                        cup.Muerto(); //la desaparece del cuadrado
                    }
                }
                break; 
        }
    }

}

std::pair<double, int>  getTauAndNalive(std::vector<Coffee>&cup,int N,int time){ // Define una función 'calculos' que toma un vector de objetos 'Coffee', un entero 'N' que representa el número total de objetos 'Coffee', y un entero 'latti' que se usa para determinar el tamaño de la malla.
    double N0 = N ; // Es el numero inicial de particuals "vivas" inicial, es decir, que no han salido por el agujero
    int Nvivas = 0; //Es el numero de particulas vivas que quedan, es decir, las que aun no han salido por el agujero
    
    for (int i = 0; i < N; i++) // Itera sobre cada objeto 'Coffee' en el vector 'cup'.
    {
        if( cup[i].Alive() ) // Si la particula sigue viva
            Nvivas = Nvivas + 1; // Se actualiza en 1 el numero de particulas vivas 
    }

    double tau = 0;
    double det = log(Nvivas/N0);
    //std::cout << "det: " << det << std::endl;
    // Se obtiene la constante de tiempo tau
    if(Nvivas > 0 && N0 > 0 && det != 0) // Asegurar que Nvivas no sea 0 para evitar división por cero
        tau = - time / det ; // Es el resultado de obtener tau a partir de la ecuación Nvivas = N0 * e^{-time/tau} 

    return std::make_pair(tau, Nvivas); // Retorna un par con tau y Nvivas
}

double calcularPromedio(const std::vector<int>&tau) {
    double suma = 0;
    for(int valor : tau) {
        suma += valor; // Suma todos los valores en tau
    }
    if (!tau.empty()) {
        return suma / tau.size(); // Calcula el promedio
    }
    return 0; // En caso de que tau esté vacío, retorna 0 para evitar división por cero
}

int calcularNvivasTeoricas(double tau, int N0, int time) { //La función entrega los valores teoricos de la población de particulas que no han salido por el agujero
    int NvivasTeoricas = static_cast<int>(N0 * std::exp(-time / tau)); //N0 es la población inicial de particulas, time es el tiempo para el que se calcula Nvivas, y tau es la constante
    return NvivasTeoricas; // Se entrega un entero porque la población solo puede estar compuesta de enteror
}