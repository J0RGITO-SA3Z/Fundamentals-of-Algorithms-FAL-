// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using tPersona = std::pair < std::string, int >;
// función que resuelve el problema
std::vector <tPersona> resolver(std::vector <tPersona>& v, std::vector <tPersona>& bajo, const int& pivote) {
    std::vector <tPersona>alto;
    int p = 0, q = (int)v.size();
    while (p < q) {
        if (v[p].second <= pivote) { bajo.push_back(v[p]); ++p; }// elemento del indice izquierdo correcto
        else if (v[q - 1].second > pivote) { alto.push_back(v[q - 1]);   --q; }// elemento del indice derecho correcto
        else { // Ambos elementos fuera de sitio
            std::swap(v[p], v[q - 1]);
            bajo.push_back(v[p]);
            alto.push_back(v[q - 1]);
            ++p; --q;
        }
    }
    return alto;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int size;
    std::cin >> size;
    if (!std::cin)
        return false;
    int k;
    std::cin >> k;
    std::vector <tPersona>v(size);
    std::vector <tPersona>u;
    std::vector <tPersona>w;
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i].first;
        std::cin >> v[i].second;
    }
    u = resolver(v,w, k);
    std::sort(u.begin(), u.end());
    std::sort(w.begin(), w.end());
    std::cout << "BAJOS: ";
    for (int i = 0; i < w.size(); i++) {
        std::cout << w[i].first << " ";
    }
    std::cout << std::endl;
    std::cout << "ALTOS: ";
    for (int i = 0; i < u.size(); i++) {
        std::cout << u[i].first << " ";
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