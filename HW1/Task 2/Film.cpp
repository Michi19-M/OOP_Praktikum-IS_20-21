#include "Film.h"

void Film::copy(const Film& other)
{
	filmName = new char[strlen(other.filmName) + 1];
	strcpy_s(filmName, strlen(other.filmName) + 1, other.filmName);
	directorName = new char[strlen(other.directorName) + 1];
	strcpy_s(directorName, strlen(other.directorName) + 1, other.directorName);
	rewards = other.rewards;
}

void Film::erase()
{
	delete[] filmName;
	delete[] directorName;
}

Film::Film()
{
	filmName = new char[1];
	filmName[0] = '\0';
	directorName = new char[1];
	directorName[0] = '\0';
	rewards = 0;
}

Film::Film(const Film& other)
{
	copy(other);
}

Film& Film::operator=(const Film& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

void Film::setFilmName(const char* other_filmName)
{
	delete[] filmName;
	filmName = new char[strlen(other_filmName) + 1];
	strcpy_s(filmName, strlen(other_filmName) + 1, other_filmName);
}

void Film::setDirectorName(const char* other_directorName)
{
	delete[] directorName;
	directorName = new char[strlen(other_directorName) + 1];
	strcpy_s(directorName, strlen(other_directorName) + 1, other_directorName);
}

void Film::setRewards(size_t other_rewards)
{
	rewards = other_rewards;
}

const char* Film::getFilmName() const
{
	return filmName;
}

const char* Film::getDirectoName() const
{
	return directorName;
}

size_t Film::getRewards() const
{
	return rewards;
}

void Film::printFilm() const
{
	std::cout << "Film name: " << filmName << std::endl;
	std::cout << "Director name: " << directorName << std::endl;
	std::cout << "Rewards: " << rewards << std::endl;
}

Film::~Film()
{
	erase();
}