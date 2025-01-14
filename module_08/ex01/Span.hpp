/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:09:00 by tcampbel          #+#    #+#             */
/*   Updated: 2024/11/13 17:15:20 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Span
{
private:
	uint				limit;
	std::vector<int>	spanVector;
public:
	Span();
	Span(uint N);
	Span(const Span& copy);
	~Span();
	const Span& operator=(const Span& other);
	void	addNumber(int num);
	uint	shortestSpan(); //smallest difference between 2 numbers
	uint	longestSpan(); //largest difference between 2 numbers
	void	addAllTheNumbers(uint numAmount);
};