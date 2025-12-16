// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

bool resolver(std::vector <int> const& v,int& p) {
    int suma = 0;// Coste 1
    int i = v.size() - 1;// Coste 1
    bool encontrado = false;// Coste 1
    while (i >= 0 && !encontrado) {// Coste 1 //Considerando el peor de los casos donde se recorre el vector completo, hay n interacciones.
       encontrado = suma == v[i];// Coste 1
       p = i;// Coste 1
       suma = suma + v[i]; // Coste 1
        i--;// Coste 1
    }
    return encontrado;// Coste 1
}
//La complejidad total es de orden n (lineal), mas exactamente f(n)= 5n + 4.

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int size;
    // leer los datos de la entrada
    std::cin >> size;

    std::vector <int> v(size);

    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    bool sol = resolver(v,size);
    if (sol) {
        std::cout << "Si " << size << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
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