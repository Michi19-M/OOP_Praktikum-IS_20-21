#pragma once
#include<fstream>
#include "Deck.h"

template <typename T, typename S, typename M, typename N>
class Player
{
public:
	Player();
	Player(const char* name, size_t other_wins, size_t other_losses,const Deck<T>& other_fD,const Deck<S>& other_sD);

	void setPlayer(const Player<T, S, M, N>& other);
	void setPlayerName(const char* name);
	void setWins(size_t other_wins);
	void setLosses(size_t other_losses);
	void setFirstDeck(const Deck<T>& deck);
	void setSecondDeck(const Deck<S>& deck);
	void printPlayer() const;

	Deck<T> getFirstDeck() const;
	Deck<S> getSecondDeck() const;

	size_t getWins() const;
	size_t getLosses() const;

	size_t operator++();
	size_t operator--();

	void drawCard();

	void savePlayer(const char* filename);
	void loadPlayer(const char* filename);
private:
	String playerName;
	size_t wins;
	size_t losses;
	Deck<T> firstDeck;
	Deck<S> secondDeck;
};

template<typename T, typename S, typename M, typename N>
inline Player<T, S, M, N>::Player()
{
	wins = 0;
	losses = 0;
}

template<typename T, typename S, typename M, typename N>
inline Player<T, S, M, N>::Player(const char* name, size_t other_wins, size_t other_losses,const Deck<T>& other_fD,const Deck<S>& other_sD)
{
	playerName.setString(name, strlen(name) + 1, strlen(name) + 2);
	wins = other_wins;
	losses = other_losses;
	firstDeck.setDeck(other_fD);
	secondDeck.setDeck(other_sD);
}

template<typename T, typename S, typename M, typename N>
inline void Player<T, S, M, N>::setPlayer(const Player<T, S, M, N>& other)
{
	playerName.setString(other.playerName.getString(), other.playerName.getSize(), other.playerName.getCapacity());
	wins = other.wins;
	losses = other.losses;
	firstDeck = other.firstDeck;
	secondDeck = other.secondDeck;
}

template<typename T, typename S, typename M, typename N>
inline void Player<T, S, M, N>::setPlayerName(const char* name)
{
	playerName.setString(name, strlen(name) + 1, strlen(name) + 2);
}

template<typename T, typename S, typename M, typename N>
inline void Player<T, S, M, N>::setWins(size_t other_wins)
{
	wins = other_wins;
}

template<typename T, typename S, typename M, typename N>
inline void Player<T, S, M, N>::setLosses(size_t other_losses)
{
	losses = other_losses;
}

template<typename T, typename S, typename M, typename N>
inline void Player<T, S, M, N>::setFirstDeck(const Deck<T>& deck)
{
	firstDeck = deck;
}

template<typename T, typename S, typename M, typename N>
inline void Player<T, S, M, N>::setSecondDeck(const Deck<S>& deck)
{
	secondDeck = deck;
}

template<typename T, typename S, typename M, typename N>
inline void Player<T, S, M, N>::printPlayer() const
{
	std::cout << "Player name: " << playerName.getString() << std::endl;
	std::cout << "Wins: " << wins << std::endl;
	std::cout << "Losses: " << losses << std::endl;
}

template<typename T, typename S, typename M, typename N>
inline Deck<T> Player<T, S, M, N>::getFirstDeck() const
{
	return firstDeck;
}

template<typename T, typename S, typename M, typename N>
inline Deck<S> Player<T, S, M, N>::getSecondDeck() const
{
	return secondDeck;
}

template<typename T, typename S, typename M, typename N>
inline size_t Player<T, S, M, N>::getWins() const
{
	return wins;
}

template<typename T, typename S, typename M, typename N>
inline size_t Player<T, S, M, N>::getLosses() const
{
	return losses;
}

template<typename T, typename S, typename M, typename N>
inline size_t Player<T, S, M, N>::operator++()
{
	return wins++;
}

template<typename T, typename S, typename M, typename N>
inline size_t Player<T, S, M, N>::operator--()
{
	return losses++;
}

template<typename T, typename S, typename M, typename N>
inline void Player<T, S, M, N>::drawCard()
{
	srand(time(0));
	int r = rand() % 2;
	if (r == 0)
	{
		return firstDeck.drawCard();
	}
	else
	{
		return secondDeck.drawCard();
	}
}

template<typename T, typename S, typename M, typename N>
inline void Player<T, S, M, N>::savePlayer(const char* filename)
{
	std::ofstream out(filename);
	if (out.is_open())
	{
		out << playerName.getString() << std::endl;
		out << wins << std::endl;
		out << losses << std::endl;

		out.close();
	}
	else
	{
		std::cout << "Unable to open!\n";
	}
}

template<typename T, typename S, typename M, typename N>
inline void Player<T, S, M, N>::loadPlayer(const char* filename)
{
	std::ifstream in(filename);
	if (in.is_open())
	{
		char* name = new char[playerName.getCapacity()];

		for (size_t i = 0; i < playerName.getSize(); i++)
		{
			name[i] = playerName.getString()[i];
		}
		name[playerName.getSize()] = '\0';

		char ch = ' ';
		size_t counter = 0;

		while (ch != '\n')
		{
			in.get();
			if (ch != '\n')
			{
				name[counter++] = ch;
			}
		}
		name[counter] = '\0';
		in >> wins;
		in >> losses;

		in.close();
	}
	else
	{
		std::cout << "Unable to open!\n";
	}
}
