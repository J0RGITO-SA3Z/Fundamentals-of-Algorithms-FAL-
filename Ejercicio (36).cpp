// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

//Calculamnos su coste
int resolverNofinal(const int& num1, const int& num2) {
    if (num1 > 0 || num2 > 0) {
        int digit1 = num1 % 10;
        int digit2 = num2 % 10;
        return (digit1 + digit2) % 10 + resolverNofinal(num1 / 10, num2 / 10) * 10;
    }
    else {
        return 0;
    }
}
//Coste de función recursiva, RECURRENCIA, Disminucion del tamano del problema por division y coste constante de las funciones sucesor y de combinacion.
// T(n,m)=  { c0                      si n == 0 && m == 0
//          { T(n/10,m/10) + c1       si n > 0 || m > 0
// El coste es el maximo de m y n.
// Desplegado: T(n/10^k, m/10^k) + kc1;decimos que T(n/10^k, m/10^k) +kc1 = c0 + kc1 = f(k), el orden de comnplejidad es O(k) DONDE K ES LA LONGITUD DEL NÚMERO MAS LARGO YA SEA M O N;
//Definicion recursiva (NO FINAL)
// suma(n,m)=  { 0                               si n == 0 && m == 0                            
//             {(n+m)%10 + 10* suma(n/10,m/10);  si n > 0 || m > 0;
//Nos vamos quedando con las ultimas cifras de n y m nos quedamos con el menos significativo y seguimos la suma quitando un digito a ambos numeros para la siguiente llamada.

int resolverFinal(const int& num1, const int& num2, const int& resul, const int& pot) {
    if (num1 > 0 || num2 > 0) {
        int digit1 = num1 % 10;
        int digit2 = num2 % 10;
            return  resolverFinal(num1/10, num2/10,resul + ((digit1+ digit2)%10)*pot, pot*10);
    }
    else {
        return resul;
    }
}

void resuelveCaso() {
    // leer los datos de la entrada
    int number1;
    int number2;
    std::cin >> number1;
    std::cin >> number2;
    int sol1 = resolverNofinal(number1, number2);
    int sol2 = resolverFinal(number1, number2,0,1);
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