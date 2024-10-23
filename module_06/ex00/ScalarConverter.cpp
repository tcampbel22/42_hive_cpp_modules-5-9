/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:36:27 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/23 14:53:54 by tcampbel         ###   ########.fr       */
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

int		isSpecial(const std::string literal)
{
	if (!literal.compare("-inff") || !literal.compare("-inf"))
		return 1;
	else if (!literal.compare("+inff") || !literal.compare("+inf"))
		return 2;
	else if (!literal.compare("nanf") || !literal.compare("nan"))
		return 3;
	else
		return 0;
}

bool	isChar(const std::string literal)
{
	const char *temp = literal.c_str();
	if (literal.length() == 3 && literal.back() == '\'' && literal.front() == '\'')
	{
		if (temp[1] >= 0 && temp[1] <= 126)
			return true;
	}
	else if (literal.length() == 1 && (temp[0] >= 0 && temp[0] <= 127))
		return true;
	return false;
}

bool	isInt(const std::string literal)
{
	const char*	temp = literal.c_str();
	char *end;
	if (!literal.compare("0") || !literal.compare("-0") || !literal.compare("+0"))
		return true;
	else if (std::strtol(temp, &end, 10) && *end == '\0')
		return true;
	return false;
}

bool	isFloat(const std::string literal)
{
	const char*	temp = literal.c_str();
	char *end;
	if (!literal.compare("0.0f") || !literal.compare("-0.0f") || !literal.compare("+0.0f"))
		return true;
	else if (std::strtod(temp, &end) && literal.back() == 'f'  && *end == '\0')
		return true;
	return false;
}

bool	isDouble(const std::string literal)
{
	const char*	temp = literal.c_str();
	char *end;
	if (!literal.compare("0.0") || !literal.compare("-0.0") || !literal.compare("+0.0"))
		return true;
	else if (literal.find('.') != std::string::npos && std::strtold(temp, &end) && *end == '\0')
		return true;
	return false;
}


void	printScalar(const std::string literal, e_type flag)
{
	switch (flag)
	{
		case CHAR:
			convertChar(literal);
			break;
		case FLOAT:
			convertFloat(literal);
			break;
		case DOUBLE:
			convertDouble(literal);
			break;
		case INT:
			convertInt(literal);
			break;
		default:
			std::cout <<  literal << " is not a scalar type\n";
	}
}

void	ScalarConverter::convert(const std::string literal)
{
	if (isFloat(literal) || isSpecial(literal))
		printScalar(literal, FLOAT);
	else if (isDouble(literal) || isSpecial(literal))
		printScalar(literal, DOUBLE);
	else if (isInt(literal))
		printScalar(literal, INT);
	else if (isChar(literal))
		printScalar(literal, CHAR);
	else
		std::cout << literal << " is not a scalar type!\n";
}