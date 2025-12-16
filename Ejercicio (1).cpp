// Nombre del alumno: Jorge Sáez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


// función que resuelve el problema
bool resolver(std::vector< int > const& v, int const& particion) {
    int max;
    int min;
    max = v[0];
    if (particion + 1 < v.size()) {
        min = v[particion + 1];
        for (int i = 1; i < particion + 1; i++) {
            if (max < v[i]) {
                max = v[i];
            }
        }
        for (int i = particion + 1; i < v.size(); i++) {
            if (min > v[i]) {
                min = v[i];
            }
        }
        if (max >= min) { return false; }
    }
    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int size;
    std::cin >> size;
    std::vector< int > v(size);
    std::cin >> size;
    for (int i = 0; i < v.size(); i++) { std::cin >> v[i]; }
    if (resolver(v, size)) { std::cout << "SI" << std::endl; }
    else{ std::cout << "NO" << std::endl;}
}

int main() {
 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();




    return 0;
}