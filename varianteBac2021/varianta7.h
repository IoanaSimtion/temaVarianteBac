using namespace std;
#include <iostream>
#include <fstream>
#pragma once

//S3:

/*1. Subprogramul afisare are trei parametri:
• x și y, prin care primește câte un număr natural din intervalul [0,106] (xy);
• k, prin care primește un număr natural (k[2,102]).
Subprogramul afișează pe ecran, în ordine strict crescătoare, numerele din intervalul [x,y], în secvențe de
câte k, cu excepția ultimei secvențe care poate conține mai puțin de k numere. Fiecare secvență se încheie
cu câte un simbol *, iar numerele și simbolurile sunt separate prin câte un spațiu, ca în exemplu.
Scrieți definiția completă a subprogramului.
Exemplu: dacă x=11, y=21 și k=4 se afișează pe ecran numerele de mai jos, în acest format.
11 12 13 14 * 15 16 17 18 * 19 20 21 *
*/

void afisare(int x, int y, int k) {
	int ct = 0;
	for (int i = x; i <= y; i++) {
		cout << i << ' ';
		ct++;
		if (ct == k) {
			cout << '*' << ' ';
			ct = 0;
		}
	}
	cout << '*';
}

/*2. Scrieți un program C/C++ care citește de la tastatură un număr natural, x (x[1,109]), și construiește în
memorie un tablou bidimensional, pentru care atât numărul de linii, cât și numărul de coloane sunt egale
cu numărul de cifre ale lui x, iar elementele fiecărei linii au ca valori cifrele lui x, în ordine, ca în exemplu.
Elementele tabloului obținut sunt afișate pe ecran, linie cu linie, fiecare linie a tabloului pe
câte o linie a ecranului, cu elementele de pe aceeași linie separate prin câte un spațiu.
Exemplu: dacă x=1359, se afișează tabloul alăturat. 

1 3 5 9
1 3 5 9
1 3 5 9
1 3 5 9
*/

int nrCifre(int n) {
	int ct = 0;
	while (n) {
		n /= 10;
		ct++;
	}
	return ct;
}

void generareMatrice(int x, int a[100][100]) {
	int n = nrCifre(x);
	for (int i = n; i >= 0; i--) {
		for (int j = n; j >= 0; j--) {
			a[i][j] = x % 10;
		}
		x /= 10;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; i++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

}

/*3. Fișierul bac.txt conține cel mult 106 cifre, separate prin câte un spațiu.
Se cere să se afișeze pe ecran, separate prin câte un spațiu, toate cifrele pare care apar în fișier sau
mesajul nu exista, dacă nu există astfel de cifre. Proiectați un algoritm eficient din punctul de vedere
al timpului de executare.
Exemplu: dacă fișierul conține cifrele 3 3 0 8 2 1 2 1 3 7 1 5 2 7 1 0 3 2 3
pe ecran se afișează, de exemplu în ordine crescătoare, cifrele 0 0 2 2 2 2 8*/

