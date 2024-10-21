/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:36:27 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/21 18:52:57 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) { *this = copy; }
ScalarConverter::~ScalarConverter() {}
const ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) 
{
	if (this == &other)
		return *this;
	return *this;
}

void	ScalarConverter::convert(const char* literal)
{
	return ;
}