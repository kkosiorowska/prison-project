#include "Prisoner.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>


long long int Prisoner::lengthTunnel = 0;


Prisoner::Prisoner()
{
   // Generowanie imienia
	// _name = Knowledge::name();


   // Przyznajemy cechy
	 _determination = rand() % 10  + 1;
	 _force = rand() % 10  + 1;

	// Zerujemy
	 _isKey = false;
	 _isTunnel = false;
   _isFree = false;
	 lengthTunnel = 0;
	 _isAlive =true  ;

	 srand(time(NULL));

}

void Prisoner::stealKey()
{
	// Jezeli los usmiechnie sie to wieznia
	//i przyjmie taka sama wartosc jak zmienna steal
	// zadanie zostanie wykonanne
	int steal = rand() % 1100 + 1;
	int fate = rand() % 1100 + 1 ;

 // Zwroci wartosc true
	if(steal==fate) _isKey = true ;
	else _isKey = false ;


}

bool Prisoner::checkStatus()
{
	// Funkcja sprawdza czy zadania zostaly wykonanne
	// i daje wynik o statusie ucieczki
	if( isKey() ==true && isTunnel() == true ){
		_isFree = true  ;
		return true  ; // Mozna uciekac
	}
	else{
		_isFree = false ;
		  return false ;
	}                                 // Zadania nie zostaly wykonane

}

bool Prisoner::isKey()
{
	return _isKey ;

}
bool Prisoner::isAlive()
{
	return _isAlive ;

}

bool Prisoner::isTunnel()
{
	long long int l = currentlength();

	// Sprawdza czy wykopany tunnel ma odpowiednia dlugosc
	if( l >= 10000) return true;
	else return false ;

}

void Prisoner::showAdvance ()
{
	 long long int l = currentlength() ;

	if( _isFree == true ){

			printf("Wszystkie warunki zostay spenione !!! UCIECZKA\n");

	}
	else{

		if(isTunnel() == false) printf("Dlugosc tunelu wynosi : %lld \n" , l);
		else printf("Dlugosc tunelu jest wystarczajaca .\n");

		printf("Zdobycie klucza :  ");

		if(isKey()==true) printf("tak\n") ;
		else printf("nie\n");


	}
}


//////////////////////////////////
void Prisoner::digTunnel ( )
{
	//printf("Kopanie Tunelu :\n");
	//static long long int l = currentlength () ;

	if( isTunnel() == false)
	{

		// Wyliczamy iloczyn sily
		float factor = _determination * _force ;
		float badLuck = 0 ;

		do{

			// Wyliczamy ilocyzn pecha i sytuacji wiezenia czy ma szanse na powodzenie akcji
			 badLuck = 0 ;
			 badLuck =  ( rand()% 100 + 1 );// * Knowledge::chanceToFailure( );


			if( badLuck > 80 ) break ; // Przypadek uniemozliwiajacy kopanie

      int x =  ( rand()% 10 + 1 );
			lengthTunnel += _determination * x ;


		}while( factor > badLuck);


	}
}

void Prisoner::die()
{
	_isAlive = false;
}
bool Prisoner::willDie()
{
	float chanceToDie = Knowledge::chanceToDie();
	float fate = (rand() % 1000000) / 1000000.;
	return !_isAlive || fate < chanceToDie;
}
