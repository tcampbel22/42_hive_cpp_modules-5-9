/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:09:00 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/28 17:56:36 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
class Span
{
private:
	std::vector<int>	spanVector;
public:
	Span();
	Span(uint N);
	Span(const Span& copy);
	~Span();
	const Span& operator=(const Span& other);
	void	addNumber(uint num);
	uint	shortestSpan(); //smallest difference between 2 numbers
	uint	longestSpan(); //largest difference between 2 numbers
	// void	addAllTheNumbers(int numAmount);
};