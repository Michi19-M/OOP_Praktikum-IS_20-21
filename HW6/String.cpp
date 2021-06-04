#include "String.h"

void String::copy(const String& other)
{
	string = new char[other.capacity];
	strcpy_s(string, other.size, other.string);
	size = other.size;
	capacity = other.capacity;
}

void String::destroy()
{
	delete[] string;
}

void String::resize()
{
	capacity *= 2;
	char* newString = new char[capacity];
	strcpy_s(newString, size, string);

	delete[] string;
	string = newString;
}

String::String()
{
	size = 1;
	capacity = 6;
	string = new char[capacity];
	string[0] = '\0';
}
String::String(const String& other)
{
	copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

String::~String()
{
	destroy();
}

void String::setString(const char* other_string, size_t other_size, size_t other_capacity)
{
	delete[] string;
	size = other_size;
	capacity = other_capacity;
	string = new char[capacity];
	strcpy_s(string, size, other_string);
}

const char* String::getString() const
{
	return string;
}

size_t String::getSize() const
{
	return size;
}

size_t String::getCapacity() const
{
	return capacity;
}

size_t String::getLength() const
{
	return strlen(string);
}

void String::printString() const
{
	std::cout << "String: " << string << std::endl;
}

bool String::operator==(const String& other)
{
	for (size_t i = 0; i < size; i++)
	{
		if (string[i] != other.string[i])
		{
			return false;
		}
	}
	return true;
}

bool String::operator!=(const String& other)
{
	if (this->operator==(other))
	{
		return false;
	}
	return true;
}

char String::operator[](size_t index)
{
	index -= 1;
	if (index >= size)
	{
		std::cout << "Index is too big!\n";
		return 0;
	}
	return string[index];
}