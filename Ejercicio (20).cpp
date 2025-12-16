// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema

int resolver(std::vector <int>& v, const int& k) {
    int suma = 0;
    int max;
    int i = 0;
    max= v[k - 1];
    for (int a = 1; a + k -1< v.size(); a++) {
        suma = v[k + a - 1] - v[a - 1];
        if (max <= suma) {
            max = suma;
            i = a;
        }
    }
    return i;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int size;
    int k;
    std::cin >> size;
    std::cin >> k;
    if (size == 0 && k == 0)
        return false;
    int suma = 0;
    std::vector <int>v(size);
    std::vector <int>u(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
        suma += v[i];
        u[i] = suma;
    }
    int sol = resolver(u, k);
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