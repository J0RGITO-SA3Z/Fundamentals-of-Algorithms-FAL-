// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool esValida(const int& k, const int& c, std::vector <int>const& sol, std::vector <int>const& apar, const int& a, const int& r, const int& v) {
    if (c == 2 && sol[k - 1] == 2)
        return false;
    if (apar[2] > apar[0])
        return false;
    if (apar[0] > a || apar[1] > r || apar[2] > v)
        return false;
    return true;
}

bool esSolvalida(std::vector <int>const& sol, std::vector <int>const& apar) {
    if (apar[1] <= apar[2] + apar[0])
        return false;
    return true;
}

void escribirsol(const std::vector <int>& sol) {
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i] == 0) {
            std::cout << "azul" << " ";

        }
        else if (sol[i] == 1) {
            std::cout << "rojo" << " ";

        }
        else if (sol[i] == 2) {
            std::cout << "verde" << " ";

        }
    }
    std::cout << std::endl;
}

// función que resuelve el problema
int resolver(const int& m, const int& n, std::vector <int>& sol, const int& k, std::vector <int>& apar, const int& a, const int& r, const int& v) {
    int numsol = 0;
    for (int c = 0; c < n; c++) {
        sol[k] = c;
        apar[c]++;
        if (esValida(k, c, sol, apar, a, r, v)) {
            if (k == sol.size() - 1) {
                if (esSolvalida(sol, apar)) {
                    escribirsol(sol);
                    numsol++;
                }
            }
            else {
                numsol += resolver(m, n, sol, k + 1, apar, a, r, v);
            }
        }
        apar[c]--;
    }
    return numsol;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int m;
    int a;
    int r;
    int v;
    std::cin >> m;
    std::cin >> a;
    std::cin >> r;
    std::cin >> v;
    if (m == 0 && a == 0 && r == 0 && v == 0)
        return false;
    int soluciones = 0;
    int n = 3;
    std::vector <int> sol(m);
    std::vector <int> apar(n, 0);
    apar[1] = 1;
    sol[0] = 1;
    if (sol.size() > 1) {
        soluciones = resolver(m, n, sol, 1, apar, a, r, v);
    }
    else {
        escribirsol(sol);
        soluciones++;
    }
    if (soluciones == 0) {
        std::cout << "SIN SOLUCION" << std::endl;
    }
    std::cout << std::endl;
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