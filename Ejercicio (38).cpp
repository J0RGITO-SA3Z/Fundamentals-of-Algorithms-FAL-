// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>


bool resolverComple(const  long long int& num1, const  long long int& num2, bool resul, const long long int& suma) {
    if ((num1 > 0) && resul) {
        long long int digit = num1 % 10;
        resul = suma % digit == 0;
        return  resolverComple(num1 / 10,num2, resul, suma + digit);
    }
    else if (num1 == 0 && num2 > 0 && resul) {
        long long int digit2 = num2 % 10;
        resul = (suma - digit2) % digit2 == 0;
        return  resolverComple(num1,num2/10, resul, suma - digit2);
    }
    else {
        return resul;
    }
}

void resuelveCaso() {
    long long int number1;
    std::cin >> number1;
    bool sol1 = resolverComple(number1,number1,true, 0);
    if (sol1) {
        std::cout << "SI" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
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