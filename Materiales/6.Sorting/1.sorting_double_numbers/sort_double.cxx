///
/// sort_double.cxx
///

#include "sort_double.h"

#include <cstdio>
#include <cstdlib>

using std::vector;

// Copiar el código de sort_int y modificarlo ayuda .. pero ..
// no olviden que ahora estan trabajando con 'double' en vez de 'int'
// Sin embargo, noten que los índices de los vectores son de tipo int .. duh!
// Presten atención para diferenciar si estan trabajando con datos o indices!

int min(int lb, int ub, const vector<double>& data) {
    // @@@ TAREA: completar
    return -1; // @@@ eliminen esta última línea: lo puse sólo para que compile
}

int min(const vector<double>& data) {
    const int n = data.size();
    int index = min(0, n, data);
    if (index < 0) {
        exit(EXIT_FAILURE);
    }
    return index;
}

void selection_sort(vector<double>& data) {
    // @@@ TAREA: completar
}
