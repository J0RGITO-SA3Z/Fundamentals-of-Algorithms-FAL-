// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int cotainf;
    int cotasup;
    int cota;
    int num;
    long long int suma = 0;
    std::cin >> cotainf;
    std::cin >> cotasup;
    if (cotainf == 0 && cotasup == 0) {
        return false;
    }
    cotasup = cotasup - cotainf + 1;
    std::vector <int> v(cotasup);
    std::vector <long long int> u(cotasup + 1);
    u[0] = 0;
    for (int i = 1; i < v.size() + 1; i++) {
        std::cin >> v[i - 1];
        suma = suma + v[i - 1];
        u[i] = suma;
    }
    std::cin >> num;
    for (int a = 0; a < num; a++) {
        std::cin >> cotasup;
        cotasup = cotasup - cotainf;
        std::cin >> cota;
        cota = cota - cotainf;
        std::cout << u[cota + 1] - u[cotasup] << std::endl;
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