// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


// función que resuelve el problema
long long int resolver(std::vector <bool>& v, const long long int& k) {
    std::vector <int>d(v.size());
    int mindist = v.size() + 1;
    int dist = 0;
    int start = 0;
    int cont = 1;
    int numtrues = 0;
    int pos = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]) {
            numtrues++;
            d[pos] = cont;
            dist += cont;
            pos++;
            if (numtrues == k) {
                if (dist < mindist) {
                    mindist = dist;
                }
                if (k > 1) {
                    numtrues--;
                    dist -= d[pos + 1 - k];
                }
            }
            start = 1;
            cont = 1;
        }
        else if (start == 1) {
            cont++;
        }
    }
    return mindist;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int size;
    std::cin >> size;
    if (size == -1)
        return false;
    int num;
    std::vector <bool>v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> num;
        if (num == 0) {
            v[i] = false;
        }
        else {
            v[i] = true;
        }
    }
    int k;
    std::cin >> k;
    long long int u = resolver(v, k);
    std::cout << u << std::endl;
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