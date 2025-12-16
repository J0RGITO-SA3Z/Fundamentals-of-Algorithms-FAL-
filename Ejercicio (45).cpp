// Nombre del alumno Jorge Saéz Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

char buscarIz(const int& ini, const int& fin, std::vector<char> const& v) {
    if (ini >= fin || ini + 1 == fin) {
        return v[ini] - 1;
    }
    else {
        int mitad = (fin + ini - 1) / 2;
        if ( v[mitad] - v[0] == mitad) {
            return buscarIz(mitad + 1, fin, v);
        }
        else {
            return buscarIz(ini, mitad + 1, v);
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char x1;
    char x2;
    char sol1 = 0;
    std::cin >> x1;
    std::cin >> x2;
    int size = x2 - x1;
    std::vector<char> v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    if (v[0] == x1 && v[v.size() - 1] == x2) {
        sol1 = buscarIz(1, v.size() - 1, v);
    }
    else {
        if (v[0] != x1) {
            sol1 = x1;
        }
        else {
            sol1 = x2;
        }
    }
    std::cout << sol1 << std::endl;
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