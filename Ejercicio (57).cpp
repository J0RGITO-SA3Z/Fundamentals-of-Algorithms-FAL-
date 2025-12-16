// Nombre del alumno Jorge Saez Salto
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

struct tDatos {
    int numCanciones, tiempoida, tiempovuelta;
    std::vector < std::pair < int, int > > array;//first duracion second satisfaccion
};

class comparador {
public:
    bool operator ()(std::pair <int, int > p1, std::pair <int, int > p2) {
        return (float)p1.second / p1.first > (float)p2.second / p2.first;
    }
};

bool esValida(const int& c, const int& k, int& tiempoidaact, int& tiempovueltaact, const tDatos& datos) {
    if (c == 0 && tiempoidaact > datos.tiempoida) { return false; }
    if (c == 1 && tiempovueltaact > datos.tiempovuelta) { return false; }
    return true;
}

bool esSolValida(const int& tiempoidaact,const int& tiempovueltaact, const tDatos& datos) {
    return tiempoidaact == datos.tiempoida && tiempovueltaact == datos.tiempovuelta;
}

int estimacion(const tDatos& datos, const int& k, const int& tiempoidaact, const int& tiempovueltaact) {
    int a = k + 1;
    int sumat = 0;
    int sumasa = 0 ;
    int totalact = tiempoidaact + tiempovueltaact;
    int totaltiempo = datos.tiempoida + datos.tiempovuelta;
    while (a < datos.numCanciones && totalact + sumat <= totaltiempo) {
        sumat += datos.array[a].first; // REALIZAMOS UNA ESTIMACION DE LA SATISFACCION  CON EL CONJUNTO DE TIEMPO 
        sumasa += datos.array[a].second;
        a++;
    }

    if (a < datos.numCanciones && sumat < totaltiempo) {
        sumasa += datos.array[a].second * ((totaltiempo - sumat) / datos.array[a].first) + 1;  //COTA SUPERIOR LE SUMAMOS A LA SUMA LA PARTE SATISFACCION CORRESPONDIENTE DEL ELEMENTO EN POS A SUMANDO 1 
    }

    return sumasa;
}

// función que resuelve el problema
void resolver(const tDatos& datos, std::vector <int>& sol, const int& k, int& satisf, int& satisfmayor, int& tiempoidaact, int& tiempovueltaact) {//const std::vector <int>& maxsnino

    for (int c = 0; c < 3; c++) {

        sol[k] = c;
        if (c == 0) { tiempoidaact += datos.array[k].first; }
        if (c == 1) { tiempovueltaact += datos.array[k].first; }
        if (c != 2) { satisf += datos.array[k].second;}

        if (esValida(c, k, tiempoidaact, tiempovueltaact, datos)) {

            if (k == sol.size() - 1) {
                if (esSolValida(tiempoidaact, tiempovueltaact, datos)) {
                    if (satisf > satisfmayor) { satisfmayor = satisf; }
                }
            }
            else {
                if (estimacion(datos,k , tiempoidaact, tiempovueltaact) + satisf > satisfmayor) {
                    resolver(datos, sol, k + 1, satisf, satisfmayor, tiempoidaact, tiempovueltaact);
                }
            }

        }
        if (c == 0) { tiempoidaact -= datos.array[k].first;}
        if (c == 1) { tiempovueltaact -= datos.array[k].first; }
        if (c != 2) { satisf -= datos.array[k].second;}
    }
}
//ARBOL DE EXPLORACIÓN 
//LAS RAMAS SON LA SOPCIONES PARA CADA CANCION (IDA,VUELTA,NO USAR)   -- 3 RAMAS
//LA SALTURAS DEL ARBOL SON CADA UNA DE LAS CANCIONES DISPONIBLES     -- (NUMERO DE CANCIONES) ALTURAS
//EEL VECTOR SOLUCION ES UN VECTOR CON TAMANO EL NUMERO DE CANCIONE Y CADA VALOR ES 0 ,1 O 2 (0 PARA LA IDA, 1 PARA LA VUELTA, 2 NO SE USA) -- VECTROR SOLCION DE TAMANO NUMERO DE CANCIONES
//SE HA UTILIZADO OPTIMIZACIÓN CON ESTIMACION Y ORDENANDO LAS DUPAS DE LA ENTRADA DE FORMA MAS OPTIMA (ORDENADO POR RELACION DE SATISFACCION/ DURACION) -- ENTRADA ORDENADA DE FORMA OPTIMA 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    tDatos datos;
    int satisf = 0;
    int num = 0;
    int val;
    int val2;

    std::cin >> datos.numCanciones;
    std::cin >> datos.tiempoida;
    std::cin >> datos.tiempovuelta;
    if (datos.numCanciones == 0 && datos.tiempoida == 0 && datos.tiempovuelta == 0)
        return false;

    for (int i = 0; i < datos.numCanciones; i++) {
        std::cin >> val;
        std::cin >> val2;
        datos.array.push_back({val ,val2});
    }

    std::sort(datos.array.begin(), datos.array.end(), comparador());

    std::vector <int> sol(datos.numCanciones);

    int satisfmax = 0, tiempoida = 0, tiempovuelta = 0;

    resolver(datos, sol, 0, satisf, satisfmax, tiempoida, tiempovuelta);

    if (satisfmax > 0) { std::cout << satisfmax << std::endl; }
    else { std::cout << "Imposible" << std::endl; }
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