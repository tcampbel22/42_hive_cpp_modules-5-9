#include <iostream>
#include "Iter.hpp"
#include "Iter.tpp"


template<typename T>
void	addOne(T& x)
{
	x += 1;
}
template<typename T>
void printInt(T& x)
{
	std::cout << '[' << x << "] ";
}

int main()
{
	int	intArray[] = { 1, 2, 3, 4, 5 };
	int len = 5;
	Iter<int> IterInt;

	std::cout << "Before:\n";
	IterInt.iter(intArray, len, printInt<int>);
	IterInt.iter(intArray, len, addOne<int>);
	std::cout << "\nAfter:\n";
	IterInt.iter(intArray, len, printInt<int>);

	char charArray[] = { 'a', 'b', 'c', 'd', 'e' };
	int len2 = 5;
	Iter<char> IterChar;

	std::cout << "\n\nBefore:\n";
	IterChar.iter(charArray, len2, printInt<char>);
	IterChar.iter(charArray, len2, addOne<char>);
	std::cout << "\nAfter:\n";
	IterChar.iter(charArray, len2, printInt<char>);

	return 0;
}