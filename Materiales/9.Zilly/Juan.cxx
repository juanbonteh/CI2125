///
/// Zilly in C++
///
/// A partial emulation of Zilly in C++, with sample usage
///

#include <cstdio>
#include <cstdlib>

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

// Change sign | Cambio de signo (negativo <=> positivo) es decir .. negaci�n

Z chs(Z n) {

    return sub(n, 0);

}

// Add | Suma
Z add(Z n, Z k) {

    return sub(chs(n), k);

}

Z no(Z p){

	if(p){

		return 0;

	} else {

		return 1;

	}

}

Z eq(Z n, Z k){

	if(sub(n, k) == 0){

		return 1;

	} else {

		return 0;

	}

}

Z z_or(Z p, Z q){//Definici�n de "or" en Zilly

	if(eq(p, 1)){

		return 1;

	} else if(eq(q, 1)){

		return 1;

	} else {

		return 0;

	}

}

// Less or equal to | Menor o igual a
Z le(Z n, Z k) {

    if(z_or(eq(n, k), lt(n, k))){

    	return 1;

    } else {

    	return 0;

    }

}

Z ne(Z p, Z q){

	return no(eq(p, q));

}

Z gt(Z n, Z k){

	return no(lt(n, k));

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
    Z r2 = sub(sub(25, 67), 42); // traducci�n de la expresi�n arriba, usando solo las primitivas de Zilly

    fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);
}

void test03() {
    Z r1 = 1024 - 512 - (67 - (42 - 512));
    Z r2 = sub(sub(sub(512, 42), 67), sub(512, 1024)); // <== @@@ TAREA: traducir la expresi�n arriba a la equivalente usando solo las primitivas de Zilly

    fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);
}

void test04() {

	Z r1 = 93;
	Z r2 = chs(93);
	fprintf(stdout, "r1 = %3d\n", r1);
	fprintf(stdout, "chs(r1) = %3d\n", r2);

}

void test05() {

	fprintf(stdout, "add( 0, 23) ==> %3d\n", add( 0, 23));
	fprintf(stdout, "add(23,  0) ==> %3d\n", add(23,  0));
	fprintf(stdout, "add( 0, 32) ==> %3d\n", add( 0, 32));
	fprintf(stdout, "add(32,  0) ==> %3d\n", add(32,  0));
	fprintf(stdout, "add(23, 32) ==> %3d\n", add(23, 32));
	fprintf(stdout, "add(32, 23) ==> %3d\n", add(32, 23));

}

void test06() {

    fprintf(stdout, "le(0, -1) ==> %3d\n", le(0, -1));
    fprintf(stdout, "le(0,  0) ==> %3d\n", le(0,  0));
    fprintf(stdout, "le(0,  1) ==> %3d\n", le(0,  1));

}

int square(int n) {

	if(eq(n, 0)){//Caso cero: 0 elevado al cuadrado es 0

		return 0;

	} else {

		//n^2 = (n - 1)^2 + 2n - 1
		//int s = add(square(n - 1), sub(1, add(n, n)));
		Z s = sub(sub(sub(1, sub(sub(n, 0), n)), 0), square(sub(1, n)));

		return s;

	}

    // <== @@@ TAREA: implemente esta funci�n, que computa el cuadrado de n (positivo)
    // Pero deben hacerlo tan solo con primitivas de Zilly
    // Y pueden hacerlo con recursi�n .. �sumando numeros impares!
    // Ayudas: a) sumen de mayor a menor; b) consigan la relacion de square(n) con square(n-1)
    // Tip: implem�ntela primero en C++, usando suma y recursi�n .. �con expresi�n condicional, obviamente!
    // Despu�s de conseguir la f�rmula recursiva m�gica, comp�tenla a las primitivas de Zilly:
    // solo se vale usar sub, lt (opcional), y recursion .. bien fundada con condicional.
	// λλλ Reemplazar el 0 por el λλλ chorizo λλλ m�gico
}

void test07() {

    for (int i = 0; i < 9; ++i) {

        Z r1 = i * i;       // Broadway the easy way
        Z r2 = square(i);   // Broadway the hard way
        fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);

    }
}

Z mult(Z n, Z m){ //Dados dos enteros positivos, realiza la multiplicaci�n de ambos

	if(z_or(eq(n, 0), eq(m, 0))){//Factor cero, todo n�mero por cero es 0

		return 0;

	} else if(eq(n, 1)){ //Elemento neutro multiplicativo, o identidad multiplicativa

		return m;

	} else if(eq(m, 1)){

		return n;

	} else {
		//m + m*(n-1)
		Z s = add(m, mult(m, sub(1, n)));
		return s;

	}

}

Z division(Z a, Z b){ //Dados dos enteros positivos, realiza el cociente entre ambos
	//b > 0
	if(eq(b, 0)){//Divisi�n por cero da error

		return EXIT_FAILURE;

	} else if(eq(a, 0)){//Si el numerador es cero, entonces el resultado es 0

		return 0;

	} else if(lt(b, a)){//Si a < b, enotnces el resultado es 0

		return 0;

	} else {
		//1+(a-b)/b
		Z q = add(1, division(sub(b, a), b));
		return q;

	}

}

Z resto(Z a, Z b){//Dados dos enteros positivos, expresa el resto del cociente

	if(eq(b, 0)){//Divisi�n por cero da error

		return EXIT_FAILURE;

	} else if(eq(a, 0)){//Si el numerador es cero, el resto es 0.

		return 0;

	} else {

		Z q = division(a, b);
		Z r = sub(mult(q, b), a); //r = a - q*b

		return r;

	}

}

Z reversor(Z n, Z j) {//Funci�n que invierte los d�gitos de un n�mero positivo

    if (gt(n, 0)) {//Si n > 0, da error

    	return j;

    } else {//Algoritmo de la inversi�n

        Z r = resto(n, 10);

        return reversor(division(n, 10), add(mult(10, j), r));
    }
}

Z reverse(Z n) {//Funci�n auxiliar que garantiza la ejecuci�n limpia de "reversor", con k = 0.

    return reversor(n, 0);

}

int palindromo(int i){

	return eq(reverse(i), i);

  // @@@ TAREA: implemente esta funci�n, que determina si un n�mero es pal�ndromo
  // Debe hacerlo tan solo con primitivas de Zilly
  // Puede definir cualquier funci�n auxiliar que necesite (las cuales dependan de las primitivas de zilly)
  // Y pueden hacerlo con recursi�n.
  // Retorna 1 si lo es
  // Retorna 0 si en caso contrario.
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
    test08();

    return 0;
}
