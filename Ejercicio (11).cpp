// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema

int resolver(std::vector <int>& v, const int& k) {
    int cont = 0;
    int suma = 0;
    int j = 0;
    int i = 0;
   while( i < v.size() && j < v.size()) {
        if (v[j] - v[i] > k) {
            i++;
        }
        else if(v[j] - v[i] < k){
            j++;
        }
        else if (v[j] - v[i] == k) {
            cont++;
            i++;
            j++;
        }
    }
    return cont;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int size;
    int k;
    std::cin >> size;
    std::cin >> k;
    if (size == -1)
        return false;
    std::vector <int>v(size);
    for(int i = 0; i < v.size(); i++){
        std::cin >> v[i];
    }
    int sol = resolver(v,k);
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