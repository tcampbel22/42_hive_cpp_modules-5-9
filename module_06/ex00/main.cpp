/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:06:43 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/22 17:53:57 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main()
{
	try
	{
		// std::string _char = "'*'";
		// std::string _int = "2147483647";
		std::string _float = "465.2f";
		std::string	_double = "+inf";
		// ScalarConverter::convert(_char);
		// ScalarConverter::convert(_int);
		ScalarConverter::convert(_float);
		ScalarConverter::convert(_double);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}