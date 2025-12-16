// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


// función que resuelve el problema
std::vector <int> resolver(std::vector <int>const& v, const int& k) {
    std::vector <int>par;
    std::vector <int>sol;
    int cont = 1;
    int contparcelas = 0;
    int maxdist = 0;
    int dist = 0;
    int maxaltura = v[v.size() - 1];
    int pos = v.size() - 1;
    for (int i = v.size() - 2; i > - 1; i--){
        if (v[i] >= maxaltura) {
            if (v[i] == v[i + 1]) {
                cont++;
                if(cont > maxdist && cont >= k){
                    maxdist = cont;
                }
                if (cont == k) {
                    contparcelas++;
                    par.push_back(pos);
                }
            }
            else {
                pos = i;
                cont = 1;
            }
            maxaltura = v[i];
        }
    }
    sol.push_back(maxdist);
    sol.push_back(contparcelas);
    for (int b = 0; b < par.size(); b++) {
        sol.push_back(par[b]);
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
    if(v.size() > 0){ u = resolver(v, k); }
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