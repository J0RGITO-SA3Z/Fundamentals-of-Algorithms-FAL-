// Nombre del alumno Jortge Sáez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema

void cerosyunos(std::vector <int> const& v , int& numceros, int& numunos) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1){
            numunos++;
        }
        else if (v[i] == 0) {
            numceros++;
        }
    }
}

int equilibrio(std::vector <int> const& v){
    int p = -1;
    int i = v.size() - 1;
    int numunos = 0;
    int numceros = 0;
    cerosyunos(v, numceros, numunos);
    while (i >= 0 && p == -1) {
        if (numceros == numunos) {
            p = i;
        }
        if (v[i] == 1) {
            numunos--;
        }
        else if (v[i] == 0) {
            numceros--;
        }
        i--;
    }
    return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int size;
    std::cin >> size;
    std::vector <int> v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    int sol = equilibrio(v);
    // escribir sol
    std::cout << sol << std::endl;
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