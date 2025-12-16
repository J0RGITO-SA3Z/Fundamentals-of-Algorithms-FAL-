// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>



// función que resuelve el problema
long long int resolver(const long long int& n, long long int pot) {
    long long int sol = 0;
    if (n == 0 && pot > 1) {
        sol = 0;
    }
    else if (n == 0 && pot == 1) {
        sol = 1;
    }
    else {
        int num = n % 10;
        if (num > 1) {
            if (pot == 1) {sol = (num - 1) * pot + 1 + resolver(n / 10, pot * 9);}
            else { sol = (num - 1) * pot + resolver(n / 10, pot * 9); }
        }
        else {
            sol = num*pot + resolver(n / 10, pot * 9);
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int n;
    std::cin >> n;
    if (!std::cin)
        return false;

    long long int sol = resolver(n,1);

    // escribir sol
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