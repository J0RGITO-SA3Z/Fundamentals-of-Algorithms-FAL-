// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool esValida(const int& num, const int& k, const int& c,  std::vector <int>& sol, const std::vector <int>& apar, const int& ca, const int& m, const int& cm) {
    if (k > 1 && c == sol[k - 1] && c == sol[k - 2])
        return false;
    if (apar[c] > num - apar[c] + 1)
        return false;
    if (ca > cm)
        return false;
    return true;
}

// función que resuelve el problema
int resolver(int& minconsum,int& num,const int& m, const int& n, std::vector <int>& sol, const int& k, int& consumoActual, int& consumoMayor, std::vector <int>& apar, std::vector <int>& consumo) {
    int numsol = 0;
    for (int c = 0; c < n; c++) {
        sol[k] = c;
        apar[c]++;
        consumoActual += consumo[c];
        num++;
        if (esValida(num, k, c, sol, apar, consumoActual, m,consumoMayor)) {
            if (k == sol.size() - 1) {
                    numsol++;
            }
            else {
                if (consumoActual + minconsum <= consumoMayor) {
                    numsol += resolver(minconsum, num, m, n, sol, k + 1, consumoActual, consumoMayor, apar, consumo);
                }
            }
        }
        num--;
        consumoActual -= consumo[c];
        apar[c]--;
    }
    return numsol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int m;
    int n;
    int consumomax;
    int cons = 0;
    int num = 0;
    int minconsum;
    std::cin >> m;
    if (m == 0)
        return false;
    std::cin >> n;
    int soluciones = 0;
    std::vector <int> sol(m);
    std::vector <int> apar(n,0);
    std::vector <int> consumo(n);
    std::cin >> consumomax;

    if (n > 0) {
        std::cin >> consumo[0];
        minconsum = consumo[0];
        for (int i = 1; i < consumo.size(); i++) {
            std::cin >> consumo[i];
            if (consumo[i] < minconsum) {
                minconsum = consumo[i];
            }
        }


    }
    soluciones = resolver(minconsum, num,m, n, sol, 0,cons, consumomax, apar, consumo);
    
 
    std::cout << soluciones << std::endl;
    

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