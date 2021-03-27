#include <iostream>
#include "String.h"

int main()
{
	String s1, s2;
	s1.setString("M@r7iN", 11, 14);
	s1.printString();		
	/*s1.insertAt();
	s1.removeAt(2);
	s1.trimEnd();
	s1.trimStart(2);
	s1.trimEnd(2);
	s1.printString();*/

	s2.setString(" M1r4eV", 8, 15);
	s2.printString();
	s1.operator+(s2);
	s1.printString();

	std::cout << "Your symbol is: " << s2.operator[](4) << std::endl;

	return 0;
}