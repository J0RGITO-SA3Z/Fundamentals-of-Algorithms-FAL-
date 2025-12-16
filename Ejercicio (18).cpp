// Nombre del alumno Jorge Saéz Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void resolver(std::vector<int> const& v, int& comienzo, int& final,const int& alt) {
    int cont = 0;
    int max = 0;
    int c = 0;
    int f = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > alt) {
            cont++;
            f = i;
        }
        else {
            cont = 0;
            c = i + 1;
        }
        if (cont > max) {
            max = cont;
            comienzo = c;
            final = f;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int size;
    int alt;
    int c = 0;
    int f = 0;
    std::cin >> size;
    std::cin >> alt;
    std::vector<int> v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    resolver(v, c, f, alt);
    std::cout << c << " " << f << std::endl;
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