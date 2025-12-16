// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

int resolver(std::vector <int>const& v, const int& k) {
    int sol = 0;
    int contiz = 0;
    int contder = 0;
    for (int a = 0; a < k; a++) {
        if (a < k/2 && v[a]>= 0) {
            contiz++;
        }
        else if (a >= k / 2 && v[a] >= 0) {
            contder++;
        }
    }
    if (contiz >= contder) {
        sol++;
    }
    for (int a = 0; a + k < v.size(); a++) {
        if (v[a + k] >= 0) {
            contder++;
        }
        if (v[a + k/2] >= 0) {
            contiz++;
            contder--;
        }
        if (v[a] >= 0) {
            contiz--;
        }
        if (contiz >= contder) {
            sol++;
        }
    }
   return sol;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int size;
    std::cin >> size;
    if (size == 0)
        return false;
    int k;
    std::cin >> k;
    std::vector <int>v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    int sol = resolver(v, k);
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