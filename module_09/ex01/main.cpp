/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:36:53 by tcampbel          #+#    #+#             */
/*   Updated: 2025/02/11 11:05:35 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		RPN rpn;
		try 
		{
			rpn.operation(av[1]);
			return (0);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			exit(1);
		}
	}
	else
	{
		std::cerr << "error: invalid argument amount" << std::endl;
		return (1);
	}	
}