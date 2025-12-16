// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>



int resolverNofinal(const int& num1, const int& dis0) {
    int digito = num1 % 10;
    if (num1 != 0) {
        if (digito % 2 == 0) {
            return  digito +1 + resolverNofinal(num1/10,1)*10;
        }
        else {
            return  digito - 1 + resolverNofinal(num1/10,1)*10;
        }
    }
    else if (num1 == 0 && dis0 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}


void resuelveCaso() {
    int number1;
    std::cin >> number1;
    int sol1 = resolverNofinal(number1,0);
    std::cout << sol1 << std::endl;
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