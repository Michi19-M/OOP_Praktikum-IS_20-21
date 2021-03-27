#include "String.h"

void String::copy(const String& other)
{
	string = new char[other.capacity];
	strcpy_s(string, other.size, other.string);
	size = other.size;
	capacity = other.capacity;
}

void String::erase()
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

void String::swap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
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
		erase();
		copy(other);
	}
	return *this;
}

String::~String()
{
	erase();
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

void String::add(char newElement)
{
	if (size >= capacity){
		resize();
	}
	string[size] = newElement;
	++size;
}

void String::insertAt(/*size_t index, char symbol*/)
{
	size_t length = strlen(string);
	int index;
	char symbol;

	do
	{
		std::cout << "Input index to insert: ";
		std::cin >> index;
		std::cout << "What symbol do you want to add: ";
		std::cin >> symbol;
	} while (index < 0 || index > length);

	index -= 1;
	length++;
	string[length] = symbol;

	for (int i = length; i >= 0; i--)
	{
		if (i == index){
			break;
		}
		swap(string[i], string[i - 1]);
	}
	++size;
}

void String::removeAt(size_t index)
{
	index -= 1;
	size_t length = strlen(string);

	for (size_t i = 0; i < length; i++)
	{		
		swap(string[index + i], string[index + i + 1]);

		if (string[index + i] == '\0')
			break;
	}
	size--;
}

void String::trimStart()
{
	size_t length = strlen(string);
	
	for (size_t i = 0; i < length; i++)
	{
		swap(string[i], string[i + 1]);
	}
	size--;
}

void String::trimEnd()
{
	string[strlen(string) - 1] = '\0';
	size--;
}

void String::trimStart(size_t number)
{
	for (size_t i = 0; i < number; i++)
	{
		for (size_t j = 0; j < size - 1; j++)
		{
			swap(string[j], string[j + 1]);
		}
		size--;
	}
}

void String::trimEnd(size_t number)
{
	for (size_t i = 0; i < number; i++)
	{
		swap(string[size - 2], string[size - 1]);
		size--;
	}
}

String& String::operator+(const String& other)
{
	capacity += other.capacity;
	char* tempString = new char[capacity];
	strcpy_s(tempString, size, string);

	size_t index = 0;
	for (size_t i = size - 1; other.string[index] != '\0'; i++)
	{
		tempString[i] = other.string[index];
		index++;
	}
	size += (other.size - 1);
	tempString[size - 1] = '\0';

	delete[] string;
	string = tempString;
	return *this;
}

String& String::operator+=(const String& other)
{
	operator+(other);
	return *this;
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
