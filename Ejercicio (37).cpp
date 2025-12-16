// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>


std::string resolverComple(const  long long int& num1, std::string& resul,const int& cero) {
    if (num1 > 0 || cero == 0) {
        long long int digit = num1 % 2;
        resul = std::to_string(digit) + resul;
        return  resolverComple(num1 / 2, resul,1);
    }
    else {
        return resul;
    }
}

void resuelveCaso() {
    long long int number1;
    std::string ini = "";
    std::cin >> number1;
    std::string sol1 = resolverComple(number1,ini,0);
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