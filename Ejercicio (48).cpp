// Nombre del alumno Jorge Saéz Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
    bool cumple;
    int suma;
};


int absvalue(int num) {
    int sol = num;
    if (num < 0) {
        sol =  -1 * num;
    }
    return sol;
}

// función que resuelve el problema
tSol buscarIz(const int& ini, const int& fin, std::vector<int> const& v) {
    tSol sol;
    if (ini + 1 == fin) {
        sol.cumple = true;
        sol.suma = 0;
        if (v[ini] % 2 == 0 ) {
            sol.suma = 1;
        }
        return sol;
    }
    if (ini + 2 == fin) {
        sol.cumple = true;
        sol.suma = 0;
        if (v[ini] % 2 == 0 && v[ini + 1] % 2 == 0) {
            sol.suma = 2;
        }
        else if(v[ini] % 2 == 0 || v[ini + 1] % 2 == 0)  {
            sol.suma = 1;
        }
        return sol;
    }
    else {
       int mitad = (fin + ini - 1) / 2;
       tSol iz = buscarIz(ini, mitad + 1,  v);
       tSol dr = buscarIz(mitad + 1, fin,  v);
       sol.suma = iz.suma + dr.suma;
       sol.cumple = absvalue(iz.suma - dr.suma) <= 2 && iz.cumple && dr.cumple;
       return sol;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size;
    tSol sol1;
    std::cin >> size;
    if (size == 0)
        return false;
    std::vector<int> v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    sol1 = buscarIz(0, v.size(), v);
    if (sol1.cumple) {
        std::cout << "SI" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
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