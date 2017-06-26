
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Prisoner.h"
#include "Knowledge.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//Knowledge::nameFile();
  Prisoner pi ;

  // Wyrok kary wieznia
	int years_of_sentence = 20;
  int years = 2017;

	printf("Prograam sumuluje ucieczke z wiezenia :\n\n");
	printf("Nasz bohater zosta skazany na %d lat\n", years_of_sentence);

	// Petla wyznaczajaca kolejny dzien
	do
	{

		int time = Knowledge::currentTime();
		char timestamp[128];
		sprintf(timestamp, "[%02i/%02i/%04i]",
			time % MONTH + 1,
			(time / MONTH) % 12 + 1,
			(time / YEAR + 1 ) + years);

			//WYWOLANIE NASZEGO WIEZNIA
			pi.stealKey();
			pi.digTunnel();

			// RAPORT Z DNIA
			//printf( "%s DZIENNIK WIEZIENNY\n\n", timestamp );
			//pi.showAdvance();

			// Zacznijmy nowy dzień
			if (pi.isAlive() == true) Knowledge::tick();
			else
			{
				printf("  %s  Nasz bohater nie zyje...\n\n", timestamp);
				break;
			}

      if(pi.checkStatus() == 1)
      {

        printf("Garść statystyk:\n");
        printf("- Data ucieczki -  %s\n", timestamp);
        printf("- Ile lat mu zajela ucieczka -  %d\n", Knowledge::checkAge());
        //printf("- Ile zajelo mu zdobycie klucza - %d , )
        printf("- Srednia dlugosc dzienna kopania tunelu -  %lld [ m ]\n",  pi.currentlength() / Knowledge::currentTime());
        break;

      }
      Knowledge::newYear();

	}
	while ( Knowledge::checkAge() < years_of_sentence);



	return 0;
}
