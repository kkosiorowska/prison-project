#include "Knowledge.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>

int Knowledge::_currentAge = 0 ;
long long int Knowledge:: _currentTime = 0;

using namespace std;
/*
vector <string> Knowledge::names ;
long long int Knowledge::_currentTime = 0;

void Knowledge::nameFile()
{

	srand(time(NULL));
	ifstream file;

	// Imiona
	file.open("data/names_men.csv");
	copy(istream_iterator<string>(file),
         istream_iterator<string>(),
         back_inserter(names));
	file.close();

}
/*
string Knowledge::name()
{
	printf("imie %s ", names[rand() % names.size()]); /// WTFFFFFFFFFFFFFFFFFFFFFFF
	return names[rand() % names.size()];
}*/


float Knowledge::chanceToFailure( )
{
	long long int time = currentTime();

	if(time %10==0) 		return .002;
	else				return .002;
}

void Knowledge::newYear()
	{
		// Obliczanie roku odsiadki
		long long int t = currentTime();
			_currentAge = (t / YEAR + 1);

	}

	float Knowledge::chanceToDie()
	{
		int age = currentTime();
		if(age < 5) 		return .002;
		else if(age < 10)	return .0002;
		else if(age < 15)	return .00002;
		else if(age < 20)	return .0002;
		else				return .002;
	}
