using namespace std;
#include <iostream>
#include <fstream>
#pragma once


//S2:

/*2. Variabila c memorează simultan următoarele date despre o carte dintr-o bibliotecă: titlul (un șir de
maximum 50 de caractere), numele autorului/autorilor și numărul de exemplare (maximum 102); o carte
poate avea cel mult 10 autori, fiecare având un nume de maximum 50 de caractere. Știind că expresiile
C/C++ de mai jos au ca valori două șiruri de caractere, reprezentând titlul, respectiv numele primului
autor al cărții, și un număr natural reprezentând numărul de exemplare ale acestei cărți, scrieți definiția
unei structuri cu eticheta carte, care permite memorarea datelor despre o carte, și declarați
corespunzător variabila c.*/

struct carte {
	string titlu;
	char autor[10];
	int nrExemplare;
};

//S3:

/*1. Subprogramul identice are un singur parametru, n, prin care primește un număr natural (n[10,109]).
Subprogramul returnează valoarea 1, dacă numărul n are toate cifrele egale, sau valoarea 0 în caz contrar.
Scrieți definiția completă a subprogramului.
Exemplu: dacă n=2222, subprogramul returnează valoarea 1, iar dacă n=212, subprogramul
returnează valoarea 0.*/

bool identice(int n) {
	while (n > 100) {
		if (n % 10 != (n / 10) % 10) {
			return 0;
		}
		n /= 10;
	}
	return 1;
}

/*2. Scrieţi un program C/C++ care citeşte de la tastatură două numere naturale din intervalul [2,102], m și n, şi
construieşte în memorie un tablou bidimensional cu m linii şi n coloane, numerotate începând cu 1, astfel
încât elementul de pe linia i şi coloana j primeşte ca valoare ultima cifră a produsului ij.
Programul afişează pe ecran elementele tabloului obținut, linie cu linie, fiecare linie a tabloului
pe câte o linie a ecranului, cu valorile aflate pe aceeaşi linie separate prin câte un spaţiu.
Exemplu: dacă m=4 și n=5 se afişează pe ecran tabloul alăturat.

1 2 3 4 5
2 4 6 8 0
3 6 9 2 5
4 8 2 6 0
*/


void generareMatice(int a[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = (i * j) % 10;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

/*3. Fişierul bac.txt conține numere naturale din intervalul [2,106]: pe prima linie n, iar pe a doua linie
un șir de n numere, separate prin câte un spațiu.
Se cere să se afișeze pe ecran, pentru fiecare număr natural i (i[1,n]), cea mai mare dintre primele
i valori ale șirului aflat în fișier. Numerele afișate sunt separate prin câte un spațiu. Proiectați un
algoritm eficient din punctul de vedere al memoriei utilizate şi al timpului de executare.*/

void citireVector(int v[], int& d) {
	ifstream f("vector.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
}

int maxim(int v[], int d) {
	int max = 0;
	for (int i = 0; i <= d; i++) {
		if (max < v[i]) {
			max = v[i];
		}
	}
	return max;
}

void afisareMax(int v[], int dim) {
	for (int i = 0; i < dim; i++) {
		cout << maxim(v, i) << ' ';
	}
}

