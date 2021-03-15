#include <iostream>
#include "Film.h"

int main()
{
	Film f1;
	f1.printFilm();
	std::cout << std::endl;

	Film f2;
	f2.setFilmName("Once upon a time in Hollywood");
	f2.setDirectorName("Quentin Tarantino");
	f2.setRewards(13);
	f2.printFilm();

	return 0;
}