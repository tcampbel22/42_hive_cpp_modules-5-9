#include <iostream>
#include "Iter.hpp"


template<typename T>
void	addOne(T& x)
{
	x += 1;
}
template<typename T>
void printT(T& x)
{
	std::cout << '[' << x << "] ";
}

int main()
{
	{
		int	intArray[] = { 1, 2, 3, 4, 5 };
		int len = 5;

		std::cout << "Before:\n";
		iter(intArray, len, printT<int>);
		iter(intArray, len, addOne<int>);
		std::cout << "\nAfter:\n";
		iter(intArray, len, printT<int>);
	}
	{
		char charArray[] = { 'a', 'b', 'c', 'd', 'e' };
		int len2 = 5;

		std::cout << "\n\nBefore:\n";
		iter(charArray, len2, printT<char>);
		iter(charArray, len2, addOne<char>);
		std::cout << "\nAfter:\n";
		iter(charArray, len2, printT<char>);
	}
	return 0;
}