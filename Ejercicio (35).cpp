// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


int resolverInvertir(const int& num1, const int& resul, const int& longitud) {
    if (num1 > 0 || longitud > 0) {
        int digit1 = num1 % 10;
        return resolverInvertir(num1 / 10, resul * 10 + digit1 , longitud -1);
    }
    else {
        return resul;
    }
    std::cout << std::endl;
}

int resolverComple(const int& num1, const int& resul, const int& pot,const int& cero, int& longitud) {
    if (num1 > 0 || cero == 0) {
        longitud++;
        int digit1 = num1 % 10;
        return  resolverComple(num1 / 10, resul +  (9 - digit1) * pot, pot * 10,1,longitud);
    }
    else {
        return resul;
    }
}

void resuelveCaso() {
    int number1;
    int longi = 0;
    std::cin >> number1;
    int sol1 = resolverComple(number1,0,1,0,longi);
    int sol2 = resolverInvertir(sol1,0,longi);
    std::cout << sol1 << " ";
    std::cout << sol2 << std::endl;
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