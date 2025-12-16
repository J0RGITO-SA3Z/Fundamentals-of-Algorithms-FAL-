// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector <int> resolver(std::vector <int>& v, const int& k) {
    std::sort(v.begin(), v.end());
    std::vector <int>u(k + 1);
    std::vector <int>sol;
    int longmax = 1;
    int cont = 1;
    for (int i = 0; i < v.size(); i++) {
        u[v[i]] = 0;
    }
    u[v[0]] = 1;
    for (int a = 1; a < v.size(); a++) {
        if (v[a] == v[a - 1]) {
            cont++;
        }
        else {
            cont = 1;
        }
        if (cont > longmax) {
            longmax = cont;
        }
        u[v[a]] = cont;
    }
    for (int i = u.size() - 1; i > -1; i--) {
        if (u[i] == longmax) {
            sol.push_back(i);
        }
    }
    return sol;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int size;
    std::cin >> size;
    if (size == -1)
        return false;
    int k;
    std::cin >> k;
    std::vector <int>v(size);
    std::vector <int>u;
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    u = resolver(v, k);
    for (int i = 0; i < u.size(); i++) {
        std::cout << u[i] << " ";
    }
    std::cout << std::endl;
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