// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
//Calculemos su complejidad 
int resolver(std::vector <int> const& v) {
    int impares = 0;//coste 1
    int combinaciones = 0;//coste 1
    for (int i = 0; i < v.size(); i++) {//coste 1 //Bucle iteraivo de complejidad variable dada por el valor n
        if (v[i] % 2 != 0) {//coste 1       //Escogiendo el peor de los casos de la operacion condicional el coste es 2
            impares++;//coste 1
        }
        else {//coste 1
            combinaciones = combinaciones + impares;//coste 1
        }
    }
    return combinaciones;//coste 1
}
//Dado el bucle iterativo y el peor de los casos de la expresión condicional la funcion de complejidad es f(n)= 3n + 3 que pertenece al Orden de complejidad de n O(n).
void resuelveCaso() {
    int size;
    std::cin >> size;
    std::vector <int> v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    int sol = resolver(v);
    std::cout << sol << std::endl;
}
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}