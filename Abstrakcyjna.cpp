/**
 * @file Abstrakcyjna.cpp
 * @author Wojciech Bakun i Przemys³aw Dzier¿anowski
 * @date 20-01-2018
 *
 * @brief Plik zrodlowy dla klasy Magazyn
 *
 * Ten plik zawiera opisy metod dla klasy Magazyn. Zawarte sa w nim menu wyswietlane podczas generowania raportu, oraz nieulokowane palety.
 */

#include "Abstrakcyjna.h"

using namespace std;

void Magazynn::wyswietl(Magazyn *x,Palety *y){
    cout<<"============================================"<<endl;
    cout<<"============ Generowanie raportu ==========="<<endl;
    cout<<"============================================"<<endl<<endl;

	for (int i = 0; i < x->ilosc(); i++){
		cout << "Rzad: " << x->magazyn[i].wiersz << ", kolumna: " << x->magazyn[i].kolumna << ", numer palety: " << x->magazyn[i].id << " o zawartosci: " << x->magazyn[i].zawartosc << endl;
	}
    cout<<endl<<"============================================"<<endl;
}

void Paletyy::wyswietl(Magazyn *x, Palety *y){
	cout<<"============================================"<<endl;
    cout<<"==========  Nieulokowane palety  ==========="<<endl;
    cout<<"============================================"<<endl<<endl;
	for (int i = 0; i<y->ilosc(); i++){
		cout << i+1 << ". " <<"Numer palety: " <<y->palety[i].id << ", zawartosc: " << y->palety[i].zawartosc << endl;
	}
	cout<<endl<<"============================================"<<endl;
}
