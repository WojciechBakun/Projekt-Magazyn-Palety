/**
 * @file Menu.h
 * @author Wojciech Bakun i Przemys³aw Dzier¿anowski
 * @date 20-01-2018
 *
 * @brief Plik naglowkowy dla klasy Menu
 *
 *  Klasa Menu zawiera menu glowne programu.
 */

#ifndef Menu_h
#define Menu_h
#include<iostream>
class Menu{	//klasa zawierajaca funkcje menu;
public:
	void wyswietlMenu(){ //funkcja klasy menu wyswietlajaca menu
    std::cout<<"=============================================="<<std::endl;
    std::cout<<"=================== MENU ====================="<<std::endl;
    std::cout<<"=============================================="<<std::endl;
    std::cout<<"== 1. Generuj raport o stanie magazynowym   =="<<std::endl;
    std::cout<<"== 2. Wyswietl dostepne nieulokowane palety =="<<std::endl;
    std::cout<<"== 3. Dodaj palete do ulokowania            =="<<std::endl;
    std::cout<<"== 4. Ulokuj palete                         =="<<std::endl;
    std::cout<<"== 5. Usun palete z magazynu                =="<<std::endl;
    std::cout<<"== 6. Wyjscie                               =="<<std::endl;
    std::cout<<"=============================================="<<std::endl;
	}
};


#endif // Menu_h

