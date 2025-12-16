// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


// función que resuelve el problema
long long int resolver(std::vector <bool>& v, const long long int& k) {
    int minlog = 0;
    int lon = 1;
    int cont = 0;
    int i = 0;
    int j = 0;
    while (cont < k && i < v.size() && j<v.size()) {
        if (!v[j]) {
            j++;
        }
        if (!v[i]) {
            i++;
        }
        else if (v[i] && cont < k) {
            cont++;
            i++;
        }
    }
    if (i == v.size() && cont < k) {
        return i + 1;
    }
    minlog = i - j;
    j++;
    int a = i;
    while(a < v.size()) {
        if (v[a]) {
            if (v[j]) {
                lon = a - j + 1;
                if (lon < minlog) {
                    minlog = lon;
                }
                a++;
            }
            else {
                j++;
            }
        }
        else {
            a++;
        }
    }
    return minlog;
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