#include <iostream>
#include "Iter.hpp"
#include "Iter.tpp"


void	addOne(int&	x)
{
	x += 1;
}

void printInt(int& x)
{
	std::cout << '[' << x << "] ";
}

int main()
{
	int	array[] = { 1, 2, 3, 4, 5 };
	int len = 5;
	Iter<int> IterInt;

	std::cout << "Before:\n";
	IterInt.iter(array, len, printInt);
	IterInt.iter(array, len, addOne);
	std::cout << "\nAfter:\n";
	IterInt.iter(array, len, printInt);

	return 0;
}