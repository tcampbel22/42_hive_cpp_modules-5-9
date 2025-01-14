/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:08:37 by tcampbel          #+#    #+#             */
/*   Updated: 2024/11/13 17:15:25 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : limit(0), spanVector(0, 0) {}

Span::Span(uint N) : limit(N), spanVector(0, 0) {}

Span::Span(const Span& copy) : spanVector(copy.spanVector) {}

Span::~Span() {}

const Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		limit = other.limit;
		spanVector = other.spanVector;
	}
	return *this;
}

void	Span::addNumber(int num)
{
	if (spanVector.size() <= limit)
		spanVector.push_back(num);
	else
		throw std::out_of_range("Cannot add any more numbers");
}

uint	Span::shortestSpan() 
{
	if (spanVector.size() <= 1)
		throw std::invalid_argument("Not enough numbers in array");
	else
	{
		std::vector<int> diff(spanVector.size());
		sort(spanVector.begin(), spanVector.end()); //sorts in ascending order
		std::adjacent_difference(spanVector.begin(), spanVector.end(), diff.begin());
		diff.erase(diff.begin());
		std::vector<int>::iterator min = std::min_element(diff.begin(), diff.end());
		if (*min)
			return *min;
		else
			throw std::invalid_argument("No span in array");
	}
}

uint	Span::longestSpan() 
{
	if (spanVector.size() <= 1)
		throw std::invalid_argument("Not enough numbers in array");
	else
	{
		std::vector<int>::iterator max = std::max_element(spanVector.begin(), spanVector.end());
		std::vector<int>::iterator min = std::min_element(spanVector.begin(), spanVector.end());
		int result = *max - *min;
		if (result)
			return result;
		else
			throw std::invalid_argument("No span in array");
	}
}

void	Span::addAllTheNumbers(uint numAmount) 
{
	if (numAmount > limit)
		throw std::out_of_range("Exceeds array limit");
	std::srand(time(0));
	while (spanVector.size() <= limit)
		spanVector.push_back((int)rand());
}