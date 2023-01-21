using namespace std;
#include <iostream>
#include <fstream>
#pragma once


//S2:

/*2. Pentru un cerc se memorează date specifice: coordonatele reale (abscisa și ordonata), în sistemul de
coordonate xOy, ale centrului cercului, precum și lungimea diametrului acestuia. Știind că expresiile de
mai jos au ca valori numere reale reprezentând datele specifice ale unui cerc, scrieți definiția unei
structuri cu eticheta figura, care permite memorarea datelor specifice ale unui cerc, și declarați
corespunzător variabila c*/

struct Coordonate {
	int x; 
	int y;
};
struct figura {
	Coordonate x, y;
	int diametru;
};

//S3:

/*1. Subprogramul numar are trei parametri:
• n și c, prin care primește câte un număr natural (n[0,109], c[0,9]);
• m, prin care furnizează numărul obținut din n, prin eliminarea din acesta a tuturor cifrelor egale cu c, sau
-1 dacă toate cifrele lui n sunt egale cu c. Cifrele nule nesemnificative sunt ignorate, ca în exemplu.
Scrieți definiția completă a subprogramului.
Exemplu: dacă n=50752 sau n=72 și c=5, după apel m=72, dacă n=500 și c=5, după apel m=0, iar
dacă n=55 și c=5, după apel m=-1. */

int numar(int n, int c, int m) {
	m = 0;
	int p = 1;
	while (n) {
		if (n % 10 == c) {
			n /= 10;
		}
		else {
			m = m + (n % 10) * p;
			p *= 10;
			n /= 10;
		}
	}
	return m;
}

/*2. Scrieți un program C/C++ care citește de la tastatură un număr natural, n (n∈[3,20]), și construiește
în memorie un tablou bidimensional cu n linii și n coloane, având proprietățile:
• toate elementele situate pe diagonala secundară sunt nule;
• prima linie conține un șir strict descrescător de numere consecutive, iar ultima linie conține un șir strict
crescător de numere consecutive;
• fiecare dintre celelalte linii conține, începând cu prima poziție, până la diagonala secundară inclusiv, de la
stânga la dreapta, un șir strict descrescător de numere consecutive, iar începând de la diagonala secundară,
inclusiv, până la ultima poziție, de la stânga la dreapta, un șir strict crescător de numere consecutive.
Programul afișează pe ecran tabloul construit, fiecare linie a tabloului pe câte o linie a
ecranului, cu elementele aflate pe aceeași linie separate prin câte un spațiu.
Exemplu: dacă n=4 se afișează pe ecran tabloul alăturat. 

3 2 1 0
2 1 0 1
1 0 1 2
0 1 2 3
*/

void generareMatice(int a[100][100], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = n- abs(i - j)-1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}