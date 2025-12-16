// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

long long int resolver(std::vector <int> const& v, int& tamano) {
    int min = v[0]; // Coste 1
    int aparicion = 1;// Coste 1
    long long int suma = v[0];// Coste 1
    for (int i = 1; i < v.size(); i++) { // Como s un bucle for tiene n interacciones por y la cosntante multiplicativa de 4 (peor de los casos)
            if (min > v[i]) { // Coste 1
                min = v[i]; // Coste 1
                aparicion = 1; // Coste 1
            }
            else if (min == v[i]) { // Coste 1
                aparicion++; // Coste 1
            }
        suma = suma + v[i]; // Coste 1
    }
    suma = suma - (min * aparicion); // Coste 1
    tamano = tamano - aparicion;// Coste 1
    return suma;// Coste 1
}
//La complejidad total es de orden n , mas exactamente f(n)= 4n + 6

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int size;
    // leer los datos de la entrada
    std::cin >> size;
    std::vector < long int> v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    long long int sol = resolver(v, size);
    std::cout << sol << " " << size << std::endl;
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