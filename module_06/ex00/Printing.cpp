/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printing.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:13:29 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/22 17:44:01 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


void print_all(char c, long i, double f, long double d)
{
	if (c == 0)
		std::cout << "char: Non displayable" << std::endl;
	else if (c == -1)
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: Impossible\n";
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	
	if (f > FLT_MAX || f < FLT_MIN )
		std::cout << "float: Impossible\n";
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(f) << "f" << std::endl;
	
	if (d > DBL_MAX || d < DBL_MIN )
		std::cout << "double: Impossible\n";
	else
		std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(d) << std::endl;
}

void	print_special(int flag)
{
	std::cout << "char: Impossible\n";
	std::cout << "int: Impossible\n";
	switch (flag)
	{
		case 1:
			std::cout << "float: -inff\ndouble: -inf\n"; 
			break;
		case 2:
			std::cout << "float: +inff\ndouble: +inf\n";
			break; 
		case 3:
			std::cout << "float: nanf\ndouble: nan\n";
			break;
		default:
			return;
	}
}

void	convertChar(const std::string literal)
{
	const char *temp = literal.c_str();
	if ((temp[1] >= 0 && temp[1] <= 31) || temp[1] == 127)
		std::cout << "Char is valid but unprintable\n";
	else
		print_all(temp[1], temp[1], temp[1], temp[1]);
}

void	convertInt(const std::string literal)
{
	const char* temp = literal.c_str();
	char*		end;
	long		result = std::strtol(temp, &end, 10);
	
	if (!literal.compare("0") || !literal.compare("-0") || !literal.compare("+0"))
		print_all(0, 0, 0, 0);
	else if ((result >= 0 && result <= 31) || result == 127)
		print_all(0, result, result, result);
	else if (result >= 32 && result <= 126)
		print_all((char)result, result, result, result);
	else
		print_all(-1, result, result, result);
}

void	convertFloat(const std::string literal)
{
	const char* temp = literal.c_str();
	char*		end;
	double		result = std::strtof(temp, &end);
	
	if (!literal.compare("0") || !literal.compare("-0") || !literal.compare("+0"))
		print_all(0, 0, 0, 0);
	else if (isSpecial(literal, FLOAT))
		print_special(isSpecial(literal, FLOAT));
	else if ((result >= 0 && result <= 31) || result == 127)
		print_all(0, result, result, result);
	else if (result >= 32 && result <= 126)
		print_all((char)result, result, result, result);
	else if (result >= FLT_MIN && result <= FLT_MAX)
		print_all(-1, result, result, result);
}

void	convertDouble(const std::string literal)
{
	const char* temp = literal.c_str();
	char*		end;
	long double		result = std::strtod(temp, &end);
	if (!literal.compare("0") || !literal.compare("-0") || !literal.compare("+0"))
		print_all(0, 0, 0, 0);
	else if (isSpecial(literal, DOUBLE))
		print_special(isSpecial(literal, DOUBLE));
	else if ((result >= 0 && result <= 31) || result == 127)
		print_all(0, result, result, result);
	else if (result >= 32 && result <= 126)
		print_all((char)result, result, result, result);
	else if (result >= DBL_MIN && result <= DBL_MAX)
		print_all(-1, result, result, result);
}