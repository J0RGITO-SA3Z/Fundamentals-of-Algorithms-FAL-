// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
// funcion que resuelve el problema
//CALCULAMOS SU COMPLEJIDAD
int resolver(std::vector <int>const& v, const int& k, int& maxi) {
	int suma = 0; //coste 2;
	int a = 0; //coste 2;
	for (int i = 0; i < k; ++i) //coste 1; coste dependiente de k del buccle iterativo f(k) = 2k
		suma = suma + v[i];//coste 1;
	int max = suma; //coste 2;
	for (int j = 0; j < v.size() - k; ++j) { //coste 1; coste dependiente de v.size - k del buccle iterativo f(v.size - k) = 6(v.size - k)
		suma = suma + v[j + k];//coste 1;
		suma = suma - v[j];//coste 1;
		if (suma >= max) { //Expresion condicional, se tiene en cuenta el peor de os casos (coste 3)
			max = suma; 
			a = j + 1; 
		}//coste 3;
	}
	maxi = max;//coste 1;
	return a;//coste 1;
}
//Teniendo en cuenta el peor de los casos f(v.size - k) = 2k + 6(v.size - k) + 8, es decir que la complejidad pertenece al orden de O(v.size - k), es decir, complejidad lineal.
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
	int size;
	int k;
	int max = 0;
	std::cin >> size;
	std::cin >> k;
	std::vector <int>v(size);
	for (int i = 0; i < v.size(); i++) {
		std::cin >> v[i];
	}
	int sol = resolver(v, k, max);
	std::cout << sol << " " << max << std::endl;
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