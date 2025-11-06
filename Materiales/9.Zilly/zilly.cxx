///
/// Zilly in C++
///
/// A partial emulation of Zilly in C++, with sample usage
///

#include <cstdio>

/// Zilly Emulator | Emulador de Zilly

typedef int Z;

/// Zilly primitive functions | Funciones primitivas de Zilly

// less than | menor que
Z lt(Z n, Z k) {
    // return k < n;
    return k < n ? 1 : 0;
}

// subtract | resta
Z sub(Z n, Z k) {
    return k - n;
}

///
/// Programmer defined functions | Funciones definidas por el programador
/// De aqui en adelante, todal las definiciones deben hacerse usando las primitivas ..
/// .. o funciones que derivaron anteriormente a partir de las primitivas.
///

// Change sign | Cambio de signo (negativo <=> positivo) es decir .. negación
Z chs(Z n) {
    // return -n
    return 0; // <== @@@ TAREA: ¡cambiar esto para que haga lo correcto!
}

// Add | Suma
Z add(Z n, Z k) {
    // return n + k;
    return 0; // <== @@@ TAREA: ¡cambiar esto para que haga lo correcto!
}

// Less or equal to | Menor o igual a
Z le(Z n, Z k) {
    // return k <= n;
    return 0; // <== @@@ TAREA: ¡cambiar esto para que haga lo correcto!
}

/// Test cases | Casos de prueba

void test00() {
    fprintf(stdout, "lt(0, -1) ==> %3d\n", lt(0, -1));
    fprintf(stdout, "lt(0,  0) ==> %3d\n", lt(0,  0));
    fprintf(stdout, "lt(0,  1) ==> %3d\n", lt(0,  1));
}

void test01() {
    fprintf(stdout, "sub(42,  0) ==> %3d\n", sub( 0, 42));
    fprintf(stdout, "sub(42,  0) ==> %3d\n", sub(42,  0));
    fprintf(stdout, "sub( 0, 67) ==> %3d\n", sub( 0, 67));
    fprintf(stdout, "sub(67,  0) ==> %3d\n", sub(67,  0));
    fprintf(stdout, "sub(42, 67) ==> %3d\n", sub(42, 67));
    fprintf(stdout, "sub(67, 42) ==> %3d\n", sub(67, 42));
}

void test02() {
    Z r1 = 42 - (67 - 25);
    Z r2 = sub(sub(25, 67), 42); // traducción de la expresión arriba, usando sólo las primitivas de Zilly

    fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);
}

void test03() {
    Z r1 = 1024 - 512 - (67 - (42 - 512));
    Z r2 = 0; // <== @@@ TAREA: traducir la expresión arriba a la equivalente usando sólo las primitivas de Zilly

    fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);
}

void test04() {
    // @@@ TAREA: defina casos de prueba para 'chs'
}

void test05() {
    // @@@ TAREA: defina casos de prueba para 'add'
}

void test06() {
    // @@@ TAREA: defina casos de prueba para 'le'
}

int square(int n) {
    // <== @@@ TAREA: implemente esta función, que computa el cuadrado de n (positivo)
    // Pero deben hacerlo tan sólo con primitivas de Zilly
    // Y pueden hacerlo con recursión .. ¡sumando numeros impares!
    // Ayudas: a) sumen de mayor a menor; b) consigan la relacion de square(n) con square(n-1)
    // Tip: impleméntela primero en C++, usando suma y recursión .. ¡con expresión condicional, obviamente!
    // Después de conseguir la fórmula recursiva mágica, compílenla a las primitivas de Zilly:
    // sólo se vale usar sub, lt (opcional), y recursión .. bien fundada con condicional.
    return 0; // λλλ Reemplazar el 0 por el λλλ chorizo λλλ mágico
}

void test07() {
    for (int i = 0; i < 9; ++i) {
        Z r1 = i * i;       // Broadway the easy way
        Z r2 = square(i);   // Broadway the hard way
        fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);
    }
}

int palindromo(int i){
  // @@@ TAREA: implemente esta función, que determina si un número es palíndromo
  // Debe hacerlo tan sólo con primitivas de Zilly
  // Puede definir cualquier función auxiliar que necesite (las cuales dependan de las primitivas de zilly)
  // Y pueden hacerlo con recursión.
  // Retorna 1 si lo es
  // Retorna 0 si en caso contrario.
  return 0;
}

void test08(){
  int numeros[] = {121, 123, 454, 789, 1331, 12321, 1234321, 123456};
  for(int i = 0; i < 8; ++i){
    int n = numeros[i];
    int r = palindromo(n);
    fprintf(stdout, "palindromo(%d) ==> %d\n", n, r);
  }
}

int main() {
    test00();
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    return 0;
}
