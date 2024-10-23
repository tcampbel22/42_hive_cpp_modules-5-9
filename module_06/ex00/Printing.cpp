/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printing.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:13:29 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/23 15:13:06 by tcampbel         ###   ########.fr       */
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
	
	if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
		std::cout << "int: Impossible\n";
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	
	if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
		std::cout << "float: Impossible\n";
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(f) << "f" << std::endl;
		
	if (i >= std::numeric_limits<long long>::max() || i <= std::numeric_limits<long long>::min())
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
	
	if (literal.length() == 3)
			print_all(temp[1], temp[1], temp[1], temp[1]);
	else
			print_all(temp[0], temp[0], temp[0], temp[0]);
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
		print_all(result, result, result, result);
	else
		print_all(-1, result, result, result);
}

void	convertFloat(const std::string literal)
{
	const char* temp = literal.c_str();
	char*		end;
	double		result = std::strtod(temp, &end);
	
	if (!literal.compare("0.0f") || !literal.compare("-0.0f") || !literal.compare("+0.0f"))
		print_all(0, 0, 0, 0);
	else if (isSpecial(literal))
		print_special(isSpecial(literal));
	else if ((result >= 0 && result <= 31) || result == 127)
		print_all(0, result, result, result);
	else if (result >= 32 && result <= 126)
		print_all(result, result, result, result);
	else
		print_all(-1, result, result, result);
}

void	convertDouble(const std::string literal)
{
	const char* 	temp = literal.c_str();
	char*			end;
	long double		result = std::strtold(temp, &end);
	if (!literal.compare("0.0f") || !literal.compare("-0.0") || !literal.compare("+0.0"))
		print_all(0, 0, 0, 0);
	else if (isSpecial(literal))
		print_special(isSpecial(literal));
	else if ((result >= 0 && result <= 31) || result == 127)
		print_all(0, result, result, result);
	else if (result >= 32 && result <= 126)
		print_all(result, result, result, result);
	else
		print_all(-1, result, result, result);
}