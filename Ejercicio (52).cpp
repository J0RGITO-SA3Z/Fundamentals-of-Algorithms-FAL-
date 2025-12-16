// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void escribirsol(const std::vector <char>& sol) {
    for (int i = 0; i < sol.size(); i++) {
        std::cout << sol[i];
    }
    std::cout << std::endl;
}

// función que resuelve el problema
void resolver(const int& m, const int& n, std::vector <char>& sol, std::vector <bool>& marca, const int& k) {
    for (char c = 'a'; c < 'a' + m; c++) {
        sol[k] = c;
        if (!marca[c - 'a']) {
            marca[c - 'a'] = true;
                if (k == sol.size() - 1) {
                    escribirsol(sol);
                }
                else {
                    resolver(m, n, sol, marca, k + 1);
                }
            marca[c - 'a'] = false;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int m;
    std::cin >> m;
    if (!std::cin)
        return false;
    int n;
    std::cin >> n;
    std::vector <char> sol(n);
    std::vector <bool> marca(m);
    resolver(m, n, sol,marca, 0);
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