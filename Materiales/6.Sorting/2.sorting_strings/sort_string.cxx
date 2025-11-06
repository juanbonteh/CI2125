///
/// sort_string.cxx
///

#include "sort_string.h"

#include <cstdio>

using std::string;
using std::vector;

int min(int lb, int ub, const vector<string>& data) {
    // @@@ TAREA: completar
    return -1; // @@@ eliminen esta última línea: lo puse sólo para que compile
}

int min(const vector<string>& data) {
    const int n = data.size();
    int index = min(0, n, data);
    if (index < 0) {
        exit(EXIT_FAILURE);
    }
    return index;
}

void selection_sort(vector<string>& data) {
    // @@@ TAREA: completar
}
