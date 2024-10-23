/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:30:13 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/23 15:18:48 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>
#include <iomanip>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	~ScalarConverter();
	const ScalarConverter&	operator=(const ScalarConverter& other);
public:
	static void	convert(const std::string literal);
};

void	convertChar(const std::string literal);
void	convertInt(const std::string literal);
void	convertFloat(const std::string literal);
void	convertDouble(const std::string literal);
void	print_all(char c, long i, double f, long double d);
void	print_special(int flag);
int		isSpecial(const std::string literal);