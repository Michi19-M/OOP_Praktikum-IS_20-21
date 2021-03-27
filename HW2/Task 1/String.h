#pragma once
#include <iostream>

class String
{
private:
	char* string;
	size_t size;
	size_t capacity;

	void copy(const String& other);
	void erase();
	void resize();
	void swap(char &a, char &b);
public:
	String();
	String(const String& other);
	String& operator=(const String& other);
	~String();

	void setString(const char* other_string, size_t other_size, size_t other_capacity);

	const char* getString() const;
	size_t getSize() const;
	size_t getCapacity() const;
	size_t getLength() const;

	void printString() const;

	void add(char newElement);
	void insertAt(/*size_t index, char symbol*/);
	void removeAt(size_t index);
	void trimStart();
	void trimEnd();
	void trimStart(size_t number);
	void trimEnd(size_t number);

	String& operator+(const String& other);
	String& operator+=(const String& other);
	bool operator==(const String& other);
	bool operator!=(const String& other);
	char operator[](size_t index);
};