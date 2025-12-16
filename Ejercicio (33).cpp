// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


int numsum(int num) {
    if (num < 10) {
        return num;
    }
    else {
        return num % 10 + numsum(num / 10);
    }
}

void resolver(std::vector<int>const& v, int num) {
    for (int i = 0; i < v.size(); i++) {
        if (numsum(num) == numsum(v[i])) {
            std::cout << v[i] <<" ";
        }
    }
    std::cout << std::endl;
}

void resuelveCaso() {
    // leer los datos de la entrada
    int size;
    int number;
    std::cin >> size;
    std::cin >> number;
    std::vector<int> v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    resolver(v, number);
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