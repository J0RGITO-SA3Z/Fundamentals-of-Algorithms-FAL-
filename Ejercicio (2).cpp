// Nombre del alumno: Jorge Sáez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


// función que resuelve el problema
bool resolver(std::vector< int > const& v, int const& DM) {
    int i = 0;
    int D = 0;
    int min = v[0];
    while (i < v.size() - 1 && D <= DM) {
        if (v[i] < v[i + 1]) {
            D = v[i + 1] - min;
        }
        else {
            D = 0;
            min = v[i];
        }
        i++;
    }
   if (D <= DM) { return true; }
   return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int size;
    int D;
    std::cin >> D;
    std::cin >> size;
    std::vector< int > v(size);
    for (int i = 0; i < v.size(); i++) { std::cin >> v[i]; }
    if (resolver(v, D)) { std::cout << "APTA" << std::endl; }
    else { std::cout << "NO APTA" << std::endl; }
    return true;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (true) { resuelveCaso(); }

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}