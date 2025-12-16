// Nombre del alumno Jorge Saéz Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

int buscarIz(const int& ini, const int& fin, std::vector<int> const& v, const int& viajes) {
    if (ini >= fin || ini + 1 == fin) {
        return ini;
    }
    else {
        int mitad = (fin + ini - 1) / 2;
        int necesarios = 1;
        int suma = 0;
        for (int i = 0; i < v.size(); i++) {
            if (suma + v[i] <= mitad) {
                suma += v[i];
            }
            else {
                necesarios++;
                suma = v[i];
            }
        }
        if (necesarios >  viajes) {
            return buscarIz(mitad + 1, fin, v, viajes);
        }
        else {
            return buscarIz(ini, mitad + 1, v,  viajes);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size;
    int sol1;
    int max;
    int viajes;
    std::cin >> size;
    std::cin >> viajes;
    if (size == 0 && viajes == 0)
        return false;
    std::vector<int> v(size);
    std::vector<int> espacio;
    std::cin >> v[0];
    max = v[0];
    int suma = v[0];
    for (int i = 1; i < v.size(); i++) {
        std::cin >> v[i];
        if(v[i] > max){
            max = v[i];
        }
        suma += v[i];
    }
    sol1 = buscarIz(max, suma + 1, v, viajes);
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