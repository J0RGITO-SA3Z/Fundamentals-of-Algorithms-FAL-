// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// funcion que resuelve el problema
//CALCULAMOS SU COMPLEJIDAD
int resolver(std::vector <int>const& v,const int& m) {
    int sumParcial = 0;
    int max = v[0];
    int indicemax = 0;
    int indice2 = 0;
    int sol = 0;
    int s = 0;
    for (int a = 1; a < v.size(); a++) {
        if (v[a] >= max) {
            max = v[a];
            indicemax = a;
        }
    }
    for (int i = 0; i < m; ++i) {
        sumParcial = sumParcial + v[i];
        if (v[i] >= max) {
            max = v[i];
            indice2 = i;
        }
    }
    if (v[indice2] == v[indicemax]) {
        s = sumParcial;
    }
    for (int j = 0; j < v.size() - m; ++j){ 
        sumParcial = sumParcial + v[j + m];
        sumParcial = sumParcial - v[j];
        if (v[j+m] == v[indicemax]) {
            indice2 = j+m;
        }
        if (sumParcial >= s && j < indice2 && j + m >= indice2) { s = sumParcial; sol = j+1; }
    }

    return sol;
}

bool resuelveCaso() {
    long long int size;
    int paginas;
    std::cin >> size;
    std::cin >> paginas;
    if (size == 0 && paginas == 0)
        return false;
    std::vector <int>v(size);
    for (long long int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    int sol = resolver(v,paginas);
    std::cout << sol << std::endl;
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
