// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolverComple(std::vector<int> const& v) {
    int lon = 0;
    int cont = 0;
    int lonmax = 0;
    if (v.size() == 0 || v.size() == 1) {
        lonmax = v.size();
    }
    int j = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > v[i - 1]) {
            cont++;
        }
        else {
            cont = 0;
        }
        if (cont >= 2) {
            j = i - 1;
        }
        lon = i - j + 1;
        if (lon > lonmax) {
            lonmax = lon;
        }
    }
    return lonmax;
}

void resuelveCaso() {
    long long int number1;
    std::cin >> number1;
    std::vector<int> v(number1);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    int sol = resolverComple(v);
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