// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using tPersona = std::pair < std::string, int >;
// función que resuelve el problema
int resolver(std::vector <tPersona>& v, int&y) {
    int p = 0; int q = v.size(); int k = 0;
    while (k < q) {
        if (v[k].first == "v") ++k;
        else if (v[k].first == "a") {
            std::swap(v[p], v[k]);
            ++p; ++k;
        }
        else {
            std::swap(v[q - 1], v[k]);
            --q;
        }
    }
    y = q;
    return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int size;
    std::cin >> size;
    if (!std::cin)
        return false;
    int k = 0;
    std::vector <tPersona>v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i].first;
        std::cin >> v[i].second;
    }
    int p = resolver(v,k);
    std::sort(v.begin(), v.begin() + p);
    std::sort(v.begin() + p, v.begin() + k);
    std::sort(v.begin() + k, v.end());
    std::cout << "Azules: ";
    for (int i = 0; i < p; i++) {
        std::cout << v[i].second << " ";
    }
    std::cout << std::endl;
    std::cout << "Verdes: ";
    for (int i = p; i <=  k - 1; i++) {
        std::cout << v[i].second << " ";
    }
    std::cout << std::endl;
    std::cout << "Rojas: ";
    for (int i = k; i < v.size(); i++) {
        std::cout << v[i].second << " ";
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