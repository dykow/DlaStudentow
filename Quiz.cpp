

#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

const int pytan_w_pliku = 30;
const int ile_pytan = 10;
int punkty = 0;
string nik;
string odpowiedz;

struct pytanie {
	string tresc;
	string odpA, odpB, odpC, odpD;
	string poprawna;
};

pytanie wszystkie_pytania[pytan_w_pliku];
pytanie zestaw_pytan[ile_pytan];


void wylosuj(int ile, int tablica[]);
bool czyBylaWylosowana(int iLiczba, int tab[], int ile);


int wczytaj_pytania();
int zadaj_pytania();
void zapisz_wynik();


int main()
{
	int zestaw_pytan_num[10];


	wylosuj(ile_pytan, zestaw_pytan_num);


	cout << "Wylosowano nastepujace pytania";
	for (int i = 0; i < ile_pytan; i++)
		cout << zestaw_pytan_num[i] << endl;

	if (wczytaj_pytania()==0);
	{
		cout << "Nastapil blad dzialania programu";
		return 0;
	}


	for (int i = 0; i < ile_pytan; i++)
		zestaw_pytan[i] = wszystkie_pytania[zestaw_pytan_num[i]];


	punkty=zadaj_pytania();
	cout << "Koniec quizu. Zdobyte punkty: " << punkty;


	zapisz_wynik();


	return 0;
}


// ta funkcja ma wczytać z pliku Pytania.txt pytania do zadania uzytkownikowi, pytanie składa się z 6 kolejnych linijek
// linijka 1- Tresc pytania
// linijka 2-5 kolejne odpowiedzi A,B,C,D
// linijka 6 - prawidlowa odpowiedz

int wczytaj_pytania() {};




// ta funkcja ma zadać użytkownikowi 10 losowych pytań z pośród wszystkich wczytanych pytań
int zadaj_pytania() {};

// ta funkcja na koniec dzialania programu, o ile zostal przeprowadzony quiz, zapytać użytkownika o nick i utworzyć plik o nazwie
// nik.txt z usyskanym wynikiem
void zapisz_wynik() {};

bool czyBylaWylosowana(int iLiczba, int tab[], int ile)
{
	if (ile <= 0)
		return false;

	int i = 0;
	do
	{
		if (tab[i] == iLiczba)
			return true;

		i++;
	} while (i < ile);

	return false;
}

void wylosuj(int ile, int tablica[])
{
	int wylosowane[wszystkich_pytan];
	int wylosowanych = 0;
	do
	{
		int liczba = rand() % wszystkich_pytan + 1;
		if (czyBylaWylosowana(liczba, wylosowane, wylosowanych) == false)
		{
			wylosowane[wylosowanych] = liczba;
			wylosowanych++;
		}

	} while (wylosowanych < ile);

	for (int i = 0; i < ile; i++)
		tablica[i] = wylosowane[i];


}

