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
        fprintf(stdout, "%4d: %s\n", i, data[i].c_str());
    }
    fprintf(stdout, "\n");
}

void run(int n) {
    vector<string> data = generate_vector(n);
    show("datos antes:", data);
    selection_sort(data);
    show("datos despues:", data);
}

void bad_usage(const char *program) {
    fprintf(stderr, "uso: %s n (para 0 <= n < 128)\n", program);
}

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        bad_usage(argv[0]);
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);
    if (n < 0 || n >= 128) {
        bad_usage(argv[0]);
        return EXIT_FAILURE;
    }

    run(n);
    return EXIT_SUCCESS;
}
