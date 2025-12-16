// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
std::vector <int> resolver(std::vector <int> & v, std::vector <int> & w) {
    std::vector <int>u;
    std::sort(v.begin(), v.end());
    std::sort(w.begin(), w.end());
    int i = 0, j = 0; // se recorren los dos vectores de izquierda a derecha
    while (i < v.size() && j < w.size()) {
        // mientras quedan elementos en los dos vectores se selecciona el menor
        if (v[i] < w[j]) { ++i; }
        else if(v[i] > w[j]){ ++j; }
        else { u.push_back(v[i]); ++i; ++j;}
    }
    return u;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int size;
    std::cin >> size;
    std::vector <int>a;
    while (size != 0) {
        a.push_back(size);
        std::cin >> size;
    }
    std::cin >> size;
    std::vector <int>b;
    while (size != 0) {
        b.push_back(size);
        std::cin >> size;
    }
    std::vector <int>u;
    u = resolver(a, b);
    for (int i = 0; i < u.size(); i++) {
        std::cout << u[i] << " ";
    }
    std::cout << std::endl;
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