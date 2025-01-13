/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:01:50 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/13 16:58:07 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		std::cerr << "Expected one file as input: ./btc <file>" << std::endl;
	Bitcoin bitcoin;
	try
	{
		bitcoin.parseDb("data.csv");
		bitcoin.createFile(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}