/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:08:37 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/28 17:58:44 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : spanVector(0, 0) {}

Span::Span(uint N) : spanVector(N, 0) {}

Span::Span(const Span& copy) : spanVector(copy.spanVector){}

Span::~Span() {}

const Span& Span::operator=(const Span& other)
{
	if (this != &other)
		spanVector = other.spanVector;
	return *this;
}

void	Span::addNumber(uint num)
{
	spanVector.push_back(num);
}

uint	Span::shortestSpan() 
{
	if (spanVector.size() <= 1)
		throw std::invalid_argument("Not enough numbers in array");
	else
	{
		sort(spanVector.begin(), spanVector.end());
		
		
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
		// std::cout << "Max: " << *max << " Min: " << *min << "\nResult: " << *max - *min << '\n';
		return *max - *min;
	}
}

// void	Span::addAllTheNumbers(int numAmount) {}