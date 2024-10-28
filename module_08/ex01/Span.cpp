/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:08:37 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/28 14:57:27 by tcampbel         ###   ########.fr       */
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
		
	}
}

uint	Span::longestSpan() {}

void	Span::addAllTheNumbers(int numAmount) {}