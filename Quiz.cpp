#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
// tutaj zmienne globalne, ktorych mozna uzywac w calym programie i w funkcjach
const int pytan_w_pliku = 30;
const int ile_pytan = 10;
int punkty = 0;
string nik;

// tutaj definicja nowego rodzaju 
struct pytanie {
	string tresc;
	string odp1, odp2, odp3, odp4;
	int poprawna;
};



// te funkcje są już przygotowane
void wylosuj(int ile, int tablica[]);
bool czyBylaWylosowana(int iLiczba, int tab[], int ile);
void wypisz_pytanie(pytanie p);


// te funkcje należy przygotować, opis na dole
bool wczytaj_pytania();
int zadaj_pytania();
void zapisz_wynik();


int main()
{
	pytanie wszystkie_pytania[pytan_w_pliku];
	pytanie zestaw_pytan[ile_pytan];
	int zestaw_pytan_num[10];
	srand(time(NULL));

	wylosuj(ile_pytan, zestaw_pytan_num);


	cout << "Wylosowano nastepujace pytania" << endl;
	for (int i = 0; i < ile_pytan; i++)
		cout << zestaw_pytan_num[i] << endl;
	cout << "Wypisano wylosowane pytania" << endl;

	cout << "Proba wczytania pytan" << endl;
	if (wczytaj_pytania())
	{
		cout << "Udało sie wczytac wszystkie pytania z pliku z pytaniami" << endl;

	}
	else
	{
		cout	<< "Nie udalo sie wczytac poprawnie pytan"		<< endl;
		cout	<< "Nastapi zakonczenie dzialania programu"		<< endl;
		system("pause");
		return 0;
	}

	/*
	tutaj umieścić kod, który przypisze wylosowane pytania spośród wylosowanych do zestawu pytań do zadania
	
	
	cout << "Udalo wybrac sie zestaw odpowiednich pytan" << endl;
	*/

	/* 
	// tutaj maja zostac zadane pytania i zliczone zdobyte punkty
	
	cout << "Koniec quizu. Zdobyte punkty: " << punkty;
	*/

	//zapisz_wynik();

	system("pause");
	return 0;
}


// ta funkcja ma wczytać z pliku Pytania.txt wszystkie pytania, z ktorych zostanie wylosowany zestaw
// pytan do zadania uzytkownikowi, pytanie składa się z 6 kolejnych linijek
// linijka 1- Tresc pytania
// linijka 2-5 kolejne odpowiedzi 1,2,3,4
// linijka 6 - prawidlowa odpowiedz 1,2,3 lub 4.
// funkcja przyjmuje dwa argumenty:
// tablicę pytan o rozmiarze n, który równy jest ilości wszystkich pytań w pliku z pytaniami oraz ilość tych pytań
// funkcja w wypadku poprawnego wczytania pytan zwraca prawdę, w przeciwnym wypadku fałsz
bool wczytaj_pytania()
{
	return true;
};




// ta funkcja ma zadać użytkownikowi pytania z wylosowanego zestawu pytań i zwrocić ilość uzyskanych w quizie punktów
int zadaj_pytania() {


	return 1;
};

// ta funkcja na koniec dzialania programu, o ile zostal przeprowadzony quiz, ma zapytać użytkownika o nick i utworzyć plik o nazwie
// nik.txt , w którym zapisze uzyskany wynik
void zapisz_wynik() {

};


// ta funkcja sprawdza, czy dana liczba została już wylosowana, jeżeli tak, zwraca prawdę, w przeciwnym wypadku fałsz
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


//	ta funkcja losuje zestaw M niepowtarzalnych liczb z zakresu 1-n (w tym wypadku to liczba wszystkich pytań w pliku) 
//	i zapisuje je do tablicy M elementowej danej jako parametr funkcji;
//	wykorzystywana jest funkcja czyBylaWylosowana()....

void wylosuj(int M, int tablica[])
{
	int wylosowane[ile_pytan];
	int wylosowanych = 0;
	do
	{
		int liczba = rand() % pytan_w_pliku + 1;
		if (czyBylaWylosowana(liczba, wylosowane, wylosowanych) == false)
		{
			wylosowane[wylosowanych] = liczba;
			wylosowanych++;
		}

	} while (wylosowanych < M);

	for (int i = 0; i < M; i++)
		tablica[i] = wylosowane[i];


}

void wypisz_pytanie(pytanie p) {
	cout << p.tresc << endl;
	cout << p.odp1 << endl;
	cout << p.odp2 << endl;
	cout << p.odp3 << endl;
	cout << p.odp4 << endl;
	cout << endl;
}
