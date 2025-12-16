// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


// función que resuelve el problema
std::vector <int> resolver(std::vector <int>& v, const int& k) {
    std::vector <int>sol;
    std::vector <int>par;
    int longmax = 1;
    int longpar = 1;
    int cont = 1;
    int contpar = 0;
    int max = v[v.size()- 1];
    int indice = v.size() - 1;
    if (cont == k) {
        contpar++;
        par.push_back(0);
    }
    for (int i = v.size() - 2; i > -1; i--) {
        if (v[i] > max) {
            max = v[i];
        }
        if (v[i] == v[i + 1]) {
            cont++;
            longpar++;
        }
        else {
            cont = 1;
            longpar = 1;
            indice = i;
        }
        if (longpar > longmax) {
            longmax = longpar;
        }
        if (cont == k && v[i] >= max) {
            cont = 0;
            contpar++;
            par.push_back(indice);
        }
    }
    if (longmax < k) {
        sol.push_back(0);
    }
    else {
        sol.push_back(longmax);
    }
    sol.push_back(contpar);
    for (int i = 0; i < par.size(); i++) {
        sol.push_back(par[i]);
    }
    return sol;
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