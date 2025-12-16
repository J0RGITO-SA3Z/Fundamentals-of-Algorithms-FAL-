// Nombre del alumno Jorge Saéz Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
    bool cumple;
    int num;
    int aparicion;
};

// función que resuelve el problema
//Calculamos su complejidad
tSol buscarIz(const int& ini, const int& fin, std::vector<int> const& v) {
    tSol sol;
    if (ini + 1 == fin) { //CASO BASE UN ELEMENTO
        sol.cumple = true;
        sol.num = v[ini];
        sol.aparicion = 1;
        return sol;
    }
    else {
        int mitad = (fin + ini - 1) / 2;
        tSol iz = buscarIz(ini, mitad +1, v);
        tSol dr = buscarIz(mitad + 1 , fin, v);
        int i = ini;
        int j = fin;
        while (i < j) {
            if (i <= mitad) {
                if (v[i] == dr.num) { dr.aparicion++; }
            }
            else {
                if (v[i] == iz.num) { iz.aparicion++; }
            }
            i++;
        }
        if (iz.aparicion > (ini+fin)/2 ) {
            sol.num = iz.num;
            sol.aparicion = iz.aparicion;
            sol.cumple = true;
        }
        else if (dr.aparicion > (ini + fin) / 2) {
            sol.num = dr.num;
            sol.aparicion = dr.aparicion;
            sol.cumple = true;
        }
        else {
            sol.num = dr.num;
            sol.aparicion = dr.aparicion;
            sol.cumple = false;
        }
        return sol;
    }
}
//Ejercicio resuelto usando la tecnica de Merge short 
//Recurrencia:
//      T(n) = {c0              si n == 1 ;
//             {
//             {2T(n/2) + n     si n > 2
//Desplegado:
// Sacamos los primeros terminos
// T(n) = 2T(n/2) + n = 2(2T(n/4) + n/2) + n = 4T(n/4) + 2n = 4(2T(n/8) + n/4) + 2n = 8T(n/8) + 7n = 8(2T(n/16) + n/8) + 3n =
// 16T(n/16) + 4n= 16(2T(n/32) + n/16) + 4n = 32T(n/32) + 5n
//Haciendo el desplegado k veces: f(n) =  2^k T(n/2^k) + kn
// Si reemplazamos k por log2(n) => f(n) = nT(n/n) + log2(n)n = nT(1) + log2(n)n  = n*c0 + log2(n)n = f(n) SIENDO N EL NUMERO DE ELEMENTOS DEL VECTOR
// LA COMLEJIDAD DEL ALGORITMO USANDO LA TÉCNICA DE MERGE SHORT ES DE => O(nlogn) SIENDO N EL NUMERO DE ELEMENTOS DEL VECTOR
//
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int size;
    tSol sol1;
    std::vector<int> v;
    std::cin >> size;
    if (size != 0) {
        while (size != 0) {
            v.push_back(size);
            std::cin >> size;
        }
        sol1 = buscarIz(0, v.size(), v);
        if (sol1.cumple) {
            std::cout << sol1.num << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
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