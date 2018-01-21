/**
 * @file Magazyn.cpp
 * @author Wojciech Bakun i Przemys³aw Dzier¿anowski
 * @date 20-01-2018
 *
 * @brief Plik zrodlowy dla klasy Magazyn
 *
 * Ten plik zawiera opisy metod dla klasy Magazyn. Zawarte s¹ w nim menu lokowania nowych palet w magazynie i usuwania palet z magazynu.
 */

#include "Magazyn.h"
#include <fstream>
#include <sstream>

using namespace std;

Magazyn::Magazyn() {};

Magazyn::Magazyn(int _wiersz,int _kolumna, std::string _id, std::string _zawartosc){
	wiersz = _wiersz;
	kolumna = _kolumna;
	id = _id;
	zawartosc = _zawartosc;
}

int Magazyn::ilosc(){
	return magazyn.size();
}

void Magazyn::wczytanieMagazynu(string s){
	ifstream plik(s);
	string linie, zawartosc,id;
	int wiersz, kolumna;
	while (getline(plik, linie)){
		stringstream wczyt(linie);
		wczyt >> wiersz;
		wczyt.ignore();
		wczyt >> kolumna;
		wczyt.ignore();
		wczyt >> id;
		wczyt.ignore();
		wczyt >> zawartosc;
		wczyt.ignore();
		magazyn.push_back(Magazyn(wiersz, kolumna, id, zawartosc));
	}
	plik.close();
}

void Magazyn::wyswietlenieMagazynu(){
	for (int i = 0; i < ilosc(); i++){
		cout << "Rzad: "<< magazyn[i].wiersz << " | Kolumna: " << magazyn[i].kolumna << " | Numer palety: " << magazyn[i].id << " (Zawartosc: " << magazyn[i].zawartosc << ")" << endl;
	}
}

void Magazyn::zapiszMagazyn(Magazyn& dane, std::string nazwaPliku)
{
	ofstream zapis(nazwaPliku);
	for (int i = 0; i<ilosc(); i++){
		zapis << magazyn[i].wiersz << " " << magazyn[i].kolumna << " " << magazyn[i].id << " " << magazyn[i].zawartosc << endl;
	}
	zapis.close();
}

void Magazyn::wstawPalete(Palety *x){
	int wiersz, kolumna;
	cout<<"=========================================================="<<endl;
    cout<<"=================== Lokowanie palety ====================="<<endl;
    cout<<"=========================================================="<<endl;
    cout<<"== Dostepne miejsca:                                    =="<<endl;

	for (int j = 0; j < ilosc(); j++){
		if (magazyn[j].id == "-") cout << "Rzad: "<< magazyn[j].wiersz << ", kolumna: " << magazyn[j].kolumna << endl;
	}
	cout<<"=========================================================="<<endl;
	cout<<"== Podaj rzad i kolumne w ktorym chcesz ulokowac palete =="<<endl;
    cout<<"== (rzad od 1 do 5 kolumna od 1 do 2)                   =="<<endl;
    cout<<"=========================================================="<<endl;
	cin >> wiersz >> kolumna;
	for (int i = 0; i < ilosc(); i++){
		while (magazyn[i].wiersz == wiersz && magazyn[i].kolumna == kolumna && magazyn[i].id != "-"){
			cout << "Miejsce jest zajete podaj inne!" << endl;
			Sleep(1000);
			system("cls");
            cout<<"=========================================================="<<endl;
            cout<<"=================== Lokowanie palety ====================="<<endl;
            cout<<"=========================================================="<<endl;
            cout<<"== Dostepne miejsca:                                    =="<<endl;

			for (int j = 0; j < ilosc(); j++){
				if (magazyn[j].id == "-") cout << "Rzad: " << magazyn[j].wiersz << ", kolumna: " << magazyn[j].kolumna << endl;
			}
			cout<<"=========================================================="<<endl;
            cout<<"== Podaj rzad i kolumne w ktorym chcesz ulokowac palete =="<<endl;
            cout<<"== (rzad od 1 do 5 kolumna od 1 do 2)                   =="<<endl;
            cout<<"=========================================================="<<endl;
			cin >> wiersz >> kolumna;
		}
		if (magazyn[i].wiersz == wiersz && magazyn[i].kolumna == kolumna && magazyn[i].id == "-"){

			system("cls");
            cout<<"============================================"<<endl;
            cout<<"============ Lokowanie palety =============="<<endl;
            cout<<"============================================"<<endl;
            x->wyswietleniePalet();
            cout<<endl<<"============================================"<<endl;
            cout<<"== Podaj numer palety: ";
			string numer;
			cin >> numer;
			int sprawdzanie = 0;
			for (int j = 0; j < x->ilosc(); j++){
				if (numer == x->palety[j].id){
					magazyn[i].id = x->palety[j].id;
					magazyn[i].zawartosc = x->palety[j].zawartosc;
					x->palety.erase(x->palety.begin() + j);
					sprawdzanie++;
					break;
				}
			}
			if (sprawdzanie ==0){
					cout << "Nie ma takiego numeru!";
					Sleep(1000);
					exit(0);
            }
		}
	}
}

void Magazyn::wolneMiejsca(std::string s){
	ofstream zapis(s);
	for (int i = 0; i<ilosc(); i++){
		if(magazyn[i].id=="-")
		zapis << magazyn[i].wiersz << " " << magazyn[i].kolumna << endl;
	}
	zapis.close();
}

void Magazyn::usunPalete(){
	int wiersz, kolumna;
	cout<<"============================================"<<endl;
    cout<<"============= Usuwanie palety =============="<<endl;
    cout<<"============================================"<<endl;
    cout<<"== Zawartosc magazynu: "<<endl<<endl;
    wyswietlenieMagazynu();
    cout<<endl<<"============================================"<<endl;
    cout<<"== Podaj rzad i kolumne z ktorego chcesz usunac palete: ";
	cin >> wiersz >> kolumna;
	for (int i = 0; i < ilosc(); i++){

		while (magazyn[i].wiersz == wiersz && magazyn[i].kolumna == kolumna && magazyn[i].id == "-"){
			cout << "Jest juz wolne" << endl;
			Sleep(1000);
			system("cls");
			cout<<"============================================"<<endl;
            cout<<"============= Usuwanie palety =============="<<endl;
            cout<<"============================================"<<endl;
            cout<<"== Zawartosc magazynu: "<<endl<<endl;
			wyswietlenieMagazynu();
			cout<<endl<<"============================================"<<endl;
            cout<<"== Podaj rzad i kolumne z ktorego chcesz usunac palete: ";
			cin >> wiersz >> kolumna;
		}
		while (magazyn[i].wiersz == wiersz && magazyn[i].kolumna == kolumna && magazyn[i].id != "-"){
			magazyn[i].id = "-";
			magazyn[i].zawartosc = "-";
		}
	}
}
