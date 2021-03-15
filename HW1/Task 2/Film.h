#pragma once
#include <iostream>

class Film
{
private:
	char* filmName;
	char* directorName;
	size_t rewards;

	void copy(const Film& other);
	void erase();
public:
	Film();
	Film(const Film& other);
	Film& operator=(const Film& other);

	void setFilmName(const char* other_filmName);
	void setDirectorName(const char* other_directorName);
	void setRewards(size_t other_rewards);

	const char* getFilmName() const;
	const char* getDirectoName() const;
	size_t getRewards() const;

	void printFilm() const;

	~Film();
};