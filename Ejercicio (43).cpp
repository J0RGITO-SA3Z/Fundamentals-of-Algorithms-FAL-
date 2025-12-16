// Nombre del alumno Jorge Saéz Slto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

int buscarIz(const int& ini, const int& fin, std::vector<int> const& v) {
    if (ini >= fin || ini + 1 == fin) {
        return ini;
    }
    else {
        int mitad = (fin + ini - 1) / 2;
        if (v[mitad] > v[mitad + 1]) {
            return buscarIz(mitad + 1, fin, v);
        }
        else {
            return buscarIz(ini, mitad + 1, v);
        }
    }

}

int buscarDr(const int& ini, const int& fin, std::vector<int> const& v) {
    if (ini >= fin || ini + 1 == fin) {
        return ini;
    }
    else {
        int mitad = (fin + ini) / 2;
        if (v[mitad] > v[mitad - 1]) {
            return buscarDr(ini, mitad, v);
        }
        else {
            return buscarDr(mitad, fin, v);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size;
    std::cin >> size;
    if (size == -1)
        return false;
    std::vector<int> v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    int sol1 = buscarIz(0, v.size(), v);
    int sol2 = buscarDr(0, v.size(), v);
    if (v.size() == 0) {
        std::cout << sol2 - sol1 << std::endl;
    }
    else {
        std::cout << sol2 - sol1 + 1 << std::endl;
    }
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