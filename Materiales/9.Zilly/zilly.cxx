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
    // chs(n) = -n  -> 0 - n
    return sub(n, 0);
}


// Add | Suma
Z add(Z n, Z k) {
    // add(n)(k) = k + n = k - (-n) = sub(chs(n), k)
    return sub(chs(n), k);
}

// Less or equal to | Menor o igual a
Z le(Z n, Z k) {
    // k <= n  <=>  k < n+1  => le(n,k) = lt(n+1, k)
    // n+1 = sub(-1, n)  (porque sub(a,b) = b - a, así sub(-1,n) = n - (-1) = n+1)
    return lt(sub(-1, n), k);
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
    // r1 y r2 ahora se calculan solo con sub
    fprintf(stdout, "sub(sub(12, 65), 89) ==> %3d\n", sub(sub(12, 65), 89));
    fprintf(stdout, "sub(sub(25, 67), 42) ==> %3d\n", sub(sub(25, 67), 42));
}

void test03() {
    // A = 42 - 512  => sub(512, 42)
    Z A = sub(512, 42);

    // B = 67 - A    => sub(A, 67)
    Z B = sub(A, 67);

    // C = 512 - 1024 => sub(1024, 512)
    Z C = sub(1024, 512);

    // r = C - B     => sub(B, C)
    Z r = sub(B, C);

    fprintf(stdout, "test03 ==> %3d\n", r);
}

void test04() {
    // pruebas para chs
    fprintf(stdout, "chs(5)  ==> %3d\n", chs(5));   // -5
    fprintf(stdout, "chs(0)  ==> %3d\n", chs(0));   //  0
    fprintf(stdout, "chs(-3) ==> %3d\n", chs(-3));  //  3
}

void test05() {
    // pruebas para add (add(n,k) = k + n)
    fprintf(stdout, "add(3, 4)  ==> %3d\n", add(3, 4));   // 7
    fprintf(stdout, "add(0, 10) ==> %3d\n", add(0, 10));  // 10
    fprintf(stdout, "add(-2, 5) ==> %3d\n", add(-2, 5));  // 3
}

void test06() {
    // pruebas para le (k <= n)
    fprintf(stdout, "le(5, 5)  ==> %3d\n", le(5, 5));   // 1
    fprintf(stdout, "le(5, 4)  ==> %3d\n", le(5, 4));   // 1
    fprintf(stdout, "le(5, 4)  ==> %3d\n", le(5, 4));   // 1
    fprintf(stdout, "le(5, 6)  ==> %3d\n", le(5, 6));   // 0
    fprintf(stdout, "le(0, 0)  ==> %3d\n", le(0, 0));   // 1
}

// square
int square(int n) {
    // base: si n < 1 => retornamos 0 (esto cubre n == 0 y negativos)
    if (lt(1, n)) {
        return 0;
    }
    // m = n - 1
    Z m = sub(1, n);
    // sqm = square(m)
    Z sqm = square(m);
    // t = m + m
    Z t = add(m, m);
    // t2 = 2*m + 1
    Z t2 = add(1, t); // add(1, t) = t + 1
    // resultado = sqm + t2
    Z res = add(t2, sqm);
    return res;
}

void test07() {
    for (int i = 0; i < 9; ++i) {
        Z r1 = i * i;       // Broadway the easy way
        Z r2 = square(i);   // Broadway the hard way
        fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);
    }
}

int palindromo(int i) {
    Z n = i;

    // normalizar negativo: si n < 0 entonces n = -n
    if (lt(0, n)) {
        n = chs(n);
    }

    Z orig = n;
    Z rev  = 0;

    // bucle principal: mientras n != 0
    while (n != 0) {
        // calcular q = n / 10 y r = n % 10 usando restas repetidas
        Z q = 0;
        Z tmp = n;
        // while tmp >= 10  <=>  while lt(10, tmp) == 0
        while (lt(10, tmp) == 0) {
            tmp = sub(10, tmp);   // tmp = tmp - 10
            q = add(1, q);        // q = q + 1
        }
        Z r = tmp; // resto (0..9)

        // rev = rev * 10 + r
        // multiplicar rev * 10 por sumas repetidas (10 veces sumar rev).
        Z rev_times_10 = 0;
        for (int k = 0; k < 10; ++k) {
            rev_times_10 = add(rev, rev_times_10); // rev_times_10 += rev
        }
        rev = add(r, rev_times_10); // rev = rev*10 + r

        // avanzar: n = q
        n = q;
    }

    // comparar orig y rev: igualdad <=> (orig <= rev) && (rev <= orig)
    // usamos le(...) para cada dirección y combinamos con && de C++
    if (le(orig, rev) && le(rev, orig)) {
        return 1;
    } else {
        return 0;
    }
}

void test08() {
    int numeros[] = {121, 123, 454, 789, 1331, 12321, 1234321, 123456};
    for (int i = 0; i < 8; ++i) {
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
    test08();
    return 0;
}
