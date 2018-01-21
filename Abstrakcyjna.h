/**
 * @file Abstrakcyjna.h
 * @author Wojciech Bakun i Przemys³aw Dzier¿anowski
 * @date 20-01-2018
 *
 * @brief Plik naglowkowy dla klasy Abstrakcyjna
 *
 *  Klasa Abstrakcyjna jest klasa abstrakcyjna i robi za interface, a klasy Magazynn i Paletyy po niej dziedzicza.
 */

#ifndef Abstrakcyjna_H
#define Abstrakcyjna_H
#include<iostream>
#include"Magazyn.h"
#include"Palety.h"

class Abstrakcyjna{	//bazowa klasa abstrakcyjna
public:
	virtual void wyswietl(Magazyn *x,Palety *y)=0; //funkcja wirtualna ktora nigdy nie bedzie uzyta gdyz zawsze bedzie nadpisana
};

class Magazynn :public Abstrakcyjna{ //klasa Magazynn dzieczaca funkcje abstrakcyjna po klasie Abstrakcja;
public:
    virtual void wyswietl(Magazyn *x, Palety *y); //funkcja wyswietlajaca magazyn wraz z ustawieniem palet
};
class Paletyy :public Abstrakcyjna{ //klasa Paletyy dzieczaca funkcje abstrakcyjna po klasie Abstrakcja;
public:
	virtual void wyswietl(Magazyn *x, Palety *y); //funkcja wyswietlajaca dostepne palety
};


#endif // !Abstrakcyjna_H




