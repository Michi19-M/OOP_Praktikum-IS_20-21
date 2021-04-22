#pragma once
#include "WaterCard.h"
#include "FireCard.h"
#include "EarthCard.h"
#include "WindCard.h"
#include <cstdlib> // no need ??

template <class T>
class Deck
{
public:
	Deck();
	void setDeck(const Deck<T>& other);

	T getDeck() const;
	size_t getDeckSize() const;

	void addCard(const T& newCard);
	void shuffleDeck();
	T& drawCard(); // void ??

	Deck<T> operator+(const T& newCard);
	Deck<T>& operator+=(const T& newCard);

	void printDeck() const;
private:
	T deck[30];
	size_t numberOfCards;

	bool sameCardNameCheck(const T& card) const;
	void swap(T& a, T& b);
};

template<class T>
inline Deck<T>::Deck()
{
	numberOfCards = 0;
}

template<class T>
inline void Deck<T>::setDeck(const Deck<T>& other)
{
	numberOfCards = other.numberOfCards;

	for (size_t i = 0; i < numberOfCards; i++)
	{
		deck[i] = other.deck[i];
	}
}

template<class T>
inline T Deck<T>::getDeck() const
{
	return *deck;
}

template<class T>
inline size_t Deck<T>::getDeckSize() const
{
	return numberOfCards;
}

template<class T>
inline void Deck<T>::addCard(const T& newCard)
{
	if (sameCardNameCheck(newCard) && numberOfCards < 30)
	{
		deck[numberOfCards++] = newCard;
	}
}

template<class T>
inline void Deck<T>::shuffleDeck()
{
	// Initialize seed randomly
	srand(time(0));

	for (size_t i = 0; i < numberOfCards; i++)
	{
		size_t r = i + (rand() % (numberOfCards - i));
		//if( i != r) ??
		swap(deck[i], deck[r]);
	}
}

template<class T>
inline T& Deck<T>::drawCard()
{
	for (size_t i = 0; i < numberOfCards - 1; i++)
	{
		swap(deck[i], deck[numberOfCards - 1]);
	}
	return deck[0];
}

template<class T>
inline Deck<T> Deck<T>::operator+(const T& newCard)
{
	return addCard(newCard);
}

template<class T>
inline Deck<T>& Deck<T>::operator+=(const T& newCard)
{
	*this = *this + newCard;
	return *this;
}

template<class T>
inline void Deck<T>::printDeck() const
{
	for (size_t i = 0; i < numberOfCards; i++)
	{
		std::cout << deck[i] << '\n';
	}
}

template<class T>
inline bool Deck<T>::sameCardNameCheck(const T& card) const
{
	if (numberOfCards == 0){
		return true;
	}
	for (size_t i = 0; i < numberOfCards; i++)
	{
		if (deck[i].getCardName() == card.getCardName()){
			return false;
		}
	}
	return true;
}

template<class T>
inline void Deck<T>::swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
