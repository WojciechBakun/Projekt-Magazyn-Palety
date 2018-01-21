/**
 * @file Palety.h
 * @author Wojciech Bakun i Przemys³aw Dzier¿anowski
 * @date 20-01-2018
 *
 * @brief Plik naglowkowy dla klasy Palety
 *
 *  Klasa Palety zawiera metody zwiazane z paletami. Potrafi ona dodac palete, zapisac je do pliku, wyswietlic nieuzywane palety i wczytac z pliku
 */

#ifndef Palety_h
#define Palety_h
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<Windows.h>

class Palety{ //klasa palety zawierajaca metody zwiazane z paletami;
public:
		std::string zawartosc, id;
		std::vector<Palety> palety;
		Palety(); //konstruktor obiektu do klasy Palety
		Palety(std::string _id, std::string _zawartosc); //konstruktor podstawiajacy wartosc do obiektu

		void dodajPalete();	//funkcja dodajaca palete do zbioru palet nie ustawionych w magazynie
		void zapisPalet(Palety& dane, std::string nazwaPliku); //funkcja zapisujaca nie uzywane palety do pliku
		void wyswietleniePalet(); //funkcja wyswietlajaca nie uzywane palety
		int ilosc(); //funkcja zwracajaca liczne calkowita ilosc palet nieustawionych w magazynie
		void wczytajPalety(std::string s); //funkcja wczytujaca palety z pliku i podstawiajaca pod vector
};

#endif // !Palety_h
