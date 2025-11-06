///
/// test.cxx
///
/// programa para probar el ordenamiento de datos de tipo 'double' (punto flotante de doble precisión)
///
/// @@@ NOTA: La idea es que este programa funcione como lo hace el ordenamiento de datos enteros
/// la única diferencia es que aqui lo hacemos con valores de punto flotante de doble precisión
///

#include <cstdio>
#include <cstdlib>

#include "sort_double.h"

using std::vector;

// Un simple generador de numeros aleatorios
// de acuerdo a la distribucion uniforme estandard: 0 <= x <= 1
double uniform() {
    double numerator = double(rand());
    double denominator = double(RAND_MAX);
    return numerator / denominator;
}

// Un simple generador de numeros aleatorios en el intervalo [lb .. ub]
// Asume (sin chequear) que lb es menor o igual a ub
double random(double lb, double ub) {
    return (ub - lb) * uniform() + lb;
}

// genera el vector (muestra) de datos para la prueba de ordenamiento
vector<double> generate_vector(int n) {
    vector<double> data = {};
    for (int i = 0; i < n; ++i) {
        double x = random(-8.0, 8.0);
        data.push_back(x);
    }
    return data;
}

// @@@ TIP
// En lo que sigue, usen el ejemplo de ordenamiento de datos enteros como inspiración.
// Pueden copiar las partes que deben completar, PERO ..
// .. no olviden que ahora estan trabajando con datos de tipo 'double' en vez de 'int'

// @@@ TAREA: implementar la funcion 'show' que muestra el vector
void show(const char *label, const vector<double>& data) {
    // van a tener que usar un especificador de formato (format specifier) para punto flotante
    // No se limiten a usar %f: usen uno de la forma %W.Df donde:
    // W es el ancho necesario para mostrar los números con el punto decimal bien alineado
    // D es el número de digitos a la derecha del punto decimal: sugiero D igual a 6
}

void run(int n) {
    // @@@ TAREA: completar
}

void bad_usage(const char *program) {
    fprintf(stderr, "uso: %s n (para 0 <= n < 128)\n", program);
}

int main(int argc, const char *argv[]) {
    // @@@ TAREA: completar
}
