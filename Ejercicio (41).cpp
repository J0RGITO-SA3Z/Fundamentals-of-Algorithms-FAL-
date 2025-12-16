// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>

//CALCULAMOS SU COMPLEJIDAD
long long int resolverPolinomio(const int& y, const  int& n, const  long long int& n1, const long long int& n2) {
    if (n == 0) {
        return n2;
    }
    else if (n == 1) {
        return n1;
    }
    else {
        return resolverPolinomio(y, n - 1, 2 * y * n1 - 2 * (n - 1) * n2, n1);
    }

}

//Coste de función recursiva, RECURRENCIA.
// T(n) =  { c0                  si n == 0 V n == 1;
//         { T(n - 1) + c1       si n > 1;
// Escribimos los primero terminos del desplegado
// T(n - 1) + c1 =>  sabemos que : T(n - 1) = T(n - 2) + c1 entonces T(n - 2) + c1 + c1 = T(n - 2) + 2c1; Aplicamos de nuevo:
// T(n-3) + c1 +2c1 = T(n - 3) + 3c1 De forma que desplegando k veces :   T(n - k) + kc1
// Desplegando k veces: T(n - k) + kc1 => siendo k = n => c0 + nc1 = f(n) que pertenece al orden de O(n) siendo n el grado del polinomio ; 
// => COSTE LINEAL RESPECTO AL GRADO DEL POLINOMIO => ES EFICIENTE
//Definicion recursiva (FINAL)
// ResolverPolinomio(y,n,n1,n2)=  { n2                                                             si n == 0;
//                                { n1                                                             si n == 1;
//                                { ResolverPolinomio(y,n - 1, 2 * y * n1 - 2 * (n - 1) * n2,n1)   si n > 1;
//Nos vamos quedando con las ultimas cifras de n y m nos quedamos con el menos significativo y seguimos la suma quitando un digito a ambos numeros para la siguiente llamada.

bool resuelveCaso() {
    int y;
    int n;
    std::cin >> n;
    if (n == -1)
        return false;
    std::cin >> y;
    long long int sol1 = resolverPolinomio(y, n, 2 * y, 1);
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