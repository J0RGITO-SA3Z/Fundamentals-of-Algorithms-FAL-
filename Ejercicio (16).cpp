// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
std::vector <int> resolver(std::vector <int> const& v, std::vector <int> const& u) {
    std::vector <int> w;
    int i = 0;
    int j = 0;
    while (i < v.size() && j < u.size()) {
        if (v[i] > u[j]) {
            w.push_back(u[j]);
            j++;
        }
        else if (u[j] > v[i]) {
            w.push_back(v[i]);
            i++;
        }
        else {
            i++; j++;
        }
    }
    int k = v.size();
    while (i < k) {
        w.push_back(v[i]);
        i++;
    }
    k = u.size();
    while (j < k) {
        w.push_back(u[j]);
        j++;
    }
    return w;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int dato;
    int size = 0;
    std::vector <int> v(size);
    std::vector <int> u(size);
    std::vector <int> w(size);
    std::cin >> dato;
    while (dato != 0) {
        v.push_back(dato);
        std::cin >> dato;
    }
    std::cin >> dato;
    while (dato != 0) {
        u.push_back(dato);
        std::cin >> dato;
    }
    w = resolver(v, u);
    for (int a = 0; a < w.size(); a++) {
        std::cout << w[a] << " ";
    }
    std::cout <<std::endl;
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