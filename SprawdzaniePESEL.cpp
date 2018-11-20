#include<iostream>
#include <string>
#include <fstream>
using namespace std;

short PESEL[11];
int valid = 0;

int getBirthYear();		// zwraca rok urodzenia z numeru PESEL
int getBirthMonth();	// zwraca miesiąc urodzenia z numeru PESEL
int getBirthDay();		// zwraca dzień urodzenia z numeru PESEL
string getSex();		// zwraca płeć
int checkSum();			// sprawdza sumę kontrolną

void PeselValidator(string PESELNumber); //funkcja sprawdzajaca czy pesel jest poprawny

void main(void)
{
	string PESEL;
	PESEL = "44100249422";


	PeselValidator(PESEL);
	if (valid == 1) {
		cout << "Numer PESEL " << PESEL << " jest prawidlowy\n" << endl;;
		cout << "Rok urodzenia: \t\t" << getBirthYear() << endl;
		cout << "Miesiac urodzenia: \t" << getBirthMonth() << endl;
		cout << "Dzien urodzenia: \t" << getBirthDay() << endl;
		cout << "Plec : \t\t\t" << getSex() << endl;
		cout << "=========================================" << endl << endl;
	}
	else {
		cout << "Numer PESEL " << PESEL << " jest nieprawidlowy" << endl;
		cout << "=========================================" << endl << endl;
	}






	ifstream plik_wejsciowy; //utworzenie obiektu klasy ifstream
	plik_wejsciowy.open("NumeryPESEL.txt"); //skojarzenie obiektu plik_wejsciowy z plikiem




	if (!plik_wejsciowy.is_open())		  //sprawdzenie czy plik został otwarty
		return;

	string linia;
	while (!plik_wejsciowy.eof())
	{
		getline(plik_wejsciowy, linia);
		cout << linia << endl;

	}
	plik_wejsciowy.close();
	system("pause");
	return;
}







int getBirthYear() {
	//funkcja ma zwrócić rok urodzenia wynikający z numeru PESEL
	//dwie pierwsze cyfry to rok urodzenia%100
	//do miesiąca urodzenia została dodana liczba w zależności od roku urodzenia:
	//	dla lat 1800 - 1899 - 80
	//	dla lat 1900 - 1999 - 0
	//	dla lat 2000 - 2099 - 20
	//	dla lat 2100 - 2199 - 40
	//	dla lat 2200 - 2299 - 60
	// należy pobrać rok urodzenia (jego wartość dziesiętną i jedności) i następnie na podstawie warrości liczby oznaczających miesiące ustalić które to setlecie.
/*

tutaj wstaw swój kod

*/

}

int getBirthMonth() {
	// funkcja ma zwrócić numer miesiąca urodzenia wynikający z numeru PESEL 
	//w zależności od przedziału, w którym jest liczba, należy od niej odjąć odpowiednią wartość

/*

tutaj wstaw swój kod

*/

}

int getBirthDay() {
	// funkcja ma zwrócić numer dnia urodzenia wynikający z numeru PESEL 
	//należy pobrać odpowiednie wartości z numeru pesel i potraktować je jako dziesiatki i jedności


	/*

tutaj wstaw swój kod

*/


}

string getSex() {
	// 1 oznacza mężczyznę, 0 oznacza kobietę
/*

tutaj wstaw swój kod

*/
}

int checkSum() {
	//dodajemy do siebie kolejne pozycje nr pesel pomnożone przez wagi
	// 1 3 7 9 1 3 7 9 1 3
	// następnie uzyskujemy resztę z dzielenia przez 10
	// następnie tę resztę odejmujemy od 10
	// z uzyskanej różnicy liczymy resztę z dzielenia przez 10
	// jeżeli uzyskana liczba jest równa 11 cyfrze numeru pesel, weryfikacja przebiegła 
	// pomyślnie to funkcja zwraca 1,			w przeciwnym wypadku 0


}





void PeselValidator(string PESELNumber) {
	int i;

	if (int(PESELNumber.length()) != int(11)) {
		valid = 0;
	}
	else {
		for (i = 0; i < 11; i++) {
			PESEL[i] = PESELNumber[i] - 48;
		}
		if (checkSum()) {
			valid = 1;
		}
		else {
			valid = 0;
		}
	}
}
