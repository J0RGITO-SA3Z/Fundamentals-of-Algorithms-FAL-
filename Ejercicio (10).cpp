// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
bool resolver(std::vector <int>& v,const int& d) {
    int i = 0;
    int dec = 1;
    int dif = 0;
    while (i < v.size() - 1 && dec <= d && (dif == 1 || dif == 0)) {
        if (v[i] == v[i + 1]) {
            dec++;
        }
        else {
            dec = 1;
            dif =  v[i + 1] - v[i];
        }
        i++;
    }
    return dec <= d && (dif == 1 || dif == 0);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int diver;
    int size;
    std::cin >> diver >> size;
    std::vector <int> v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    if (resolver(v,diver)) {
        std::cout << "SI\n";
    }
    else {
        std::cout << "NO\n";
    }
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