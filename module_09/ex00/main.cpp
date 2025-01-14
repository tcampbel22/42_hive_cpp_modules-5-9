/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:01:50 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/14 17:39:07 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Expected one file as input: ./btc <file>" << std::endl;
		exit(1);
	}
	Bitcoin bitcoin;
	try
	{
		bitcoin.parseFile("data.csv", ',', bitcoin.getMap(DATABASE));
		bitcoin.printExchange(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	exit(0);
}