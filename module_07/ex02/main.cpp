#include <iostream>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 0

std::ostream& operator<<(std::ostream& stream, int* intArray)
{
	for (uint i = 0; i < MAX_VAL; i++)
		stream << intArray[i] << " ";
	return stream;
}


int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
	Array<int> number2(2);
	std::cout << "Number2: " << number2 << '\n';
	number2 = numbers;
	std::cout << "Numbers: " << numbers << '\n';
	std::cout << "Mirror: " << mirror << '\n';
	std::cout << "Number2: " << number2 << '\n';
    
	//Testing copy constructor and operator= further
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		std::cout << "\ntmp: " << tmp << '\n';
		std::cout << "test: " << test << '\n';
	}

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
		else
			std::cout << "Values at index [" << i << "] are the same!\n";
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}