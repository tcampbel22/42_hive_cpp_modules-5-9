/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:01:50 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/17 13:27:03 by tcampbel         ###   ########.fr       */
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
		bitcoin.parseFile("data.csv", ',', DATABASE);
		bitcoin.parseFile(av[1], '|', EXCHANGE);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	exit(0);
}