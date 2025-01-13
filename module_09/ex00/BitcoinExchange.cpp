/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:06:35 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/13 17:01:28 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(){}

Bitcoin::~Bitcoin(){}

bool	Bitcoin::validDate(std::string& date)
{
	std::regex date_format("^\\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\\d|3[01])$");
	if (regex_match(date, date_format))
		return true;
	return false;
}

void	Bitcoin::parseDb(std::string file)
{
	std::string line, date, rate;
	data.open(file);
	if (!data)
		throw std::runtime_error("failed to open file\n");
	if(!std::getline(data, line))
		throw std::runtime_error("Invalid format");
	while (std::getline(data, line))
	{
		std::istringstream	tempLine(line);
		if (!std::getline(tempLine, date, ',') || (!std::getline(tempLine, rate)))
			throw std::runtime_error("Invalid format");
		if (validDate(date))
		{
			try {
				double conv_rate = std::stod(rate);
				if (conv_rate < 0 || conv_rate > INT32_MAX)
					throw std::invalid_argument("Invalid rate");
				dataBase[date] = conv_rate;
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
		else
			throw std::runtime_error("Invalid date");
	}
	data.close();
}

void	Bitcoin::createFile(std::string& inputfile) 
{
	input.open(inputfile);
	if (!input)
		throw std::runtime_error("File failed to open");
	
}