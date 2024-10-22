/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:36:27 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/22 18:04:10 by tcampbel         ###   ########.fr       */
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

int		isSpecial(const std::string literal, e_type flag)
{
	if ((!literal.compare("-inff") && flag == FLOAT) 
		|| (!literal.compare("-inf") && flag == DOUBLE))
		return 1;
	else if ((!literal.compare("+inff") && flag == FLOAT)
		 || (!literal.compare("+inf") && flag == DOUBLE))
		return 2;
	else if ((!literal.compare("nanf") && flag == FLOAT) 
		|| (!literal.compare("nan") && flag == DOUBLE))
		return 3;
	else
		return 0;
}

bool	isChar(const std::string literal)
{
	if (literal.length() == 3 && literal.back() == '\'' && literal.front() == '\'')
	{
		const char *temp = literal.c_str();
		if (temp[1] >= 0 && temp[1] <= 126)
			return true;
	}
	return false;
}

bool	isInt(const std::string literal)
{
	const char*	temp = literal.c_str();
	char *end;
	if (!literal.compare("0"))
		return true;
	else if (std::strtol(temp, &end, 10) != 0)
		return true;
	return false;
}

bool	isFloat(const std::string literal)
{
	const char*	temp = literal.c_str();
	char *end;
	if (!literal.compare("0.0f"))
		return true;
	else if (std::strtof(temp, &end) && literal.back() == 'f' && !isSpecial(literal, FLOAT))
		return true;
	return false;
}

bool	isDouble(const std::string literal)
{
	const char*	temp = literal.c_str();
	char *end;
	if (!literal.compare("0.0"))
		return true;
	else if (std::strtod(temp, &end) && !isSpecial(literal, DOUBLE))
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
		break;
	}
}

void	ScalarConverter::convert(const std::string literal)
{
	if (isChar(literal))
		printScalar(literal, CHAR);
	else if (isFloat(literal) || isSpecial(literal, FLOAT))
		printScalar(literal, FLOAT);
	else if (isDouble(literal) || isSpecial(literal, DOUBLE))
		printScalar(literal, DOUBLE);
	else if (isInt(literal))
		printScalar(literal, INT);
	else
		std::cout << "Not a scalar type!\n";
}