// Nombre del alumno Jorge Sáez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
struct tPiso {
    std::string identificador;
    int altura;
    int piso;
};
//Calculamos el coste de la función
std::vector <std::string> resolver(std::vector <tPiso> const& v) { 
    std::vector <std::string> u;  //Coste 1
    int max = -1;  //Coste 1
    for (int i = v.size() - 1; i >= 0; i--) {  //Coste 1 // Bucle iterativo de longitud n
        if (v[i].piso > max) {  //Coste 1 // Dada las instrucciones condicionales escogemos el peor de los casos
            u.push_back(v[i].identificador);  //Coste 1
        }
        if (v[i].altura > max) {  //Coste 1 // Dada las instrucciones condicionales escogemos el peor de los casos
            max = v[i].altura;  //Coste 1
        }
    }
    return u;  //Coste 1
}
// Dado el peor de los casos y un bucleiterativo, la funcion de complejidad aproximada es f(n)= 5n + 3 que pertenece al orden de O(n);

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int caso;
    std::cin >> caso;
    if (caso == 0) {
        return false;
    }
    std::vector <tPiso> lista(caso);
    for (int i = 0; i < caso; i++) {
        std::cin >> lista[i].identificador;
        std::cin >> lista[i].altura;
        std::cin >> lista[i].piso;
    }
    std::vector <std::string> u = resolver(lista);
    if (u.size() > 0) {
        std::cout << u.size() << std::endl;
        for (int a = 0; a < u.size(); a++) {
            std::cout << u[a] << " ";
        }
        std::cout << std::endl;
    }
    else
        std::cout << "Ninguno" << std::endl;

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