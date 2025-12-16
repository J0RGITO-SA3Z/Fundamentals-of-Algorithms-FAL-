// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60


// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>


long long int resolverFibonacci(const  long long int& num1, const  long long int& n1, const  long long int& n2) {

    if (num1 > 0) {
        return resolverFibonacci(num1 - 1, n2, n1 + n2);
    }
    else {
        return n1;
    }
  
}

bool resuelveCaso() {
    long long int number1;
    std::cin >> number1;
    if (!std::cin)
        return false;
    long long int sol1 = resolverFibonacci(number1, 0 , 1);
    std::cout << sol1 << std::endl;
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