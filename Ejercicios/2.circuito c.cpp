#include <iostream>
using namespace std;

int notZ(int p) {
    return p ? 0 : 1;
}

int andZ(int p, int q) {
    return (p && q) ? 1 : 0;
}

int orZ(int p, int q) {
    return (p || q) ? 1 : 0;
}

int nandZ(int x, int y) {
    return notZ(andZ(x, y));
}

int C(int x, int y) {
    return orZ(nandZ(x, y), y);
}

int main() {
    int x, y;
    for (x = 1; x >= 0; x--) {
        for (y = 1; y >= 0; y--) {
            cout << "x=" << x << ", y=" << y << " => r=" << C(x, y) << endl;
        }
    }
    return 0;
}