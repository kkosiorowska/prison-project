#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "Knowledge.h"

using namespace std;


//Klasa Wieznia

class Prisoner{

private:
	// Dane
	//string _name;
	float _determination;             // determinacja do wykonywania zadan
	float _force;                    // stopien sily zeby przeplynac ocean
	static long long int lengthTunnel;             // dlugosc wykopanego tunelu

	//Zmienne potrzebne do ucieszki
	bool _isKey;                 // zmienna okreslająca czy wiezien zdobyl klucz do ucieczki
	bool _isTunnel;             // zmienna okresalajaca czy wiezien wykopal tunel do ucieczki
	bool _isFree;              // zmienna pokazujaca czy udalo sie uciec
  bool _isAlive ;



public:
//	Metody klasy /////////////////////UWGAAAAA
	//static vector <Prisoner> createPrisoner(int n); // stworzenie Wieznia

// Metody obiektu

Prisoner ();
// Konstruktor
void digTunnel();
// Funkcja majaca zadanie wykopac tunnel
void stealKey();
// Funkcja majaca na zadnaiu ukrasc klucz
int workout(int day );
// Funkcja zwiekszajaca sile fizyczna
bool willDie();
// Funkcja odpowiadajaca za jego zycie
void die();
// Funkcja odbierajaca zycie
//static
long long int currentlength() { return lengthTunnel; }



// Metody opisujce

void showAdvance ( );
// Funkcja wyswietlajaca postepy wykonania akcji przez wieznia i reakcji wiezenia
bool isKey( );
// Funkacja zwracajaca informacje o sukcesie spelnienia warunku
bool isTunnel(  );
// Funkacja zwracajaca informacje o sukcesie spelnienia warunku
bool checkStatus() ; 
// Sprawdzenie statusu ucieczki
bool isAlive( );
// Funkacja sprawdzajaca czy zyje


};
