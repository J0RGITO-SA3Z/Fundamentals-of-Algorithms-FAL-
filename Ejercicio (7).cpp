// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
//Calculamos su complejidad
void resolver(std::vector <long long int> &v, int fallo) {//coste 1
    int inicial = 0;//coste 1
    int contador = 0;//coste 1
    for (int i = 0; i < v.size(); i++) {//coste 1 //Bucle iterativo de complejidad variable n
        if (v[i] != fallo) {//coste 1 //Tendremos en cuenta el peor de los casos de la expresión condicional
            v[contador] = v[i];//coste 1
            contador++;//coste 1
        }
    }
    v.resize(contador);//coste 1
}
//Dado el peor de los casos y el bucle iterativo, la funcion de complejidad para el algoritmo dado es f(n)= 4n + 3 que pertenece la orden de O(n) (Requisito que nos exigia el enunciado).

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int size;
    int fallo;
    std::cin >> size;
    std::cin >> fallo;
    std::vector <long long int> v(size);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
   resolver(v, fallo);
    // escribir sol
   std::cout << v.size()<< std::endl;
   for (int i = 0; i < v.size(); i++) {
       std::cout<< v[i]<<" ";
   }
   std::cout << std::endl;
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