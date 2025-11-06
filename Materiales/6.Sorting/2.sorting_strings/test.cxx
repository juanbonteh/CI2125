///
/// test.cxx
///
/// programa para probar el ordenamiento de datos de tipo 'string'
///
/// @@@ NOTA: La idea es que este programa funcione como lo hace el ordenamiento de datos enteros
/// la única diferencia es que aqui lo hacemos con valores de tipo 'string'
///
/// @@@ IMPORTANTE: Para hacer que este programa compile y corra, deben ..
/// 1. Copiar los archivos 'names.h' y 'names.cxx' que se encuentran en Materiales/1.Vectors & Strings/3.Nombres
/// 2. Hacer las TAREAS requeridas .. como ya lo hicieron para el ordenamiento de números de doble precisión
/// Eso es todo. Buenas noticias: NO hay que hacer ningún cambio a 'names.h' y 'names.cxx'
/// la funcion 'generate_vector' en este archivo llama a 'generate_names', definida en 'names.cxx'

#include <cstdio>
#include <cstdlib>

#include "names.h"
#include "sort_string.h"

using std::string;
using std::vector;

vector<string> generate_vector(int n) {
    vector<string> data = generate_names(n);
    return data;
}

void show(const char *label, const vector<string>& data) {
    fprintf(stdout, "%s\n", label);
    const int n = data.size();
    for (int i = 0; i < n; ++i) {
        fprintf(stdout, "%4d: %s\n", i, data[i].c_str()); // @@@ Noten el uso de %s y el método c_str()
    }
    fprintf(stdout, "\n");
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
