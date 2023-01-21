using namespace std;
#include <iostream>
#include <fstream>
#pragma once

//S2:

//1d

void algoritm() {
	int n, x, m, p, cn, c;
	cin >> n;
	x = 0;
	m = 0;
	p = 1;
	while (x < 10) {
		cn = n;
		if (cn != 0) {
			do {
				c = cn % 10;
				cn = cn / 10;
				if (c == x) {
					m = c * p + m;
					p = p * 10;
				}
			} while (cn != 0);
		}
		x = x + 2;
	}
	cout << m;
}


/*2.Variabila m memorează simultan numărul de exponate dintr-un muzeu (număr natural din intervalul
[3, 102)) și date despre fiecare exponat(numele și colecția din care face parte, șiruri de cel mult 20 de
caractere).Expresiile C / C++ de mai jos au ca valori numărul de exponate, numele celui de al treilea
exponat, respectiv colecția din care face parte acesta.Scrieți definiția unei structuri cu eticheta muzeu,
care permite memorarea datelor despre un muzeu, și declarați corespunzător variabila m.
m.numar m.exponat[2].nume m.exponat[2].colectie*/

struct muzeu {
	int numar;
	string nume;
	string colectie;
};

//S3:

/*1. Subprogramul suma are un singur parametru, n, prin care primește un număr natural (n[1,106]).
Subprogramul returnează suma divizorilor pozitivi ai lui n care nu sunt primi.
Scrieți definiția completă a subprogramului.
Exemplu: pentru n = 12 subprogramul returnează 23 (23 = 1 + 4 + 6 + 12).*/

int suma(int n) {
	int s = 1;
	for (int div = 4; div <= n; div++) {
		if (n % div == 0) {
			s += div;
		}
	}
	return s;
}

/*2. O sală de spectacole are mai multe rânduri de scaune, toate rândurile având același număr de locuri. O
persoană poate rezerva mai multe locuri, dar cel mult câte unul pe un rând. Configurația sălii este
memorată ca un tablou bidimensional, în care prima coloană corespunde primului rând de scaune, iar
ultima coloană corespunde ultimului rând de scaune. Locurile libere sunt notate cu 0, iar cele rezervate
sunt notate cu numere naturale nenule, astfel încât toate locurile rezervate de o persoană sunt notate
cu același număr, iar cele rezervate de persoane distincte sunt notate cu numere distincte.
Scrieți un program C/C++ care citește de la tastatură numerele naturale din intervalul [2,20], m și n, apoi m∙n
numere naturale din intervalul [0,400], elemente ale tabloului bidimensional cu m linii și n coloane,
reprezentând configurația sălii. Programul verifică dacă există persoane care au rezervat locuri atât pe primul,
cât și pe ultimul rând al sălii, și afișează pe ecran numerele cu care sunt notate aceste locuri, ca în exemplu.
Numerele sunt afișate într-o ordine oarecare, separate prin câte un spațiu, iar dacă nu există
astfel de locuri se afișează pe ecran mesajul nu exista.
Exemplu: pentru m=5, n=4 și tabloul alăturat se afișează pe ecran, nu neapărat în această
ordine, numerele 6 8 

3 7 0 0
0 0 5 8
6 2 0 1
0 3 0 6
8 0 6 4

*/

void citireMatrice(int a[100][100], int& m, int& n) {
	ifstream f("matrice.txt");
	f >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			f >> a[i][j];
		}
	}
}

void locuriRezervate(int a[100][100], int m, int n) {
	bool rezervat = 0;
	for (int j = 0; j < m; j++) {
		if (a[j][0] != 0) {
			rezervat = 0;
			for (int i = 0; i < m && rezervat == 0; i++) {
				if (a[i][n-1] == a[j][0]) {
					rezervat = 1;
				}
			}
			if (rezervat == 1) {
				cout << a[j][0] << ' ';
			}
		}
	}
}

/*3. Două numere naturale sunt numite z-prietene dacă au aceeași cifră a zecilor.
Fișierul bac.in conține un șir de cel mult 106 numere naturale din intervalul[10, 109], separate prin
câte un spațiu.Se cere să se afișeze pe ecran pozițiile din șir pe care se află termeni precedați de un
număr maxim de valori z - prietene cu ei.Numerele afișate sunt separate prin câte un spațiu.Proiectați
un algoritm eficient din punctul de vedere al timpului de executare.
Exemplu: dacă fișierul conține numerele 726 358 98 157 20 49 128 879 659 271
pe ecran se afișează numerele 7 9 (termenii 128, respectiv 659 respectă proprietatea cerută).*/

int cifraZecilor(int n) {
	while (n > 100) {
		n /= 10;
	}
	return n % 10;
}

void solutie3() {
	int nr, ct = 0, fr[10]{}, poz[10]{};
	ifstream f("zPrietene.txt");
	while (f >> nr) {
		ct++;
		fr[cifraZecilor(nr)]++;
		poz[cifraZecilor(nr)] = ct;
	}
	int frecv = 0;
	for (int i = 0; i < 10; i++) {
		if (fr[i] > frecv) {
			frecv = fr[i];
		}
	}
	for (int i = 0; i < 10; i++) {
		if (fr[i] == frecv) {
			cout << poz[i] << ' ';
		}
	}
}

