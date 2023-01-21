using namespace std;
#include <iostream>
#include <fstream>
#pragma once

//S2:

/*2. Variabila p memorează simultan numărul de elevi dintr-o clasă (număr natural din intervalul [2,40]) și,
pentru fiecare elev al clasei, media de pe primul semestru precum și media de pe cel de-al doilea
semestru (numere reale cu cel mult două zecimale) la disciplina informatică. Știind că expresiile C/C++
de mai jos au ca valori numărul de elevi din clasă, respectiv mediile pe primul și pe al doilea semestru
pentru primul dintre elevii clasei, scrieți definiția unei structuri cu eticheta clasa, care permite
memorarea datelor despre elevii clasei, și declarați corespunzător variabila p.*/

struct semestre {
	int sem1;
	int sem2;
};

struct clasa {
	int numar;
	
};

//S3:

/*1. Subprogramul nrfp are doi parametri:
• n, prin care primește un număr natural (n[2,105]);
• m, prin care furnizează numărul din intervalul închis [2,n] care are cei mai mulți factori primi; dacă
există mai multe numere cu această proprietate, subprogramul îl returnează pe cel mai mare dintre ele.
Scrieți definiția completă a subprogramului.
Exemplu: dacă n=100 atunci, în urma apelului, m=90.*/

void nrfp(int n, int& m) {
	for (int i = n; i >= 2; i--) {

	}
}

/*3. Fișierul bac.txt conține un șir de cel mult 106 numere naturale din intervalul [0,109].
Se cere să se determine și să se afișeze pe ecran, separate printr-un spațiu, ultimele două numere
impare (nu neapărat distincte) din șirul aflat în fișier, sau mesajul nu exista, dacă nu există două
astfel de numere. Proiectați un algoritm eficient din punctul de vedere al memoriei utilizate și al timpului
de executare.
Exemplu: dacă fișierul conține valorile 122 1635 628 1413 1647 900 3001 4252
se afișează pe ecran 1647 3001*/

void solutie3() {
	ifstream f("nr.txt");
	int nr, imp1 = -1, imp2 = -1;
	while (f >> nr) {
		if (nr % 2 == 1) {
			imp1 = imp2;
			imp2 = nr;
		}
	}
	if (imp1 == -1 || imp2 == -1) {
		cout << "nu exista";
	}
	else {
		cout << imp1 << ' ' << imp2;
	}
}