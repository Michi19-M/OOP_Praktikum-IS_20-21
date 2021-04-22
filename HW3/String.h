#pragma once
#include <iostream>

class String
{
private:
	char* string;
	size_t size;
	size_t capacity;

	void copy(const String& other);
	void destroy();
	void resize();
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

	bool operator==(const String& other);
	bool operator!=(const String& other);
	char operator[](size_t index);
};