/**
 * @file main.cpp
 * @author Wojciech Bakun i Przemys³aw Dzier¿anowski
 * @date 20-01-2018
 *
 * @brief Plik glowny w ktorym uzywamy wszytkich klas.
 *
 *
 */

#include"Magazyn.h"
#include"Palety.h"
#include"Menu.h"
#include"Abstrakcyjna.h"

using namespace std;

int main(){
	Magazyn m;
	Palety p;
	Menu menu;
	Magazynn ma;
	Paletyy pa;
	Abstrakcyjna *wsk;
	wsk = &ma;

	string a = "Magazyn.txt", b = "Palety.txt",c="WolneMiejsca.txt";

	m.wczytanieMagazynu(a);
	p.wczytajPalety(b);

	menu.wyswietlMenu();
	char wybor1;
	cin >> wybor1;
	switch (wybor1){
	case '1':
	{
        system("cls");
		wsk = &ma;
		wsk->wyswietl(&m,&p);
	}
	break;
	case '2':
	{
		system("cls");
		wsk = &pa;
		wsk->wyswietl(&m, &p);
	}
	break;
	case '3':
	{
		system("cls");
		p.dodajPalete();
		p.zapisPalet(p,b);
	}
	break;
	case '4':
	{
		system("cls");
		m.wstawPalete(&p);
		m.zapiszMagazyn(m,a);
		p.zapisPalet(p, b);
	}
	break;
	case '5':
	{
		system("cls");
		m.usunPalete();
		m.zapiszMagazyn(m, a);
	}
	break;
	case '6':
        break;
	default:
		break;
	}
	m.wolneMiejsca(c);

	system("pause");
	return 0;
}
