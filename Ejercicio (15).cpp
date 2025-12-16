// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
long long int resolver(std::vector<long long int> const& u , const int& dia) {
    if (dia - 1 > u.size() - 1 || dia - 1 <= -1) {
        return 0;
    }
    else {
        return u[dia - 1];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size;
    int num;
    long long int suma = 0;
    int dia;
    std::cin >> size;
    if (size == -1)
        return false;
    std::vector<int> v(size);
    std::vector<long long int> u(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    for (int i = v.size() - 1; i > -1; i--) {
        suma = suma + v[i];
        u[i] = suma;
    }
    std::cin >> num;
    for (int a = 0; a < num; a++) {
        std::cin >> dia;
        std::cout << resolver(u,dia) << std::endl;
    }
    std::cout << "---" << std::endl;
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
