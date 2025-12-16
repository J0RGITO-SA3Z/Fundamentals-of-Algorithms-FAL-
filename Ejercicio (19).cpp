// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// funcion que resuelve el problema
//CALCULAMOS SU COMPLEJIDAD
int resolver(std::vector <int>& v) {
    long long int cont = 1;
    long long int max = 1;
    std::sort(v.begin(), v.end());
    int sol = v[0];
    for (long long int i = 1; i < v.size(); i++) {
        if (v[i] == v[i - 1]) {
            cont++;
            if (cont > max) {
                max = cont;
                sol = v[i];
            }
        }
        else {
            cont = 1;
        }
    }
    return sol;
}

bool resuelveCaso() {
    long long int size;
    std::cin >> size;
    if (size == -1)
        return false;
    std::vector <int>v(size);
    for (long long int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    int sol = resolver(v);
    std::cout << sol << std::endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}