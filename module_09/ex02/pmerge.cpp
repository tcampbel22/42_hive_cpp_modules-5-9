/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:00:29 by tcampbel          #+#    #+#             */
/*   Updated: 2025/02/11 16:17:41 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pmerge.hpp"

Pmergeme::Pmergeme() {}
Pmergeme::Pmergeme(Pmergeme& copy) : vec(copy.vec), deq(copy.deq) {}
Pmergeme& Pmergeme::operator=(Pmergeme& other) 
{
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
	}
	return *this;
}

Pmergeme::~Pmergeme() {}


void	Pmergeme::storeValues(char** values, int count)
{
	for (int i = 1; i < count; i++)
	{
		try 
		{
			vec.push_back(std::stoi(values[i]));
			deq.push_back(std::stoi(values[i]));
		}
		catch(std::exception& e)
		{
			throw std::invalid_argument("error: invalid input");
		}
		if (std::stoi(values[i]) < 0)
			throw std::invalid_argument("error: positive integers only");
	}
	sort_vec = vec;
	sort_deq = deq;
}

void	Pmergeme::vecSort() 
{

}

void	Pmergeme::deqSort()
{
	
}

void	Pmergeme::printResult(int count) 
{
	std::cout << "Before: "; 
	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';
	std::cout << "After:  ";
	for (auto it = sort_vec.begin(); it != sort_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';
	std::cout << "Before: ";
	for (auto it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';
	std::cout << "After:  ";
	for (auto it = sort_deq.begin(); it != sort_deq.end(); it++)
	std::cout << *it << " ";
	std::cout << '\n';
	std::cout << "Time to process a range of " << count << " elements with std::vector: " << vec_time << "us\n";
	std::cout << "Time to process a range of " << count << " elements with std::deque:  " << deq_time << "us\n";
}