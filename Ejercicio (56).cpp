// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct tDatos {
    int numJuguetes, numNinos;
    std::vector < std::vector <int > > satis;
};


bool esValida(const std::vector <bool>& marcas, const int& c) {
    return !marcas[c];
}

bool esSolValida(const std::vector <int>& sol, const int& k) {
    return k == sol.size() - 1;
}

bool estimacion(const std::vector <int>& maxsnino, const int& satisf, const int& satisfMax, const int& k) {
    return satisf + maxsnino[k] > satisfMax;
}


// función que resuelve el problema
void resolver(const tDatos& datos, std::vector <int>& sol, const int& k, int& satisf, int& satisfmayor, std::vector <bool>& marcas,const std::vector <int>&  maxsnino) {
    for (int c = 0; c < datos.numJuguetes; c++) {
        sol[k] = c;
        satisf += datos.satis[k][c];
        if (esValida(marcas,c)) {
            marcas[c] = true;
                if (esSolValida(sol,k)) {
                    if (satisf > satisfmayor) {satisfmayor = satisf;}
                }
                else {
                    if (estimacion(maxsnino,satisf,satisfmayor,k+1)) {
                       resolver(datos, sol, k + 1, satisf, satisfmayor, marcas,maxsnino);
                    }
                }
            marcas[c] = false;
        }
        satisf -= datos.satis[k][c];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    tDatos datos;
    int consumomax;
    int satisf = 0;
    int num = 0;
    int minconsum;
    std::cin >> datos.numJuguetes;
    if (!std::cin )
        return false;
    std::cin >> datos.numNinos;
    std::vector <int>  maxsnino(datos.numNinos);
    std::vector <int>  aux(datos.numJuguetes);
    for (int i = 0; i < datos.numNinos; i++) {
        std::cin >> aux[0];
        maxsnino[i] = aux[0];
        for (int a = 1; a < datos.numJuguetes; a++){
            std::cin >> aux[a];
            if (aux[a] > maxsnino[i]) { maxsnino[i] = aux[a]; }
        }
        datos.satis.push_back(aux);
    }
    for (int i = maxsnino.size() - 1; i > 0; i--) {
        maxsnino[i - 1] += maxsnino[i];
    }
    int satisfmax = 0;
    int satisMejor = 0;
    for (int i = 0; i < datos.numNinos; ++i) {
        satisMejor += datos.satis[i][i];
    }
    std::vector <int> sol(datos.numNinos);
    std::vector <bool> marcas(datos.numJuguetes,false);
    resolver(datos, sol, 0, satisf, satisfmax, marcas,maxsnino);
    std::cout << satisfmax<< std::endl;


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