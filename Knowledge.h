#pragma once

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

#include "Prisoner.h"
// Stale mowioce o dacie

#define YEAR 360
#define MONTH 30
#define DAY 1

// Klasa Wiezienia



class Knowledge{

private:
  //static std::vector <string> names ;
  //Zmienna przechowujaca nam czas
	static long long int _currentTime;
  //Zmienna przechowujaca lata odsiatki
  static int _currentAge ;


public:
  static void nameFile();
  static void tick() { _currentTime++; }

//  Genatory

  //static string name();
  // Generuje imie Wieznia
  static float chanceToFailure(  );
  // Funkcja dodajac kolejny dzien
//  static void tick() { _currentTime++; }
  //	Funkcja zwracajaca czas w wiezieniu
  static float chanceToDie();

  //	Akcesory
  static long long int currentTime() { return _currentTime; }
  //Zmiena zwracajaca rok odsiatki
  static int checkAge() { return _currentAge;  }
	//Funkcja dodaje rok
  static void newYear();



};
